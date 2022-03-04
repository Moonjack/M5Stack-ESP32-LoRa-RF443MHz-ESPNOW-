//#include <iostream>
//#include <stack>

#include "page.h"
#include "M5Stack.h"
#include "StackArray.h"
using namespace std;
class Menu
{
    public:
    
    String prompt = "initial";
    page * current_page;
   // stack<page *> * sta;
    StackArray<page * >  stackxy;
    Menu(page * cp);
    void browse(page * p);
    void display(int x);
    void install(page * p1, page * p2, int i);
    void push(page * p);
    page * pop();

};