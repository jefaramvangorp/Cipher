
#ifndef CIPHER_UI_TEXTBASEDUI_H_
#define CIPHER_UI_TEXTBASEDUI_H_

// Includes.
#include "UI.h"

class TextBasedUI : public UI
{
public:
    virtual ~TextBasedUI();
    
    virtual void displayInfoMessage(const std::string& message);
    virtual void displayErrorMessage(const std::string& message);
    virtual std::string getTextFromUser(const std::string& message);
};


#endif // CIPHER_UI_TEXTBASEDUI_H_
