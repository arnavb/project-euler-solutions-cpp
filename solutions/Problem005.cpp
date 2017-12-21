/******************************************************************************
* Solution to Problem 5 (https://projecteuler.net/problem=5) of Project Euler *
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
    int divisibleNumber = 1;
    
    // Keep incrementing divisibleNumber until it is divisible from 1 - 20
    while (!(
        (divisibleNumber % 11 == 0) &&
        (divisibleNumber % 12 == 0) && // 4, 3, 6, and 2 as well
        (divisibleNumber % 13 == 0) &&
        (divisibleNumber % 14 == 0) && // 7 as well
        (divisibleNumber % 15 == 0) && // 5 as well
        (divisibleNumber % 16 == 0) && // 8 as well
        (divisibleNumber % 17 == 0) &&
        (divisibleNumber % 18 == 0) && // 9 as well
        (divisibleNumber % 19 == 0) &&
        (divisibleNumber % 20 == 0)    // 10 as well
        // No need to check for divisibility by 1
    ))
    {
        ++divisibleNumber;
    }
    
    std::cout << divisibleNumber << "\n";
}
