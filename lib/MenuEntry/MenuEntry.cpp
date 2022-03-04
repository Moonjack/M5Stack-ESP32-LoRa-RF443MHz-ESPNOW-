#include "MenuEntry.h"
#include <Arduino.h>

MenuEntry::MenuEntry(char *a)
{
  this->txt = a;
}



MenuEntry::MenuEntry(char * a, page *p, void (*func)())
{

    //MenuEntry(a);
    this->txt = a;
    this->p = p;
    this->fcnPtr = func;
   // this->next = next;
}


char * MenuEntry::getTXT()
{
    if(this->txt!=nullptr)
   { Serial.printf("NULL POINTER NOT");
     return this->txt;}

    else{Serial.printf("ERROR CODE"); 
      return "error";}
}

