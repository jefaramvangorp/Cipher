
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
    
    void executeCommand(const std::string& command, const std::vector<std::string>& args);
    void showHelp() const;
    
private:
    
    void encrypt();
    void decrypt();
    
    UI* ui;
};

#endif // CIPHER_APPLICATION_CIPHERAPP_H_
