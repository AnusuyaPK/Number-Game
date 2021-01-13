#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

void swap_init(int* board,int count,int size);
void swap(int row1,int col1,int row2,int col2,int* board,int size);
void print_board(int* board,int size);
int check(int* board,int size);

struct indx
{
    int row;
    int col;
}s;

int check(int* board,int size)
{
    for(int x=1;x<size*size;x++)
    {
        if(*(board+x)<*(board+(x-1)))
        {
            return 0;
        }
    }
    return 1;
}

void print_board(int* board,int size)
{
    for(int r=0;r<size;r++)
    {
        for(int c=0;c<size;c++)
        {
            if(*(board+((r*size)+c))==size*size)
            {
                printf("     ");
            }
            else
            {
                printf("%4d ",*(board+((r*size)+c)));
            }
        }
        printf("\n");
    }

}

void swap(int row1,int col1,int row2,int col2,int* board,int size)
{
    int temp;
    temp = *(board+((row1*size)+col1));
    *(board+((row1*size)+col1)) = *(board+((row2*size)+col2));
    *(board+((row2*size)+col2)) = temp;
}

void swap_init(int* board,int count,int size)
{

    int row = 0,col = 0,f = 0;
    for(row=0;row<size;row++)
    {
        for(col=0;col<size;col++)
        {
            if(*(board+((row*size)+col)) == (size*size))
            {
                f = 1;
                break;
            }
        }
        if(f)
        {
            break;
        }
    }
    char movements[4] = {'u','d','r','l'};
    while(1)
    {
    char ch = movements[rand()%4];
    if(ch == 'd' && row-1>=0)
    {
    swap(row,col,row-1,col,board,size);//down swap
    row--;
    count--;
    if(count<0) break;
    }

    else if(ch == 'r' && col-1>=0 )
    {
    swap(row,col,row,col-1,board,size);//right swap
    col--;
    count--;
    if(count<0) break;
    }

    else if(ch == 'u' && row+1<size)
    {
    swap(row,col,row+1,col,board,size);//up swap
    row++;
    count--;
    if(count<0) break;
    }

    else if(ch == 'l' && col+1<size)
    {
    swap(row,col,row,col+1,board,size);//left swap
    col++;
    count--;
    if(count<0) break;
    }
    }
    s.row = row;
    s.col = col;
    print_board(board,size);

}

int main()
{
    int size;
    printf("Instructions:\n");
    printf("1 Initially select any size of box you want to play!\n");
    printf("2 Choose the complexity level\n");
    printf("3 You can use  the following arrow keys to move the numners:\n");
    printf("  RIGHT ARROW to move the number right\n");
    printf("  LEFT ARROW to move the number left\n");
    printf("  UP ARROW to move the number up\n");
    printf("  DOWN ARROW to move the number down\n");
    printf("4 Press 1 to start the game and Press 0 key to quit the game\n");

    char token;
    int complx;
    scanf("%c",&token);
    if(token=='1')
    {
        system ("cls");
        printf("GAME BEGINS NOW!!\n");
        printf("Enter n value (n*n): ");
        scanf("%d",&size);
        if(size<1)
        {
            printf("Enter a valid size: ");
            scanf("%d",&size);
        }
        printf("YOUR COMPLEXITY:\n");
        printf("1 EASY\n");
        printf("2 MEDIUM\n");
        printf("3 HARD\n");

        scanf("%d",&complx);
        printf("HERE IS YOUR BOARD:\n");

        int board[size][size];
        int count = 1;
        for(int r=0;r<size;r++)
        {
            for(int c=0;c<size;c++)
            {
                board[r][c] = count;
                count++;
            }
        }
        if(complx == 1)
        {
            swap_init(board,20,size);
        }
        else if(complx == 2)
        {
            swap_init(board,30,size);
        }
        else if(complx == 3)
        {
            swap_init(board,50,size);
        }

        char move;
        while(1)
        {
            move = getch();
            if(move == 72)
            {
                if(s.row+1<size)
                {
                    swap(s.row,s.col,s.row+1,s.col,board,size);//up swap
                    s.row++;
                    printf("\e[1;1H\e[2J");
                    print_board(board,size);
                }
                else
                {
                    printf("\a");
                }
            }
            else if(move == 80)
            {
                if(s.row-1>=0)
                {
                    swap(s.row,s.col,s.row-1,s.col,board,size);//down swap
                    s.row--;
                    printf("\e[1;1H\e[2J");
                    print_board(board,size);
                }
                else
                {
                    printf("\a");
                }
            }
            else if(move == 75)
            {
                if(s.col+1<size)
                {
                    swap(s.row,s.col,s.row,s.col+1,board,size);//left swap
                    s.col++;
                    printf("\e[1;1H\e[2J");
                    print_board(board,size);
                }
                else
                {
                    printf("\a");
                }
            }
            else if(move == 77)
            {
                if(s.col-1>=0)
                {
                    swap(s.row,s.col,s.row,s.col-1,board,size);//right swap
                    s.col--;
                    printf("\e[1;1H\e[2J");
                    print_board(board,size);
                }
                else
                {
                    printf("\a");
                }
            }
            else if(move == '0')
            {
                printf("QUITING...");
                break;
            }
            if(check(board,size))
            {
                printf("CONGRATS!!\n");
                printf("YOU WON THE GAME\n");
                break;
            }
        }
    }
    else if(token=='0')
    {
        printf("QUITING...");
    }

}
