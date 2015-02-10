
// Includes.
#include "Application/CipherApp.h"
#include "UI/TextBasedUI.h"

int main(int argc, char** argv)
{
    TextBasedUI ui;
    CipherApp app(&ui);
    
    if (argc >= 2)
    {
        std::string action(argv[1]);
        
        app.execute(action);
        
        return 0;
    }
    else
    {
        app.showHelp();
        return -1;
    }
}
