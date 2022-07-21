#include <iostream>
#include <map>
#include <string>

std::string ToLowerCase(std::string str)
{
    for (char& c : str)
    {
        if (c >= 'A' && c <= 'Z')
        {
            c = 'a' + (c - 'A');
        }
    }

    return str;
}

std::map<char, char> GetCharsMap(const std::string& str)
{
    std::map<char, char> tempMap;

    for (auto c : str)
    {
        if (tempMap.find(c) == tempMap.end())
        {
            tempMap[c] = '(';
        }
        else
        {
            tempMap[c] = ')';
        }
    }

    return tempMap;
}


int main(int argc, char* argv[])
{
    char quitChar = 'n';

    while (quitChar == 'n')
    {
        std::cout << "=========================\n";
        std::cout << "Enter string:\n";
        std::string inputStr;

        std::cin >> std::ws;
        std::getline(std::cin, inputStr);

        // Using copy of entered string if we will need original string in future.
        std::string outputStr = ToLowerCase(inputStr);

        std::map<char, char> charsMap = GetCharsMap(outputStr);

        for (const char c : outputStr)
        {
            std::cout << charsMap[c];
        }

        std::cout << "\n\n" << "Quit? \'y/n\'" << std::endl;
        std::cin >> quitChar;
        std::cout << std::endl;
    }

    return 0;
}
