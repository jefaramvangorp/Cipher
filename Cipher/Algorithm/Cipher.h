
#ifndef CIPHER_ALGORITHM_CIPHER_H_
#define CIPHER_ALGORITHM_CIPHER_H_

// STD.
#include <string>


class Cipher
{
public:
    virtual ~Cipher() {}
    
    virtual std::string encrypt(const std::string& message) = 0;
    virtual std::string decrypt(const std::string& message) = 0;
    
};


#endif // CIPHER_ALGORITHM_CIPHER_H_
