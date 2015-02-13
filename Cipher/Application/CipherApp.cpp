
// Includes.
#include "CipherApp.h"
#include "Algorithm/VigenereCipher.h"
#include "UI/UI.h"
#include "IO/FileIO.h"

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
    bool read_ok = FileIO::readTextFile(file_name.c_str(), &message);
    if (!read_ok)
    {
        this->ui->displayErrorMessage("Unable to read file: " + file_name);
        return;
    }
    
    VigenereCipher cipher(key);
    std::string encrypted_message = cipher.encrypt(message);
    
    bool write_ok = FileIO::writeTextFile(file_name, encrypted_message);
    if (!write_ok)
    {
        this->ui->displayErrorMessage("Unable to write file: " + file_name);
    }
}

void CipherApp::decrypt()
{
    std::string file_name = this->ui->getTextFromUser("File:");
    std::string key = this->ui->getTextFromUser("Enter key:");
    
    std::string message;
    bool read_ok = FileIO::readTextFile(file_name, &message);
    if (!read_ok)
    {
        this->ui->displayErrorMessage("Unable to read file: " + file_name);
        return;
    }

    
    VigenereCipher cipher(key);
    std::string decrypted_message = cipher.decrypt(message);
    
    bool write_ok = FileIO::writeTextFile(file_name, decrypted_message);
    if (!write_ok)
    {
        this->ui->displayErrorMessage("Unable to write file: " + file_name);
    }
}

void CipherApp::showHelp() const
{
    this->ui->displayErrorMessage("Usage: Cipher <encrypt|decrypt>");       
}
