#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <zconf.h>


//#define WIDTH 61
#define WIDTH 151
#define HEIGHT 91
//#define HEIGHT 31

#define PI 3.14159265

#define MAX_V 1000

#define QUIT            'q'

#define DEFAULT_COLOR   'X'
#define BACKGROUND_COLOR ' '

#define CLEAR_SCREEN    'c'
#define ANALYTIC_LINE   'a'
#define DDA_LINE        'd'
#define BRESENHAM_LINE  'b'
#define PARAM_CIRCLE    'p'
#define INCREMENTAL_CIRCLE 'i'
#define BRESENHAM_CIRCLE 'B'

#define FLOOD_FILL_1      'f'
#define FLOOD_FILL_2      'F'
#define GEOMETRIC_FILL  'g'

#define WRITE_PHRASE  'w'
#define DRAW_POLYGON  'D'

#define FIGURA_A        '1'
#define FIGURA_B        '2'
#define FIGURA_C        '3'
#define FIGURA_D        '4'
#define FIGURA_E        '5'
#define FIGURA_F        '6'
#define FIGURA_G        '7'

#define CUT_1           '%'
#define CUT_2           '$'
#define CUT_3           '#'
#define CUT_4           '@'

#define SUTHERLAND_CUT  's'


#define BEZIER 'Z'
#define CASTELJAU 'C'

int screen[HEIGHT][WIDTH] = {0};

void printScreen();
void clearScreen();
void analiticsLine(int x1, int y1, int x2, int y2, char color);
void ddaLine(int x1, int y1, int x2, int y2, char color);
void bresenhamLine(int x1, int y1, int x2, int y2, char color);
void paramCircle(int xc, int yc, int ray, char color);
void incrementalCircle(int xc, int yc, int ray, char color);
void bresenhamCircle(int xc, int yc, int ray, char color);

void drawPolygon(int * x, int * y, int nDots, char color);

void floodFill1(int x, int y, char color);
void floodFill2(int x, int y, char color1, char color2);
void geometricFill(int * x, int * y, int nDots, char color);

int getScreenColor(int x, int y);
void colorDot(int x, int y, char color);

void turninto(char color1, char color2);


void dcc();

void writeScreen(char string[MAX_V], char color, int x0, int y0, int width, int heith);

void bezier(int nDots, int * xs, int * ys, char color);
void casteljau(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4, float stop, int var);


void sutherland(int *xs, int *ys, int nDots, int *squarexs, int *squareys, int side);

int  _x[MAX_V], _y[MAX_V], _nDots;
double __x[MAX_V], __y[MAX_V];
int helperCoordsX[MAX_V];
int helperCoordsY[MAX_V];

