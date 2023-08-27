#include <stdio.h>
#include <strings.h>
#include <conio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include <time.h>
void input(int **);
void display(int **);
bool checkGame(int **);
void rule(char *);
void result(char *, int);
int StartGame(int **, int);
int readKey();

void textcolour(int clr)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), clr);
}
int readKey()
{
    char c;
    c = _getch();
    if (c == -32)
        c = _getch();
    return c;
}
void rule(char *name)
{
    textcolour(1);
    printf("\n\t\t HeY !! %s\n", name);
    textcolour(4);
    printf("\t\t RULE OF THIS GAME\n\t\t -----------------");
    printf("\n");
    textcolour(2);
    printf("1. You can move only 1 step at a time with the arrow key.\n");
    textcolour(7);
    printf("Move up   : by Up Arrow key\n");
    printf("Move down : by Down Arrow key\n");
    printf("Move left : by Left Arrow key\n");
    printf("Move right: by Right Arrow key\n");
    textcolour(2);
    printf("2. You can move numbers at an empty position only\n");
    printf("3. For each valid move : your total number of moves will decrease by 1.\n");
    printf("4. Winning situation : number in a 4*4 matrix should be in order from 1 to 15.");
    textcolour(3);
    printf("\n\t\t WINNING SITUATION :\n");
    textcolour(7);
    printf("---------------------\n");
    int demo[4][4];
    for (int i = 0; i < 4; i++)
    {
        printf("|");
        for (int j = 0; j < 4; j++)
        {
            demo[i][j] = 4 * i + j + 1;
            // y++;
            if (demo[i][j] < 10)
                printf(" %d  |", demo[i][j]);
            else if (demo[i][j] != 16)
                printf(" %d |", demo[i][j]);
            else
            {
                demo[i][j] = ' ';
                printf("    |");
                break;
            }
        }
        printf("\n");
    }
    printf("---------------------\n");
    textcolour(2);
    printf("5. You can exit the game at any time by pressing 'esc' (escape key).\n");
    printf("So Try to win in minimum no of move");
    textcolour(5);
    printf("\n\n\t\t HAPPY GAMING , GOOD LUCK:");
    textcolour(7);
    printf("\n\nEnter any key to start......");
    getch();
}
void input(int **q)
{
    srand(time(0));
    int c[16];
    for (int i = 0; i < 16; i++)
    {
        int t = rand() % 16 + 1;
        int j = 0;
        for (j = 0; j <= i - 1; j++)
        {
            if (t == c[j])
                break;
        }
        if (j == i)
            c[i] = t;
        else
            i--;
    }
    int m = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            q[i][j] = c[m];
            m++;
        }
    }
    for (int i = 0; i < 4; i++)
    {
        int j;
        for (j = 0; j < 4; j++)
        {
            if (q[i][j] == 16)
            {
                int temp = q[3][3];
                q[3][3] = 16;
                q[i][j] = temp;
                break;
            }
        }
        if (j != 4)
        {
            break;
        }
    }
}
void display(int **q)
{
    printf("\n---------------------\n");
    for (int i = 0; i < 4; i++)
    {
        printf("|");
        for (int j = 0; j < 4; j++)
        {
            if (q[i][j] < 10)
            {
                printf(" %d  |", q[i][j]);
            }
            else
            {
                if (q[i][j] == 16)
                {
                    // q[i][j] = '_';    //ASCII code of '_' = 137
                    printf(" _  |");
                }
                else
                    printf(" %d |", q[i][j]);
            }
        }
        printf("\n");
    }
    printf("---------------------\n");
}
bool checkGame(int **q)
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (q[i][j] != 4 * i + j + 1)
                return false;
        }
    }
    return true;
}
int StartGame(int **q, int move)
{
   
    int i = 3;
    int j = 3;
    for (int k = move; k > 0; k--)
    {
        char press;
        press = readKey();
        switch (press)
        {
        case 72: // upward key
        {
            if (i - 1 >= 0)
            {
                int temp = q[i][j];
                q[i][j] = q[i - 1][j];
                q[i - 1][j] = temp;
                i--;
                system("cls");
            }
            else
            {
                printf("\nUpward Not Possible");
                k++;
            }
            break;
        }
        case 80: // downward key
        {
            if (i + 1 < 4)
            {
                int temp = q[i][j];
                q[i][j] = q[i + 1][j];
                q[i + 1][j] = temp;
                i++;
                system("cls");
            }
            else
            {
                printf("\nDownward Not Possible");
                k++;
            }
            break;
        }
        case 77: // rightward key
        {
            if (j + 1 < 4)
            {
                int temp = q[i][j];
                q[i][j] = q[i][j + 1];
                q[i][j + 1] = temp;
                j++;
                system("cls");
            }
            else
            {
                printf("\nRightward Not Possible");
                k++;
            }
            break;
        }
        case 75: // leftward key
        {
            if (j - 1 >= 0)
            {
                int temp = q[i][j];
                q[i][j] = q[i][j - 1];
                q[i][j - 1] = temp;
                j--;
                system("cls");
            }
            else
            {
                printf("\nLeftward Not Possible");
                k++;
            }
            break;
        }
        case 27:
        {
            return 0;
        }
        default:
        {
            printf("Press Valid Key\n");
            k++;
        }
        }
        //system("cls");
        textcolour(6);
        display(q);
        textcolour(2);
        printf("%d moves left \n", k - 1);
        if (checkGame(q))
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    printf("Enter your Name :");
    char name[30];
    fgets(name, 30, stdin);
    int len = strlen(name);
    name[len - 1] = '\0';
    strcpy(name, strupr(name));
    rule(name); // fuction call

    system("cls"); // for clear the screen
    int arr[4][4];
    int *p[4];
    for (int i = 0; i < 4; i++)
    {
        p[i] = arr[i];
    }
    while (1)
    {
        textcolour(3);
        printf("\n%s", name);
        int move = 20;
        printf(" ,You have only %d moves to win this game\n", move);
        input(p);
        textcolour(6);
        display(p);
        int cup;
        cup = StartGame(p, move);
        result(name, cup);
        textcolour(10);
        int choice;
        while (1)
        {
            printf("\n if you want to play again");
            printf("\n1.Yes");
            printf("\n2.No");

            choice = readKey();
            switch (choice)
            {
            case '1':
                printf("\n Starting new GAME:");
                break;
            case '2':
                break;
            default:
                printf("\nPlease choose correct option\n");
            }
            if (choice == '1' || choice == '2')
                break;
        }
        if (choice == '2')
            break;
    }
    textcolour(7);
    printf("\n %s ,ThankYou For Coming.", name);
    printf("\n BYE ! See You.");
    return 0;
}
void result(char *name, int cup)
{
    if (cup == 1)
    {
        textcolour(7);
        printf("\nYehh !!! \nCongratulation %s \nYOU WIN THIS GAME", name);
    }
    else
    {
        textcolour(4);
        printf("\n Ohhh ! \n %s ,You LOOSE THIS GAME\n", name);
    }
}
