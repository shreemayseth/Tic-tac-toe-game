#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>

char mat[3][3]={'1','2','3','4','5','6','7','8','9'};
char player1[20],player2[20];
int count=0;

void board(){
    int i,j;
    printf("\n\n%s :[X]\t\t\t\t\t\t\t %s :[O]",player1,player2);
    printf("\n\n\n");
    for(i=0;i<3;i++){
       printf("\t\t\t\t    |    |   \n\t\t\t\t");
        for(j=0;j<3;j++){
            printf(" %c",mat[i][j]);
                if(j<2)
                printf("  |");
                }
        if(i==2)
            printf("\n\t\t\t\t    |    |  \n\n");
        else
            printf("\n\t\t\t\t____|____|____\n");
    }
}

void input(char pos){
    int i,j;
    system("color 0c");
    if(count%2==0){
        printf("Enter your position no. %s: ",player1);
        fflush(stdin);
        scanf("%c",&pos);
          for(i=0;i<3;i++){
            for(j=0;j<3;j++){
                if(mat[i][j]==pos){
                  mat[i][j]='X';
             }
        }
    }
}

    else {
    printf("Enter your position no. %s: ",player2);
    fflush(stdin);
    scanf("%c",&pos);
    for(i=0;i<3;i++){
      for(j=0;j<3;j++){
        if(mat[i][j]==pos){
            mat[i][j]='O';
            }
          }
        }
      }
}

int checkwin(){
    int i,x,o;
    for(i=0;i<3;i++){
        if(mat[i][0]=='X' && mat[i][1]=='X' && mat[i][2]=='X'|| mat[0][i]=='X' && mat[1][i]=='X' && mat[2][i]=='X'||
           mat[0][2]=='X' && mat[1][1]=='X' && mat[2][0]=='X' || mat[0][0]=='X' && mat[1][1]=='X'&& mat[2][2]=='X'){
               return 100;
           }
        else if(mat[i][0]=='O'&& mat[i][1]=='O' && mat[i][2]=='O' || mat[0][i]=='O' && mat[1][i]=='O' && mat[2][i]=='O'||
           mat[0][2]=='O' && mat[1][1]=='O' && mat[2][0]=='O' || mat[0][0]=='O' && mat[1][1]=='O'&& mat[2][2]=='O'){
               return 200;
           }
        }
        return 300;
}

void gotoxy(int x,int y){
    COORD c;
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}

void mov(){
int i,x=0,y=15;
 for(i=0;i<50;i++){
    gotoxy(x,y);
    printf("Loading......");
    Sleep(100);
    system("cls");

    x++;
    }
}

void title(){
    int i,j,x=20,y=8;
    for(i=0;i<3;i++){
        gotoxy(x,y);
        system("color 0c");

    printf("\n********************************************************************************\n");
    printf("  _______ _______  _____    _______  ____   _____    _______  _____   ____   \n");
    printf("     |       |    |            |    |    | |            |    |     | |      \n");
    printf("     |       |    |            |    |----| |            |    |     | |---   \n");
    printf("     |    ___|___ |_____       |    |    | |_____       |    |_____| |____  \n\n");
    printf("********************************************************************************\n");
    Sleep(1000);
    system("cls");
    printf("   ");
    Sleep(500);
    }
mov();
}

void menu(){

    system("color 1c");
    int ch,who;
    system("cls");
    printf("\n\n");
    printf("********************************************************************************\n");
    printf("                               TIC TAC TOE                                      \n");
    printf("********************************************************************************\n");
    printf("\n                    ---------------------------");
    printf("\n                           MAIN MENU           ");
    printf("\n                    ---------------------------");
    printf("\n               >>>> 1:Start the game.... \n");
    printf("\n               >>>> 2:How to play....\n");
    printf("\n               >>>> 3:Exit....\n");
    printf("\n\n\nEnter your choice : ");
    fflush(stdin);
    scanf("%d",&ch);
    switch(ch)
    {
        case 1: system("cls");
                printf("\n\n\nEnter player1 name:");
                scanf("%s",&player1);
                fflush(stdin);
                printf("\nEnter player2 name:");
                scanf("%s",&player2);
                fflush(stdin);
                printf("\n\n%s your symbol is :[X]",player1);
                printf("\n\n%s your symbol is :[O]",player2);
                printf("\n\n\t\t\tLETS BEGIN THE GAME.....\n\n\n\n");
                system("pause");
                break;

        case 2: system("cls");
                system("color 0e");
                printf("\n\n<---------------------------How to play------------------------->\n");
                printf("\n1. First you have to enter player1 and player2 names. \n\n");
                printf("2. Player1 will be 'X' and Player2 will be 'O'.\n\n");
                printf("3. Player1 will always start the game followed by player2.\n\n");
                printf("4. In the 3x3 board the players need to choose the location number in which they   want to place their symbol\n\n");
                printf("5. Alternative chance will be given to both the players.\n\n");
                printf("6. Both players have to play until they get three in a row with their respective   symbols.\n\n");
                printf("7. The one who get three in a horizontal ,vertical or diagonal row will wins the   game.\n\n");
                printf("8. Otherwise game will get draw.\n\n\n");
                system("pause");
                menu();
                break;

        case 3: exit(0);

    }
}

int main(){

  int a,i,j;
  char pos,ch;
  Beep(1500,500);
  Beep(1000,500);
  Beep(900,400);
  Beep(800,200);
  Beep(1000,300);
  title();

while(1){
  menu();

  label1:
  system("cls");
  board();
  input(pos);

  label:
  system("cls");
  board();
  count++;
  Beep(9000,100);
  input(pos);
  board();
  a=checkwin();
  system("cls");
  board();
  if(count<8){

    if(a==100){
            system("color 4e");
            printf("\n\n\n\t\t    Congratulations %s you won the game!!!!\n",player1);
            count=0;
        }
    else if(a==200){
            system("color 4e");
            printf("\n\n\n\t\t    Congratulations %s you won the game!!!!\n",player2);
            count=0;
        }
     else{
          goto label;
         }
  }
   else{
        system("color 3e");
        printf("\n\n\n\t\t\t\tGAME DRAWN!!!!");
        count=0;
    }

printf("\n\n\nDo you want to play again..?? Press y for Yes or n for No\n");
fflush(stdin);
scanf("%s",&ch);
if(ch=='y'|| ch=='Y')
    {
        mat[0][0]='1';
        mat[0][1]='2';
        mat[0][2]='3';
        mat[1][0]='4';
        mat[1][1]='5';
        mat[1][2]='6';
        mat[2][0]='7';
        mat[2][1]='8';
        mat[2][2]='9';
        goto label1;
   }
   else{
        mat[0][0]='1';
        mat[0][1]='2';
        mat[0][2]='3';
        mat[1][0]='4';
        mat[1][1]='5';
        mat[1][2]='6';
        mat[2][0]='7';
        mat[2][1]='8';
        mat[2][2]='9';
        }
    }
    return 0;
}



