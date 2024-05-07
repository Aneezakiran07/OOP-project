#include<iostream>
#include"Base.h"
#include"Post.h"

using namespace std;

BASE_CLASS::BASE_CLASS() : ID(nullptr) {}

BASE_CLASS::~BASE_CLASS() {
	delete[] ID;
}

char* BASE_CLASS::GetterforID() {
	return ID;
}
void BASE_CLASS::SetterforId(char* ptr) {
	ID = ptr;
}
void BASE_CLASS::SetId(char* id) {
	ID = id;
}

void BASE_CLASS::display() {
	cout << ID;
}
void BASE_CLASS::display_home() {
	cout << "Error	Not Found!!!!!!" << std::endl;
}

void BASE_CLASS::add_postTo_timeline(Post* ptr) {
	cout << "Error	Not Found!!!!!!" << endl;
}