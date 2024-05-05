#pragma once
#include "Facebook.h"
using namespace std;

Facebook::Facebook() : pages(nullptr), users(nullptr), posts(nullptr), comments(nullptr) { }

Facebook::~Facebook() {
    for (int i = 0; i < totalUsers; i++) {
        if (users[i] != nullptr)
            delete users[i];
    }
    delete[] users;

    for (int i = 0; i < totalPages; i++) {
        if (pages[i] != nullptr)
            delete pages[i];
    }
    delete[] pages;

    for (int i = 0; i < totalPosts; i++) {
        if (posts[i] != nullptr)
            delete posts[i];
    }
    delete[] posts;

    for (int i = 0; i < totalComments; i++) {
        if (comments[i] != nullptr)
            delete comments[i];
    }
    delete[] comments;
}

void Facebook::LoadPages(string filename) {

    ifstream input;
    input.open(filename);
    if (input)
    {
        input >> totalPages;

        pages = new Pages * [totalPages];
        for (int i = 0; i < totalPages; i++)
        {
            pages[i] = new Pages;
            pages[i]->ReadDataFromFile(input);
        }

        input.close();
    }
}

void Facebook::LoadUsers(string filename) {

    ifstream input;
    input.open(filename);
    if (input)
    {
        input >> totalUsers;

        users = new Users * [totalUsers];
        char*** friendList = new char** [totalUsers];
        char temp[50];

        for (int i = 0; i < totalUsers; i++)
        {
            users[i] = new Users;
            users[i]->ReadDataFromFile(input);
            friendList[i] = new char* [10];
            for (int h = 0; h < 10; h++)
            {
                friendList[i][h] = 0;
            }
            for (int j = 0; j < 10; j++)
            {
                input >> temp;
                if (Helper::compareString(temp, "-1"))
                {
                    break;
                }
                else
                    Helper::strcpy(temp, friendList[i][j]);
            }
            input.ignore();

            Pages* pointer;
            for (int j = 0; j < 10; j++)
            {
                inp >> temp;
                if (Helper::compareString(temp, "-1"))
                {
                    break;
                }
                else
                {
                    pointer = GetPageFromId(temp);
                    users[i]->SetPage(pointer);
                }
            }

        }

        //associate friends
        Users* ptr;
        for (int j = 0; j < totalUsers; j++)
        {
            for (int k = 0; k < 10; k++)
            {
                if (friendList[j][k] == 0)
                {
                    break;
                }

                ptr = GetUserFromId(friendList[j][k]);
                users[j]->SetFriend(ptr);
            }
        }

        //deallocate the 3d pointer
        for (int h = 0; h < totalUsers; h++)
        {
            if (friendList[h])
            {
                for (int g = 0; g < 10; g++)
                {
                    if (friendList[h][g])
                        delete[]friendList[h][g];
                }
                delete[] friendList[h];
            }

        }

        inp.close();

        if (friendList)
        {
            delete[]friendList;
        }

    }


}

void Facebook::LoadPosts(string filename) {

    ifstream inp(filename);
    char temp[100];
    if (inp) {
        inp >> totalPosts;
        posts = new Post * [totalPosts];

        for (int i = 0; i < totalPosts; i++) {
            posts[i] = new Post;
            posts[i]->ReadDataFromFile(inp);

            inp >> temp;

            BASE_CLASS* sharedBy = GetObjectById(temp);

            posts[i]->SetSharedBy(sharedBy);

            sharedBy->add_postTo_timeline(posts[i]);

            inp >> temp;
            for (int j = 0; temp[0] != '-'; j++) {
                posts[i]->SetLikedBy(GetObjectById(temp));
                inp.ignore();
                inp >> temp;
            }
        }
    }

    inp.close();
}

void Facebook::LoadComments(string filename)
{
    ifstream inp(filename);
    if (inp) {
        inp >> totalComments;
        char tempId[100], strText[100], temp[50], tempPost[50];
        BASE_CLASS* commentBy;
        comments = new Comment * [totalComments];
        for (int i = 0; i < totalComments; i++) {
            comments[i] = new Comment;
            inp >> tempId;
            inp.ignore();
            inp >> tempPost;
            inp >> temp;
            commentBy = GetObjectById(temp);
            inp.ignore();
            inp.getline(strText, 100);
            comments[i]->SetValues(tempId, strText, commentBy);
            Post* ptr = GetPostById(tempPost);
            ptr->AddComment(comments[i]);
        }
        inp.close();
    }
}

void Facebook::PrintUser(char* str)
{
    std::cout << "Set Current User " << str << std::endl;
    Users* ptr = GetUserFromId(str);
    ptr->Print();
}

Users* Facebook::GetUserFromId(const char* str)
{
    for (int i = 0; i < totalUsers; i++) {
        if (Helper::compareString(str, users[i]->GetId())) {
            return users[i];
        }
    }
    return nullptr;
}

Pages* Facebook::GetPageFromId(char* str)
{
    for (int i = 0; i < totalPages; i++) {
        if (Helper::compareString(str, pages[i]->GetterForId()))
        {
            return pages[i];
        }
    }
    return nullptr;
}

BASE_CLASS* Facebook::GetObjectById(char* str)
{
    if (str[0] == 'u') {
        return GetUserFromId(str);
    }
    else if (str[0] == 'p') {
        return GetPageFromId(str);
    }
    else {
        return nullptr;
    }
}

Post* Facebook::GetPostById(char* str)
{
    for (int i = 0; i < totalPosts; i++) {
        if (Helper::compareString(str, posts[i]->GetId())) {
            return posts[i];
        }
    }
    return nullptr;
}

void Facebook::ViewFriendList(Users* currentUser)
{

}

void Facebook::ViewLikedPages(Users* currentUser)
{
}

void Facebook::ViewHome(Users* currentUser, Date currentDate)
{

}


void Facebook::ViewTimeline(Users* currentUser)
{
}

void Facebook::ViewLikedList(char* str)
{

}


void Facebook::LikePost(Users* currentUser, char* post)
{

}

void Facebook::AddComment(Users* CurrentUser, char* post, char* txt)
{

}

void Facebook::ViewPost(char* post)
{

}

void Facebook::ViewMemory(Users* currentUser, Date CurrentDate)
{
}

void Facebook::ShareMemory(Users* currentUser, char* originalPostId, char* txt, Date currentDate) {

}

void Facebook::ViewPage(char* pageName) {

}

void Facebook::Load() {
    LoadPages("Pages.txt");
    LoadUsers("Users.txt");
    LoadPosts("Posts.txt");
    LoadComments("Comments.txt");
}

void Facebook::Run(char* str) {

}

int Facebook::totalUsers = 0;
int Facebook::totalPages = 0;
int Facebook::totalPosts = 0;
int Facebook::totalComments = 0;