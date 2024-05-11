#include "Helper.h"

using namespace std;
int Helper::strLen(const char* str)
{
    int size = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        size++;
    }
    return size;
}

void Helper::strcpy(const char* temp, char*& str)
{
    int len = strLen(temp);
    str = new char[len + 1];
    for (int i = 0; i <= len; i++)
    {
        str[i] = temp[i];
    }
}

bool Helper::compareString(const char* str, const char* str2)
{
    int i = 0;
    while (str[i] != '\0' && str2[i] != '\0') {
        if (str[i] != str2[i]) {
            return false;
        }
        i++;
    }
    return (str[i] == '\0' && str2[i] == '\0');
}

char* Helper::Int_str_concatenation(const char* str, int num)
{
    int str_len = strLen(str);

    int num_copy = num;
    int num_len = 0;
    while (num_copy > 0) {
        num_copy /= 10;
        num_len++;
    }

    char* result = new char[str_len + num_len + 1];

    int i = 0;
    while (str[i] != '\0') {
        result[i] = str[i];
        i++;
    }

    int j = i + num_len - 1;
    while (num > 0) {
        result[j] = '0' + (num % 10);
        num /= 10;
        j--;
    }

    result[str_len + num_len] = '\0';
    return result;
}
