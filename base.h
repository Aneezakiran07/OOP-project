#ifndef BASECLASS_H
#define BASECLASS_H

//#include"Post.h"

#include<string>
using namespace std;

class Post;

class BASE_CLASS {
protected:
    char* ID;

public:
    BASE_CLASS();
    virtual ~BASE_CLASS();
    char* GetterforID();
    void SetterforId(char* ptr);
    void SetId(char* id);
    virtual void display();
    virtual void display_home();
    virtual void add_postTo_timeline(Post* ptr);
};

#endif 