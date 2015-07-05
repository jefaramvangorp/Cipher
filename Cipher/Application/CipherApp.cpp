
// Includes.
#include "CipherApp.h"
#include "Algorithm/VigenereCipher.h"
#include "UI/UI.h"
#include "IO/FileIO.h"

// STD.
#include <ctime>
#include <sstream>


// --------------------------------------------------------------------------------
// PRIVATE HELPER FUNCTIONS AND CONSTANTS

namespace
{
    const int SUCCESS = 0;
    const int FAILURE = -1;
    
    std::string durationMessage(const clock_t& start, const clock_t& end)
    {
        std::stringstream stream;
        stream << "Duration: " << (1000 * (end-start)/CLOCKS_PER_SEC)<< " ms";
        return stream.str();
    }
}

// --------------------------------------------------------------------------------

CipherApp::CipherApp(UI* ui)
    : ui(ui)
{
    
}

int CipherApp::executeCommand(const std::string& command, const std::vector<std::string>& args)
{
    if (isValidCommand(command, args))
    {
        std::string file_name = args[0];
        std::string key = args[1];

        clock_t start = clock();
        
        if (command == "encrypt")
        {
            encrypt(file_name, key);
        }
        else // Can only be "decrypt"
        {
            decrypt(file_name, key);
        }
        
        clock_t end = clock();
        this->ui->displayInfoMessage( durationMessage(start, end) );
        
        return SUCCESS;
    }
    else
    {
        showHelp();
        return FAILURE;
    }
}

bool CipherApp::isValidCommand(const std::string& command, const std::vector<std::string>& args)
{
    return (command == "encrypt" || command == "decrypt") && args.size() >= 2;
}

void CipherApp::encrypt(const std::string& fileName, const std::string& key)
{
    std::string message;
    bool read_ok = FileIO::readTextFile(fileName.c_str(), &message);
    if (!read_ok)
    {
        this->ui->displayErrorMessage("Unable to read file: " + fileName);
        return;
    }
    
    VigenereCipher cipher(key);
    std::string encrypted_message = cipher.encrypt(message);
    
    bool write_ok = FileIO::writeTextFile(fileName, encrypted_message);
    if (!write_ok)
    {
        this->ui->displayErrorMessage("Unable to write file: " + fileName);
    }
}

void CipherApp::decrypt(const std::string& fileName, const std::string& key)
{
    std::string message;
    bool read_ok = FileIO::readTextFile(fileName, &message);
    if (!read_ok)
    {
        this->ui->displayErrorMessage("Unable to read file: " + fileName);
        return;
    }
    
    VigenereCipher cipher(key);
    std::string decrypted_message = cipher.decrypt(message);
    
    bool write_ok = FileIO::writeTextFile(fileName, decrypted_message);
    if (!write_ok)
    {
        this->ui->displayErrorMessage("Unable to write file: " + fileName);
    }
}

void CipherApp::showHelp() const
{
    this->ui->displayInfoMessage("Usage: Cipher <encrypt|decrypt> <filename> <key>");
}
