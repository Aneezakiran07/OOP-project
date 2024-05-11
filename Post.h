#ifndef POST_H
#define POST_H

#include "Pages.h" 
#include "Users.h"
#include "Post.h"
#include "Comment.h"
//#include"Memory.h"
#include "Helper.h"
#include <fstream>
#include <iostream>
#include "Date.h" 

class BASE_CLASS;
class Activity;
class Comment;

class Post
{
private:
    char* Id;
    char* text;
    Date sharedDate;
    BASE_CLASS* sharedBy;
    BASE_CLASS** LikedBy;
    Comment** comments;
    Activity* activity;

    int totalLikedBy;
    int totalComment;

    static int TotalPosts;

public:
    ~Post();
    Post(const char* txt, BASE_CLASS* SharedBy, Date currentDate);
    Post();

    void ReadDataFromFile(std::ifstream& inp);
    void SetSharedBy(BASE_CLASS* ptr);
    void SetLikedBy(BASE_CLASS* ptr);
    void AddComment(Comment* ptr);
    bool CompareDate(Date currentDate, bool isMemory);
    void ViewLikedList();

    virtual void Print(bool& flag);
    void Print();

    Date GetSharedDate();
    char* GetId();

    static int GetTotalPosts();
};


class Memory : public Post {
private:
    Post* Original;

public:
    Memory();
    Memory(Post*& oldPost, const char* text, BASE_CLASS* userptr, Date currentDate);
    ~Memory();
    void Print(bool& flag);
    Post* GetOriginalPost();
};

#endif // POST_H