int main()
{
    char command;
    int coords[4];
    float stop;
    char color, color2;
    clearScreen();
    char write_[MAX_V];




    int a = -60;/*
    while(1)
    {
        clearScreen();
        writeScreen("welcome", '#', a, 45, 5, 7);
        printScreen();
        usleep(10000);
        a++;
        if(a == 55) break;
    }
    usleep(1000000);*/
    clearScreen();
    dcc();
    printScreen();
    getc(stdin);
    clearScreen();

    int i = 2;
    while(1)
    {
        system("clear");
        printScreen();
        printf("What would you like to draw? ");
        setbuf(stdin, NULL);
        scanf("%c", &command);


        switch (command)
        {
            case QUIT:
                a = -60;
                while(1)
                {
                    clearScreen();
                    writeScreen("good bye", '#', a, 45, 5, 7);
                    printScreen();
                    usleep(10000);
                    a++;
                    if(a == 50) break;
                }

                usleep(1000000);
                exit(0);
            case CLEAR_SCREEN:
                clearScreen();
                break;
            case ANALYTIC_LINE:
                setbuf(stdin, NULL);
                printf("Analytics line Coords (x1 y1 x2 y2 color): ");
                scanf("%d %d %d %d %c", &coords[0], &coords[1], &coords[2], &coords[3], &color);
                analiticsLine(coords[0], coords[1], coords[2], coords[3], color);
                break;
            case DDA_LINE:
                setbuf(stdin, NULL);
                printf("DDA line Coords (x1 y1 x2 y2 color): ");
                scanf("%d %d %d %d %c", &coords[0], &coords[1], &coords[2], &coords[3], &color);
                ddaLine(coords[0], coords[1], coords[2], coords[3], color);
                break;
            case BRESENHAM_LINE:
                setbuf(stdin, NULL);
                printf("Bresenham line Coords (x1 y1 x2 y2 color): ");
                scanf("%d %d %d %d %c", &coords[0], &coords[1], &coords[2], &coords[3], &color);
                bresenhamLine(coords[0], coords[1], coords[2], coords[3], color);
                break;
            case PARAM_CIRCLE:
                setbuf(stdin, NULL);
                printf("Param circle Coords (xc yc ray color): ");
                scanf("%d %d %d %c", &coords[0], &coords[1], &coords[2], &color);
                paramCircle(coords[0], coords[1], coords[2], color);
                break;
            case INCREMENTAL_CIRCLE:
                setbuf(stdin, NULL);
                printf("Incremental circle Coords (xc yc ray color): ");
                scanf("%d %d %d %c", &coords[0], &coords[1], &coords[2], &color);
                incrementalCircle(coords[0], coords[1], coords[2], color);
                break;
            case BRESENHAM_CIRCLE:
                setbuf(stdin, NULL);
                printf("Bresenham circle Coords (xc yc ray color): ");
                scanf("%d %d %d %c", &coords[0], &coords[1], &coords[2], &color);
                bresenhamCircle(coords[0], coords[1], coords[2], color);
                break;
            case FIGURA_A:
                _x[0] = 5, _y[0] = 30;
                _x[1] = 45, _y[1] = 45;
                _x[2] = 95, _y[2] = 20;
                _x[3] = 90, _y[3] = 10;
                _x[4] = 15, _y[4] = 5;
                _x[5] = 35, _y[5] = 18;
                _x[6] = 5, _y[6] = 30;
                _nDots = 7;
                drawPolygon(_x,_y, _nDots, DEFAULT_COLOR);
                break;
            case FIGURA_B:
                _x[0] = 5, _y[0] = 40;
                _x[1] = 45, _y[1] = 50;
                _x[2] = 95, _y[2] = 40;
                _x[3] = 97, _y[3] = 20;
                _x[4] = 45, _y[4] = 5;
                _x[5] = 30, _y[5] = 25;
                _x[6] = 60, _y[6] = 30;
                _x[7] = 55, _y[7] = 18;
                _x[8] = 15, _y[8] = 15;
                _x[9] = 5, _y[9] = 40;
                _nDots = 10;
                drawPolygon(_x,_y, _nDots, DEFAULT_COLOR);
                break;
            case FIGURA_C:
                _x[0] = 5, _y[0] = 45;
                _x[1] = 40, _y[1] = 45;
                _x[2] = 50, _y[2] = 40;
                _x[3] = 55, _y[3] = 45;
                _x[4] = 95, _y[4] = 45;
                _x[5] = 95, _y[5] = 25;
                _x[6] = 50, _y[6] = 5;
                _x[7] = 5, _y[7] = 25;
                _x[8] = 5, _y[8] = 45;
                _nDots = 9;
                drawPolygon(_x,_y, _nDots, DEFAULT_COLOR);
                break;
            case FIGURA_D:
                _x[0] = 5, _y[0] = 25;
                _x[1] = 20, _y[1] = 45;
                _x[2] = 40, _y[2] = 20;
                _x[3] = 60, _y[3] = 45;
                _x[4] = 75, _y[4] = 25;
                _x[5] = 60, _y[5] = 5;
                _x[6] = 40, _y[6] = 30;
                _x[7] = 20, _y[7] = 5;
                _x[8] = 5, _y[8] = 25;
                _nDots = 9;
                drawPolygon(_x,_y, _nDots, DEFAULT_COLOR);
                break;
            case FIGURA_E:
                bresenhamCircle((1.0/2.0) * WIDTH, (1.0/2.0) * HEIGHT, (1.0/3.0) * HEIGHT, DEFAULT_COLOR);
                break;
            case FIGURA_F:
                _x[0] = 5, _y[0] = 45;
                _x[1] = 95, _y[1] = 45;
                _x[2] = 95, _y[2] = 5;
                _x[3] = 5, _y[3] = 5;
                _x[4] = 5, _y[4] = 45;
                _nDots = 5;
                drawPolygon(_x,_y, _nDots, DEFAULT_COLOR);
                break;
            case FIGURA_G:
                //dcc();
                _x[0] = 60, _y[0] = 70;
                _x[1] = 110, _y[1] = 30;
                _x[2] = 130, _y[2] = 0;
                _x[3] = 100, _y[3] = 30;
                _x[4] = 80, _y[4] = 0;
                _x[5] = 0, _y[5] = 10;
                _x[6] = 40, _y[6] = 30;
                _x[7] = 20, _y[7] = 50;
                _x[8] = 60, _y[8] = 70;
                _nDots = 9;
                drawPolygon(_x,_y, _nDots, DEFAULT_COLOR);
                geometricFill(_x, _y, _nDots, DEFAULT_COLOR);
                break;
            case FLOOD_FILL_1:
                setbuf(stdin, NULL);
                printf("Flood Fill Coords (xc yc color): ");
                scanf("%d %d %c", &coords[0], &coords[1], &color);
                floodFill1(coords[0], HEIGHT - coords[1] - 1, color);
                break;
            case FLOOD_FILL_2:
                setbuf(stdin, NULL);
                printf("Flood Fill Coords (xc yc color1 color2): ");
                scanf("%d %d %c %c", &coords[0], &coords[1], &color, &color2);
                floodFill2(coords[0], HEIGHT - coords[1] - 1, color, color2);
                break;
            case GEOMETRIC_FILL:
                geometricFill(_x, _y, _nDots, '#');
                break;
            case WRITE_PHRASE:
                setbuf(stdin, NULL);
                printf("Write Coords (x0 y0 width height color): ");
                scanf("%d %d %d %d %c %[^\n]s", &coords[0], &coords[1], &coords[2], &coords[3], &color, write_);
                setbuf(stdin, NULL);
                printf("Phrase: ");
                writeScreen(write_,  color, coords[0], coords[1], coords[2], coords[3]);
                break;
            case BEZIER:
                setbuf(stdin, NULL);
                i = 0;
                printf("Bezier Curve (x1 y1 x2 y2 x3... -1 -1): ");
                //
                do
                {
                    scanf("%d %d", &_x[i], &_y[i]);
                } while(_x[i] >= 0 && _y[i++] >= 0);
                bezier(i, _x, _y, DEFAULT_COLOR);
                break;
            case CASTELJAU:
                setbuf(stdin, NULL);
                printf("Casteljau Curve (x1 y1 ... x4 y4 stop): ");
                scanf("%lf %lf %lf %lf %lf %lf %lf %lf %f", &__x[0], &__y[0], &__x[1], &__y[1], &__x[2], &__y[2], &__x[3], &__y[3], &stop);
                casteljau(__x[0], __y[0], __x[1], __y[1], __x[2], __y[2], __x[3], __y[3], stop, 1);
                break;
            case CUT_1:
                _x[0] = 10, _y[0] = 10;
                _x[1] = 10, _y[1] = 90;
                _x[2] = 100, _y[2] = 10;
                _x[3] = 10, _y[3] = 10;
                _nDots = 4;
                drawPolygon(_x,_y, _nDots, DEFAULT_COLOR);

                helperCoordsX[0] = 5;
                helperCoordsY[0] = 50;

                helperCoordsX[1] = 80;
                helperCoordsY[1] = 5;

                sutherland(_x, _y, _nDots, helperCoordsX, helperCoordsY, 1);

                break;
            case CUT_2:
                _x[0] = 40, _y[0] = 10;
                _x[1] = 40, _y[1] = 30;
                _x[2] = 20, _y[2] = 30;
                _x[3] = 20, _y[3] = 60;
                _x[4] = 40, _y[4] = 60;
                _x[5] = 40, _y[5] = 80;
                _x[6] = 70, _y[6] = 80;
                _x[7] = 70, _y[7] = 60;
                _x[8] = 90, _y[8] = 60;
                _x[9] = 90, _y[9] = 30;
                _x[10] = 70, _y[10] = 30;
                _x[11] = 70, _y[11] = 10;
                _x[12] = 40, _y[12] = 10;
                _nDots = 13;
                drawPolygon(_x,_y, _nDots, DEFAULT_COLOR);

                helperCoordsX[0] = 10;
                helperCoordsY[0] = 84;

                helperCoordsX[1] = 110;
                helperCoordsY[1] = 45;

                sutherland(_x, _y, _nDots, helperCoordsX, helperCoordsY, 1);

                break;
            case CUT_3:
                _x[0] = 20, _y[0] = 10;
                _x[1] = 10, _y[1] = 40;
                _x[2] = 35, _y[2] = 60;
                _x[3] = 60, _y[3] = 40;
                _x[4] = 50, _y[4] = 10;
                _x[5] = 20, _y[5] = 10;
                _nDots = 6;
                drawPolygon(_x,_y, _nDots, DEFAULT_COLOR);

                helperCoordsX[0] = 30;
                helperCoordsY[0] = 50;

                helperCoordsX[1] = 70;
                helperCoordsY[1] = 5;

                sutherland(_x, _y, _nDots, helperCoordsX, helperCoordsY, 1);
                break;
            case CUT_4:
                _x[0] = 10, _y[0] = 10;
                _x[1] = 10, _y[1] = 50;
                _x[2] = 80, _y[2] = 50;
                _x[3] = 80, _y[3] = 10;
                _x[4] = 60, _y[4] = 10;
                _x[5] = 60, _y[5] = 30;
                _x[6] = 30, _y[6] = 30;
                _x[7] = 30, _y[7] = 10;
                _x[8] = 10, _y[8] = 10;
                _nDots = 9;
                drawPolygon(_x,_y, _nDots, DEFAULT_COLOR);

                helperCoordsX[0] = 5;
                helperCoordsY[0] = 25;

                helperCoordsX[1] = 90;
                helperCoordsY[1] = 5;

                sutherland(_x, _y, _nDots, helperCoordsX, helperCoordsY, 1);

                break;
            case DRAW_POLYGON:
                drawPolygon(_x,_y, _nDots, DEFAULT_COLOR);
                break;
            case SUTHERLAND_CUT:

                break;
            default:
                break;
        }


    }
}


