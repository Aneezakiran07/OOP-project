#include "Pages.h"
using namespace std;

Pages::Pages()
{
    title = nullptr;
    total_timeline = 0;
    timeline = nullptr;
}

Pages::~Pages() 
{
    delete[] title;
    if (timeline != nullptr)
        delete[] timeline;
}

void Pages::ReadData(ifstream& inp) 
{
    char temp[100];
    inp >> temp;
    char* ptr;
    Helper::strcpy(temp, ptr);
    SetterforId(ptr);
    inp.ignore();
    inp.getline(temp, 100, '\n');
    Helper::strcpy(temp, title);
}

void Pages::display_home() {
    cout << title;
}

void Pages::add_postTo_timeline(Post* ptr) {
    if (total_timeline == 0) {
        timeline = new Post * [10];
        for (int i = 0; i < 10; i++) {
            timeline[i] = nullptr;
        }
        timeline[total_timeline] = ptr;
        total_timeline++;
    }
    else {
        timeline[total_timeline] = ptr;
        total_timeline++;
    }
}

void Pages::CheckDate(Date CurrentDate, bool memory) {
    bool temp = false;
    for (int i = 0; i < total_timeline; i++) {
        if (timeline[i]->CompareDate(CurrentDate, memory)) {
            timeline[i]->Print(temp);
        }
    }
}

void Pages::display() {
    cout << this->GetterforID() << "\t" << title << endl;
}

void Pages::view_timeline() {
    bool temp = false;
    if (timeline != nullptr) {
        for (int i = 0; i < total_timeline; i++) {
            timeline[i]->Print(temp);
        }
    }
}

char* Pages::GetterForId() {
    return this->GetterforID();
}
