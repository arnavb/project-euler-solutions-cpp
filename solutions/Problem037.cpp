/*
*
* Solution to Problem 37 (https://projecteuler.net/problem=37) of Project Euler
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

#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <string>

std::vector<long long int> primesUpto(long long int limit) // Function that implements the Sieve of Eratosthenes
{
    std::vector<bool> primesBoolArray(limit, true);
    std::vector <long long int> primesUptoLimit;
    
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
            primesUptoLimit.push_back(i);
        }
    }
    return primesUptoLimit;
}

bool isTruncPrime(long long int number, const std::vector<long long int>& primeList)
{
    std::string numberString = std::to_string(number);
    for (int i = 1; i < numberString.size(); ++i)
    {
        std::string truncLeft = numberString.substr(0, i); // The truncated prime from the left
        std::string truncRight = numberString.substr(i, numberString.size() - 1); // The truncated prime from the right
        if (!
            (
                std::binary_search(primeList.begin(), primeList.end(), std::atol(truncLeft.c_str())) &&
                std::binary_search(primeList.begin(), primeList.end(), std::atol(truncRight.c_str()))
            )   // If either of the two truncated sides are not prime
        )
        {
            return false;
        }
    }
    return true; // All truncated parts are prime, so the number is a truncatable prime
}

int main()
{
    const std::vector<long long int> primesUptoMillion = primesUpto(1000000); // Represents all the primes up to 1 million
    int numberTruncatablePrimes = 0;
    long long int currentNumber = 9; // 2, 3, 5, and 7 are not included in the search for truncatable primes
    long long int truncatablePrimeSum = 0;
    while (numberTruncatablePrimes != 11) 
    {
        if (
            std::binary_search(primesUptoMillion.begin(), primesUptoMillion.end(), currentNumber) && // If the number itself is prime
            isTruncPrime(currentNumber, primesUptoMillion) // If the number is also a truncatable prime
        )
        {
            ++numberTruncatablePrimes; // Increase amount of truncatable primes
            truncatablePrimeSum += currentNumber; // Add the number's sum
        }
        currentNumber += 2; // Only odd numbers can be prime other than 2, so no need to look at every number
    }
    std::cout << truncatablePrimeSum << "\n";
}