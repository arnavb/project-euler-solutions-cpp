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

def test_all_solutions(directory_name, compiler_name, expected_solutions):
    files = glob.glob(directory_name + "/Problem***.cpp")
    
    if not files:
        print(colors.FAIL + "Error: No files were found!" + colors.ENDC)
        return 1
        
    files.sort()
    
    print("\nThe following files were found: ")
    
    for file in files:
        print(file)
    
    print("\n")
    
    try:
        dir_util.copy_tree(directory_name + "/data/", "./data/") # Copy the data folder that some solutions need
    except dir_util.DistutilsFileError:
        print(colors.WARNING + "The data folder was unable to be copied from " + directory_name + " to ./data!")
        print("Some solutions may not be able to compile!\n" + colors.ENDC)

    passed_tests = 0
    
    for file in files:
        compile_command = compiler_name + " " + file + " -std=c++14 -O2"
        current_key = file[-7: -4]
        
        print(colors.BOLD + "===============" + colors.ENDC)
        print(colors.OKBLUE + "TEST" + colors.ENDC + ": Problem " + str(current_key) + "\n")
        print("Trying to compile " + file + " with " + compile_command)
        
        if (subprocess.call(compile_command.split(), stdout = subprocess.DEVNULL, stderr = subprocess.STDOUT) != 0): # Compile the current file
            print("Result: " + colors.FAIL + "FAILURE" + colors.ENDC + ": File was unable to be compiled!")
        else:
            try:
                print("File was successfully able to be compiled. Running executable with ./a.out\n")
                current_output = int(subprocess.check_output(['./a.out']).decode('utf-8')) # Execute the file and capture output
                
                print("Current output: " + str(current_output))
                
                if current_key in expected_solutions:
                    expected_solution = expected_solutions[current_key] # Extract problem number for indexing solution
                    
                    print("Expected output: " + str(expected_solution))
                    
                    if current_output == expected_solution:
                        print("\nResult: " + colors.OKGREEN +  "SUCCESS" + colors.ENDC)
                        passed_tests += 1
                    else:
                        print("\nResult: " + colors.FAIL + "FAILURE" + colors.ENDC + ": Current output " + str(current_output) + " does not match expected output " + str(expected_solution) + "!")
                else:
                    print("Result: " + colors.FAIL + "FAILURE" + colors.ENDC + ": Expected solution to problem " + str(current_key) + " was not found!")
            except ValueError:
                print("Result: " + colors.FAIL + "FAILURE" + colors.ENDC + ": Output is of non-integer type!")
            
    print(colors.BOLD + "===============" + colors.ENDC)        
        
    if os.path.isfile('./a.out'): # Remove the new executable file
        os.remove('a.out')
    
    if os.path.isdir("./data"): # Remove the data directory
        shutil.rmtree("./data")
    
    print("\n")
    
    num_tests = len(expected_solutions)
    
    print(colors.BOLD + str(passed_tests) + " out of " + str(num_tests) + " tests were successful." + colors.ENDC)
    
    if passed_tests == num_tests:
        print("Result: " + colors.OKGREEN +  "SUCCESS" + colors.ENDC)
        return 0
    else:
        print("Result: " + colors.FAIL + "FAILURE" + colors.ENDC)
        return 1
    
    

if __name__ == '__main__':
    
    expected_solutions = { }
    try:
        with open("expected_solutions.txt", "r") as expected_solutions_file:
            for line in expected_solutions_file:
                line = line[:-1] # Remove trailing newlines
                key_value_pair = line.split(" ")
                if len(key_value_pair) == 2 and key_value_pair[1].isdigit(): # Extract all expected solutions; ignore bad entries
                    print("Got here")
                    expected_solutions[key_value_pair[0]] = int(key_value_pair[1])
    except IOError:
        print("Unable to open file './expected_solutions.txt'! Please check that the file is located in the current working directory!")
    
    if len(sys.argv) != 3: 
        print("Error: Missing operands!")
        print("Usage: " + sys.argv[0] + " path/to/problems compiler-name")
        sys.exit(1)
    elif not os.path.exists(sys.argv[1]):
        print("Error: Path " + sys.argv[1] + " does not exist!")
    else:
        sys.exit(test_all_solutions(sys.argv[1], sys.argv[2], expected_solutions))
