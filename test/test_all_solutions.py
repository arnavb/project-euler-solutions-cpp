import glob # For getting all the solution files
import os # For checking if path exists
import shutil # For deleting the data directory
import subprocess # For executing the files
import sys # For commond line arguments
import distutils # For copying the data directory
from distutils import dir_util # https://stackoverflow.com/a/33417555/6525260

def test_all_solutions(directory_name):
    
    dir_util.copy_tree(directory_name + "/data/", "./data/")
    
    files = glob.glob(directory_name + "/Problem***.cpp")
    
    files.sort()
    
    print("The following files were found: " + ' '.join(files))
    
    for file in files:
        print(subprocess.check_output(['g++-5', file, '-std=c++14', '-O2']).decode('utf-8'), end='') # Compile the current file
        print(subprocess.check_output(['./a.out']).decode('utf-8'), end='') # Execute the file and print its output
        
        if os.path.isfile('./a.out'): # Remove the new executable file
            os.remove('a.out')
    
    shutil.rmtree("./data") # Remove the data directory
    
    

if __name__ == '__main__':
    if len(sys.argv) != 2 or not os.path.exists(sys.argv[1]): 
        print("Usage: " + sys.argv[0] + " path/to/problems")
    else:
        test_all_solutions(sys.argv[1])