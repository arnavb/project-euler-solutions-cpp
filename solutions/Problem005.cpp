/******************************************************************************
* Solution to Problem 2 (https://projecteuler.net/problem=2) of Project Euler *
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

#include "AllProblems.hpp"

int problem005()
{
    int divisibleNumber = 1;
    
    // Keep incrementing divisibleNumber until it is divisible from 1 - 20
    while (!(
        (i % 11 == 0) &&
        (i % 12 == 0) && // 4, 3, 6, and 2 as well
        (i % 13 == 0) &&
        (i % 14 == 0) && // 7 as well
        (i % 15 == 0) && // 5 as well
        (i % 16 == 0) && // 8 as well
        (i % 17 == 0) &&
        (i % 18 == 0) && // 9 as well
        (i % 19 == 0) &&
        (i % 20 == 0)    // 10 as well
        // No need to check for divisibility by 1
    ))
    {
        ++divisibleNumber;
    }
    
    return divisibleNumber;
}