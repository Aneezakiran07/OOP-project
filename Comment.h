#ifndef COMMENT_H
#define COMMENT_H

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

class BASE_CLASS;
class Comment {
    char* Id;
    BASE_CLASS* commentPostedBy;
    char* Text;
    static int TotalComments;

public:
    Comment(BASE_CLASS* CurrentUser, char* txt);
    Comment();
    ~Comment();

    void SetValues(char* id, char* text, BASE_CLASS* commentPostedByPtr);
    void display();
};

#endif 
