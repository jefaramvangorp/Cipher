
#ifndef CIPHER_IO_FILEIO_H_
#define CIPHER_IO_FILEIO_H_

// STD.
#include <string>

class FileIO
{
public:
    
    static void readTextFile(const std::string& fileName, std::string* text);
    static void writeTextFile(const std::string& fileName, const std::string& text);
    
};

#endif // CIPHER_IO_FILEIO_H_
