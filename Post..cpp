#include "Post.h"
//#include "Memory.h"
#include <iostream>

using namespace std;

int Post::TotalPosts = 0;

Post::~Post() {
    delete[] Id;
    delete[] text;
    if (LikedBy != nullptr)
        delete[] LikedBy;
    if (comments != nullptr)
        delete[] comments;
    delete activity;
}

Post::Post(const char* txt, BASE_CLASS* SharedBy, Date currentDate) : Id(nullptr), text(nullptr), sharedBy(nullptr), LikedBy(nullptr), comments(nullptr), activity(nullptr), totalLikedBy(0), totalComment(0) {
    activity = nullptr;
    char* IdForNewPost = Helper::Int_str_concatenation("post", TotalPosts + 1);
    Helper::strcpy(IdForNewPost, Id);
    Helper::strcpy(txt, text);
    sharedBy = SharedBy;
    sharedDate = currentDate;
    totalComment = 0;
    totalLikedBy = 0;
}

Post::Post() : Id(nullptr), text(nullptr), sharedBy(nullptr), LikedBy(nullptr), comments(nullptr), activity(nullptr), totalLikedBy(0), totalComment(0) {}

void Post::SetSharedBy(BASE_CLASS* ptr) {
    sharedBy = ptr;
}

void Post::SetLikedBy(BASE_CLASS* ptr) {
    if (totalLikedBy == 0) {
        LikedBy = new BASE_CLASS * [10];
        for (int i = 0; i < 10; i++) {
            LikedBy[i] = nullptr;
        }
        LikedBy[totalLikedBy] = ptr;
        totalLikedBy++;
    }
    else {
        LikedBy[totalLikedBy] = ptr;
        totalLikedBy++;
    }
}

void Post::AddComment(Comment* ptr) {
    if (totalComment == 0) {
        comments = new Comment * [10];
        for (int i = 0; i < 10; i++) {
            comments[i] = nullptr;
        }
        comments[totalComment] = ptr;
        totalComment++;
    }
    else {
        comments[totalComment] = ptr;
        totalComment++;
    }
}

bool Post::CompareDate(Date currentDate, bool isMemory) {
    if (currentDate.compareyear_mem(sharedDate, isMemory)) {
        return true;
    }
    else {
        return false;
    }
}

Date Post::GetSharedDate() {
    return sharedDate;
}

char* Post::GetId() {
    return Id;
}

void Post::Print(bool& flag) {
    sharedBy->display_home();
    cout << " ";
    if (activity != 0) {
        activity->display();
    }
    cout << endl;
    cout << "\"" << text << "\"";
    cout << " (";
    sharedDate.display();
    cout << ") " << endl << "\t";
    for (int i = 0; i < totalComment; i++) {
        comments[i]->display();
        cout << "\t";
    }
    cout << endl;
}

void Post::Print() {
    sharedBy->display_home();
    cout << " ";
    if (activity != 0) {
        activity->display();
    }
    cout << endl;
    cout << "\"" << text << "\"";
    cout << " (";
    cout << ") " << endl << "\t";
    for (int i = 0; i < totalComment; i++) {
        comments[i]->display();
        cout << "\t";
    }
    cout << endl;
}

void Post::ViewLikedList() {
    if (LikedBy != 0) {
        cout << "-----------------------------------------------------------------------------------------" << endl;
        for (int i = 0; i < totalLikedBy; i++) {
            LikedBy[i]->display();
            cout << endl;
        }
    }
}
int Post::GetTotalPosts()
{
    return TotalPosts;
}
void Post::ReadDataFromFile(ifstream& inp)
{
    int activityId = 0;
    inp >> activityId;
    char temp[100];
    inp >> temp;

    Helper::strcpy(temp, Id);

    sharedDate.readData(inp);
    //  cout << "HI" << endl;
    inp.ignore();

    inp.getline(temp, 100, '\n');
    Helper::strcpy(temp, text);
    if (activityId == 2)
    {
        activity = new Activity;
        activity->readData(inp);
    }
    TotalPosts++;
}

Memory::Memory() : Original(nullptr) {}

Memory::Memory(Post*& oldPost, const char* text, BASE_CLASS* userptr, Date currentDate) : Post(text, userptr, currentDate), Original(oldPost) {}

Memory::~Memory() {
    delete Original;
}

void Memory::Print(bool& flag) {
    cout << "Shared a memory (" << Date::difYear(Original->GetSharedDate(), GetSharedDate()) << " years) ago" << endl;
    Original->Print(flag);
    flag = true;
}

Post* Memory::GetOriginalPost() {
    return Original;
}
