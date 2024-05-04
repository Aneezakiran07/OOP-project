#include<Helper.h>
using namespace std;

//for global functions( i mean to not use built in)

int Helper::strLen(const char* str)
{
    nt size = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        size++;
    }
    return size;
}

void Helper::strcpy(const char* temp, char*& str)
{
    int length = strLen(temp);
    str = new char[length + 1];
    for (int i = 0; i <= length; i++)
    {
        str[i] = temp[i];
    }
}

bool Helper::compareString(const char* string, const char* string2)
{
    int i = 0;
    while (string[i] != '\0' && string2[i] != '\0') {
        if (string[i] != string2[i]) {
            return false;
        }
        i++;
    }
    return (string[i] == '\0' && string2[i] == '\0');
}

char* Helper::Int_str_concatenation(const char* str, int num)
{
   
}