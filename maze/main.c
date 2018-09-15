#include <stdio.h>
#include <stdlib.h>

void printSolution(string sol[x][y])
{ int i,j;
    for ( i = 0; i < x; i++)
    {
        for ( j = 0; j < y; j++)
            printf(" %d ", sol[i][j]);
        printf("\n");
    }
}

bool isSafe(string maze[x][y], int a, int b)
{

    if(a >= 0 && a < x && b >= 0 && b < y && maze[a][b] == '.')
        return true;



     return false;
}

bool solveMazeUtil(string maze[x][y], int a, int b, string sol[x][y])
{


    if(a >= 0 && a < x && b >= 0 && b < y && maze[a][b] == 'e')
    {
        sol[x][y] = 'e';
        return true;
    }
    if(isSafe(maze, x, y) == true)
    {
        sol[x][y] = 1;

        /* Move forward in x direction */
        if (solveMazeUtil(maze, a+1, b, sol) == true)
            return true;

        /* If moving in x direction doesn't give solution then
           Move down in y direction  */
        if (solveMazeUtil(maze, a, b+1, sol) == true)
            return true;

         else
        sol[a][b] = 0;
        return false;
    }


    return false;
}

int main()
{   int x,y,i,j;
    printf("enter index of array\n");
    scanf("%d%d",&x,&y);
    string maze[x][y];
    string sol [x][y];
    printf("enter array\n ");
    for ( i = 0; i < x; i++)
    {
        for ( j = 0; j < y; j++){
            scanf("%d", &maze[i][j]);
    }}
    for ( i = 0; i < x; i++)
    {
        for ( j = 0; j < y; j++){
         solveMazeUtil(maze,i,j,sol);
    }
    }
        printSolution(sol);

    return 0;
}
