import glob # For getting all the solution files
import os # For checking if path exists
import shutil # For deleting the data directory
import subprocess # For executing the files
import sys # For command line arguments
import distutils # For copying the data directory
from distutils import dir_util # https://stackoverflow.com/a/33417555/6525260

class colors:
    OKBLUE = '\033[36;1m'
    OKGREEN = '\033[32;1m'
    WARNING = '\033[33;1m'
    FAIL = '\033[31;1m'
    ENDC = '\033[0m'
    BOLD = '\033[1m'
    UNDERLINE = '\033[4m'

def color_string(color, string):
    return color + string + colors.ENDC

def test_all_solutions(directory_name, compiler_name, expected_solutions):
    files = glob.glob(directory_name + "/Problem***.cpp")
    
    if not files:
        print(color_string(colors.FAIL, "Error: No files were found!"))
        return 1
        
    files.sort()
    
    print("\nThe following files were found: ")
    
    print(*files, sep = "\n")
    
    print("\n")
    
    try:
        dir_util.copy_tree(directory_name + "/data/", "./data/") # Copy the data folder that some solutions need
    except dir_util.DistutilsFileError:
        print(color_string(colors.WARNING, "The data folder was unable to be copied from " + directory_name + "/solutions to ./data!\nSome solutions may not be able to compile!\n"))

    passed_tests = 0
    
    for file in files:
        compile_command = compiler_name + " " + file + " -std=c++14 -O2"
        current_key = file[-7: -4]
        
        print(color_string(colors.BOLD, "==============="))
        print(color_string(colors.OKBLUE, "TEST") + ": Problem " + str(current_key) + "\n")
        print("Trying to compile " + file + " with " + compile_command)
        
        if (subprocess.call(compile_command.split(), stdout = subprocess.DEVNULL, stderr = subprocess.STDOUT) != 0): # Compile the current file
            print("Result: " + color_string(colors.FAIL, "FAILURE") + ": File was unable to be compiled!")
        else:
            try:
                print("File was successfully able to be compiled. Running executable with ./a.out\n")
                current_output = int(subprocess.check_output(['./a.out']).decode('utf-8')) # Execute the file and capture output
                
                print("Current output: " + str(current_output))
                
                if current_key in expected_solutions:
                    expected_solution = expected_solutions[current_key] # Extract problem number for indexing solution
                    
                    print("Expected output: " + str(expected_solution))
                    
                    if current_output == expected_solution:
                        print("\nResult: " + color_string(colors.OKGREEN, "SUCCESS"))
                        passed_tests += 1
                    else:
                        print("\nResult: " + color_string(colors.FAIL, "FAILURE") + ": Current output " + str(current_output) + " does not match expected output " + str(expected_solution) + "!")
                else:
                    print("Result: " + color_string(colors.FAIL, "FAILURE") + ": Expected solution to problem " + str(current_key) + " was not found!")
            except ValueError:
                print("Result: " + color_string(colors.FAIL, "FAILURE") + ": Output is of non-integer type!")
            
    print(color_string(colors.BOLD, "==============="))        
        
    if os.path.isfile('./a.out'): # Remove the new executable file
        os.remove('a.out')
    
    if os.path.isdir("./data"): # Remove the data directory
        shutil.rmtree("./data")
    
    print("\n")
    
    num_tests = len(expected_solutions)
    
    print(color_string(colors.BOLD, str(passed_tests) + " out of " + str(num_tests) + " tests were successful."))
    
    if passed_tests == num_tests:
        print("Result: " + color_string(colors.OKGREEN, "SUCCESS"))
        return 0
    else:
        print("Result: " + color_string(colors.FAIL, "SUCCESS"))
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
        print("Usage: " + sys.argv[0] + " repository-root compiler-name")
        sys.exit(1)
    elif not os.path.exists(sys.argv[1]):
        print("Error: Path " + sys.argv[1] + " does not exist!")
    else:
        sys.exit(test_all_solutions(sys.argv[1] + "/solutions", sys.argv[2], expected_solutions))
