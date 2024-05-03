#ifndef ACTIVITY_H
#define ACTIVITY_H


#include"Facebook.h"
//#include"Memory.h"
#include"Activity.h"
#include"Comment.h"

#include "Pages.h" // Include necessary headers for other classes used in FaceBook.h
#include "Users.h"
#include "Post.h"
#include "Date.h"
#include "Helper.h"
#include <fstream>
#include <iostream>
#include "Base.h"

#include<string>
using namespace std;


class Activity {
private:
    int type;
    char* value;

public:
    Activity();
    ~Activity();
    void ReadDataFromFile(ifstream& inp);
    void SetValue(char* text);
    void Print();
};

#endif 
