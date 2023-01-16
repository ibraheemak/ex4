#ifndef EXCEPTION
#define EXCEPTION

#include <exception>
#include <string>
using namespace std;

const string  EXEPTION_ERROR_MESSAGE= "Deck File Error: File format error in line ";

class DeckFileNotFound : public exception
{
public:
    const char* what() const noexcept override
    {
        return "Deck File Error: File not found";
    }
};

class DeckFileFormatError:public exception
{

    string m_exeptionMessage;
public:
    DeckFileFormatError(int line) : m_exeptionMessage(EXEPTION_ERROR_MESSAGE+to_string(line+1)) {}
    virtual ~DeckFileFormatError()override = default;
    const char* what() const noexcept override
    {
        return (m_exeptionMessage).c_str();
    }
};

class DeckFileInvalidSize:public exception
{
public:
    const char* what() const noexcept override
    {
        return "Deck File Error: Deck size is invalid";
    }
};





#endif