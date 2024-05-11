#ifndef PAGES_H
#define PAGES_H

#include "Base.h"
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


#include<string>
using namespace std;

class BASE_CLASS;
class Post;

class Pages : public BASE_CLASS {
    char* title;
    Post** timeline;
    int total_timeline;

public:
    Pages();
    ~Pages();

    void ReadData(ifstream& inp);
    void display_home() override;
    void add_postTo_timeline(Post* ptr);
    void CheckDate(Date CurrentDate, bool memory);
    void display() override;
    void view_timeline();
    char* GetterForId();
};

#endif 
