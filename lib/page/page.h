
#include "MenuEntry.h"
class page
{
    

    public:
    page * parent;
    MenuEntry  * Entries[44];
    char * txt;
    int Line = 1;
    int config_line = 0;

    page(char * a);
    
    void setEntry(MenuEntry * ME);
    void select();
    page * back();
    page * gopage(int i);
    void display();
    
   
};