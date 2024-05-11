#include"Comment.h"
//#include"base.h"
using namespace std;

Comment::Comment(BASE_CLASS* CurrentUser, char* txt) {
    char* IdForNewComment = Helper::Int_str_concatenation("c", TotalComments + 1);
    Text = txt;
    commentPostedBy = CurrentUser;
    Id = IdForNewComment;
}

Comment::Comment() : commentPostedBy(nullptr), Text(nullptr), Id(nullptr) {}

Comment::~Comment() {
    delete commentPostedBy;
    delete[] Text;
    delete[] Id;
}

void Comment::SetValues(char* idStr, char* textStr, BASE_CLASS* commentByPtr) {
    commentPostedBy = commentByPtr;
    Helper::strcpy(textStr, Text);
    Helper::strcpy(idStr, Id);
    TotalComments++;
}

void Comment::display() {
    commentPostedBy->display_home();
    cout << " Wrote: " << Text << endl;
}
int Comment::TotalComments = 0;