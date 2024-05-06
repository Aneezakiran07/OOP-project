#include "Activity.h"
using namespace std;
Activity::Activity() {
    type = 0;
    value = nullptr;
}

Activity::~Activity() {
    delete[] value;
}

void Activity::Print() {
    if (type == 1) {
        cout << "feeling " << value;
    }
    else if (type == 2) {
        cout << "thinking about " << value;
    }
    else if (type == 3) {
        cout << "Making " << value;
    }
    else if (type == 4) {
        cout << "celebrating " << value;
    }
}

void Activity::ReadDataFromFile(ifstream& inp) {
    char temp[100];
    inp >> type;
    inp.getline(temp, 100);
    Helper::strcpy(temp, value);
}

void Activity::SetValue(char* text) {
    Helper::strcpy(text, value);
}
