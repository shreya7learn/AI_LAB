#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define size 3

void printboard(char board[size][size]){
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            printf(" %c ",board[i][j]);
            if (j<size-1){
                printf("|");
            }
        }
        printf("\n");
        if (i<size-1){
                printf("---+---+---\n");
            }     
    }
    
}

int checkwin(char board[size][size]){
    int row , col;
    for (int i = 0; i < size; i++)
    {
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
        return 1;
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ' )
        return 1;
    }

    if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
        return 1;
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ' )
        return 1;
    
    return 0;
}

int boardfull(char board[size][size]){
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            if(board[i][j] == ' ' ) return 0;
        }
    }
    return 1;
}

void usermove(char board[size][size]){
    int row,col;
    do{
    printf("enter row and col between 1-3: ");
    scanf("%d %d",&row ,&col );
    if(row < 1 || col < 1 || row > size || col > size || board[row-1][col-1] != ' '){
        printf("invalid input ");
    }
    }while(row < 1 || col < 1 || row > size || col > size || board[row-1][col-1] != ' ');
    board[row-1][col-1]='X';

}

void compmove(char board[size][size]){
    int row,col;
    do{
     row = rand() % size;
     col = rand() % size;
    }while(board[row][col] != ' ');
    board[row][col] = 'O';

}

int main(){
    char board[size][size]={
        {' ',' ',' '},
        {' ',' ',' '},
        {' ',' ',' '}
    };
    srand(time(0));

    printf("welcome to tic tac toe game!! \n");

    while(1){
        printboard(board);
        usermove(board);
        if(checkwin(board)){
            printboard(board);
            printf("you won\n");
            break;
        }
        if (boardfull(board))
        {
            printboard(board);
            printf("draw\n");
            break;
        }
        
        compmove(board);
        if(checkwin(board)){
            printboard(board);
            printf("computer won\n");
            break;
        }
        if (boardfull(board))
        {
            printboard(board);
            printf("draw\n");
            break;
        }
        
    }
    printf("thank you for playing");
    return 0;
}
