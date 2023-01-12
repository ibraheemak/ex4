#ifndef EXCEPTION
#define EXCEPTION

#include <exception>
#include <string>
using namespace std;
 

class DeckFileNotFound : public exception
{
    public:
    const char* what() const override
    {
        return "Deck File Error: File not found";
    }
};

 class DeckFileFormatError:public exception
 {

    int m_line;
    public:
    DeckFileFormatError(int line) : m_line(line){};
    ~DeckFileFormatError()override=default;
    const char* what() const override
    {
        return ("Deck File Error: File format error in line "+to_string(m_line)).c_str();
    }
 };

class DeckFileInvalidSize:public exception
{
public:
const char* what() const override
{
return "Deck File Error: Deck size is invalid";
}
};





#endif