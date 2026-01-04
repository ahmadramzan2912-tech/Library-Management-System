#include<iostream>
#include<windows.h>
#include<cstdlib>
#include<ctime>
using namespace std;

void printPlayMap(char playMap[][41]);
bool playerMov(char choice, int &targetX, int &targetY);
void ghost1Mov(int &gTargetX1,int &gTargetY1,int direction1);
void ghost2Mov(int &gTargetX2,int &gTargetY2,int direction2);
void ghost3Mov(int &gTargetX3,int &gTargetY3,int direction3);
void printGameOver(int score);
void printWin(int score);

int main()
{
    srand(time(0));
    bool cond = true; 
    char playMap[20][41] = {
    "#######################################",
    "# . . . . . . . . # . . . . . . . . . #",
    "# . ### . ##### . # . ##### . ### . . #",
    "# O #   . #   # . # . #   # .   # . O #",
    "# . ### . ##### . # . ##### . ### . . #",
    "# . . . . . . . . . . . . . . . . . . #",
    "####### . # . ########### . # . #######",
    "#       . # . . . # . . . # .       . #",
    "####### . #####   #   ##### . ####### #",
    "#       . #               # .         #", 
    "####### . #####       ##### . ####### #",
    "#       . # . . . . . . . # .       . #",
    "####### . # . ########### . # . #######",
    "# . . . . . . . . # . . . . . . . . . #",
    "# . ### . ##### . # . ##### . ### . . #",
    "# O . # . . . . .   . . . . . # . . O #", 
    "##### # . # . ########### . # . # #####",
    "# . . . . # . . . # . . . # . . . . . #",
    "# . ########### . # . ########### . . #",
    "#######################################"
    };
    int x = 15, y = 18, gX1 = 9 , gY1 = 18 , gX2 = 9 , gY2 = 24 , gX3 = 9 , gY3 = 12 , score = 0;
    int targetX, targetY, gTargetX1, gTargetY1, gTargetX2, gTargetY2, gTargetX3, gTargetY3, direction1, direction2, direction3;
    char choice, temp1 = ' ', temp2 = ' ', temp3 = ' ';
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

    while(cond)
    {
        targetX = x, targetY = y, gTargetX1 = gX1, gTargetY1 = gY1, gTargetX2 = gX2, gTargetY2 = gY2, gTargetX3 = gX3, gTargetY3 = gY3;
        direction1 = rand() % 4, direction2 = rand() % 4,direction3 = rand() % 4;
        system("cls");
        
        SetConsoleTextAttribute(h, 14); 
        cout<<"Score: "<<score<<endl;
        SetConsoleTextAttribute(h, 7);

        playMap[x][y] = 'P'; playMap[gX1][gY1] = 'G'; playMap[gX2][gY2] = 'G'; playMap[gX3][gY3] = 'G';
        printPlayMap(playMap);
        playMap[x][y] = ' ';

        cout<<"Enter w/s/a/d :";
        cin>>choice;

        playerMov(choice,targetX,targetY);
        if(playMap[targetX][targetY] != '#')
        {if(playMap[targetX][targetY] == '.'){x = targetX; y = targetY ; score = score+5;}
        else{x = targetX; y = targetY;}}

        ghost1Mov(gTargetX1,gTargetY1,direction1);
        if(playMap[gTargetX1][gTargetY1] != '#')
        {if(playMap[gTargetX1][gTargetY1] == '.'){playMap[gX1][gY1] = temp1;gX1 = gTargetX1; gY1 = gTargetY1 ; temp1 = '.';}
        else{playMap[gX1][gY1] = temp1;gX1 = gTargetX1; gY1 = gTargetY1;temp1 = ' ';}}

        ghost2Mov(gTargetX2,gTargetY2,direction2);
        if(playMap[gTargetX2][gTargetY2] != '#')
        {if(playMap[gTargetX2][gTargetY2] == '.'){playMap[gX2][gY2] = temp2;gX2 = gTargetX2; gY2 = gTargetY2 ; temp2 = '.';}
        else{playMap[gX2][gY2] = temp2;gX2 = gTargetX2; gY2 = gTargetY2;temp2 = ' ';}}

        ghost3Mov(gTargetX3,gTargetY3,direction3);
        if(playMap[gTargetX3][gTargetY3] != '#')
        {if(playMap[gTargetX3][gTargetY3] == '.'){playMap[gX3][gY3] = temp3;gX3 = gTargetX3; gY3 = gTargetY3 ; temp3 = '.';}
        else{playMap[gX3][gY3] = temp3 ;gX3 = gTargetX3; gY3 = gTargetY3; temp3 = ' ';}}

        if(x == gX1 && y == gY1) {printGameOver(score); cond = false;}
        if(x == gX2 && y == gY2) {printGameOver(score); cond = false;}
        if(x == gX3 && y == gY3) {printGameOver(score); cond = false;}
        if(score == 740){printWin(score);cond = false;break;}
    }

}

