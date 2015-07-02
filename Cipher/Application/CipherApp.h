
#ifndef CIPHER_APPLICATION_CIPHERAPP_H_
#define CIPHER_APPLICATION_CIPHERAPP_H_

// STD.
#include <string>
#include <vector>


// Forward declarations.
class UI;

class CipherApp
{
public:
    
    CipherApp(UI* ui);
    
    int executeCommand(const std::string& command, const std::vector<std::string>& args);
    void showHelp() const;
    
private:
    
    bool isValidCommand(const std::string& command, const std::vector<std::string>& args);
    
    void encrypt(const std::string& fileName, const std::string& key);
    void decrypt(const std::string& fileName, const std::string& key);
    
    UI* ui;
};

#endif // CIPHER_APPLICATION_CIPHERAPP_H_
