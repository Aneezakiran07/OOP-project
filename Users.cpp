
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
    if (numPages == 0) {
        Liked_pages = new Pages * [10];
        for (int i = 0; i < 10; i++) {
            Liked_pages[i] = nullptr;
        }
    }
    Liked_pages[numPages] = ptr;
    numPages++;
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
    cout << "---------------------------------------------------------------------------" << endl;
    if (Friend_list != nullptr) {
        for (int i = 0; i < numFriends; i++) {
            Friend_list[i]->CheckDate(currentDate, false);
        }
    }

    if (Liked_pages != nullptr) {
        for (int i = 0; i < numPages; i++) {
            Liked_pages[i]->CheckDate(currentDate, false);
        }
    }
    cout << endl;
}

void Users::timeline_vieww() {
    if (timeline != nullptr) {
        cout << "------------------------------------------------------------------------------" << endl;
        for (int i = 0; i < totalTimeline; i++) {
            if (timeline[i] != nullptr) {
                bool IsNewPost = false;
                timeline[i]->Print(IsNewPost);
                if (IsNewPost) {
                    timeline[i]->Print();
                }
            }
        }
    }
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
    if (totalTimeline == 0) {
        timeline = new Post * [10];
        for (int i = 0; i < 10; i++) {
            timeline[i] = nullptr;
        }
        timeline[totalTimeline] = ptr;
        totalTimeline++;
    }
    else {
        timeline[totalTimeline] = ptr;
        totalTimeline++;
    }
}

void Users::friend_list_view() {
    if (Friend_list != nullptr) {
        cout << "--------------------------------- Friend List ---------------------------------" << endl;
        for (int i = 0; i < numFriends; i++) {
            Friend_list[i]->Print();
        }
    }
}

void Users::liked_pages_view() {
    if (Liked_pages != nullptr) {
        cout << "--------------------------------- Liked Pages ---------------------------------" << endl;
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
