#ifndef STRING_H
#define STRING_H

#include <iostream>

class String
{
public:
//constructors & destructor
    String();
    String(const char* str);
    String(const String& other);
    ~String();
//member functions
    size_t size() const;
    const char* c_str() const;
    char* stcpy( char* dest, const char* src ) const;
    char* strcat( char *dest, const char *src ) const;
    char* getData() const;
    void setData(const char* src);
    bool empty() const;
    void clean();
    void resize(size_t size);
public: 
    String& operator=(const String& other);
    String operator+(const String& other) const;
    String& operator+=(const String& rhs);
    bool operator==(const String& other) const;
    bool operator!=(const String& other) const;
    char operator[](size_t index) const;
    char& operator[](size_t index);
public:
 //friend functions
    friend std::ostream& operator<<(std::ostream& os, const String& str);
    friend std::istream& operator>>(std::istream& is, String& str);
private:
    char* _data;
    size_t _size;
};


#endif //STRING_H