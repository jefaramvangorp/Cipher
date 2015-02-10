
// Includes.
#include "FileIO.h"

// STD.
#include <fstream>
#include <sstream>
#include <iostream>


void FileIO::readTextFile(const std::string& fileName, std::string* text)
{
    std::ifstream in(fileName);
    if (in.is_open())
    {
        std::string line;
        std::ostringstream stream;
        
        while (std::getline(in, line))
        {
            stream << line << "\n";
        }
        
        (*text) = stream.str();
        in.close();
    }
    else
    {
        fprintf(stderr, "Could not open file: %s\n", fileName.c_str());
    }
}

void FileIO::writeTextFile(const std::string& fileName, const std::string& text)
{
    std::ofstream out(fileName);
    if (out.is_open())
    {
        out << text;
        out.close();
    }
    else
    {
        fprintf(stderr, "Could not open file: %s\n", fileName.c_str());
    }
}
