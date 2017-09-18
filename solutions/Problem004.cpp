/******************************************************************************
* Solution to Problem 4 (https://projecteuler.net/problem=4) of Project Euler *
* Copyright (C) 2017 Arnav Borborah                                           *
*                                                                             *
* This program is free software: you can redistribute it and/or modify        *
* it under the terms of the GNU General Public License as published by        *
* the Free Software Foundation, either version 3 of the License, or           *
* (at your option) any later version.                                         *
*                                                                             *
* This program is distributed in the hope that it will be useful,             *
* but WITHOUT ANY WARRANTY; without even the implied warranty of              *
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the                *
* GNU General Public License for more details.                                *
*                                                                             *
* You should have received a copy of the GNU General Public License           *
* along with this program.  If not, see <http://www.gnu.org/licenses/>.       *
******************************************************************************/

#include <string>

int problem004()
{
    int largestPalindromeProduct = 0;
    
    // For every possible produt of two three digit numbers
    for (int i = 100; i < 1000; ++i)
    {
        for (int j = 100; j < 1000; ++j)
        {
            int currentProduct = i * j;
            std::string currentProductString = std::to_string(currentProduct);
            
            // Check if number is a palindrome by comparing number as string with its reverse
            // Also check if number is greater than our current largest palindrome number
            if (
                (currentProductString == std::string{ currentProductString.rbegin(), currentProductString.rend() }) &&
                (currentProduct > largestPalindromeProduct)
            )
            {
                largestPalindromeProduct = currentProduct;
            }
        }
    }
    
    return largestPalindromeProduct;
}