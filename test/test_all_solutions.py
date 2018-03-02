import glob # For getting all the solution files
import os # For checking if path exists
import shutil # For deleting the data directory
import subprocess # For executing the files
import sys # For command line arguments
import distutils # For copying the data directory
from distutils import dir_util # https://stackoverflow.com/a/33417555/6525260

class colors: # https://stackoverflow.com/a/287944/6525260
    HEADER = '\033[95m'
    OKBLUE = '\033[94m'
    OKGREEN = '\033[92m'
    WARNING = '\033[93m'
    FAIL = '\033[91m'
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
        print(colors.OKBLUE + "TEST: " + colors.ENDC + "Problem " + str(current_key) + "\n")
        print("Trying to compile " + file + " with " + compile_command)
        
        if (subprocess.call(compile_command.split(), stdout = subprocess.DEVNULL, stderr = subprocess.STDOUT) != 0): # Compile the current file
            print("Result: " + colors.FAIL + "FAILURE: File was unable to be compiled!" + colors.ENDC)
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
                        print("\nResult: " + colors.FAIL + "FAILURE: Current output " + str(current_output) + " does not match expected output " + str(expected_solution) + "!" + colors.ENDC)
                else:
                    print("Result: " + colors.FAIL + "FAILURE: Expected solution to problem " + str(current_key) + " was not found!" + colors.ENDC)
            except ValueError:
                print("Result: " + colors.FAIL + "FAILURE: Output is of non-integer type!" + colors.ENDC)
            
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
    
    expected_solutions = {
        "001": 233168,
        "002": 4613732,
        "003": 6857,
        "004": 906609,
        "005": 232792560,
        "006": 25164150,
        "007": 104743,
        "014": 837799,
        "022": 871198282,
        "028": 669171001,
        "037": 748317,
        "102": 228
    }
    
    if len(sys.argv) != 3: 
        print("Error: Missing operands!")
        print("Usage: " + sys.argv[0] + " path/to/problems compiler-name")
        sys.exit(1)
    elif not os.path.exists(sys.argv[1]):
        print("Error: Path " + sys.argv[1] + " does not exist!")
    else:
        sys.exit(test_all_solutions(sys.argv[1], sys.argv[2], expected_solutions))