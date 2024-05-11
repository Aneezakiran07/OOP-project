#ifndef ACTIVITY_H
#define ACTIVITY_H


#include"Facebook.h"
//#include"Memory.h"
#include"Activity.h"
#include"Comment.h"

#include "Pages.h" 
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
    void readData(ifstream& input);
    void setValue(char* text);
    void display();
};

#endif 
