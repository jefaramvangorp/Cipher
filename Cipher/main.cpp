
// Includes.
#include "Application/CipherApp.h"
#include "UI/TextBasedUI.h"

int main(int argc, char** argv)
{
    TextBasedUI ui;
    CipherApp app(&ui);
    
    if (argc >= 2)
    {
        std::string command(argv[1]);
        std::vector<std::string> args;
        
        app.executeCommand(command, args);
        
        return 0;
    }
    else
    {
        app.showHelp();
        return -1;
    }
}
