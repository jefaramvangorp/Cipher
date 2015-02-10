
// Includes.
#include "CipherApp.h"
#include "Algorithm/VigenereCipher.h"
#include "UI/UI.h"

// STD.
#include <fstream>
#include <sstream>
#include <iostream>

namespace {
    void readTextFile(const std::string& fileName, std::string* text)
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
    
    void writeTextFile(const std::string& fileName, const std::string& text)
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
}


CipherApp::CipherApp(UI* ui)
: ui(ui)
{
    
}

void CipherApp::execute(const std::string &action)
{
    if (action == "encrypt")
    {
        encrypt();
    }
    else if (action == "decrypt")
    {
        decrypt();
    }
    else
    {
        showHelp();
    }

}

void CipherApp::encrypt()
{
    std::string file_name = this->ui->getTextFromUser("File:");
    std::string key = this->ui->getTextFromUser("Enter key:");
    
    std::string message;
    readTextFile(file_name.c_str(), &message);
    
    VigenereCipher cipher(key);
    std::string encrypted_message = cipher.encrypt(message);
    
    writeTextFile(file_name, encrypted_message);
}

void CipherApp::decrypt()
{
    std::string file_name = this->ui->getTextFromUser("File:");
    std::string key = this->ui->getTextFromUser("Enter key:");
    
    std::string message;
    readTextFile(file_name, &message);
    
    VigenereCipher cipher(key);
    std::string decrypted_message = cipher.decrypt(message);
    
    writeTextFile(file_name, decrypted_message);
}

void CipherApp::showHelp() const
{
    this->ui->displayErrorMessage("Usage: Cipher <encrypt|decrypt>");       
}
