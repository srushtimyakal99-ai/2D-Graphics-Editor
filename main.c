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
void drawLine(int x1, int y1, int x2, int y2)
{
    int i;

    if(y1 == y2)   // Horizontal line
    {
        for(i = x1; i <= x2; i++)
        {
            canvas[y1][i] = '*';
        }
    }
    else if(x1 == x2)   // Vertical line
    {
        for(i = y1; i <= y2; i++)
        {
            canvas[i][x1] = '*';
        }
    }
}

void drawTriangle(int x, int y, int height)
{
    int i, j;

    for(i = 0; i < height; i++)
    {
        for(j = -i; j <= i; j++)
        {
            canvas[y + i][x + j] = '*';
        }
    }
}
int main()
{
    initCanvas();
    drawRectangle(5, 3, 10, 5);
    drawLine(2, 15, 20, 15);
    drawTriangle(30, 2, 6);
    displayCanvas();
    return 0;
}


    