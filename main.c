#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
enum player{
    player_X,
    player_O
};

void displayboard(char board[3][3])
{
    for(int i = 0; i<3; i++)
    {
        for(int j =0; j<3; j++)
        {
            printf("[%c]", board[i][j]);
        }
        printf("\n");
    }
}
int makemove(enum player p,char board[3][3])
{
    int a,b;
    if(p == 0)
    {
        printf("Enter position: ");
        scanf("%d%d",&a,&b);

        if(board[a][b] == '-')
        {
            board[a][b] = 'X';
            return  1;
        }
        else{
            printf("Invalid position\n");
            return -1;
        }
    }
    else{
        printf("Enter position: ");
        scanf("%d%d",&a,&b);

        if(board[a][b] == '-')
        {
            board[a][b] = 'O';
            return  1;
        }
        else{
            printf("Invalid position\n");
            return -1;
        }

    }
    return 0;
}
char Wincheck(char board[3][3])
{
    for(int i = 0;i<3; i++)
    {
        if(board[i][0] == board[i][1] &&board[i][1] == board[i][2] && board[i][0] != '-')
        return board[i][0];
    }
    for(int j =0;j<3; j++)
    {
        if(board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != '-')
        {
            return board[0][j];
        }
    }

    if(board[0][0]!='-'&&board[1][1] == board[2][2] && board[0][0] == board[1][1])
    {
        return board[1][1];
    }
    if(board[0][2] != '-'&&board[0][2] == board[1][1] && board[1][1] == board[2][0])
    {
        return board[1][1];
    }

    return ' ';
}
int main()
{
    enum player p;
    char arr[3][3];
    for(int i = 0; i<3; i++)
    {
        for(int j = 0; j<3; j++)
        {
            arr[i][j] = '-';
        }
    }
    char s;
     char result;
    printf("Play?: Y/N: ");
    scanf("%c",&s);
    
    if(s == 'Y' || s == 'y')
    {
        displayboard(arr);
    printf("TIC-TAC-TOE\n");
    // printf("enter 0000 to exit\n");
    for(int i = 0; i<9;i++)
    {
        if(i%2 == 0)
        {
            int n = makemove(player_X, arr);
            if(n == -1)
            {
                i--;
            }
        }
        else
        {
            int n= makemove(player_O,arr);
            if(n == -1)
            {
                i--;
            }
        }displayboard(arr); 
        result=Wincheck(arr);
        if(result!=' ')
        {
            printf("The winner is  player: %c",result);
            break;
        }
    }
    if(result ==  ' ')
    {
        printf("The game Ends in Draw");
    }
    }
    else{
        printf("OK NO PROBELM");
    }
   
    }

