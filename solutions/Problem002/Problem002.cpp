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

#include <iostream>

int main()
{
    int previousFibNum2 = 0;
    int previousFibNum1 = 0;
    int currentFibNum = 1;
    
    int fibNumSum = 0;
    
    while(currentFibNum <= 4000000)
    {
        fibNumSum += (currentFibNum % 2 == 0) ?
            currentFibNum : 0;
        previousFibNum2 = previousFibNum1;
        previousFibNum1 = currentFibNum;
        currentFibNum = previousFibNum2 + previousFibNum1;
    }
    std::cout << "The sum of the even fibonacci numbers less than 4,000,000 is " << fibNumSum << ".\n";
}