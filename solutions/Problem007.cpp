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
#include <array>
#include <vector>

template<std::size_t N>
std::vector<std::size_t> primesUpto() // Function that implements the Sieve of Eratosthenes
{
    std::array<bool, N> primesList;
    
    std::fill(primesList.begin(), primesList.end(), true);
    
    primesList[0] = primesList[1] = false;
    
    long long int sqrtLimit = std::sqrt(N) + 1;
    
    for (std::size_t i = 0; i < sqrtLimit; ++i)
    {
        if (primesList[i])
        {
            for (std::size_t j = i + i; j < N; j += i)
            {
                primesList[j] = false;
            }
        }
    }
    std::vector<std::size_t> result;
    
    for (std::size_t i = 0; i < primesList.size(); ++i)
    {
        if (primesList[i])
        {
            result.push_back(i);
        }
    }
    
    return result;
}

int main()
{
    // 1 Million is an arbitrary limit
    std::cout << primesUpto<1'000'000>()[10'000] << "\n";
}
