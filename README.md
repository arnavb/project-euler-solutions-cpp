# Project Euler Solutions in C++

[![Build Status](https://travis-ci.org/arnavb/project-euler-solutions-cpp.svg?branch=master)](https://travis-ci.org/arnavb/project-euler-solutions-cpp) [![Codacy Badge](https://api.codacy.com/project/badge/Grade/7cb6c470c0d14f5980f78d31db4c7b58)](https://www.codacy.com/app/arnavb/project-euler-solutions-cpp?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=arnavb/project-euler-solutions-cpp&amp;utm_campaign=Badge_Grade) [![license](https://img.shields.io/badge/license-GNU%20GPLv3-blue.svg)](./LICENSE)

![My Account](https://projecteuler.net/profile/arnavb11.png)

This repository holds solutions to the [Project Euler Problems](https://projecteuler.net/archives) implemented in C++. Most of the solutions here are not optimized much and use the usual method for solving these problems.

### How This Project is Organized

To check out how a solution is implemented, go to the [solutions directory](./solutions), where you will see a folder structure as follows:

```
solutions/
├── data/
    ├── triangles.txt
    └── ...
├── Problem001.cpp
├── Problem002.cpp
└── ...
```

In this folder structure, each of the files labeled `Problem***.cpp` contain the corresponding Project Euler problem's solution. For example, the code for [Problem 1](https://projecteuler.net/problem=1) is located in [Problem001.cpp](./solutions/Problem001.cpp), and the file contains the following code:

```cpp
int main()
{
    int sumMultiples = 0;
    for (int i = 0; i < 1000; ++i)
    {
        /*
         * ... Solution code ...
         */
    }
    
    std::cout << sumMultiples << "\n";
}
```

Each of the solutions are independent of one another, don't depend on other files (other than the data files, see below), and have their own `main` function which solves the problem and prints out the solution to the console. Using this code is as easy as downloading and running the file.

The [data](./solutions/data) directory in the folder structure contains the data files that some problems need for their solutions. For example, [Problem 102](https://projecteuler.net/problem=102) needs a file called `triangles.txt` for its solution. Thus, for Problem 102, there will be a file called `triangles.txt` in the `data` directory.

### Compatibility

All of the solutions in this project are fully conformant to standard C++14, and are platform-independent.

### Contributing

1. #### Pull Requests
   Unfortunately, since this is a solo project being done by me, I will not accept pull requests of any kind. Therefore, any opened pull requests will be immediately closed.
2. #### Issues
   If an error is found in one of my solutions, feel free to open an issue here, specifying _exactly_ what went wrong and where, so I can easily fix it.

### License

This project is licensed under GNU GPLv3 License, as outlined in [LICENSE](./LICENSE). Before using any of the code in this project, please read the license and follow its requirements.
