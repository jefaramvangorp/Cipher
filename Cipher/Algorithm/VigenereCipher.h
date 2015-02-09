
#ifndef CIPHER_ALGORITHM_VIGENERECIPHERE_H_
#define CIPHER_ALGORITHM_VIGENERECIPHERE_H_

// Includes.
#include "Cipher.h"

class VigenereCipher : public Cipher
{
    
public:
    
    VigenereCipher(const std::string& key);
    virtual ~VigenereCipher();
    
    virtual std::string encrypt(const std::string& message);
    virtual std::string decrypt(const std::string& message);

private:
    
    std::string key;
    const char* table;
    
};

#endif // CIPHER_ALGORITHM_VIGENERECIPHERE_H_
