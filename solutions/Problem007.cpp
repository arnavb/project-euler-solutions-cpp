/*
*
* Solution to Problem 7 (https://projecteuler.net/problem=7) of Project Euler
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

#include <cmath>
#include <iostream>
#include <vector>

std::vector<long long int> primesUpto(long long int limit) // Function that implements the Sieve of Eratosthenes
{
    std::vector<bool> primesBoolArray(limit, true);
    std::vector <long long int> result;
    
    primesBoolArray[0] = primesBoolArray[1] = false;
    long long int sqrtLimit = std::sqrt(limit) + 1;
    
    for (size_t i = 0; i < sqrtLimit; ++i)
    {
        if (primesBoolArray[i])
        {
            for (size_t j = (2 * i); j < limit; j += i)
            {
                primesBoolArray[j] = false;
            }
        }
    }
    for (size_t i = 0; i < primesBoolArray.size(); ++i)
    {
        if (primesBoolArray[i])
        {
            result.push_back(i);
        }
    }
    return result;
}

int main()
{
    // 1 Million is an arbitrary limit
    std::cout << primesUpto(1'000'000)[10'000] << "\n";
}