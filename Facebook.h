#ifndef FACEBOOK_H
#define FACEBOOK_H

#include "Pages.h" 
#include "Users.h"
#include "Post.h"
#include "Comment.h"
#include"Base.h"
#include "Helper.h"
//#include"Date.h"
#include"Activity.h"
#include <fstream>
#include<string>
#include <iostream>

using namespace std;

class Pages;
class Users;
class Post;
class Comment;
class Date;
class BASE_CLASS;
class Activity;
class Facebook

{
private:
    Pages** pages;
    Users** users;
    Post** posts;
    Comment** comments;

    static int totalUsers;
    static int totalPages;
    static int totalPosts;
    static int totalComments;

public:
    Facebook();
    ~Facebook();

    void LoadPages(string file);
    void LoadUsers(string filename);
    void LoadPosts(string filename);
    void LoadComments(string filename);

    BASE_CLASS* GetObjectById(char* str);
    Post* GetPostById(char* str);
    void PrintUser(char* str);
    Users* GetUserFromId(const char* str);
    Pages* GetPageFromId(char* str);

    void ViewFriendList(Users* currentUser);
    void ViewLikedPages(Users* currentUser);
    void ViewHome(Users* currentUser, Date currentDate);
    void ViewTimeline(Users* currentUser);
    void ViewLikedList(char* str);
    void LikePost(Users* currentUser, char* post);
    void AddComment(Users* CurrentUser, char* post, char* txt);
    void ViewPost(char* post);
    void ViewMemory(Users* currentUser, Date CurrentDate);
    void ShareMemory(Users* currentUSer, char* originalPostId, char* txt, Date currentDate);
    void ViewPage(char* pageName);

    void Load();
    void Run(char* str);
};

#endif 
