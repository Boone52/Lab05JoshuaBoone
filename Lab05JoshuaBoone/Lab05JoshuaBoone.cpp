// Lab05JoshuaBoone.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>

std::vector<char> cypher = {'V','F','X','B','L','I','T','Z','J','R','P','H','D','K','N','O','W','S','G','U','Y','Q','M','A','C','E'};

std::string getInput() {
    std::string text;
    std::cout << "Input text to Cypher:";
    std::getline(std::cin, text);
    return text;
}

char translateCharacter(char c) {
    if (c >= 65 && c <= 90) {  // If char is between 65 and 90, capital letter 
        return cypher[c - 65]; // Translate uppercase letter using cypher
    }
    else if (c >= 97 && c <= 122) { //  If char is between 97 and 122, lowercase letter
        char upperCaseLetter = c - 32; // Convert lowercase number to upper case number equivalent
        char upperCaseCode = cypher[upperCaseLetter - 65]; // Find substiution using cypher SET upperCaseCode TO CHAR AT SLOT upperCaseLetter-65 IN CODE TABLE 
        return upperCaseCode + 32; // Revert back to get lowercase letter code 
    }
    else { 
        return c; 
    }
}

std::string translateString(const std::string& input) {
    std::string result;
    for (char c : input) {
        result.push_back(translateCharacter(c));
    }
    return result;
}

int main() {
    std::string input = getInput();
    std::string translatedString = translateString(input);
    std::cout << "Cyphered text: " << translatedString << std::endl;
    return 0;
}

