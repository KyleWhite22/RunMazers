#include "FEHLCD.h"
#include "FEHUtility.h"
#include "iostream"
#include "cstring"
using namespace std;
void menu();
void start();
void stats();
void instructions();
void credits();
void easy();
int main()
{
    //call menu function to display menu
    menu();
}
void menu()
{
    float x_pos, y_pos, x_trash, y_trash;
    int i=0;
    //setting font and background colors
    LCD.SetOrientation( FEHLCD::North);
    LCD.SetFontColor(BLUE);
    LCD.SetBackgroundColor(GRAY);
    LCD.Clear();
    //title of game
    LCD.WriteAt("Run Mazers", 94, 15);
    LCD.WriteLine("                   \n");
    LCD.SetFontColor(WHITE);
    //start text/box
    LCD.WriteAt("Play Game Here", 94,80);
    LCD.DrawRectangle(90,75,175,25);
    LCD.WriteLine("                   \n");
    //stats text/box
    LCD.WriteAt("Stats", 94,110);
    LCD.DrawRectangle(90,105,70,25);
    LCD.WriteLine("                   \n");
    //instructions text/box
    LCD.WriteAt("Instructions", 94,140);
    LCD.DrawRectangle(90,135,150,25);
    LCD.WriteLine("                   \n");
    //credits text/box
    LCD.WriteAt("Credits", 94,170);
    LCD.DrawRectangle(90,165,95,25);
    LCD.WriteLine("                   \n");
while(true)
    {
    //When no touch is perceived:
        LCD.ClearBuffer();
        while (!LCD.Touch(&x_pos, &y_pos))
        {
        }
    //When touch is perceived
        while(LCD.Touch(&x_trash, &y_trash))
        {
            //if start box is selected
            if (x_trash>90 && x_trash <265 && y_trash>75 && y_trash<100)
            {
                i = 1;
            }
            //if stats box is selected
            else if( x_trash>90 && x_trash <160 && y_trash>105 && y_trash<130)
            {
                i = 2;
            }
            //if instructions box is selected
            else if(x_trash>90 && x_trash <240 && y_trash>135 && y_trash<160)
            {
                i = 3;
            }
            //if credits box is selected
            else if (x_trash>90 && x_trash <185 && y_trash>165 && y_trash<190)
            {
                i = 4;
            }
        }
    //switch case determing which function to call 
    switch (i)
    {
    //start page
    case 1:
    start();
    break;
    //stats page
    case 2:
    stats();
    break;
    //instructions page
    case 3:
    instructions();
    break;
    //credits page
    case 4:
    credits();
    break;
    default:
    menu();
    }
    }
    while (1) {
        LCD.Update();
        // Never end
    }
}

//Starting Game
void start()
{
    //Drop Down of All Difficulty Modes
    float x_pos, y_pos, x_trash, y_trash;
    int i=1;
    LCD.Clear();
    LCD.WriteAt("Select Difficulty", 70, 15);
    LCD.SetFontColor(GREEN);
    LCD.WriteAt("Easy", 110, 75);
    LCD.SetFontColor(WHITE);
    LCD.DrawRectangle(106,73,58,22);
    LCD.SetFontColor(YELLOW);
    LCD.WriteAt("Medium", 110, 105);
    LCD.SetFontColor(RED);
    LCD.WriteAt("Hard", 110, 135);
    LCD.SetFontColor(WHITE);
    LCD.WriteAt("Back", 10, 220);
    LCD.DrawRectangle(4,215,60,25);
    while(true)
    {
    //When no touch is perceived:
        LCD.ClearBuffer();
        while (!LCD.Touch(&x_pos, &y_pos))
        {
        }
    //When touch is perceived
        while(LCD.Touch(&x_trash, &y_trash))
        {
           //if "back" box is selected, return to menu
           if (x_trash>4 && x_trash <64 && y_trash>215 && y_trash<239)
            {
                i=0;
            }  
            if (x_trash>106 && x_trash <164 && y_trash>73 && y_trash<95)
            {
                i=5;
            }  
        }
    //switch case determing which function to call 
    switch (i)
    {
    case 1:
    start();
    break;
    case 5:
    easy();
    break;
    default:
    menu();
    }
    }

}

//Show Statistics
void stats()
{
    float x_pos, y_pos, x_trash, y_trash;
    int i=2;
    LCD.Clear();
    //display of player 1 wins and player 2 wins
    LCD.WriteAt("Run Mazers User Stats", 30, 15);
    LCD.WriteAt("Player 1 Wins: 10", 60, 75);
    LCD.WriteAt("Player 2 Wins: 15", 60, 105);
    LCD.SetFontColor(WHITE);
    LCD.WriteAt("Back", 10, 220);
    LCD.DrawRectangle(4,215,60,25);
    while(true)
    {
    //When no touch is perceived:
        LCD.ClearBuffer();
        while (!LCD.Touch(&x_pos, &y_pos))
        {
        }
    //When touch is perceived
    
        while(LCD.Touch(&x_trash, &y_trash))
        {
            //if "back" box is selected, return to menu
           if (x_trash>4 && x_trash <64 && y_trash>215 && y_trash<239)
            {
                i=0;
            }  
        }
    //switch case determing which function to call  
    switch (i)
    {
    case 2:
    stats();
    break;
    default:
    menu();
    }
    }
}

