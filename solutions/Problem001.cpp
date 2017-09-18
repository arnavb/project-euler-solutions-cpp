/******************************************************************************
* Solution to Problem 1 (https://projecteuler.net/problem=1) of Project Euler *
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

int problem001()
{
    int sumMultiples = 0;
    for (int i = 0; i < 1000; ++i)
    {
        // Add i to sum if it is divisible by 3 or 5
        sumMultiples += ((i % 5 == 0) || (i % 3 == 0)) ? 
            i : 0;
    }
    
    return sumMultiples;
}