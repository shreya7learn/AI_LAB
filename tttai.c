#include<stdio.h>
#include<limits.h>

#define AI 'O'
#define Player 'X'

void printboard(char board[3][3]){
    for (int i = 0; i < 3; i++){
        for (int j =0; j < 3; j++){
            printf(" %c ",board[i][j]);
            if(j<2)printf("|");
            
        }printf("\n");
        if(i<2)printf("---+---+---+\n");
    }
}

int boardfull(char board[3][3]){
    for (int i = 0; i < 3; i++){
        for (int j =0; j < 3; j++){
            if(board[i][j]== ' ')return 0;
        }
}
return 1;
}

int checkwin(char board[3][3], char player){
    for (int i = 0; i < 3; i++)
    {
        if((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
          (board[0][i] == player && board[1][i] == player && board[2][i] == player)){
            return 1;
        }
    }
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
    ( board[0][2] == player && board[1][1] == player && board[2][0] == player))
    {
        return 1;
    }

    return 0;
}

int minimax(char board[3][3],int ismaximizing){
    if (checkwin(board,Player))
    {return -1;
    }
    if (checkwin(board,AI))
    {return 1;
    }
    if (boardfull(board))
    {
        return 0;
    }
    
    if (ismaximizing)
    {
        int bestscore = INT_MIN;
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                if(board[i][j]==' '){
                board[i][j]=AI;

                int score = minimax(board,0);
                board[i][j]=' ';
                if(score > bestscore){
                    bestscore=score;
                }
                }
            }
            
        }
        return bestscore;
        
    }
    else{
        int bestscore = INT_MAX;
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                if(board[i][j]==' '){
                board[i][j]=Player;

                int score = minimax(board,1);
                board[i][j]=' ';
                if(score < bestscore){
                    bestscore=score;
                }
                }
            }
            
        }
        return bestscore;
    }
}

void bestmove(char board[3][3],int *bestrow,int *bestcol){
    int bestscore = INT_MIN;
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                if(board[i][j]==' '){
                board[i][j]=AI;
                int score = minimax(board,0);
                board[i][j]=' ';
                if(score > bestscore){
                    bestscore=score;
                    *bestrow= i;
                    *bestcol= j;
                }
                }
            }
            
        }
}

int main(){
    char board[3][3]={
        {' ',' ',' '},
        {' ',' ',' '},
        {' ',' ',' '}
    };
    int currentplayer = 1;

    while (1)
    {
        printboard(board);
        if (currentplayer)
        {
            int row,col;
            printf("enter row and col between 1-3: " );
            scanf("%d %d", &row,&col);
            row--;
            col--;
            if ((board[row][col]!=' ') || (row < 0 || row >= 3 || col < 0 || col >= 3))
            {
                printf("invalid input\n");
                continue;
            }
            board[row][col]= Player;
        }
        else
        {
            int bestrow,bestcol;
            bestmove(board,&bestrow,&bestcol);
            board[bestrow][bestcol]= AI;
            printf("Ai chose postion: (%d,%d)\n",bestrow+1,bestcol+1);
        }

        if (checkwin(board,Player))
        {
            printboard(board);
            printf("you win\n");
            break;
        }
        if (checkwin(board,AI))
        {
            printboard(board);
            printf("Ai won\n");
            break;
        }
        if (boardfull(board))
        {
            printboard(board);
            printf("draw\n");
            break;
        }
        
        
        currentplayer = !currentplayer;
        
    }
    return 0;
    
}
