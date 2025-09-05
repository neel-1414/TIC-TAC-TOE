#include<stdio.h>
#include<stdlib.h>
enum player{
    player1,
    player2
};

void display(int board[3][3])
{
    for(int i = 0; i<3; i++)
    {
        for(int j =0; j<3; j++)
        {
            printf("[%d]", board[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    enum player p;
    int arr[3][3];
    printf("TIC-TAC-TOE");
    display(arr);

}