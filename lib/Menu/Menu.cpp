#include "Menu.h"


Menu::Menu(page *p)
{
    this->current_page = p;
}
void Menu::browse(page * p)
{
 this->current_page = p;

}
void Menu::display(int x)
{
  static bool key = false;
M5.Lcd.clear();
M5.Lcd.clearDisplay();
M5.Lcd.fillScreen(BLACK);
M5.Lcd.setTextSize(1);
M5.Lcd.setTextColor(TFT_YELLOW);
M5.Lcd.drawString(this->prompt,20,2,2);
 M5.Lcd.setTextSize(3);
M5.lcd.setCursor(0,25);
Serial.printf("WE ARE IN DISPLAY\n");
for(int i = 0; i < this->current_page->config_line; i++)
{
  Serial.printf("WE ARE IN LOOP %d\n",i);
if(x == i+1)
{
  M5.Lcd.setTextColor(TFT_GREEN);
}
else 
{
  M5.Lcd.setTextColor(TFT_RED);
}
 // if(this->current_page==NULL)
  // break;
  // if(this->current_page->Entries==NULL)
    //  break;
      //if(this->current_page->Entries->getTXT()==NULL)
       //break;
    //   char * b = this->current_page->Entries[i]->getTXT();
     //  if(b==NULL)
    //   break;
       if(x <= 9)
       {
          M5.Lcd.printf("%d. %s\n",i+1,this->current_page->Entries[i]->getTXT());
       }
       else if(x>= 10 && x<=18){
                  if(key!=true)
                  M5.Lcd.clear();
                  key = true;
                  if(i >= 9)
                  { Serial.printf("x= %d",x);
                   // if(x == i+1)
                   // {
                    //  M5.Lcd.setTextColor(TFT_GREEN);
                   // }
                   // else
                   // {
                    //   M5.Lcd.setTextColor(TFT_RED);
                   // }
                      M5.Lcd.printf("%d. %s\n",i+1,this->current_page->Entries[i]->getTXT());
                  }
                 // if(x==18)
                 // key = false;
       }
        else if(x>= 19 && x<=27){
                  Serial.printf("CHEEEECK\n");
                  if(key!=true)
                  M5.Lcd.clear();
                  key = true;
                  if(i >= 18)
                  { Serial.printf("x= %d",x);
                   // if(x == i+1)
                   // {
                    //  M5.Lcd.setTextColor(TFT_GREEN);
                   // }
                   // else
                   // {
                    //   M5.Lcd.setTextColor(TFT_RED);
                   // }
                      M5.Lcd.printf("%d. %s\n",i+1,this->current_page->Entries[i]->getTXT());
                  }
                  //delay(2000);
            }

            else if(x>= 28 && x<=36){
                  if(key!=true)
                  M5.Lcd.clear();
                  key = true;
                  if(i >= 27)
                  { Serial.printf("x= %d",x);
                   // if(x == i+1)
                   // {
                    //  M5.Lcd.setTextColor(TFT_GREEN);
                   // }
                   // else
                   // {
                    //   M5.Lcd.setTextColor(TFT_RED);
                   // }
                      M5.Lcd.printf("%d. %s\n",i+1,this->current_page->Entries[i]->getTXT());
                  }
                  //delay(2000);
            }

              else if(x>= 37 && x<=44){
                  if(key!=true)
                  M5.Lcd.clear();
                  key = true;
                  if(i >= 36)
                  { Serial.printf("x= %d",x);
                   // if(x == i+1)
                   // {
                    //  M5.Lcd.setTextColor(TFT_GREEN);
                   // }
                   // else
                   // {
                    //   M5.Lcd.setTextColor(TFT_RED);
                   // }
                      M5.Lcd.printf("%d. %s\n",i+1,this->current_page->Entries[i]->getTXT());
                  }
                  //delay(2000);
            }
       }
Serial.printf("LOOOP OVER");
}

void Menu::install(page * p1, page *p2, int i)
{
  p1->Entries[i]->p = p2;
  p2->parent = p1;  
    
}
void Menu::push(page * p)
{
  this->stackxy.push(p);

}
page * Menu::pop()
{
  return this->stackxy.pop();
}