void printScreen()
{
    int i, j;
    fprintf(stdout, "   ");
    for(j = 0, i = 0; j < WIDTH; j++)
        if(!(j % 10))
            fprintf(stdout, " %d", i++ % 10);
        else
            fprintf(stdout, " .");
    fprintf(stdout, "\n");
    for(i = 0; i < HEIGHT; i++)
    {
        fprintf(stdout, "%03d|", (HEIGHT - i - 1));
        for(j = 0; j < WIDTH; j++)
        {
            fprintf(stdout, "%c%c", screen[i][j] ? screen[i][j] : BACKGROUND_COLOR, screen[i][j] ? screen[i][j] : BACKGROUND_COLOR);
        }
        fprintf(stdout, "|%03d\n", (HEIGHT - i - 1));
    }
    fprintf(stdout, "   ");
    for(j = 0, i = 0; j < WIDTH; j++)
        if(!(j % 10))
            fprintf(stdout, " %d", i++ % 10);
        else
            fprintf(stdout, " '");
    printf("\n");
}

void clearScreen()
{
    int i, j;
    for(i = 0; i < HEIGHT; i++)
        for(j = 0; j < WIDTH; j++)
            screen[i][j] = BACKGROUND_COLOR;
}

void analiticsLine(int x1, int y1, int x2, int y2, char color)
{
    if(x1 > WIDTH || x1 < 0 || x2 > WIDTH || x2 < 0 || y1 > HEIGHT || y1 < 0 || y2 > HEIGHT || y2 < 0)
    {
        return;
    }

    int i, j;
    float m, b;
    if(x1 == x2)
    {
        for(i = y1 < y2 ? y1 : y2; i <= (y1 < y2 ? y2 : y1); i++)
        {
            colorDot(x1, HEIGHT - i - 1, color);
        }
    }
    else
    {
        m = (y2 - y1 + 0.0f) / (x2 - x1 + 0.0f);
        b = y2 - m * x2;

        for(i = x1; x1 < x2 ? i <= x2 : i >= x2; i += x1 < x2 ? 1 : -1)
        {
            j = ((int ) (m * i + b));
            colorDot(i, HEIGHT - j - 1, color);
        }

    }


}

void ddaLine(int x1, int y1, int x2, int y2, char color)
{
    if(x1 > WIDTH || x1 < 0 || x2 > WIDTH || x2 < 0 || y1 > HEIGHT || y1 < 0 || y2 > HEIGHT || y2 < 0)
    {
        return;
    }
    float inc;
    float y, x;
    if(abs(x2 - x1) > abs(y2 - y1))
    {
        inc = (y2 - y1 + 0.0f) / (x2 - x1 + 0.0f);
        y = y1;
        for(x = x1; x1 < x2 ? x <= x2 : x >= x2; x += x1 < x2 ? 1.0f : -1.0f)
        {
            colorDot(((int)x), HEIGHT - ((int)y) - 1, color);
            y += inc;
        }
    }
    else
    {
        inc = (x2 - x1 + 0.0f) / (y2 - y1 + 0.0f);
        x = x1;
        for(y = y1; y1 < y2 ? y <= y2 : y >= y2; y += y1 < y2 ? 1.0f : -1.0f)
        {
            colorDot(((int)x), HEIGHT - ((int)y) - 1, color);
            x += inc;
        }
    }

}

void bresenhamLine(int x1, int y1, int x2, int y2, char color)
{
    int inverse = 0;

    if(x2 < x1)
    {
        int helper = x1;
        x1 = x2;
        x2 = helper;
        helper = y1;
        y1 = y2;
        y2 = helper;
    }

    int negative = 0;
    if(y2 < y1)
    {
        negative = 1;
        y2 *= -1;
        y1 *= -1;
    }

    if(abs(y2 - y1) > abs(x2 - x1))
    {
        inverse = 1;
        int helper = x1;
        x1 = y1;
        y1 = helper;
        helper = x2;
        x2 = y2;
        y2 = helper;
    }

    int dy = y2 - y1, dx = x2 - x1, y = y1;
    int p = 2 * dy - dx;
    int x;
    for(x = x1; x <= x2; x++)
    {
        colorDot(inverse ? y : x, negative ? (HEIGHT + (inverse ? x : y) - 1) : (HEIGHT - (inverse ? x : y) - 1), color);
        if(p >= 0)
        {
            y++;
            p += 2 * (dy - dx);
        }
        else
        {
            p += 2 * dy;
        }
    }
}

void colorDot(int x, int y, char color)
{
    if(x > WIDTH || x < 0 || y > HEIGHT || y < 0)
        return;
    screen[y][x] = color;
}

void paramCircle(int xc, int yc, int ray, char color)
{
    double x = xc + ray, y = yc;
    int t;
    for(t = 1; t <= 360; t++)
    {
        colorDot(((int) x), HEIGHT - ((int) y) - 1, color);
        x = xc + ray * cos((PI * t) / (180));
        y = yc + ray * sin((PI * t) / (180));
    }
}

void incrementalCircle(int xc, int yc, int ray, char color)
{
    double cost = cos( (1.0f) / ray);
    double sint = sin( (1.0f) / ray);

    double x = ray * cost, y = ray * sint;


    while(x >= y)
    {
        colorDot((x) + xc, HEIGHT - (y + yc) - 1, color);
        colorDot((-x + xc), HEIGHT - (y + yc) - 1, color);
        colorDot((x + xc), HEIGHT - (-y + yc) - 1, color);
        colorDot((-x + xc), HEIGHT - (-y + yc) - 1, color);
        colorDot((y + xc), HEIGHT - (x + yc) - 1, color);
        colorDot((-y + xc), HEIGHT - (x + yc) - 1, color);
        colorDot((y + xc), HEIGHT - (-x + yc) - 1, color);
        colorDot((-y + xc), HEIGHT - (-x + yc) - 1, color);

        x = x * cost - y * sint;
        y = y * cost + x * sint;
    }
    colorDot((x) + xc, HEIGHT - (y + yc) - 1, color);
    colorDot((-x + xc), HEIGHT - (y + yc) - 1, color);
    colorDot((x + xc), HEIGHT - (-y + yc) - 1, color);
    colorDot((-x + xc), HEIGHT - (-y + yc) - 1, color);
    colorDot((y + xc), HEIGHT - (x + yc) - 1, color);
    colorDot((-y + xc), HEIGHT - (x + yc) - 1, color);
    colorDot((y + xc), HEIGHT - (-x + yc) - 1, color);
    colorDot((-y + xc), HEIGHT - (-x + yc) - 1, color);
}

