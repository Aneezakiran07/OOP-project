#include "Post.h"
//#include "Memory.h"

#include <iostream>

using namespace std;

int Post::TotalPosts = 0;

Post::~Post() {
    delete[] Id;
    delete activity;
    delete[] text;
    if (liked_post_by != nullptr)
        delete[] liked_post_by;
    if (comments != nullptr)
        delete[] comments;
  
}

Post::Post(const char* txt, BASE_CLASS* SharedBy, Date currentDate) : Id(nullptr), sharedBy(nullptr),  text(nullptr) ,liked_post_by(nullptr), comments(nullptr), activity(nullptr), totalLikedBy(0), totalComment(0) {
    activity = nullptr;
    char* IdForNewPost = Helper::Int_str_concatenation("post", TotalPosts + 1);
    Helper::strcpy(IdForNewPost, Id);
    Helper::strcpy(txt, text);
    sharedBy = SharedBy;
    sharedDate = currentDate;
    totalLikedBy = 0;
    totalComment = 0;
}

Post::Post() : Id(nullptr), text(nullptr), sharedBy(nullptr), liked_post_by(nullptr), comments(nullptr), activity(nullptr), totalLikedBy(0), totalComment(0) {}

void Post::SetSharedBy(BASE_CLASS* ptr) {
    sharedBy = ptr;
}

void Post::SetLikedBy(BASE_CLASS* ptr) {
    if (totalLikedBy == 0) {
        liked_post_by = new BASE_CLASS * [10];
        for (int i = 0; i < 10; i++) {
            liked_post_by[i] = nullptr;
        }
        liked_post_by[totalLikedBy] = ptr;
        totalLikedBy++;
    }
    else {
        liked_post_by[totalLikedBy] = ptr;
        totalLikedBy++;
    }
}

void Post::AddComment(Comment* comment_ptr) {
    int maxcomment = 10;
    if (totalComment == 0) {
        comments = new Comment * [maxcomment];
        for (int i = 0; i < maxcomment ; i++) {
            comments[i] = nullptr;
        }
        comments[totalComment] = comment_ptr;
        totalComment++;
    }
    else {
        comments[totalComment] = comment_ptr;
        totalComment++;
    }
}

bool Post::CompareDate(Date currentDate, bool Memory) {
    if (currentDate.compareyear_mem(sharedDate,Memory)) {
        return 1;
    }
    else {
        return 0;
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
        activity->Print();
    }
    cout << endl;
    cout << "\"" << text << "\"";
    cout << " (";
    sharedDate.display();
    cout << ") " << endl << "\t";
    for (int i = 0; i < totalComment; i++) {
        comments[i]->Print();
        cout << "\t";
    }
    cout << endl;
}

void Post::Print() {
      sharedBy->display_home();
    cout << " ";
    if (activity != 0) {
        activity->Print();
    }
    cout << endl;
    cout << "\"" << text << "\"";
    cout << " (";
    cout << ") " << endl << "\t";
    for (int i = 0; i < totalComment; i++) {
        comments[i]->Print();
        cout << "\t";
    }
    cout << endl;
}

void Post::ViewLikedList() {
    if (liked_post_by != 0) {
        
        for (int i = 0; i < totalLikedBy; i++) {
            liked_post_by[i]->display();
            cout << endl;
        }
    }
}
int Post::GetTotalPosts()
{
    return TotalPosts;
}
void Post::readData(ifstream& inp)
{
    int activityId = 0;
    inp >> activityId;
    char temp[100];
    inp >> temp;

    Helper::strcpy(temp, Id);

    sharedDate.ReadDataFromFile(inp);
    //  cout << "HI" << endl;
    inp.ignore();

    inp.getline(temp, 100, '\n');
    Helper::strcpy(temp, text);
    if (activityId == 2)
    {
        activity = new Activity;
        activity->ReadDataFromFile(inp);
    }
    TotalPosts++;
}

Memory::Memory() : Original(nullptr) {}

Memory::Memory(Post*& oldPost, const char* text, BASE_CLASS* userptr, Date currentDate) : Post(text, userptr, currentDate), Original(oldPost) {}

Memory::~Memory() {
    delete Original;
}

void Memory::Print(bool& flag) {

}

Post* Memory::GetOriginalPost() {
    return Original;
}
