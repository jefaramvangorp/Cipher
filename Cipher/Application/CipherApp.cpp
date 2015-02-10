
// Includes.
#include "CipherApp.h"
#include "Algorithm/VigenereCipher.h"
#include "UI/UI.h"
#include "IO/FileIO.h"

// STD.
#include <iostream>

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
    FileIO::readTextFile(file_name.c_str(), &message);
    
    VigenereCipher cipher(key);
    std::string encrypted_message = cipher.encrypt(message);
    
    FileIO::writeTextFile(file_name, encrypted_message);
}

void CipherApp::decrypt()
{
    std::string file_name = this->ui->getTextFromUser("File:");
    std::string key = this->ui->getTextFromUser("Enter key:");
    
    std::string message;
    FileIO::readTextFile(file_name, &message);
    
    VigenereCipher cipher(key);
    std::string decrypted_message = cipher.decrypt(message);
    
    FileIO::writeTextFile(file_name, decrypted_message);
}

void CipherApp::showHelp() const
{
    this->ui->displayErrorMessage("Usage: Cipher <encrypt|decrypt>");       
}
