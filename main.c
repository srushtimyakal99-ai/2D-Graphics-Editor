#include<stdio.h>
#include<math.h>
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
    for(i=0;i<ROWS;i++)
    {
        for(j=0;j<COLS;j++)
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

void drawCircle(int centerX, int centerY, int radius)
{
    int x, y;

    for(y = 0; y < ROWS; y++)
    {
        for(x = 0; x < COLS; x++)
        {
            int dx = x - centerX;
            int dy = y - centerY;

            
            if(dx*dx + dy*dy <= radius * radius ) 
            {
                canvas[y][x] = '*';
            }
        }
    }
}
void deleteArea(int x, int y, int width, int height)
{
    int i, j;

    for(i = y; i < y + height; i++)
    {
        for(j = x; j < x + width; j++)
        {
            canvas[i][j] = '_';
        }
    }
}
void modifyRectangle(int oldX, int oldY,
                     int newX, int newY,
                     int width, int height)
{
    deleteArea(oldX, oldY, width, height);

    drawRectangle(newX, newY, width, height);
}

int main()
{
    initCanvas();
    drawRectangle(5, 3, 10, 5);
    drawLine(2, 15, 20, 15);
    drawTriangle(30, 2, 6);
    drawCircle(20,12,3);
    displayCanvas();
    int choice;

do
{
    printf("\n===== 2D Graphics Editor =====\n");
    printf("1. Draw Rectangle\n");
    printf("2. Draw Line\n");
    printf("3. Draw Triangle\n");
    printf("4. Draw Circle\n")
    printf("5. Delete Area\n");
    printf("6. Modify Rectangle\n");
    printf("7. Display Canvas\n");
    printf("8. Exit\n");

    printf("Enter choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            drawRectangle(5,3,10,5);
            displayCanvas();
            break; 

        case 2:
            drawLine(2,15,20,15);
            displayCanvas();
            break;

        case 3:
            drawTriangle(25,2,5);
            displayCanvas();
            break;

        case 4:
            drawCircle(20,12,3);
            displayCanvas();
            break;

        case 5:
            deleteArea(5,3,10,5);
            displayCanvas();
            break;

        case 6:
            modifyRectangle(5,3,15,5,10,5);
            displayCanvas();
            break;

        case 7:
            displayCanvas();
            break;

        case 8:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid Choice\n");
    }

} while(choice != 8);
    return 0;
}


    