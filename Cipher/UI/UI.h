
#ifndef CIPHER_UI_H_
#define CIPHER_UI_H_

// STD.
#include <string>

class UI
{
public:
    virtual ~UI() {}
    virtual void displayInfoMessage(const std::string& message) = 0;
    virtual void displayErrorMessage(const std::string& message) = 0;
    virtual std::string getTextFromUser(const std::string& message) = 0;
};

#endif // CIPHER_UI_H_
