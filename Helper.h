#ifndef HELPER_H
#define HELPER_H

#include<string>
using namespace std;

class Helper {// helper so i wont have to make global functions
public:
    static int strLen(const char* str);
    static void CopyStr(const char* temp, char*& str);
    static bool compareString(const char* str, const char* str2);
    static char* Int_str_concatenation(const char* string, int num);
};

#endif // HELPER_H
