#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#include<windows.h>
#include <unistd.h>
using namespace std;
const int a=25;
const int b=40;
int x,y,fx,fy,i,j;
int tailx[100],taily[100];
int tailn=0;
enum direction{stop=0,Left,Right,Up,Down};
direction dir;
int score;
bool go;
void setup()
{
go=false;
dir=stop;
x=a/2;
y=b/2;
fx=rand()%a;
fy=rand()%b;
score=0;
}
void welcome()
{
system("cls");
cout<<"WELCOME TO SNAKE GAME"<<endl;
cout<<"press any key to continue";
getch();
}
void rules()
{
system("cls");
cout<<"THIS IS RULES AND CONTROL"<<endl;
cout<<"@ RULES @"<<endl;
cout<<"1.If snake touch any wall gameover"<<endl;
cout<<"2.If snake touch his own body gameover "<<endl;
cout<<"enter any key to continue"<<endl;
getch();
}
void controls()
{
system("cls");
cout<<"Introduction to controls "<<endl;
cout<<"1.press w to move snake Up"<<endl;
cout<<"2.press a to move snake Left"<<endl;
cout<<"3.press s to move snake Down"<<endl;
cout<<"4.press d to move snake Right"<<endl;
cout<<"enter any key to continue"<<endl;
getch();
}
void draw()
{
    system("cls"); //system("clear");
    for (int i = 0; i < b+1; i++)
        cout << "#";
    cout << endl;
 
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            if (j == 0)
                cout << "#";
            if (i == x && j == y)
                cout << "O";
            else if (i == fx && j == fy)
                cout << "F";
            else
            {
                bool print = false;
                for (int k = 0; k < tailn; k++)
                {
                    if (tailx[k] == i && taily[k] == j)
                    {
                        cout << "o";
                        print = true;
                    }
                }
                if (!print)
                    cout << " ";
            }
                 
 
            if (j == b - 1)
                cout << "#";
        }
        cout << endl;
    }
 
    for (int i = 0; i < b+1; i++)
        cout << "#";
    cout << endl;
    cout << "Score:" << score << endl;
}
void input()
{
if(kbhit())
{
switch(getch())
{
case 'w':
dir=Up;
break;
case 'a':
dir=Left;
break;
case 's':
dir=Down;
break;
case 'd':
dir=Right;
break;
case 'q':
go=true;
break;

}
}

}
void logic()
{
int p1,p2,q1,q2;

p1=tailx[0];
p2=taily[0];
tailx[0]=x;
taily[0]=y;
for(int i=1;i<tailn;i++)
{
q1=tailx[i];
q2=taily[i];
tailx[i]=p1;
taily[i]=p2;
p1=q1;
p2=q2;

}
switch(dir)
{
case Up:
x--;
break;
case Left:
y--;
break;
case Right:
y++;
break;
case Down:
x++;
break;

}
if(x<0||x>a||y<0||y>b)
{
go=true;
}
for (int i = 0; i <tailn; i++)
        if (tailx[i] == x && taily[i] == y)
            go = true;
 
if(x==fx&&y==fy)
{
score++;
fx=rand()%a;
fy=rand()%b;
tailn++;
}
}
int main()
{
welcome();
rules();
controls();
setup();
while(go==false)
{
draw();
input();
logic();
usleep(20000);
}
return 0;
}