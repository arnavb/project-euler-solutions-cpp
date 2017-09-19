/**********************************************************************************
* Solution to Problem 102 (https://projecteuler.net/problem=102) of Project Euler *
* Copyright (C) 2017 Arnav Borborah                                               *
*                                                                                 *
* This program is free software: you can redistribute it and/or modify            *
* it under the terms of the GNU General Public License as published by            *
* the Free Software Foundation, either version 3 of the License, or               *
* (at your option) any later version.                                             *
*                                                                                 *
* This program is distributed in the hope that it will be useful,                 *
* but WITHOUT ANY WARRANTY; without even the implied warranty of                  *
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the                    *
* GNU General Public License for more details.                                    *
*                                                                                 *
* You should have received a copy of the GNU General Public License               *
* along with this program.  If not, see <http://www.gnu.org/licenses/>.           *
**********************************************************************************/

#include <iostream>
#include <fstream>

struct Coord
{
    int x;
    int y;
};

double doubleTriangleArea(Coord a, Coord b, Coord c) // Double to prevent errors by floating-point math
                                                     // Area doesn't actually need to be found either, just compared for equality
                                                     // Multiplicative property of equality guarantees equality for this
{
    /*
     * Coordinate area method for Triangle:
     * 
     * A = | (x1(y2 - y3) + x2(y3 - y1) + x3(y1 - y2))/2 |
     *
     */
     double area = ((a.x * (b.y - c.y)) + (b.x * (c.y - a.y)) + (c.x * (a.y - b.y)));
     return (area < 0) ? (-area) : (area);
}

bool containsOrigin(Coord a, Coord b, Coord c)
{
    // A triangle contains a point if the area of it as a whole is
    // equivalent to the sum of the areas of the three triangles
    // formed with two of the main triangle's points and the point
    static Coord origin {0,0};
    return doubleTriangleArea(a, b, c) == 
        (
            doubleTriangleArea(origin, a, b) + 
            doubleTriangleArea(origin, b, c) + 
            doubleTriangleArea(origin, a, c)
        );
}

int main()
{
    std::ifstream trianglesFile("data/triangles.txt");
    int numOriginTriangles = 0;
    if (trianglesFile.is_open())
    {
        Coord a, b, c;
        char comma; // Since each part of a coordinate is comma separated
        while (trianglesFile >> a.x >> comma >> a.y >> comma >> b.x >> comma >> b.y >> comma >> c.x >> comma >> c.y)
        {
            if (containsOrigin(a, b, c))
            {
                ++numOriginTriangles;
            }
        }
        trianglesFile.close();
    }
    else
    {
        std::cout << "Unable to open the file data/triangles.txt! Please check if the file exists in the appropriate location!\n";
    }
    
    std::cout << "Problem 102 solution: " << numOriginTriangles << ".\n";
}