void printPlayMap(char playMap[][41])
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    for(int i =0; i<20; i++)
    {
        cout<<"\t\t";
        for (int j=0; j<40; j++)
        {
            if(playMap[i][j] == '#') SetConsoleTextAttribute(h, 1); 
            else if(playMap[i][j] == 'P') SetConsoleTextAttribute(h, 14); 
            else if(playMap[i][j] == 'G') SetConsoleTextAttribute(h, 4);  
            else if(playMap[i][j] == '.') SetConsoleTextAttribute(h, 10); 
            else SetConsoleTextAttribute(h, 7); 
            
            cout<<playMap[i][j];
        }
        cout<<endl;
    }
    SetConsoleTextAttribute(h, 7); 
}

bool playerMov(char choice, int &targetX, int &targetY)
{
    if(choice == 'w'){targetX--;}
    else if(choice == 's'){targetX++;}
    else if(choice == 'a'){targetY--;}
    else if(choice == 'd'){targetY++;}
    else if(choice == 'q'){return false;}
    else{cout<<"Invalid choice";}
    return true;
}

void ghost1Mov(int &gTargetX1,int &gTargetY1,int direction1)
{
    if(direction1 == 0){gTargetX1--;}
    if(direction1 == 1){gTargetX1++;}
    if(direction1 == 2){gTargetY1--;}
    if(direction1 == 3){gTargetY1++;}
}

void ghost2Mov(int &gTargetX2,int &gTargetY2,int direction2)
{
    if(direction2 == 0){gTargetX2--;}
    if(direction2 == 1){gTargetX2++;}
    if(direction2 == 2){gTargetY2--;}
    if(direction2 == 3){gTargetY2++;}
}

void ghost3Mov(int &gTargetX3,int &gTargetY3,int direction3)
{
    if(direction3 == 0){gTargetX3--;}
    if(direction3 == 1){gTargetX3++;}
    if(direction3 == 2){gTargetY3--;}
    if(direction3 == 3){gTargetY3++;}
}

void printGameOver(int score)
{
    system("cls");
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, 4); 
    cout << "\n\n\n";cout << "\t\t  #####     #    #     # #######\n";cout << "\t\t #     #   # #   ##   ## #      \n";cout << "\t\t #        #   #  # # # # #      \n";
    cout << "\t\t #  #### #     # #  #  # #####  \n";cout << "\t\t #     # ####### #     # #      \n";cout << "\t\t #     # #     # #     # #      \n";
    cout << "\t\t  #####  #     # #     # #######\n";cout << "\n";cout << "\t\t ####### #     # ####### ###### \n";
    cout << "\t\t #     # #     # #       #     #\n";cout << "\t\t #     # #     # #       #     #\n";cout << "\t\t #     # #     # #####   ###### \n";
    cout << "\t\t #     #  #   #  #       #   #  \n";cout << "\t\t #     #   # #   #       #    # \n";cout << "\t\t #######    #    ####### #     #\n";
    SetConsoleTextAttribute(h, 14); cout << "\n\t\t FINAL SCORE: " << score << endl;SetConsoleTextAttribute(h, 7); 
}

void printWin(int score)
{
    system("cls");HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);SetConsoleTextAttribute(h, 10); 
    cout << "\t\t #     # ####### #     #    #    #     # ### #     # \n";cout << "\t\t  #   #  #     # #     #    #    #  #  #  #  ##    # \n";cout << "\t\t   # #   #     # #     #    #    #  #  #  #  # #   # \n";
    cout << "\t\t    #    #     # #     #    #    #  #  #  #  #  #  # \n";cout << "\t\t    #    #     # #     #    #    #  #  #  #  #   # # \n";cout << "\t\t    #    #     # #     #    #    #  #  #  #  #    ## \n";
    cout << "\t\t    #    #######  #####     #     ## ##  ### #     # \n";cout << "\n";SetConsoleTextAttribute(h, 14); 
    cout << "\t\t       CONGRATULATIONS! ALL DOTS COLLECTED!      \n"; cout << "\n\t\t            FINAL SCORE: " << score << "\n\n";SetConsoleTextAttribute(h, 7); 
}