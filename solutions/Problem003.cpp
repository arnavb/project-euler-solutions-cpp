/******************************************************************************
* Solution to Problem 3 (https://projecteuler.net/problem=3) of Project Euler *
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

#include <iostream>
#include <vector>
#include <cmath>

int main()
{
    long long int number = 600'851'475'143LL;
    long long int highestPrimeFactor = 0LL;
    long long int currentFactor = 2LL;
    while (number != 1)
    {
        if (
            (number % currentFactor == 0) && 
            (currentFactor > highestPrimeFactor)
        )   // If the number we are on is a factor of the number and larger than previous factors
        {
            highestPrimeFactor = currentFactor;
            number /= currentFactor; // Make the number smaller, so it is easier to work with
        }
        ++currentFactor; // Increase the factor
    }
    
    std::cout << highestPrimeFactor << "\n";
}