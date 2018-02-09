/*
*
* Solution to Problem 14 (https://projecteuler.net/problem=14) of Project Euler
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
#include <fstream>

long long collatzSequenceSize(long long int number)
{
    long long resultSequenceSize = 0; // Variable to hold the final sequence's size
    while (number != 1) // Keep going until the number becomes 1
    {
        
        number = (number % 2 == 0) ? (number/2) : (number * 3) + 1; // Divide by 2 if even, otherwise 
                                                                    // multiply by 3 and add 1 if odd 
        ++resultSequenceSize; // Increase the sequence's size
    }
    
    return resultSequenceSize;
}

int main()
{
    long long int numWithLargestChain = 0;
    long long int largestChainSize = 0;
    
    for (long long int i = 1; i < 1000000; ++i)
    {
        long long int currentChainSize = collatzSequenceSize(i);
        if (currentChainSize > largestChainSize) // If we have a new large sequence, we set our 
                                                 // current large sequence to its number
        {
            numWithLargestChain = i;
            largestChainSize = currentChainSize;
        }
    }
    
    std::cout << numWithLargestChain << "\n";
}