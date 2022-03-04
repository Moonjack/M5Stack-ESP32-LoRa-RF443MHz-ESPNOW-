

class page;
class MenuEntry
{
    
    char * txt;
    
    public:
    page * p;
    //page * next;
    void (*fcnPtr)(){nullptr};
    //page * np;
    MenuEntry();
    MenuEntry(char * a);
    MenuEntry(char * a, page * p, void (*func)());
    
    char * getTXT();
    //MenuEntry ** setEntry(char * a, char * b, char * c, char *d, char * e);
    
   
        
    
};