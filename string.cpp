#include "string.h"

String::String()
{
    _data = new char[1];
    _data[0] = '\0';
    _size = 0;
}

String::String(const char *str)
{
    int size = 0;
    while (str[size] != '\0')
    {
        ++size;
    }
    _size = size;
    _data = new char[size + 1];
    for (int i = 0; i < _size; ++i)
    {
        _data[i] = str[i];
    }
}

String::String(const String &other)
{
    _size = other.size();
    delete _data;
    _data = nullptr;
    stcpy(_data, other._data);
}

String::~String()
{
    delete _data;
    _data = nullptr;
    _size = 0;
}

size_t String::size() const
{   
    size_t size = 0;
    while (_data[size] != '\0')
    {
        ++size;
    }
    return size;
}

void String::resize(size_t size)
{
    this->clean();
    _size = size;
    _data = new char[_size];
}

const char *String::c_str() const
{
    return _data;
}

char* String::stcpy(char* dest, const char* src) const
{
    char* destPtr = dest;
    while (*src != '\0') 
    {
        *destPtr++ = *src++;
    }

    *destPtr = '\0';
    return dest;
}

char *String::strcat(char *dest, const char *src) const
{
    char* destPtr = dest;
    while (*destPtr != '\0')
    {
        ++destPtr;
    }
    while (*src != '\0')
    {
        *destPtr++ = *src++;
    }
    *destPtr = '\0';
    return dest;
}

void String::clean()
{
    delete[] _data;		
    _data = nullptr;		
    _size = 0;	
}

bool String::empty() const
{
   if (_size == 0)
    {
        return true;
    }
    return false;
}

char* String::getData() const
{
    return _data;
}

void String::setData(const char* src)
{
    size_t size = 0;
    while (*src != '\0')
    {
        ++size;
    }
    delete _data;
    _data = nullptr;
    _data = new char[size];
    for (int i = 0; i < size; ++i)
    {
        _data[i] = src[i];
    }
}

String& String::operator=(const String &other)
{
    if (this != &other)
    {
        delete[] _data;
        _size = other._size;
        _data = new char[_size + 1];
        stcpy(_data, other._data);
    }
    return *this;
}

String String::operator+(const String &other) const
{   
    size_t tmpSize = _size + other.size() + 1;
    char* tmpData = new char[tmpSize];
    stcpy(tmpData, _data);
    strcat(tmpData, other.getData());
    return String(tmpData);
}

String& String::operator+=(const String &rhs)
{
   if (rhs.empty())
   {
        return *this;
   }
    size_t tmpSize = _size + rhs.size();    
    char* tmpData = new char[tmpSize];
    stcpy(tmpData, _data);
    strcat(tmpData, rhs.getData());
    stcpy(_data, tmpData);
    return *this;
}

bool String::operator==(const String &other) const
{
    if (_size != other.size())
    {
        return false;
    }
    char* tmp = other.getData();
    for (int i = 0; i < _size; ++i)
    {
        if(_data[i] != tmp[i])
        {
            return false;
        }
    }
    return true;
}

bool String::operator!=(const String& other) const
{
    if (_size != other.size())
    {
        return true;
    }
    char* tmp = other.getData();
    for (int i = 0; i < _size; ++i)
    {
        if(_data[i] != tmp[i])
        {
            return true;
        }
    }
    return false;
}

char String::operator[](size_t index) const
{
    return _data[index];
}

char& String::operator[](size_t index)
{
    return _data[index];
}

std::ostream& operator<<(std::ostream& os, const String& str)
{
    for (int i = 0; i < str.size(); ++i)
    {
        os << str[i];
    }
    return os;
}

std::istream& operator>>(std::istream& is, String& str)
{
    if (!str.empty())	
    {		
        str.clean();
    }	
    const size_t capacityOfstring = 1024; 
    char* st = new char[capacityOfstring];
    int i = 0;
    is.getline(st, capacityOfstring);	
    size_t sizeOfstring = 0;	
    while (st[i] != '\0')
    {
        ++sizeOfstring;
        ++i;
    }

    str.resize(sizeOfstring + 1);
    for (int i = 0; i < sizeOfstring; ++i)	
    {
		str[i] = st[i];	
    }	
    
    str[str.size()] = '\0';	
    delete[] st;
    return is;
}