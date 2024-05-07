#ifndef USERS_H
#define USERS_H

//#include"Facebook.h"
//#include"Memory.h"
//#include"Activity.h"
//#include"Comment.h"

#include "Pages.h" // Include necessary headers for other classes used in FaceBook.h
//#include "Users.h"
//#include "Post.h"
#include "Date.h"
//#include "Helper.h"
#include <fstream>
#include <iostream>
#include "Base.h"
#include<string>

using namespace std;

class BASE_CLASS;
class Date;
class Pages;
class Users;
class Post;

class Users :public BASE_CLASS {
    char* Fname;
    char* Lname;

    int totalTimeline;
    int numPages;
    int numFriends;

    Pages** Liked_pages;
    Users** Friend_list;
    Post** timeline;


public:
    Users();
    ~Users();

    void ReadDataFromFile(ifstream& inp);
    void SetPage(Pages* ptr);

    void CheckDate(Date CurrentDate, bool isMemory);
    void LikePost(Post* post);
    void HomePage(Date currentDate);

    void timeline_vieww();
    void seeMemoryforDate(Date currentDate);
    void display_home();
    void SetFriend(Users* ptr);
    void add_postTo_timeline(Post* ptr);
    void friend_list_view();
    void liked_pages_view();
    void Print();

    char* GetId();
};

#endif /* USERS_H */
