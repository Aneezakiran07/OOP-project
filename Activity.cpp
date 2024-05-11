#include "Activity.h"
using namespace std;
Activity::Activity()
{
    type = 0;
    value = nullptr;
}

Activity::~Activity() {
    delete[] value;
}

void Activity::display() {
    if (type == 1) {
        cout << "Feeling " << value;
    }
    else if (type == 2) {
        cout << "Thinking about " << value;
    }
    else if (type == 3) {
        cout << "Making " << value;
    }
    else if (type == 4) {
        cout << "Celebrating " << value;
    }
}

void Activity::readData(ifstream& input) {
    char temp[100];
    input >> type;
    input.getline(temp, 100);
    Helper::strcpy(temp, value);
}

void Activity::setValue(char* text) {
    Helper::strcpy(text, value);
}
