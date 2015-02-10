
// Includes.
#include "TextBasedUI.h"

// STD.
#include <iostream>

TextBasedUI::~TextBasedUI()
{
    
}

void TextBasedUI::displayInfoMessage(const std::string& message)
{
    fprintf(stdout, "%s\n", message.c_str());
}

void TextBasedUI::displayErrorMessage(const std::string& message)
{
    fprintf(stderr, "%s\n", message.c_str());
}
            
std::string TextBasedUI::getTextFromUser(const std::string& message)
{
    fprintf(stdout, "%s ", message.c_str());
    std::string key;
    std::getline(std::cin, key);
    return key;
}
