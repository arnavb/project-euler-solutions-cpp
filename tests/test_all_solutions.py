import os # For checking if path exists
import shutil # For deleting the data directory
import subprocess # For executing the files
import sys # For command line arguments
import distutils # For copying the data directory
from distutils import dir_util # https://stackoverflow.com/a/33417555/6525260

class colors: # ANSI escape codes for colors
    OKBLUE = "\033[36;1m"
    OKGREEN = "\033[32;1m"
    WARNING = "\033[33;1m"
    FAIL = "\033[31;1m"
    ENDC = "\033[0m"
    BOLD = "\033[1m"
    UNDERLINE = "\033[4m"
    BRIGHTMAGENTA = "\033[95;1m"

def color_string(color, string):
    return color + string + colors.ENDC

def test_all_solutions(directory_name, compiler_name, expected_solutions):
    try:
        dir_util.copy_tree(directory_name + "/data/", "./data/") # Copy the data folder that some solutions need
    except dir_util.DistutilsFileError:
        print(color_string(colors.WARNING, f"The data folder was unable to be copied from {directory_name} to ./data!\nSome solutions may not be able to compile!\n"))

    passed_tests = 0
    
    for problem, solution in expected_solutions.items():
        print(color_string(colors.BOLD, "==============="))
        print(f"{color_string(colors.OKBLUE, 'TEST')}: Problem {str(problem)}")
        
        current_file = directory_name + "/Problem" + problem + ".cpp"
        
        print("\nFile: " + current_file)
        
        compile_command = f"{compiler_name} {current_file} -std=c++14 -O2"
        
        print("Running: " + compile_command)
        
        if (subprocess.call(compile_command.split(), stdout = subprocess.DEVNULL, stderr = subprocess.STDOUT) != 0): # Compile the current file
            print(f"Result: {color_string(colors.FAIL, 'FAILURE')}: File was unable to be compiled!")
        else:
            current_output_string = subprocess.check_output(['./a.out']).decode('utf-8') # Run the executable and capture the output
            if current_output_string.strip().isdigit():
                current_output = int(current_output_string)
                
                print(f"\nExpected output: {color_string(colors.BRIGHTMAGENTA, str(solution))}")
                print(f"Current output: {color_string(colors.BRIGHTMAGENTA, str(current_output))}")
                
                print("\nResult: ", end = '')
                if current_output == solution:
                    print(color_string(colors.OKGREEN, "SUCCESS"))
                    passed_tests += 1
                else:
                    print(f"{color_string(colors.FAIL, 'FAILURE')}: Current output {str(current_output)} does not match expected output {str(solution)}!")
            else:
                print(f"Result: {color_string(colors.FAIL, 'FAILURE')}: Expected integer but found: ")
                print(current_output_string)
    
    print(color_string(colors.BOLD, "==============="))
        
    print("\n")
    
    if os.path.isfile('./a.out'): # Remove the new executable file
        os.remove('a.out')
    
    if os.path.isdir("./data"): # Remove the data directory
        shutil.rmtree("./data")
    
    num_tests = len(expected_solutions)
    
    print(color_string(colors.BOLD, str(passed_tests) + " out of " + str(num_tests) + " tests were successful."))
    
    if passed_tests == num_tests:
        print(f"Result: {color_string(colors.OKGREEN, 'SUCCESS')}")
        return 0
    else:
        print(f"Result: {color_string(colors.FAIL, 'SUCCESS')}")
        return 1
    
    

if __name__ == '__main__':
    
    expected_solutions = { }
    try:
        with open("expected_solutions.txt", "r") as expected_solutions_file:
            for line in expected_solutions_file:
                key_value_pair = line.split(" ")
                if len(key_value_pair) == 2 and key_value_pair[1].strip().isdigit(): # Extract all expected solutions; ignore bad entries
                    expected_solutions[key_value_pair[0]] = int(key_value_pair[1])
    except IOError:
        print("Unable to open file './expected_solutions.txt'! Please check that the file is located in the current working directory!")
    
    if len(sys.argv) != 3: 
        print("Error: Missing operands!")
        print(f"Usage: {sys.argv[0]} repository-root compiler-name")
        sys.exit(1)
    elif not os.path.exists(sys.argv[1]):
        print(f"Error: Path {sys.argv[1]} does not exist!")
    else:
        sys.exit(test_all_solutions(sys.argv[1] + "/solutions", sys.argv[2], expected_solutions))