void bresenhamCircle(int xc, int yc, int ray, char color)
{
    int x = 0, y = ray, p =  1 - ray;

    while(x <= y)
    {
        colorDot((x) + xc, HEIGHT - (y + yc) - 1, color);
        colorDot((-x + xc), HEIGHT - (y + yc) - 1, color);
        colorDot((x + xc), HEIGHT - (-y + yc) - 1, color);
        colorDot((-x + xc), HEIGHT - (-y + yc) - 1, color);
        colorDot((y + xc), HEIGHT - (x + yc) - 1, color);
        colorDot((-y + xc), HEIGHT - (x + yc) - 1, color);
        colorDot((y + xc), HEIGHT - (-x + yc) - 1, color);
        colorDot((-y + xc), HEIGHT - (-x + yc) - 1, color);

        if(p>= 0)
        {
            y--;
            p += 2 * x - 2 * y + 5;
            x++;
        }
        else
        {
            p += 2 * x + 3;
            x++;
        }

    }/*
    colorDot((x) + xc, HEIGHT - (y + yc) - 1, color);
    colorDot((-x + xc), HEIGHT - (y + yc) - 1, color);
    colorDot((x + xc), HEIGHT - (-y + yc) - 1, color);
    colorDot((-x + xc), HEIGHT - (-y + yc) - 1, color);
    colorDot((y + xc), HEIGHT - (x + yc) - 1, color);
    colorDot((-y + xc), HEIGHT - (x + yc) - 1, color);
    colorDot((y + xc), HEIGHT - (-x + yc) - 1, color);
    colorDot((-y + xc), HEIGHT - (-x + yc) - 1, color);*/
}

void drawPolygon(int * x, int * y, int nDots, char color)
{
    int i;
    for(i = 0; i < nDots - 1; i++)
        bresenhamLine(x[i], y[i], x[i + 1], y[i + 1], color);
}

int getScreenColor(int x, int y)
{
    return screen[y][x];
}