void instructions()
{
    float x_pos, y_pos, x_trash, y_trash;
    int i=3;
    LCD.Clear();
    //display of game instructions
    LCD.WriteLine("Two players take turns    racing through maze.");
    LCD.WriteLine("Click and drag player icon through maze.");
    LCD.WriteLine("Times will be compared andwinner will be determined.");
    LCD.SetFontColor(WHITE);
    LCD.WriteAt("Back", 10, 220);
    LCD.DrawRectangle(4,215,60,25);
    while(true)
    {
    //When no touch is perceived:
        LCD.ClearBuffer();
        while (!LCD.Touch(&x_pos, &y_pos))
        {
        }
    //When touch is perceived
        while(LCD.Touch(&x_trash, &y_trash))
        {
            //if "back" box is selected, return to menu
           if (x_trash>4 && x_trash <64 && y_trash>215 && y_trash<239)
            {
                i=0;
            }  
        }
    //switch case determing which function to call 
    switch (i)
    {
    case 3:
    instructions();
    break;
    default:
    menu();
    }
    }
}

void credits()
{
    float x_pos, y_pos, x_trash, y_trash;
    int i=4;
    LCD.Clear();
    LCD.SetFontColor(BLUE);
    //display of game credits
    LCD.WriteAt("Credits", 110, 15);
    LCD.SetFontColor(WHITE);
    LCD.WriteAt("Connor", 110, 75);
    LCD.WriteAt("Kyle", 110, 105);
    LCD.WriteAt("Pratham", 110, 135);
    LCD.SetFontColor(WHITE);
    LCD.WriteAt("Back", 10, 220);
    LCD.DrawRectangle(4,215,60,25);
    while(true)
    {
    //When no touch is perceived:
        LCD.ClearBuffer();
        while (!LCD.Touch(&x_pos, &y_pos))
        {
        }
    //When touch is perceived
        while(LCD.Touch(&x_trash, &y_trash))
        {
           //if "back" box is selected, return to menu
           if (x_trash>4 && x_trash <64 && y_trash>215 && y_trash<239)
            {
                i=0;
            }  
        }
    //switch case determing which function to call 
    switch (i)
    {
    case 4:
    credits();
    break;
    default:
    menu();
    }
    }
}
void easy()
{
    int i;
    //Horizontal Borders
    LCD.Clear();
    LCD.WriteAt("________________________________________________________________________________", 10, 5);
    LCD.WriteAt("________________________________________________________________________________", 10, 210);
    //Left Vertical Border
        LCD.WriteAt("|", 0, 17);
        LCD.WriteAt("|", 0, 30);
        LCD.WriteAt("|", 0, 43);
        LCD.WriteAt("|", 0, 56);
        LCD.WriteAt("|", 0, 69);
        LCD.WriteAt("|", 0, 82);
        LCD.WriteAt("|", 0, 95);
        LCD.WriteAt("|", 0, 108);
        LCD.WriteAt("|", 0, 121);
        LCD.WriteAt("|", 0, 134);
        LCD.WriteAt("|", 0, 147);
        LCD.WriteAt("|", 0, 160);
        LCD.WriteAt(" ", 0, 173);
        LCD.WriteAt(" ", 0, 186);
        LCD.WriteAt("|", 0, 199);
        //Starting Opening
        LCD.WriteAt("_", 4, 186);
        LCD.WriteAt("_", 9, 186);
        LCD.WriteAt("_", 14, 186);
        LCD.WriteAt("_", 19, 186);
        LCD.WriteAt("|", 0, 210);

    //Right Vertical Border//
        LCD.WriteAt("|", 300, 17);
        //Ending Opening
        LCD.WriteAt(" ", 300, 30);
        LCD.WriteAt(" ", 300, 43);
        LCD.WriteAt("|", 300, 56);
        LCD.WriteAt("|", 300, 69);
        LCD.WriteAt("|", 300, 82);
        LCD.WriteAt("|", 300, 95);
        LCD.WriteAt("|", 300, 108);
        LCD.WriteAt("|", 300, 121);
        LCD.WriteAt("|", 300, 134);
        LCD.WriteAt("|", 300, 147);
        LCD.WriteAt("|", 300, 160);
        LCD.WriteAt("|", 300, 173);
        LCD.WriteAt("|", 300, 186);
        LCD.WriteAt("|", 300, 199);
        LCD.WriteAt("|", 300, 210);
   
    //int maze_x=9, maze_y=9;
    //char maze[maze_y][maze_x]={
     //   ' ', '_','_','_','_','_','_','_','_','_','_','_',
      //       '|','                                  ','|'
        //     };
    //cout<<maze;
}