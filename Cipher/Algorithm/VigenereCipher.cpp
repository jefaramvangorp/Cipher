
// Includes.
#include "VigenereCipher.h"

// STD.
#include <algorithm>
#include <locale>
#include <iostream>
#include <sstream>

// Constants.
#define ALPHABET_SIZE 128 // the entire fixed ascii range (TODO make sure this is always the same!).

namespace {
    
    char* buildVigenereTable()
    {
        char* table = new char[ALPHABET_SIZE * ALPHABET_SIZE];
        
        for (int i = 0; i < ALPHABET_SIZE; ++i)
        {
            table[i*ALPHABET_SIZE] = i;
            
            for (int j = 1; j < ALPHABET_SIZE; ++j)
            {
                table[i * ALPHABET_SIZE + j] = (i + j) % ALPHABET_SIZE;
            }
        }
        
        return table;
    }
}


VigenereCipher::VigenereCipher(const std::string& key)
: key(key)
, table(buildVigenereTable())
{

}

VigenereCipher::~VigenereCipher()
{
    delete [] table;
}

std::string VigenereCipher::encrypt(const std::string& message)
{
    std::ostringstream stream;
    for (int i = 0; i < message.size(); ++i)
    {
        char message_letter = message[i];
        char key_letter = key[i%key.size()];

        int row = key_letter;
        int col = message_letter;
        int index = row*ALPHABET_SIZE+col;
        
        stream << table[index];
    }
    
    return stream.str();
}

std::string VigenereCipher::decrypt(const std::string& message)
{
    std::ostringstream stream;
    for (int i = 0; i < message.size(); ++i)
    {
        char message_letter = message[i];
        char key_letter = key[i%key.size()];
        
        int row = key_letter;
        int col = 0;
        while (table[row*ALPHABET_SIZE+col] != message_letter && col < ALPHABET_SIZE)
        {
            ++col;
        }
        
        stream << (char)col;
    }
    
    return stream.str();
}
