#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <vector>

int getNameScore(const std::string& name, int listPosition)
{
    static const std::string alphabet = "/ABCDEFGHIJKLMNOPQRSTUVWXYZ"; // Slash is there so indexing starts at one for alphabet 
    
    int alphabeticalValue = 0;
    for (const auto& character : name)
    {
        alphabeticalValue += alphabet.find(character);
    }
    
    return alphabeticalValue * listPosition;
}

int main()
{
    std::ifstream nameFile{ "data/names.txt" };
    
    std::vector<std::string> names;
    if (nameFile.is_open())
    {
        std::string allNamesLine;
        getline(nameFile, allNamesLine); // All data is on one line
        
        std::istringstream nameSeparator{ allNamesLine };
        
        std::string currentName;
        while (getline(nameSeparator, currentName, ',')) // Get each comma separated name
        {
            currentName.erase
            (
                std::remove
                (
                    currentName.begin(), 
                    currentName.end(), '\"' 
                ), 
                currentName.end()
            ); // Remove the quotes at the beginning and the end of the name
            names.push_back(currentName);
        }
    }
    else
    {
        std::cout << "Unable to open the file data/names.txt! Please check if the file exists in the appropriate location!\n";
    }
    
    std::sort(names.begin(), names.end());
    
    int totalNameScores = 0;
    
    for (int i = 0; i < names.size(); ++i)
    {
        totalNameScores += getNameScore(names[i], i + 1); // Add each name score
    }
    
    std::cout << "Problem 022 solution: " << totalNameScores << ".\n";
}