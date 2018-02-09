/*
*
* Solution to Problem 28 (https://projecteuler.net/problem=28) of Project Euler
* Copyright (C) 2017 Arnav Borborah
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by 
* the Free Software Foundation, either version 3 of the License, or 
* (at your option) any later version. 
*  
* This program is distributed in the hope that it will be useful, 
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details. 
* 
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>. 
*
*/

#include <iostream>
#include <cmath>

bool isPerfectSquare(int num)
{
    int sqrtNum = static_cast<int>(std::sqrt(num));
    return sqrtNum * sqrtNum == num;
}

int main()
{
    int limit = 1001 * 1001;
    int incrementRate = 0;
    int diagonalNumberSum = 0;
    for (int i = 1; i <= limit; i += incrementRate) // Iterate over every diagonal number
    {
        diagonalNumberSum += i; // Add the current diagonal number
        if (
            (i % 2 == 1) &&      // If the current number is odd
            (isPerfectSquare(i)) // and it is a perfect square
        )                        // then we have reached the next spiral
        {
            incrementRate += 2;
        }
    }
    std::cout << diagonalNumberSum << "\n";
}