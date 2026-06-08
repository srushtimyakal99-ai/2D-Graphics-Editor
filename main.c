#include<stdio.h>
#define ROWS 20
#define COLS 40
char canvas[ROWS][COLS];
void initCanvas()
{
    int i,j;
for(i=0;i<ROWS;i++)
{
 for(j=0;j<COLS;j++)
    {
        canvas[i][j]='_';
    }
}

}
void displayCanvas()
{
    int i,j;
    for(int i=0;i<ROWS;i++)
    {
        for(int j=0;j<COLS;j++)
        {
            printf("%c",canvas[i][j]);
        }
        printf("\n");
    }
}
void drawRectangle(int x, int y, int width, int height)
{
    int i;

    for(i = x; i < x + width; i++)
    {
        canvas[y][i] = '*';
        canvas[y + height - 1][i] = '*';
    }

    for(i = y; i < y + height; i++)
    {
        canvas[i][x] = '*';
        canvas[i][x + width - 1] = '*';
    }
}
int main()
{
    initCanvas();
    drawRectangle(5, 3, 10, 5);
    displayCanvas();
    return 0;
}


    