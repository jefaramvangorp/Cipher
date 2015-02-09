
// Includes.
#include "Algorithm/VigenereCipher.h"

// STD.
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

namespace {
    void readTextFile(const char* fileName, std::string* text)
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
            fprintf(stderr, "Could not open file: %s\n", fileName);
        }
    }
    
    void writeTextFile(const char* fileName, const std::string& text)
    {
        std::ofstream out(fileName);
        if (out.is_open())
        {
            out << text;
            out.close();
        }
        else
        {
            fprintf(stderr, "Could not open file: %s\n", fileName);
        }
    }
    
    std::string readKey()
    {
        fprintf(stdout, "Enter key: ");
        std::string key;
        std::getline(std::cin, key);
        return key;
    }
    
    void encrypt(const char* fileName, const std::string& key)
    {
        std::string message;
        readTextFile(fileName, &message);
        
        VigenereCipher cipher(key);
        std::string encrypted_message = cipher.encrypt(message);
        
        writeTextFile(fileName, encrypted_message);
    }
    
    void decrypt(const char* fileName, const std::string& key)
    {
        std::string message;
        readTextFile(fileName, &message);
        
        VigenereCipher cipher(key);
        std::string decrypted_message = cipher.decrypt(message);
        
        writeTextFile(fileName, decrypted_message);
    }
    
    void printUsage()
    {
        fprintf(stderr, "Usage: Cipher <encrypt|decrypt> <filename>\n");
    }
}

int main(int argc, char** argv)
{
    if (argc >= 3)
    {
        std::string action(argv[1]);
        const char* fileName = argv[2];
        
        if (action == "encrypt")
        {
            std::string key = readKey();
            encrypt(fileName, key);
        }
        else if (action == "decrypt")
        {
            std::string key = readKey();
            decrypt(fileName, key);
        }
        else
        {
            printUsage();
        }
        
        return 0;
    }
    else
    {
        printUsage();
        return -1;
    }
}
