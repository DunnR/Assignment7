#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
typedef enum { false, true } bool;

int const MAXGAME = 9;
int gameCount = 0;


//[rows] [cols]
char board [3] [3] = 
     {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'}
     };
     
int randSelect(int seedNum)
{
    //use to randomly select spot on the board
    srand(seedNum);
    int r = rand()%3;
    return r;
}     
     
     
void createBoard()
{
    printf("%c | %c | %c\n", board[0] [0], board[0] [1], board[0] [2]);
    printf("--|---|--\n");
    printf("%c | %c | %c\n", board[1] [0], board[1] [1], board[1] [2]);
    printf("--|---|--\n");
    printf("%c | %c | %c\n\n", board[2] [0], board[2] [1], board[2] [2]);
}


void chooseSpaceC()
{
    int selectRow;
    int selectCol;
    bool spaceChosen = false;
    int randRowSeed = rand();
    int randColSeed = rand();
    
    while(spaceChosen == false)
    {
         if(board[selectRow = randSelect(randRowSeed)] [selectCol = randSelect(randColSeed)] == 'C')
         {
            break; 
         }
         else
         {
             board[selectRow] [selectCol] = 'C';
             spaceChosen = true;
         }
    }
    
    printf("\n\n Randint: %d / %d \n\n", randColSeed, randRowSeed);

    
    createBoard();
}

void chooseSpaceP()
{
    int selectRow;
    int selectCol;
    bool spaceChosen = false;
    int randRowSeed = rand();
    int randColSeed = rand();
    
    while(spaceChosen == false)
    {
         if(board[selectRow = randSelect(randRowSeed)] [selectCol = randSelect(randColSeed)] == 'P')
         {
            break; 
         }
         else
         {
             board[selectRow] [selectCol] = 'P';
             spaceChosen = true;
         }
    }
    
    printf("\n\n Randint: %d / %d \n\n", randColSeed, randRowSeed);

    
    createBoard();
}



void winCheck(char arr[][3])
{
    if((arr[0][0] && arr[1][1] && arr[2][2] == 'P') || (arr[0][2] && arr[1][1] && arr[2][0] == 'P'))
    {
        //Diagonal win
        printf("Parent is the winner");
    }
    else if((arr[0][0] && arr[1][0] && arr[2][0] == 'P') || (arr[0][1] && arr[1][1] && arr[2][1] == 'P') ||
            (arr[0][2] && arr[1][2] && arr[2][2] == 'P'))
            {
                //Down line win
                printf("Parent is the winner");
            }
    else if((arr[0][0] && arr[0][1] && arr[0][2] == 'P') || (arr[1][0] && arr[1][1] && arr[1][2] == 'P') ||
            (arr[2][0] && arr[2][1] && arr[2][2] == 'P'))
            {
                //Across line win
                printf("Parent is the winner");
            }
            
            
    if((arr[0][0] && arr[1][1] && arr[2][2] == 'C') || (arr[0][2] && arr[1][1] && arr[2][0] == 'C'))
    {
        //Diagonal win
        printf("Child is the winner");
    }
    else if((arr[0][0] && arr[1][0] && arr[2][0] == 'C') || (arr[0][1] && arr[1][1] && arr[2][1] == 'C') ||
            (arr[0][2] && arr[1][2] && arr[2][2] == 'C'))
            {
                //Vertical line win
                printf("Child is the winner");
            }
    else if((arr[0][0] && arr[0][1] && arr[0][2] == 'C') || (arr[1][0] && arr[1][1] && arr[1][2] == 'C') ||
            (arr[2][0] && arr[2][1] && arr[2][2] == 'C'))
            {
                //Horizontal line win
                printf("Child is the winner");
            }
   
    
}


int main(int argc, char** argv)
{
    
    srand (time(NULL));
    chooseSpaceC();
    chooseSpaceC();
    chooseSpaceC();
    winCheck(board);
    
    
    return 0;
}