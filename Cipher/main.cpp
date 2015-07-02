
// Includes.
#include "Application/CipherApp.h"
#include "UI/TextBasedUI.h"

// STD.
#include <vector>
#include <string>

// --------------------------------------------------------------------------------

namespace
{
    std::string commandFrom(int argc, char** argv)
    {
        if (argc > 1)
        {
            return std::string(argv[1]);
        }
        else
        {
            return std::string();
        }
    }
    
    std::vector<std::string> argsFrom(int argc, char** argv)
    {
        std::vector<std::string> list;
        
        for (int i = 2; i < argc; ++i)
        {
            list.push_back( std::string(argv[i]) );
        }
        
        return list;
    }
}

// --------------------------------------------------------------------------------


int main(int argc, char** argv)
{
    TextBasedUI ui;
    CipherApp app(&ui);
    
    return app.executeCommand(commandFrom(argc, argv),
                              argsFrom(argc, argv));
}
