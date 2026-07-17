#include<stdio.h>
#include<conio.h>

// Initial Tic-Tac-Toe board
char board[3][3]= {
    {'1' ,'2' ,'3'},
    {'4' ,'5' ,'6'},
    {'7' ,'8' ,'9'}
};

// Function to print the board
void printBoard()
{
    printf("\n");

    for(int i=0; i<3; i++)
    {
        printf(" %c | %c | %c\n", board[i][0], board[i][1], board[i][2]);

        if(i!=2)
            printf("---|---|---\n");
    }
}

// Function for Player X
void choice_of_X()
{
    int num;

back_X:

    printf("\nPlayer X :- Enter a number between 1 to 9 : ");
    scanf("%d",&num);

    // Input validation
    if(num<1 || num>9)
    {
        printf("Enter a valid number.\n");
        goto back_X;
    }

    int row_X,col_X;

    row_X=(num-1)/3;
    col_X=(num-1)%3;

    // Check if position is already occupied
    if(board[row_X][col_X]=='X' || board[row_X][col_X]=='O')
    {
        printf("Space already occupied.\n");
        goto back_X;
    }

    board[row_X][col_X]='X';

    printBoard();
}

// Function for Player O
void choice_of_O()
{
    int num_O;

back_O:

    printf("\nPlayer O :- Enter a number between 1 to 9 : ");
    scanf("%d",&num_O);

    if(num_O<1 || num_O>9)
    {
        printf("Enter a valid number.\n");
        goto back_O;
    }

    int row_O,col_O;

    row_O=(num_O-1)/3;
    col_O=(num_O-1)%3;

    if(board[row_O][col_O]=='X' || board[row_O][col_O]=='O')
    {
        printf("Space already occupied.\n");
        goto back_O;
    }

    // Place O
    board[row_O][col_O]='O';

    printBoard();
}

// Returns 1 if somebody wins else 0
int result()
{
    int i;

    // Check all rows
    for(i=0;i<3;i++)
    {
        if(board[i][0]=='X' && board[i][1]=='X' && board[i][2]=='X')
        {
            printf("\nPlayer X Wins!\n");
            return 1;
        }

        if(board[i][0]=='O' && board[i][1]=='O' && board[i][2]=='O')
        {
            printf("\nPlayer O Wins!\n");
            return 1;
        }
    }

    // Check all columns
    for(i=0;i<3;i++)
    {
        if(board[0][i]=='X' && board[1][i]=='X' && board[2][i]=='X')
        {
            printf("\nPlayer X Wins!\n");
            return 1;
        }

        if(board[0][i]=='O' && board[1][i]=='O' && board[2][i]=='O')
        {
            printf("\nPlayer O Wins!\n");
            return 1;
        }
    }

    // Main diagonal
    if(board[0][0]=='X' && board[1][1]=='X' && board[2][2]=='X')
    {
        printf("\nPlayer X Wins!\n");
        return 1;
    }

    if(board[0][0]=='O' && board[1][1]=='O' && board[2][2]=='O')
    {
        printf("\nPlayer O Wins!\n");
        return 1;
    }

    // Other diagonal
    if(board[0][2]=='X' && board[1][1]=='X' && board[2][0]=='X')
    {
        printf("\nPlayer X Wins!\n");
        return 1;
    }

    if(board[0][2]=='O' && board[1][1]=='O' && board[2][0]=='O')
    {
        printf("\nPlayer O Wins!\n");
        return 1;
    }

    return 0;
}

int main()
{
    int moves=0;

    printf("===== TIC TAC TOE =====\n");

    printBoard();

    while(moves<9)
    {
        // Player X turn
        choice_of_X();
        moves++;

        // Win is possible only after 5th move
        if(moves>=5 && result())
            return 0;

        if(moves==9)
            break;

        // Player O turn
        choice_of_O();
        moves++;

        if(moves>=5 && result())
            return 0;
    }

    printf("\nMatch Draw!\n");

    return 0;
}