/******************************************************************************
* Solution to Problem 6 (https://projecteuler.net/problem=6) of Project Euler *
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

int main()
{
    long long int sumOfSquares = 0LL;
    long int squareOfSum = 0LL;
    
    for (int number = 1; number <= 100; ++number)
    {
        sumOfSquares += (number * number); // Add the square of the current number
        squareOfSum += number; // Add the current number to the sum
    }
    squareOfSum *= squareOfSum; // Square the sum

    std::cout << "Problem 006 solution: " << (squareOfSum - sumOfSquares) << ".\n";
}