#include "page.h"
#include <M5Stack.h>


page::page(char * a)
{
    this->txt = a;
}



page * page::back()
{

    return this->parent;
    
}

void page::select()
{
   
   
       if(this->Line < this->config_line)
       {this->Line++;
       }
       else if(this->Line==this->config_line)
       {
           this->Line=1;
       }
       

   
}
page * page::gopage(int i)
{
    if(this->Entries[i]->fcnPtr!=NULL)
    {
        Serial.printf("MAKE OPERATION");
        this->Entries[i]->fcnPtr();
    }
  return this->Entries[i]->p;
}

void page::setEntry(MenuEntry * ME)
{
    this->Entries[this->config_line++] = ME;



   /*
    for(int i = 0; i < 5; i++)
    {
        switch(i)
        {
            case 0 :{

            
                   MenuEntry * ME1 = new MenuEntry(a);
                   this->Entries[0] = ME1; }
                   break;
            case 1 :{
                   MenuEntry * ME2 = new MenuEntry(b);
                   this->Entries[1] = ME2;}
                   break;
            case 2: {
                    MenuEntry * ME3 = new MenuEntry(c);
                    this->Entries[2] = ME3; }
                   break;
            case 3: {
                    MenuEntry * ME4 = new MenuEntry(d);
                    this->Entries[3] = ME4; }
                   break;
            case 4: {
                    MenuEntry * ME5 = new MenuEntry(e);
                    this->Entries[4] = ME5;}
                    break;
            default:
                    M5.Lcd.println("ERROR");
        }
    }

*/

}
void page::display()
{
    //for(int i = 0; i < 5; i++)
    // M5.Lcd.printf("%d. %s\n",i,this->Entries[i]->getTXT());
    M5.Lcd.printf("HELLO SCREEN");
    
}