void floodFill1(int x, int y, char color)
{
    if(x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
        return;

    if(getScreenColor(x, y) != color)
    {
        colorDot(x, y, color);
        floodFill1(x + 1, y, color);
        floodFill1(x, y + 1, color);
        floodFill1(x - 1, y, color);
        floodFill1(x, y - 1, color);
    }
}

void floodFill2(int x, int y, char color1, char color2)
{
    if(x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
        return;


    if(getScreenColor(x, y) == color1)
    {
        colorDot(x, y, color2);
        floodFill2(x + 1, y, color1, color2);
        floodFill2(x, y + 1, color1, color2);
        floodFill2(x - 1, y, color1, color2);
        floodFill2(x, y - 1, color1, color2);
    }
}

int getSmallestEdge(int * x, int * y, int nDots, int * isLeft)
{
    int minY = 0;
    int i;
    for(i = 1; i < nDots; i++)
    {
        if(y[minY] > y[i])
            minY = i;
        if(y[minY] == y[i])
            minY = x[minY] > x[i] ? i : minY;
    }
    *isLeft = y[minY == 0 ? nDots - 1 : minY - 1] < y[minY == nDots - 1 ? 0 : minY + 1] ? 1 : 0;
    return minY;
}

void sort(float * vector, int size)
{
    if(size == 0) return;
    int i,j, menor;
    float helper;
    for(i = 0; i < size; i++)
    {
        menor = i;
        for(j = i; j < size; j++)
        {
            if(vector[menor] > vector[j])
                menor = j;
        }
        helper = vector[menor];
        vector[menor] = vector[i];
        vector[i] = helper;
    };
}

void geometricFill(int * x, int * y, int nDots, char color)
{
    nDots--;
    int nEdges = nDots - 1;
    float table[nEdges + 1][4];
    int min, isLeft, i, j, k;
    min = getSmallestEdge(x, y, nDots, &isLeft);
    int start = y[min];

    int Ymin = 0, Ymax = 1, XtoYmin = 2, M = 3;
    for(i = 0; i < nEdges + 1; i++)
    {
        table[i][Ymin] = isLeft ? y[min] < y[min == 0 ? nEdges : min - 1] ? y[min] : y[min == 0 ? nEdges : min - 1] : y[min] < y[min == nEdges ? 0 : min + 1] ? y[min] : y[min == nEdges ? 0 : min + 1];
        table[i][Ymax] = isLeft ? y[min] > y[min == 0 ? nEdges : min - 1] ? y[min] : y[min == 0 ? nEdges : min - 1] : y[min] > y[min == nEdges ? 0 : min + 1] ? y[min] : y[min == nEdges ? 0 : min + 1];
        table[i][XtoYmin] = isLeft ? y[min] < y[min == 0 ? nEdges : min - 1] ? x[min] : x[min == 0 ? nEdges : min - 1] : y[min] < y[min == nEdges ? 0 : min + 1] ? x[min] : x[min == nEdges ? 0 : min + 1];
        table[i][M] = isLeft ? (x[min] + 0.0f) - (x[min == 0 ? nEdges : min - 1] + 0.0f) : (x[min] + 0.0f) - (x[min == nEdges ? 0 : min + 1] + 0.0f);
        table[i][M] /= isLeft ? (y[min] + 0.0f) - (y[min == 0 ? nEdges : min - 1] + 0.0f) : (y[min] + 0.0f) - (y[min == nEdges ? 0 : min + 1] + 0.0f);
        min += isLeft ? -1 : +1;
        min = min == 0 ? nEdges : min == nDots ? 0 : min;
    }


    for(i = start; i < HEIGHT; i++)
    {
        float xs[nEdges + 2];
        int index = 0;
        for(j = 0; j < nEdges + 1; j++)
        {
            if(i >= table[j][Ymin] && i <= table[j][Ymax])
            {
                xs[index++] = table[j][M] * (i - table[j][Ymin]) + table[j][XtoYmin];
            }
        }

        sort(xs, index);

        int counter = 1, paint = 1, para;

        for(j = (int) xs[0]; j <= ((int) (xs[index - 1])); j++)
        {
            if(paint)
                colorDot(j, HEIGHT - i - 1, color);
            if(j == (int)(xs[counter]))
            {
                para = 1;
                for(k = 0; k < nDots; k++)
                {
                    if(j == x[k] && i == y[k])
                    {
                        para = 0;
                    }
                }

                if(para)
                {
                    paint = !paint;
                }
                counter++;
            }
        }
    }

}

void dcc()
{
    bresenhamCircle(76, 46, 20, DEFAULT_COLOR);
    bresenhamCircle(76, 46, 15, DEFAULT_COLOR);

    bresenhamLine(89, 21, 62, 63, DEFAULT_COLOR);
    bresenhamLine(91, 24, 64, 64, DEFAULT_COLOR);

    bresenhamLine(88, 62, 75, 49, DEFAULT_COLOR);
    bresenhamLine(86, 64, 73, 49, DEFAULT_COLOR);


    int f1 = '\\';
    int f2 = 'C';
    int f3 = 'X';

    floodFill2(62, HEIGHT - 34 - 1, ' ', f1);
    floodFill2(75, HEIGHT - 64 - 1, ' ', f2);

    /**/
    bresenhamCircle(76, 46, 20, ' ');
    bresenhamCircle(76, 46, 15, ' ');

    bresenhamLine(89, 21, 62, 63, ' ');
    bresenhamLine(91, 24, 64, 64, ' ');

    bresenhamLine(88, 62, 75, 49, ' ');
    bresenhamLine(86, 64, 73, 49, ' ');

    /**/

    bresenhamCircle(101, 46, 20, DEFAULT_COLOR);
    bresenhamCircle(101, 46, 15, DEFAULT_COLOR);

    bresenhamLine(70, 47, 130, 47, DEFAULT_COLOR);
    bresenhamLine(70, 45, 130, 45, DEFAULT_COLOR);

    bresenhamLine(100, 46, 100, 70, DEFAULT_COLOR);
    bresenhamLine(102, 46, 102, 70, DEFAULT_COLOR);

    floodFill2(92, HEIGHT - 61 - 1, ' ', f2);
    floodFill2(101, HEIGHT - 29 - 1, ' ', f1);

    /**/
    bresenhamCircle(101, 46, 20, ' ');
    bresenhamCircle(101, 46, 15, ' ');

    bresenhamLine(70, 47, 130, 47, ' ');
    bresenhamLine(70, 45, 130, 45, ' ');

    bresenhamLine(100, 46, 100, 70, ' ');
    bresenhamLine(102, 46, 102, 70, ' ');
    /**/


    bresenhamCircle(34, 46, 20, DEFAULT_COLOR);
    bresenhamCircle(34, 46, 15, DEFAULT_COLOR);

    bresenhamLine(34, 5, 34, 70, DEFAULT_COLOR);

    bresenhamLine(34, 47, 55, 47, DEFAULT_COLOR);
    bresenhamLine(43, 45, 55, 45, DEFAULT_COLOR);

    floodFill2(47, HEIGHT - 58 - 1, ' ', f3);
    floodFill2(50, HEIGHT - 40 - 1, ' ', f3);

    //
    /**/
    bresenhamCircle(34, 46, 20, ' ');
    bresenhamCircle(34, 46, 15, ' ');

    bresenhamLine(34, 5, 34, 70, ' ');

    bresenhamLine(34, 47, 55, 47, ' ');
    bresenhamLine(43, 45, 55, 45, ' ');
    /**/


    bresenhamLine(32, 66, 32, 26, DEFAULT_COLOR);
    bresenhamLine(27, 66, 27, 26, DEFAULT_COLOR);

    bresenhamLine(32, 66, 27, 66, DEFAULT_COLOR);
    bresenhamLine(32, 26, 27, 26, DEFAULT_COLOR);

    floodFill2(28, HEIGHT - 28 - 1, ' ', f3);

    //
    /**/
    bresenhamLine(32, 66, 32, 26, ' ');
    bresenhamLine(27, 66, 27, 26, ' ');

    bresenhamLine(32, 66, 27, 66, ' ');
    bresenhamLine(32, 26, 27, 26, ' ');
    /**/

    floodFill2(0, 0, '.', ' ');

    char string2[MAX_V] = "departamento de";
    writeScreen(string2, '>', 28,70, 5, 7);

    char string[MAX_V] = "ciencia da computacao";
    writeScreen(string, '>', 11,15, 5, 7);
}

void writeScreen(char string[MAX_V], char color, int x0, int y0, int width, int heith)
{
    if(string == NULL)
        return;
    int i = 0;

    do{
        switch (string[i])
        {

            case 'a':
            case 'A':
                bresenhamLine(x0, y0 + heith, x0 + width - 1, y0 + heith, color);
                bresenhamLine(x0 + width - 1, y0, x0 + width - 1, y0 + heith, color);
                bresenhamLine(x0, y0, x0, y0 + heith, color);
                bresenhamLine(x0, y0 + heith/2, x0 + width - 1, y0 + heith/2, color);
                break;
            case 'b':
            case 'B':
                bresenhamLine(x0, y0, x0, y0 + heith, color);
                bresenhamLine(x0, y0 + heith, x0 + (width - 1)/2, y0 + heith, color);
                bresenhamLine(x0 + (width - 1)/2, y0 + heith, x0 + width - 1, y0 + heith/2, color);
                bresenhamLine(x0, y0 + heith/2, x0 + width - 1, y0 + heith/2, color);
                bresenhamLine(x0 + width - 1, y0 + heith/2, x0 + width - 1, y0, color);
                bresenhamLine(x0, y0, x0 + width - 1, y0, color);
                break;
            case 'c':
            case 'C':
                bresenhamLine(x0, y0, x0, y0 + heith, color);
                bresenhamLine(x0, y0, x0 + width - 1, y0, color);
                bresenhamLine(x0, y0 + heith, x0 + width - 1, y0 + heith, color);
                break;
            case 'd':
            case 'D':
                bresenhamLine(x0, y0, x0, y0 + heith, color);
                bresenhamLine(x0, y0 + heith, x0 + (width - 1)/2, y0 + heith, color);
                bresenhamLine(x0 + (width - 1)/2, y0 + heith, x0 + width - 1, y0 + heith/2, color);
                bresenhamLine(x0 + width - 1, y0 + heith/2, x0 + width - 1, y0, color);
                bresenhamLine(x0, y0, x0 + width - 1, y0, color);
                break;
            case 'e':
            case 'E':
                bresenhamLine(x0, y0, x0, y0 + heith, color);
                bresenhamLine(x0, y0 + heith, x0 + width - 1, y0 + heith, color);
                bresenhamLine(x0, y0 + heith/2, x0 + width - 1, y0 + heith/2, color);
                bresenhamLine(x0, y0, x0 + width - 1, y0, color);
                break;
            case 'f':
            case 'F':
                bresenhamLine(x0, y0, x0, y0 + heith, color);
                bresenhamLine(x0, y0 + heith, x0 + width - 1, y0 + heith, color);
                bresenhamLine(x0, y0 + heith/2, x0 + width - 1, y0 + heith/2, color);
                break;
            case 'g':
            case 'G':
                bresenhamLine(x0, y0, x0, y0 + heith, color);
                bresenhamLine(x0, y0, x0 + width - 1, y0, color);
                bresenhamLine(x0, y0 + heith, x0 + width - 1, y0 + heith, color);
                bresenhamLine(x0 + width - 1, y0, x0 + width - 1, y0 + heith/2, color);
                bresenhamLine(x0 + (width - 1)/2, y0 + heith/2, x0 + width - 1, y0 + heith/2, color);
                break;
            case 'h':
            case 'H':
                bresenhamLine(x0, y0, x0, y0 + heith, color);
                bresenhamLine(x0 + width - 1, y0, x0 + width - 1, y0 + heith, color);
                bresenhamLine(x0, y0 + heith/2, x0 + width - 1, y0 + heith/2, color);
                break;
            case 'i':
            case 'I':
            case 'í':
            case 'Í':
            case 'ĩ':
            case 'Ĩ':
                bresenhamLine(x0 + (width - 1)/2, y0, x0 + (width - 1)/2, y0 + heith, color);
                break;
            case 'j':
            case 'J':
                bresenhamLine(x0 + (width - 1)/2, y0, x0 + (width - 1)/2, y0 + heith, color);
                bresenhamLine(x0 , y0, x0 + (width - 1)/2, y0, color);
                bresenhamLine(x0 , y0, x0 , y0 + heith/2, color);
                break;
            case 'k':
            case 'K':
                bresenhamLine(x0, y0, x0, y0 + heith, color);
                bresenhamLine(x0, y0 + heith/2, x0 + width - 1, y0, color);
                bresenhamLine(x0, y0 + heith/2, x0 + width - 1, y0 + heith, color);
                break;
            case 'l':
            case 'L':
                bresenhamLine(x0 + (width - 1)/2, y0, x0 + (width - 1)/2, y0 + heith, color);
                bresenhamLine(x0 + width - 1, y0, x0 + (width - 1)/2, y0, color);
                break;
            case 'm':
            case 'M':
                bresenhamLine(x0, y0, x0, y0 + heith, color);
                bresenhamLine(x0 + width - 1, y0, x0 + width - 1, y0 + heith, color);
                bresenhamLine(x0, y0 + heith, x0 + (width - 1)/2, y0 + heith/2, color);
                bresenhamLine(x0 + (width - 1)/2, y0 + heith/2, x0 + width - 1, y0 + heith, color);
                break;
            case 'n':
            case 'N':
                bresenhamLine(x0, y0, x0, y0 + heith, color);
                bresenhamLine(x0 + width - 1, y0, x0 + width - 1, y0 + heith, color);
                bresenhamLine(x0, y0 + heith, x0 + width - 1, y0, color);
                break;
            case 'o':
            case 'O':
            case 'ó':
            case 'Ó':
            case 'õ':
            case 'Õ':
                bresenhamLine(x0, y0, x0, y0 + heith, color);
                bresenhamLine(x0 + width - 1, y0, x0 + width - 1, y0 + heith, color);
                bresenhamLine(x0, y0, x0 + width - 1, y0, color);
                bresenhamLine(x0, y0 + heith, x0 + width - 1, y0 + heith, color);
                break;
            case 'p':
            case 'P':
                bresenhamLine(x0, y0, x0, y0 + heith, color);
                bresenhamLine(x0, y0 + heith, x0 + width - 1, y0 + heith, color);
                bresenhamLine(x0, y0 + heith/2, x0 + width - 1, y0 + heith/2, color);
                bresenhamLine(x0 + width - 1, y0 + heith/2, x0 + width - 1, y0 + heith, color);
                break;
            case 'q':
            case 'Q':
                bresenhamLine(x0+ width - 1, y0, x0+ width - 1, y0 + heith, color);
                bresenhamLine(x0, y0 + heith, x0 + width - 1, y0 + heith, color);
                bresenhamLine(x0, y0 + heith/2, x0 + width - 1, y0 + heith/2, color);
                bresenhamLine(x0, y0 + heith/2, x0, y0 + heith, color);
                break;
            case 'r':
            case 'R':
                bresenhamLine(x0, y0, x0, y0 + heith, color);
                bresenhamLine(x0, y0 + heith, x0 + width - 1, y0 + heith, color);
                bresenhamLine(x0, y0 + heith/2, x0 + width - 1, y0 + heith/2, color);
                bresenhamLine(x0 + width - 1, y0 + heith, x0 + width - 1, y0 + heith/2, color);
                bresenhamLine(x0, y0 + heith/2, x0 + width - 1, y0, color);
                break;
            case 's':
            case 'S':
                bresenhamLine(x0, y0 + heith/2, x0, y0 + heith, color);
                bresenhamLine(x0, y0 + heith, x0 + width - 1, y0 + heith, color);
                bresenhamLine(x0, y0 + heith/2, x0 + width - 1, y0 + heith/2, color);
                bresenhamLine(x0 + width - 1, y0 + heith/2, x0 + width - 1, y0, color);
                bresenhamLine(x0, y0, x0 + width - 1, y0, color);
                break;
            case 't':
            case 'T':
                bresenhamLine(x0 + (width - 1)/2, y0, x0 + (width - 1)/2, y0 + heith, color);
                bresenhamLine(x0, y0 + heith, x0 + width - 1, y0 + heith, color);
                break;
            case 'u':
            case 'U':
            case 'ú':
            case 'Ú':
            case 'ũ':
            case 'Ũ':
                bresenhamLine(x0, y0, x0, y0 + heith, color);
                bresenhamLine(x0 + width - 1, y0, x0 + width - 1, y0 + heith, color);
                bresenhamLine(x0, y0, x0 + width - 1, y0, color);
                break;
            case 'v':
            case 'V':
                bresenhamLine(x0, y0 + heith, x0 + (width - 1)/2, y0, color);
                bresenhamLine(x0 + (width - 1)/2, y0, x0 + width - 1, y0 + heith, color);
                break;
            case 'w':
            case 'W':
                bresenhamLine(x0, y0, x0, y0 + heith, color);
                bresenhamLine(x0 + width - 1, y0, x0 + width - 1, y0 + heith, color);
                bresenhamLine(x0, y0, x0 + (width - 1)/2, y0 + heith/2, color);
                bresenhamLine(x0 + (width - 1)/2, y0 + heith/2, x0 + width - 1, y0, color);
                break;
            case 'x':
            case 'X':
                bresenhamLine(x0, y0, x0 + width - 1, y0 + heith, color);
                bresenhamLine(x0, y0 + heith, x0 + width - 1, y0, color);
                break;
            case 'y':
            case 'Y':
                bresenhamLine(x0, y0, x0 + width - 1, y0 + heith, color);
                bresenhamLine(x0, y0 + heith, x0 + (width - 1) / 2, y0 + heith / 2, color);
                break;
            case 'z':
            case 'Z':
                bresenhamLine(x0, y0, x0 + width - 1, y0 + heith, color);
                bresenhamLine(x0, y0, x0 + width - 1, y0, color);
                bresenhamLine(x0, y0 + heith, x0 + width - 1, y0 + heith, color);
            default:
                break;
        }
        i++;

        if(string[i] == 'á' || string[i] == 'é' || string[i] == 'í' || string[i] == 'ó' || string[i] == 'ú')
            bresenhamLine(x0 + (width - 1)/2, y0 + heith + 2, x0 + (width + 1)/2, y0 + heith + 4, color);
        if(string[i] == 'ã' || string[i] == 'ẽ' || string[i] == 'ĩ' || string[i] == 'õ' || string[i] == 'ũ')
            bresenhamLine(x0 + (width - 1)/2, y0 + heith + 2, x0 + (width + 1)/2, y0 + heith + 2, color);

        if(string[i] == 'ç')
        {
            bresenhamLine(x0, y0, x0, y0 + heith, color);
            bresenhamLine(x0, y0, x0 + width - 1, y0, color);
            bresenhamLine(x0, y0 + heith, x0 + width - 1, y0 + heith, color);
            bresenhamLine(x0 + (width - 1)/2, y0, x0 + (width - 1)/2, y0-2, color);
        }


        x0 += width + 1;
    }while(i < strlen(string));
}

void turninto(char color1, char color2)
{
    int i, j;
    for(i = 0; i < HEIGHT; i++)
        for(j = 0; j < WIDTH; j++)
            screen[i][j] = screen[i][j] == color1 ? color2 : screen[i][j];
}

int fat(int n)
{
    int i;
    int answer = 1;
    for(i = 1; i <= n; i++)
    {
        answer *= i;
    }
    return answer;
}

double newton(int n, int i, double t)
{
    return ((fat(n) + 0.0) / (fat(i) * fat(n - i) + 0.0)) * pow(t, i) * pow(1 - t, n - i);
}

void bezier(int nDots, int * xs, int * ys, char color)
{
    int ii;
    double t = 0, pass = 0.001;
    double nResult = 0;
    double x, y;
    int n = nDots - 1;
    printf("(%c) ", color);

    for(ii = 0; ii < nDots; ii++)
    {
        colorDot(xs[ii], HEIGHT - ys[ii] - 1, DEFAULT_COLOR);
    }

    for(t = 0.0; t <= 1.0; t += pass)
    {
        x = 0;
        y = 0;
        for( ii = 0; ii < nDots; ii++)
        {
            nResult = newton(n, ii, t);
            x += (xs[ii] * nResult);
            y += (ys[ii] * nResult);
        }
        colorDot((int )x, HEIGHT - (int)(y) - 1, color);
    }
}

void casteljau(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4, float stop, int var)
{
    if(((x1 - x4) < 0 ? (-1 * (x1 - x4)) : (x1 - x4)) <= stop || ((y1 - y4) < 0 ? (-1 * (y1 - y4)) : (y1 - y4)) <= stop)
        return;


    double mx12, mx23, mx34, mx1223, mx2334, mx12232334;
    double my12, my23, my34, my1223, my2334, my12232334;

    mx12 = (x1 + x2) / 2.0f;
    my12 = (y1 + y2) / 2.0f;

    mx23 = (x3 + x2) / 2.0f;
    my23 = (y3 + y2) / 2.0f;

    mx34 = (x3 + x4) / 2.0f;
    my34 = (y3 + y4) / 2.0f;

    mx1223 = (mx12 + mx23) / 2.0f;
    my1223 = (my12 + my23) / 2.0f;

    mx2334 = (mx34 + mx23) / 2.0f;
    my2334 = (my34 + my23) / 2.0f;

    mx12232334 = (mx1223 + mx2334) / 2.0f;
    my12232334 = (my1223 + my2334) / 2.0f;


    if(var)
    {
        colorDot((int)x1, HEIGHT - ((int)y1) - 1, DEFAULT_COLOR);
        colorDot((int)x2, HEIGHT - ((int)y2) - 1, DEFAULT_COLOR);
        colorDot((int)x3, HEIGHT - ((int)y3) - 1, DEFAULT_COLOR);
        colorDot((int)x4, HEIGHT - ((int)y4) - 1, DEFAULT_COLOR);
    }

    colorDot((int)mx12232334, HEIGHT - ((int) my12232334) - 1, DEFAULT_COLOR);

    casteljau(x1, y1, mx12, my12, mx1223, my1223, mx12232334, my12232334, stop, 0);
    casteljau(mx12232334, my12232334, mx2334, my2334, mx34, my34, x4, y4, stop, 0);
}

void sutherland(int *xs, int *ys, int nDots, int *squarexs, int *squareys, int side)
{
    int i, counter = 0;
    int newXs[MAX_V], newYs[MAX_V];
    double helper1, helper2;

    printf("\n\nLADO %s\n\n", side == 1 ? "DIREITO" : side == 2 ? "ABAIXO" : side == 3 ? "ESQUERDO" : "ACIMA");

    printf("Dots received (%d): ", nDots);
    for(i = 0; i < nDots; i++)
    {
        printf("(%d, %d) ", xs[i], ys[i]);
    }
    printf("\n LADOS DO QUADRADO: (%d, %d) e (%d, %d)\n", squarexs[0], squareys[0], squarexs[1], squareys[1]);

    for(i = 0; i < nDots - 1; i++)
    {
        printf("Treating (%d, %d) -> (%d, %d)\n", xs[i], ys[i], xs[i+1], ys[i+1]);
        if(side == 1) // Lado direito
        {
            if(xs[i] <= squarexs[1])
            {
                if(xs[i+1] <= squarexs[1]) // caso 1
                {
                    printf("\tCAIU NO CASO 1 (OS dois dentro)\n");
                    newXs[counter] = xs[i + 1];
                    newYs[counter++] = ys[i + 1];
                }
                else //caso 2
                {
                    printf("\tCAIU NO CASO 2 (de dentro pra fora)\n");
                    newXs[counter] = squarexs[1];
                    helper1 = (ys[i+1] - ys[i] + 0.0f) / (xs[i+1] - xs[i] + 0.0f);
                    helper2 = ys[i+1] - helper1 * xs[i+1];
                    newYs[counter++] =  (int) (helper1 * squarexs[1] + helper2);
                    printf("\tA interseçãp é no ponto (%d, %d)\n", newXs[counter - 1], newYs[counter - 1]);
                }
            }
            else
            {
                if(xs[i+1] <= squarexs[1])
                {
                    printf("\tCAIU NO CASO 4 (de fora pra dentro)\n");
                    newXs[counter] = squarexs[1];
                    helper1 = (ys[i+1] - ys[i] + 0.0f) / (xs[i+1] - xs[i] + 0.0f);
                    helper2 = ys[i+1] - helper1 * xs[i+1];
                    newYs[counter++] =  (int) (helper1 * squarexs[1] + helper2);
                    printf("\tA interseçãp é no ponto (%d, %d)\n", newXs[counter - 1], newYs[counter - 1]);
                    newXs[counter] = xs[i+1];
                    newYs[counter++] = ys[i+1];
                    printf("\tE o ponto de dentro é o (%d, %d)\n", newXs[counter - 1], newYs[counter - 1]);
                } else
                {
                    printf("\tCaiu no caso 3 (Os dois fora)\n");
                    continue;
                }
            }
        }
        else if(side == 2) // abaixo
        {
            if(ys[i] >= squareys[1])
            {
                if(ys[i + 1] >= squareys[1]) // caso 1
                {
                    printf("\tCAIU NO CASO 1 (OS dois dentro)\n");
                    newXs[counter] = xs[i + 1];
                    newYs[counter++] = ys[i + 1];
                }
                else
                {
                    printf("\tCAIU NO CASO 2 (De dentro pra fora)\n");
                    newYs[counter] = squareys[1];
                    helper1 = (ys[i+1] - ys[i] + 0.0f) / (xs[i+1] - xs[i] + 0.0f);
                    helper2 = ys[i+1] - helper1 * xs[i+1];
                    newXs[counter++] =  xs[i] == xs[i+1] ? xs[i] :  (int) ((squareys[1] - helper2) / helper1);
                    printf("\tA interseçãp é no ponto (%d, %d)\n", newXs[counter - 1], newYs[counter - 1]);
                }
            }
            else
            {
                if(ys[i + 1] >= squareys[1])
                {
                    printf("\tCAIU NO CASO 4 (de fora pra dentro)\n");
                    newYs[counter] = squareys[1];
                    helper1 = (ys[i+1] - ys[i] + 0.0f) / (xs[i+1] - xs[i] + 0.0f);
                    helper2 = ys[i+1] - helper1 * xs[i+1];
                    newXs[counter++] =  xs[i] == xs[i+1] ? xs[i] :  (int) ((squareys[1] - helper2) / helper1);
                    printf("\tA interseçãp é no ponto (%d, %d)\n", newXs[counter - 1], newYs[counter - 1]);
                    newXs[counter] = xs[i+1];
                    newYs[counter++] = ys[i+1];
                    printf("\tE o ponto de dentro é o (%d, %d)\n", newXs[counter - 1], newYs[counter - 1]);
                }
                else
                {
                    printf("\tCaiu no caso 3 (Os dois fora)\n");
                    continue;
                }
            }
        }
        else if(side == 3) // Lado esquerdo
        {
            if(xs[i] >= squarexs[0])
            {
                if(xs[i+1] >= squarexs[0]) // caso 1
                {
                    printf("\tCAIU NO CASO 1 (OS dois dentro)\n");
                    newXs[counter] = xs[i + 1];
                    newYs[counter++] = ys[i + 1];
                }
                else //caso 2
                {
                    printf("\tCAIU NO CASO 2 (De dentro pra fora)\n");
                    newXs[counter] = squarexs[0];
                    helper1 = (ys[i+1] - ys[i] + 0.0f) / (xs[i+1] - xs[i] + 0.0f);
                    helper2 = ys[i+1] - helper1 * xs[i+1];
                    newYs[counter++] =  (int) (helper1 * squarexs[0] + helper2);
                    printf("\tA interseçãp é no ponto (%d, %d)\n", newXs[counter - 1], newYs[counter - 1]);
                }
            }
            else
            {
                if(xs[i+1] >= squarexs[0])
                {
                    printf("\tCAIU NO CASO 4 (de fora pra dentro)\n");
                    newXs[counter] = squarexs[0];
                    helper1 = (ys[i+1] - ys[i] + 0.0f) / (xs[i+1] - xs[i] + 0.0f);
                    helper2 = ys[i+1] - helper1 * xs[i+1];
                    newYs[counter++] =  (int) (helper1 * squarexs[0] + helper2);
                    printf("\tA interseçãp é no ponto (%d, %d)\n", newXs[counter - 1], newYs[counter - 1]);
                    newXs[counter] = xs[i+1];
                    newYs[counter++] = ys[i+1];
                    printf("\tE o ponto de dentro é o (%d, %d)\n", newXs[counter - 1], newYs[counter - 1]);
                } else
                {
                    printf("\tCaiu no caso 3 (Os dois fora)\n");
                    continue;
                }
            }
        }
        else if(side == 4) // acima
        {
            if(ys[i] <= squareys[0])
            {
                if(ys[i + 1] <= squareys[0]) // caso 1
                {
                    printf("\tCAIU NO CASO 1 (OS dois dentro)\n");
                    newXs[counter] = xs[i + 1];
                    newYs[counter++] = ys[i + 1];
                }
                else
                {
                    printf("\tCAIU NO CASO 2 (De dentro pra fora)\n");
                    newYs[counter] = squareys[0];
                    helper1 = (ys[i+1] - ys[i] + 0.0f) / (xs[i+1] - xs[i] + 0.0f);
                    helper2 = ys[i+1] - helper1 * xs[i+1];
                    newXs[counter++] =  xs[i] == xs[i+1] ? xs[i] :  (int) ((squareys[0] - helper2) / helper1);
                    printf("\tA interseçãp é no ponto (%d, %d)\n", newXs[counter - 1], newYs[counter - 1]);
                }
            }
            else
            {
                if(ys[i + 1] <= squareys[0])
                {
                    printf("\tCAIU NO CASO 4 (de fora pra dentro)\n");
                    newYs[counter] = squareys[0];
                    helper1 = (ys[i+1] - ys[i] + 0.0f) / (xs[i+1] - xs[i] + 0.0f);
                    helper2 = ys[i+1] - helper1 * xs[i+1];
                    newXs[counter++] =  xs[i] == xs[i+1] ? xs[i] : (int) ((squareys[0] - helper2) / helper1);
                    printf("\tA interseçãp é no ponto (%d, %d)\n", newXs[counter - 1], newYs[counter - 1]);
                    newXs[counter] = xs[i+1];
                    newYs[counter++] = ys[i+1];
                    printf("\tE o ponto de dentro é o (%d, %d)\n", newXs[counter - 1], newYs[counter - 1]);
                }
                else
                {
                    printf("\tCaiu no caso 3 (Os dois fora)\n");
                    continue;
                }
            }
        }
    }
    newXs[counter] = newXs[0];
    newYs[counter++] = newYs[0];

    printf("TERMINOU UM LADO\nO NOVO POLIGONO TA ASSIM (%d): ", counter);
    for(i = 0; i < counter; i++)
    {
        printf("(%d, %d) ", newXs[i], newYs[i]);
    }
    printf("\n");


    if(side == 4) // end;
    {
        for(i = 0; i < counter; i++)
        {
            _x[i] = newXs[i];
            _y[i] = newYs[i];
        }
        _nDots = counter;
    }
    else
    {
        printf("\nCHAMANDO A FUNÇÂO NOVAMENTE\n\n");
        sutherland(newXs, newYs, counter, squarexs, squareys, side + 1);
    }
}