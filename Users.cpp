
#include "Users.h"
#include "Base.h"
using namespace std;

Users::Users() {
    totalTimeline = 0;
    numPages = 0;
    numFriends = 0;
    Fname = nullptr;
    Lname = nullptr;
    Liked_pages = nullptr;
    Friend_list = nullptr;
    timeline = nullptr;
}

Users::~Users() {
    delete[] Fname;
    delete[] Lname;
    if (Liked_pages != nullptr)
        delete[] Liked_pages;
    if (Friend_list != nullptr)
        delete[] Friend_list;
    if (timeline != nullptr)
        delete[] timeline;
}

void Users::ReadDataFromFile(ifstream& inp) {
    char temp[50];
    inp >> temp;
    char* ptr;
    Helper::strcpy(temp, ptr);
    SetterforId(ptr);
    inp >> temp;
    Helper::strcpy(temp, Fname);
    inp >> temp;
    Helper::strcpy(temp, Lname);
}

void Users::SetPage(Pages* ptr) {

}

void Users::CheckDate(Date CurrentDate, bool isMemory) {
    bool temp = false;
    for (int i = 0; i < totalTimeline; i++) {
        if (timeline[i]->CompareDate(CurrentDate, isMemory)) {
            timeline[i]->Print(temp);
        }
    }
}

void Users::LikePost(Post* post) {
    post->SetLikedBy(this);
}

void Users::HomePage(Date currentDate) {

}

void Users::timeline_vieww() {
}

void Users::seeMemoryforDate(Date currentDate) {
    bool temp = false;
    for (int i = 0; i < totalTimeline; i++) {
        if (timeline[i] != nullptr) {
            if (timeline[i]->CompareDate(currentDate, true)) {
                timeline[i]->Print(temp);
            }
        }
    }
}

void Users::display_home() {
    cout << Fname << " " << Lname;
}

void Users::SetFriend(Users* ptr) {
    int maxfrnd = 10;
    if (numFriends == 0) {
        Friend_list = new Users * [maxfrnd];
        for (int i = 0; i < maxfrnd; i++) {
            Friend_list[i] = nullptr;
        }
    }
    Friend_list[numFriends] = ptr;
    numFriends++;
}

void Users::add_postTo_timeline(Post* ptr) {

}

void Users::friend_list_view() {
    if (Friend_list != nullptr) {
       // cout << "- " << endl;
        for (int i = 0; i < numFriends; i++) {
            Friend_list[i]->Print();
        }
    }
}

void Users::liked_pages_view() {
    if (Liked_pages != nullptr) {
      //  cout << "---" << endl;
        for (int i = 0; i < numPages; i++) {
            Liked_pages[i]->display();
        }
    }
}

void Users::Print() {
    cout << this->GetId() << "\t" << Fname << " " << Lname << endl;
}

char* Users::GetId() {
    return this->GetterforID();
}
