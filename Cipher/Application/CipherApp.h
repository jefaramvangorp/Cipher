
#ifndef CIPHER_APPLICATION_CIPHERAPP_H_
#define CIPHER_APPLICATION_CIPHERAPP_H_

// STD.
#include <string>

// Forward declarations.
class UI;

class CipherApp
{
public:
    
    CipherApp(UI* ui);
    
    void execute(const std::string& action);
    void showHelp() const;
    
private:
    
    void encrypt();
    void decrypt();
    
    UI* ui;
};

#endif // CIPHER_APPLICATION_CIPHERAPP_H_
