#include <iostream>
#include <conio.h>
#include <windows.h>
#include <fstream>
#include <sstream>
using namespace std;

/*BASIC FUNCTIONS*/
void print();
void printHeader();
void printMaze();
void gotoxy(int x, int y);
char getCharATXY(short int x, short int y);
void addScore();
void minusScore();
void minusScore2();
void printHeader();
string menu();
string validateOption(string option);
void inst();
void win();
void loss();
void setColor(int color);
void showScore(int playerScore, int health);

/*PLAYERS FUNCTIONS*/
void printHero(int x, int y);
void eraseHero(int x, int y);
void heroLeft();
void heroRight();
void heroDown();
void heroUp();
void printBullet(int x, int y);
void generateBullet();
void moveBullet();
void removeBullet(int x);
void eraseBullet(int x, int y);

/*SCOUT 1 FUNCTIONS*/
void printScout(int x, int y);
void eraseScout(int x, int y);
void scou1MovementLeft();
void scou1MovementUp();
void scout1MovementRight();
void scout1Bullet(int x, int y);
void scout1BulletRemove(int x, int y);
void generateScout1Bullet();
void moveScoutBullet();
void removeBulletScout(int x);
void generateScout1Bullet();

/*SCOUT 2 FUNCTIONS*/
void printScout2(int x, int y);
void scou2MovementLeft();
void scou2MovementDown();
void scou2MovementRight();
void eraseScout2(int x, int y);
void scout2Bullet(int x, int y);
void scout2BulletRemove(int x, int y);
void generateScout2Bullet();
void moveScout2Bullet();
void removeBulletScout2(int x);
void generateScout2Bullet();

/*FAT BOY FUNCTIONS*/
void printBoy(int x, int y);
void removeBoy(int x, int y);
void moveBoy();
void moveBoyDown();
void boyBullet(int x, int y);
void boyBulletRemove(int x, int y);
void removeBulletBoy(int x);
void generateBoyBullet();
void moveBoyBullet();

/*COLLOSION CHECK*/
void collosion();
void collosion2();
void collosion3();
void enemyCollosion();
void enemyCollosion2();
void enemyCollosion3();

/*SCORING FUNCTIONS*/
bool check(int score);
bool check2(int health);
void generatePowerUp();
void addPowerUp();
void removepowerUp();

/*Storing and loading*/
void storeData();
void loadData();
void resetting();

/*VARIABLES*/
string option = "0";

int hx = 28;
int hy = 10;

int sx = 140;
int sy = 20;

int s2x = 140;
int s2y = 5;

int fx = 140;
int fy = 10;

int heartX = 50;
int heartY = 10;

int bx[1000];
int by[1000];
int bulletCount = 0;

int scoutBulletX[1000];
int scoutBulletY[1000];
int scoutBulletCount = 0;
int score = 0;
int enemyScore = 100;
int count = 0;

int scout2BulletX[1000];
int scout2BulletY[1000];
int scout2BulletCount = 0;

int boyBulletX[1000];
int boyBulletY[1000];
int boyBulletCount = 0;

int timer = 0;
int timer2 = 0;
int timer3 = 0;

int timer4 = 0;
int timer5 = 0;

int count1 = 0;
int count2 = 0;
int count3 = 0;

string direction = "left";
string direction2 = "left";
string direction3 = "up";
char previousChar = ' ';
string scout1Active = "true";
string scout2Active = "true";

main()
{
    
    storeData();
    loadData();

    bool flag1 = false;
    bool flag2 = false;

    system("cls");
    print();
    getch();
    system("cls");
    printHeader();
    int op = 0;

    while (op != 4)
    {
        system("cls");
        printHeader();
        string op = menu();

        if (op == "1")
        {
            /*RESETTING THE VARIABLES*/
            
            flag1 = false;
            flag2 = false;

            bool gameRunning = true;

            system("cls");
            printMaze();
            loadData();

            while (gameRunning == true)
            {

                showScore(score, enemyScore);

                /*SCOUT1 MOVEMENTS*/
                if (scout1Active == "true")
                {
                    if (direction == "left")
                    {
                        scou1MovementLeft();
                        if (timer3 == 6)
                        {
                            generateScout1Bullet();
                            timer3 = 0;
                        }
                    }
                    moveScoutBullet();

                    if (direction == "up")
                    {
                        scou1MovementUp();
                        if (timer3 == 6)
                        {
                            generateScout1Bullet();
                            timer3 = 0;
                        }
                    }
                    moveScoutBullet();
                    if (direction == "right")
                    {
                        scout1MovementRight();
                        if (timer3 == 6)
                        {
                            generateScout1Bullet();
                            timer3 = 0;
                        }
                    }
                    moveScoutBullet();
                    timer3++;
                }

                /*SCOUT 2 MOVEMENTS*/
                if (scout2Active == "true")
                {
                    if (direction2 == "left")
                    {
                        scou2MovementLeft();
                        if (timer2 == 6)
                        {
                            generateScout2Bullet();
                            timer2 = 0;
                        }
                    }
                    moveScout2Bullet();
                    if (direction2 == "down")
                    {
                        scou2MovementDown();
                        if (timer2 == 6)
                        {
                            generateScout2Bullet();
                            timer2 = 0;
                        }
                    }
                    moveScout2Bullet();
                    if (direction2 == "right")
                    {
                        scou2MovementRight();
                        if (timer2 == 6)
                        {
                            generateScout2Bullet();
                            timer2 = 0;
                        }
                    }
                    moveScout2Bullet();
                    timer2++;
                }

                /*CHECKING AND MOVING FAT BOY*/
                if (scout1Active == "false" && scout2Active == "false")
                {
                    printBoy(fx, fy);
                    if (direction3 == "up")
                    {
                        moveBoy();
                    }

                    if (direction3 == "down")
                    {
                        moveBoyDown();
                    }
                    if (timer3 == 6)
                    {
                        generateBoyBullet();
                        timer3 = 0;
                    }
                    timer3++;

                    moveBoyBullet();
                }

                if (timer4 == 50)
                {
                    generatePowerUp();
                    addPowerUp();
                    timer4 = 0;
                }
                timer4++;

                /*PLAYER MOVEMENTS*/

                if (GetAsyncKeyState(VK_LEFT))
                {
                    heroLeft();
                }

                if (GetAsyncKeyState(VK_RIGHT))
                {
                    heroRight();
                }

                if (GetAsyncKeyState(VK_DOWN))
                {
                    heroDown();
                }

                if (GetAsyncKeyState(VK_UP))
                {
                    heroUp();
                }
                if (GetAsyncKeyState(VK_SPACE))
                {

                    generateBullet();
                }
                if (GetAsyncKeyState(VK_ESCAPE))
                {
                    system("pause");
                    storeData();
                    break;
                }

                moveBullet();

                /*COLLOSION CHECKS*/

                collosion();
                collosion2();
                collosion3();
                enemyCollosion2();
                enemyCollosion();
                enemyCollosion3();

                Sleep(40);

                /*WIN AND LOSE CONDITIONS*/
                if (check(score) == true && check2(enemyScore) != true)
                {
                    flag1 = true;
                }
                else if (check(score) != true && check2(enemyScore) == true)
                {
                    flag2 = true;
                }

                if (flag1 == true)
                {
                    system("cls");
                    win();
                    getch();
                    resetting();
                    storeData();
                    system("pause");
                    break;
                }
                else if (flag2 == true)
                {
                    system("cls");
                    loss();
                    getch();
                    resetting();
                    storeData();
                    system("pause");
                    break;
                }
            }
        }

        if (op == "2")
        {
            system("cls");
            printHeader();
            inst();
            getch();
        }
        if (op == "3")
        {
            break;
        }
    }
}

/*FUNCTIONS*/

void resetting()
{

    scout1Active = "true";
    scout2Active = "true";

    direction = "left";
    direction2 = "left";
    direction3 = "up";
    previousChar = ' ';

    timer = 0;
    timer2 = 0;
    timer3 = 0;

    timer4 = 0;
    timer5 = 0;

    count1 = 0;
    count2 = 0;
    count3 = 0;

    hx = 28;
    hy = 10;

    sx = 140;
    sy = 20;

    s2x = 140;
    s2y = 5;

    fx = 140;
    fy = 10;

    score = 0;
    enemyScore = 100;

    bulletCount = 0;
    scoutBulletCount = 0;
    scout2BulletCount = 0;
    boyBulletCount = 0;
}

/*Collision Checks*/

// checking player bullet collision with scout
void collosion()
{
    for (int i = 0; i < bulletCount; i++)
    {
        if ((bx[i] + 1 == sx || bx[i] + 1 == sx + 2 || bx[i] + 3 == sx) && (by[i] == sy || by[i] == sy + 1 || by[i] == sy + 2 || by[i] == sy + 3))
        {
            if (scout1Active == "true")
            {
                addScore();
                eraseBullet(bx[i], by[i]);
                removeBullet(i);
            }
            count1 = count1 + 1;
            if (count1 == 10)
            {
                scout1Active = "false";
                eraseScout(sx, sy);
                count = count;
            }
        }
    }
}

// checking player bullet collision with second scout
void collosion2()
{
    for (int i = 0; i < bulletCount; i++)
    {
        if ((bx[i] + 1 == s2x || bx[i] + 1 == s2x + 2 || bx[i] + 3 == s2x) && (by[i] == s2y || by[i] == s2y + 1 || by[i] == s2y + 2 || by[i] == s2y + 3))
        {
            if (scout2Active == "true")
            {
                addScore();
                eraseBullet(bx[i], by[i]);
                removeBullet(i);
                count2++;
            }
            if (count2 == 20)
            {
                scout2Active = "false";
                eraseScout2(s2x, s2y);
                eraseBullet(bx[i], by[i]);
                count = count;
            }
        }
    }
}

// Checking player bullets collison with last enemy
void collosion3()
{
    for (int i = 0; i < bulletCount; i++)
    {
        if ((bx[i] + 1 == fx || bx[i] + 2 == fx - 1 || bx[i] + 3 == fx - 2 || bx[i] + 1 == fx - 3) && (by[i] == fy || by[i] == fy + 1 || by[i] == fy + 2 || by[i] == fy + 3))
        {

            addScore();
            eraseBullet(bx[i], by[i]);
            removeBullet(i);
            count3++;
        }
    }
}

// collison check for scout bullets with player
void enemyCollosion()
{
    for (int i = 0; i < scoutBulletCount; i++)
    {
        if ((scoutBulletX[i] + 1 == hx + 5 || scoutBulletX[i] + 1 == hx + 8 || scoutBulletX[i] + 1 == hx + 9) &&
            (scoutBulletY[i] + 1 == hy + 3 || scoutBulletY[i] + 1 == hy + 2 || scoutBulletY[i] + 1 == hy + 1 || scoutBulletY[i] + 1 == hy || scoutBulletY[i] + 1 == hy - 1 || scoutBulletY[i] + 1 == hy - 2 || scoutBulletY[i] + 1 == hy - 3))
        {
            minusScore();
            scout1BulletRemove(scoutBulletX[i], scoutBulletY[i]);
            removeBulletScout(i);
        }
    }
}

// collison check for second scout bullets with player
void enemyCollosion2()
{
    for (int i = 0; i < scout2BulletCount; i++)
    {
        if ((scout2BulletX[i] + 1 == hx + 5 || scout2BulletX[i] + 1 == hx + 8 || scout2BulletX[i] + 1 == hx + 9) &&
            (scout2BulletY[i] + 1 == hy + 3 || scout2BulletY[i] + 1 == hy + 2 || scout2BulletY[i] + 1 == hy + 1 || scout2BulletY[i] + 1 == hy || scout2BulletY[i] + 1 == hy - 1 || scout2BulletY[i] + 1 == hy - 2 || scout2BulletY[i] + 1 == hy - 3))
        {
            minusScore();
            scout2BulletRemove(scout2BulletX[i], scout2BulletY[i]);
            removeBulletScout2(i);
        }
    }
}

// collison check for last enemy bullets with player
void enemyCollosion3()
{
    for (int i = 0; i < boyBulletCount; i++)
    {
        if ((boyBulletX[i] + 1 == hx + 5 || boyBulletX[i] + 1 == hx + 8 || boyBulletX[i] + 1 == hx + 9 || boyBulletX[i] + 1 == hx + 7) &&
            (boyBulletY[i] + 1 == hy + 3 || boyBulletY[i] + 1 == hy + 2 || boyBulletY[i] + 1 == hy + 1 || boyBulletY[i] + 1 == hy || boyBulletY[i] + 1 == hy - 1 || boyBulletY[i] + 1 == hy - 2 || boyBulletY[i] + 1 == hy - 3))
        {
            minusScore2();
            boyBulletRemove(boyBulletX[i], boyBulletY[i]);
            removeBulletBoy(i);
        }
    }
}

/*Loading and storing*/

// storing the data
void storeData()
{
    fstream file;

    file.open("game.txt", ios ::out);
    file << to_string(hx) << endl;
    file << to_string(hy) << endl;
    file << to_string(sx) << endl;
    file << to_string(sy) << endl;
    file << to_string(s2x) << endl;
    file << to_string(s2y) << endl;
    file << to_string(fx) << endl;
    file << to_string(fy) << endl;
    // Saving scores
    file << to_string(score) << endl;
    file << to_string(enemyScore) << endl;
    // saving timers
    file << to_string(timer) << endl;
    file << to_string(timer2) << endl;
    file << to_string(timer3) << endl;
    file << to_string(timer4) << endl;
    file << to_string(timer5) << endl;
    // saving directions
    file << direction << endl;
    file << direction2 << endl;
    file << direction3 << endl;
    // saving counts
    file << to_string(count) << endl;
    file << to_string(count1) << endl;
    file << to_string(count2) << endl;
    file << to_string(count3) << endl;
    // saving array counts
    file << to_string(bulletCount) << endl;
    file << to_string(scoutBulletCount) << endl;
    file << to_string(scout2BulletCount) << endl;
    file << to_string(boyBulletCount) << endl;
    // saving scout status
    file << scout1Active << endl;
    file << scout2Active << endl;

    file.close();
}

// loading the data
void loadData()
{
    fstream file;
    string line;
    stringstream ss;

    file.open("game.txt", ios ::in);
    getline(file, line);
    // Loading coordinates
    ss.str(line);
    ss >> hx;
    getline(file, line);
    ss.str(line);
    ss >> hy;
    getline(file, line);
    ss.str(line);
    ss >> sx;
    getline(file, line);
    ss.str(line);
    ss >> sy;
    getline(file, line);
    ss.str(line);
    ss >> s2x;
    getline(file, line);
    ss.str(line);
    ss >> s2y;
    getline(file, line);
    ss.str(line);
    ss >> fx;
    getline(file, line);
    ss.str(line);
    ss >> fy;
    // Loading scores
    getline(file, line);
    ss.str(line);
    ss >> score;
    getline(file, line);
    ss.str(line);
    ss >> enemyScore;
    // Loading timers
    getline(file, line);
    ss.str(line);
    ss >> timer;
    getline(file, line);
    ss.str(line);
    ss >> timer2;
    getline(file, line);
    ss.str(line);
    ss >> timer3;
    getline(file, line);
    ss.str(line);
    ss >> timer4;
    getline(file, line);
    ss.str(line);
    ss >> timer5;
    // Loading directions
    getline(file, direction);
    getline(file, direction2);
    getline(file, direction3);
    // Loading Counts
    getline(file, line);
    ss.str(line);
    ss >> count;
    getline(file, line);
    ss.str(line);
    ss >> count1;
    getline(file, line);
    ss.str(line);
    ss >> count2;
    getline(file, line);
    ss.str(line);
    ss >> count3;
    // loading array bullet count
    getline(file, line);
    ss.str(line);
    ss >> bulletCount;
    getline(file, line);
    ss.str(line);
    ss >> scoutBulletCount;
    getline(file, line);
    ss.str(line);
    ss >> scout2BulletCount;
    getline(file, line);
    ss.str(line);
    ss >> boyBulletCount;
    // loading scout status
    getline(file, scout1Active);
    getline(file, scout2Active);

    file.close();
}

/*POWER UP FUNCTIONS*/
void addPowerUp()
{

    if (hx == heartX || hx + 1 == heartX || hx + 3 == heartX || hx + 5 == heartX || hx + 7 == heartX || hx + 9 == heartX || hx + 11 == heartX || hx + 13 == heartX || hx + 16 == heartX)
    {
        enemyScore = enemyScore + 10;
    }
}

void removepowerUp()
{
    cout << " ";
    enemyScore = enemyScore;
}

void generatePowerUp()
{

    char heart = '\3';
    gotoxy(heartX, heartY);
    cout << heart;
}

/*FAT BOY FUNCTIONS*/

// moving bullets
void moveBoyBullet()
{
    for (int i = 0; i < boyBulletCount; i++)
    {
        char nextLocation = getCharATXY(boyBulletX[i] - 2, boyBulletY[i]);
        if (nextLocation != ' ')
        {
            boyBulletRemove(boyBulletX[i], boyBulletY[i]);
            removeBulletBoy(i);
        }
        else
        {
            boyBulletRemove(boyBulletX[i], boyBulletY[i]);
            boyBulletX[i] = boyBulletX[i] - 2;
            boyBullet(boyBulletX[i], boyBulletY[i]);
        }
    }
}

// generating boy bullets
void generateBoyBullet()
{
    boyBulletX[boyBulletCount] = fx - 2;
    boyBulletY[boyBulletCount] = fy;

    boyBulletCount++;
}

// removing bullets from arrays
void removeBulletBoy(int x)
{
    for (int i = x; i < boyBulletCount - 1; i++)
    {
        boyBulletX[i] = boyBulletX[i + 1];
        boyBulletY[i] = boyBulletY[i + 1];
    }
    boyBulletCount--;
}

// erasing bullets
void boyBulletRemove(int x, int y)
{
    gotoxy(x, y + 1);
    cout << " " << endl;
}

// printing bullets
void boyBullet(int x, int y)
{
    gotoxy(x, y + 1);
    cout << "0" << endl;
}

// moving boy down
void moveBoy()
{
    char nextLocation = getCharATXY(fx - 5, fy + 5);
    if (nextLocation == ' ' || nextLocation == '-')
    {
        removeBoy(fx, fy);
        fy = fy + 1;
        printBoy(fx, fy);
    }
    else if (nextLocation == '#')
    {
        direction3 = "down";
    }
}

// moving boy up
void moveBoyDown()
{

    char nextLocation = getCharATXY(fx - 2, fy - 5);
    if (nextLocation == ' ' || nextLocation == '-')
    {
        removeBoy(fx, fy);
        fy = fy - 1;
        printBoy(fx, fy);
    }
    else if (nextLocation == '#')
    {
        direction3 = "up";
    }
}

// erasing the fat boy
void removeBoy(int x, int y)
{

    char boyErase[4][16] = {{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                            {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                            {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                            {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}};

    for (int i = 0; i < 4; i++)
    {
        gotoxy(x, y + i);
        for (int j = 0; j < 16; j++)
        {
            cout << boyErase[i][j];
        }
        cout << endl;
    }
}

// printing the fat boy
void printBoy(int x, int y)
{
    setColor(4);
    char box = 219;
    char line = 205;
    char tail = 185;
    char up = 244;
    char down = 245;
    char boy[4][16] = {{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', up},
                       {' ', line, line, line, box, box, box, box, box, box, box, box, box, box, tail},
                       {' ', line, line, line, box, box, box, box, box, box, box, box, box, box, tail}, // initializing array
                       {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', down}};

    for (int i = 0; i < 4; i++)
    {
        gotoxy(x, y + i);
        for (int j = 0; j < 16; j++)
        {
            cout << boy[i][j];
        }
        cout << endl;
    }
    setColor(7);
}

/*SCOUT 2 FUNCTIONS*/

// Moving bullets
void moveScout2Bullet()
{
    for (int i = 0; i < scout2BulletCount; i++)
    {
        char nextLocation = getCharATXY(scout2BulletX[i] - 1, scout2BulletY[i]);
        if (nextLocation != ' ')
        {
            scout2BulletRemove(scout2BulletX[i], scout2BulletY[i]);
            removeBulletScout2(i);
        }
        else
        {
            scout2BulletRemove(scout2BulletX[i], scout2BulletY[i]);
            scout2BulletX[i] = scout2BulletX[i] - 1;
            scout2Bullet(scout2BulletX[i], scout2BulletY[i]);
        }
    }
}

// generating bullets
void generateScout2Bullet()
{
    scout2BulletX[scout2BulletCount] = s2x - 1;
    scout2BulletY[scout2BulletCount] = s2y;

    scout2BulletCount++;
}

// removing from arrays
void removeBulletScout2(int x)
{
    for (int i = x; i < scout2BulletCount - 1; i++)
    {
        scout2BulletX[i] = scout2BulletX[i + 1];
        scout2BulletY[i] = scout2BulletY[i + 1];
    }
    scout2BulletCount--;
}

// erasing the bullet
void scout2BulletRemove(int x, int y)
{
    gotoxy(x, y + 1);
    cout << " " << endl;
}

// printing bullet
void scout2Bullet(int x, int y)
{
    gotoxy(x, y + 1);
    cout << "." << endl;
}

// erasing scout second
void eraseScout2(int x, int y)
{
    char scout2Erase[4][8] = {{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                              {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                              {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}};

    for (int i = 0; i < 3; i++)
    {
        gotoxy(x, y + i);
        for (int j = 0; j < 8; j++)
        {
            cout << scout2Erase[i][j];
        }
        cout << endl;
    }
}

// pring scout second
void printScout2(int x, int y)
{
    setColor(6);
    char scout2[4][8] = {{' ', ' ', '*', ' ', ' ', '*', '*', '*'},
                         {'*', '*', '*', ' ', '*', '*', '*', '*'}, // initializating the array
                         {' ', ' ', '*', ' ', ' ', '*', '*', '*'}};
    for (int i = 0; i < 3; i++)
    {
        gotoxy(x, y + i);
        for (int j = 0; j < 8; j++)
        {
            cout << scout2[i][j];
        }
        cout << endl;
    }
    setColor(7);
}

// moving scout2 vertically
void scou2MovementRight()
{
    char nextLocation = getCharATXY(s2x - 5, s2y - 4);
    if (nextLocation == '#')
    {
        direction2 = "down";
    }
    else if (nextLocation == ' ' || nextLocation == '-')
    {
        eraseScout2(s2x, s2y);
        s2y = s2y - 1;
        previousChar = nextLocation;
        printScout2(s2x, s2y);
    }
}

// moving scout2 down
void scou2MovementDown()
{
    char nextLocation = getCharATXY(s2x - 5, s2y + 3);

    if (s2y == 18)
    {
        direction2 = "right";
    }

    else if (nextLocation == ' ' || nextLocation == '-')
    {
        eraseScout2(s2x, s2y);
        s2y = s2y + 1;
        previousChar = nextLocation;
        printScout2(s2x, s2y);
    }
}

// moving scout 2 to left
void scou2MovementLeft()
{
    char nextLocation = getCharATXY(s2x - 5, s2y);
    if (nextLocation == '|')
    {
        direction2 = "right";
    }
    else if (s2x == 100)
    {
        direction2 = "down";
    }
    else if (nextLocation == ' ' || nextLocation == '-')
    {
        eraseScout2(s2x, s2y);
        s2x = s2x - 1;
        previousChar = nextLocation;
        printScout2(s2x, s2y);
    }
}

/*SCOUT 1 FUNCTIONS*/

// Moving the scout bullet
void moveScoutBullet()
{
    for (int i = 0; i < scoutBulletCount; i++)
    {
        char nextLocation = getCharATXY(scoutBulletX[i] - 1, scoutBulletY[i]);
        if (nextLocation != ' ')
        {
            scout1BulletRemove(scoutBulletX[i], scoutBulletY[i]);
            removeBulletScout(i);
        }
        else if (nextLocation == ' ')
        {
            scout1BulletRemove(scoutBulletX[i], scoutBulletY[i]);
            scoutBulletX[i] = scoutBulletX[i] - 1;
            scout1Bullet(scoutBulletX[i], scoutBulletY[i]);
        }
    }
}

// Generating scout bullet
void generateScout1Bullet()
{
    scoutBulletX[scoutBulletCount] = sx - 1;
    scoutBulletY[scoutBulletCount] = sy;

    scoutBulletCount++;
}

// removing bullet from array
void removeBulletScout(int x)
{
    for (int i = x; i < scoutBulletCount - 1; i++)
    {
        scoutBulletX[i] = scoutBulletX[i + 1];
        scoutBulletY[i] = scoutBulletY[i + 1];
    }
    scoutBulletCount--;
}

// erasing bullet
void scout1BulletRemove(int x, int y)
{
    gotoxy(x, y + 1);
    cout << " " << endl;
}

// printing bullet
void scout1Bullet(int x, int y)
{
    gotoxy(x, y + 1);
    cout << "*" << endl;
}

// Moving scout to left again
void scout1MovementRight()
{
    char nextLocation = getCharATXY(sx - 5, sy);
    if (nextLocation == '|')
    {
        direction = "up";
    }
    else if (nextLocation == ' ' || nextLocation == '-')
    {
        eraseScout(sx, sy);
        sx = sx - 1;
        previousChar = nextLocation;
        printScout(sx, sy);
    }
}

// Moving scout to up second
void scou1MovementUp()
{
    char nextLocation = getCharATXY(sx - 5, sy + 3);

    if (sy == 5)
    {
        direction = "right";
    }

    else if (nextLocation == ' ' || nextLocation == '-')
    {
        eraseScout(sx, sy);
        sy = sy - 1;
        previousChar = nextLocation;
        printScout(sx, sy);
    }
}

// Moving scout to left first
void scou1MovementLeft()
{
    char nextLocation = getCharATXY(sx - 5, sy);
    if (nextLocation == '|')
    {
        direction = "right";
    }
    else if (sx == 120)
    {
        direction = "up";
    }
    else if (nextLocation == ' ' || nextLocation == '-')
    {
        eraseScout(sx, sy);
        sx = sx - 1;
        previousChar = nextLocation;
        printScout(sx, sy);
    }
}

// Erasing scout
void eraseScout(int x, int y)
{
    char scout1Erase[4][8] = {{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                              {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                              {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}};
    for (int i = 0; i < 3; i++)
    {
        gotoxy(x, y + i);
        for (int j = 0; j < 8; j++)
        {
            cout << scout1Erase[i][j];
        }
        cout << endl;
    }
}

// Printing scout
void printScout(int x, int y)
{
    setColor(1);
    char scout1[4][8] = {{' ', ' ', '*', ' ', ' ', '*', '*', '*'},
                         {'*', '*', '*', ' ', '*', '*', '*', '*'},
                         {' ', ' ', '*', ' ', ' ', '*', '*', '*'}};

    for (int i = 0; i < 3; i++)
    {
        gotoxy(x, y + i);
        for (int j = 0; j < 8; j++)
        {
            cout << scout1[i][j];
        }
        cout << endl;
    }
    cout << endl;

    setColor(7);
}

/* CHECKING SCORES*/

bool check(int score)
{
    if (score >= 200)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool check2(int health)
{
    if (health <= 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/*SCORING FUNCTIONS*/

void addScore()
{
    score = score + 2; // Increasing score of player
}
void minusScore()
{
    enemyScore = enemyScore - 5; // Decreasing health for fisrt 2 enemies
}

void minusScore2()
{
    enemyScore = enemyScore - 10; // Decreasing health for last enemy
}

void showScore(int playerScore, int health)
{
    gotoxy(1, 1);
    cout << "score: " << playerScore << " ";
    gotoxy(1, 2);
    cout << "Health: " << health << " ";
}

/*FUNCTIONS FOR PLAYER*/

// Generating bullets
void generateBullet()
{
    bx[bulletCount] = hx + 20;
    by[bulletCount] = hy + 3;
    gotoxy(hx + 20, hy + 3);
    cout << "-";
    bulletCount++;
}

// Removing bullets from array
void removeBullet(int x)
{
    for (int i = x; i < bulletCount - 1; i++)
    {
        bx[i] = bx[i + 1];
        by[i] = by[i + 1];
    }
    bulletCount--;
}

// Moving bullets
void moveBullet()
{
    for (int i = 0; i < bulletCount; i++)
    {
        char nextLocation = getCharATXY(bx[i] + 1, by[i] + 1);
        if (nextLocation != ' ')
        {
            eraseBullet(bx[i], by[i]);
            removeBullet(i);
        }
        else
        {
            eraseBullet(bx[i], by[i]);
            bx[i] = bx[i] + 1;
            printBullet(bx[i], by[i]);
        }
    }
}

// Erasing bullet
void eraseBullet(int x, int y)
{
    gotoxy(x, y);
    cout << " ";
}

// Printing bullet
void printBullet(int x, int y)
{
    gotoxy(x, y);
    cout << "-";
}

/*MOVING PLAYER FUNCTION*/
void heroUp()
{
    char nextLocation = getCharATXY(hx, hy - 1);
    if ((nextLocation == ' '))
    {
        eraseHero(hx, hy);
        hy = hy - 1; // moving player up
        printHero(hx, hy);
    }
}

void heroDown()
{
    char nextLocation = getCharATXY(hx, hy + 6);
    if ((nextLocation == ' ') || (nextLocation == '-'))
    {
        eraseHero(hx, hy);
        hy = hy + 1; // moving player down
        printHero(hx, hy);
    }
}

void heroRight()
{
    char nextLocation = getCharATXY(hx + 20, hy);
    if (nextLocation == ' ' || nextLocation == '-')
    {
        eraseHero(hx, hy);
        hx = hx + 1; // moving player right
        printHero(hx, hy);
    }
}
void heroLeft()
{
    char nextLocation = getCharATXY(hx - 1, hy);
    if (nextLocation == ' ')
    {
        eraseHero(hx, hy);
        hx = hx - 1; // moving player left
        printHero(hx, hy);
    }
}

void eraseHero(int x, int y)
{
    char box = 219;

    char heroErase[5][20] = {
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, // initializaing array
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    };

    for (int i = 0; i < 5; i++)
    {
        gotoxy(x, y + i);
        for (int j = 0; j < 17; j++)
        {

            cout << heroErase[i][j]; // removing array
        }
        cout << endl;
    }
}

void printHero(int x, int y)
{
    setColor(2);
    char box = 219;

    char hero[5][20] = {
        {' ', ' ', ' ', ' ', '_', '_', '_', '_', '_', '_'},
        {' ', ' ', ' ', '|', ' ', ' '},
        {box, box, box, box, box, box, box, box, box, box, '-', '-', '-', '-', '-', '-', '>'}, // initializaing array
        {box, box, box, box, box, box, box, box, box, box, '-', '-', '-', '-', '-', '-', '>'},
        {' ', ' ', ' ', '|', '_', '_', '_', '_', '_', '_'},
    };

    for (int i = 0; i < 5; i++)
    {
        gotoxy(x, y + i);
        for (int j = 0; j < 17; j++)
        {
            cout << hero[i][j]; // printing array
        }
        cout << endl;
    }
    setColor(7);
}

/*PRINTING OTHERS FUNCTIONS*/

string menu()
{

    cout << endl
         << endl;
    cout << "\t1.PLAY GAME" << endl;
    cout << "\t2.INSTRUCTIONS" << endl;
    cout << "\t3.EXIT" << endl;
    cout << "Enter your option: ";
    cin >> option;
    cout << endl;
    option = validateOption(option);
    return option;
}

// validating the input
string validateOption(string option)
{
    while (true)
    {
        bool flag = true;

        for (int i = 0; i < option.length(); i++)
        {
            if (option[i] < 49 || option[i] > 51)
            {
                flag = false;
                cout << "Error" << endl;
                break;
            }
        }

        if (flag)
        {
            return option;
        }
        cin >> option;
    }
}

// printing instructions
void inst()
{

    cout << "\tArrow Up = MOVE UP" << endl;
    cout << "\tArrow Down  = MOVE DOWN" << endl;
    cout << "\tLeft arrow = MOVE LEFT" << endl;
    cout << "\tRight arrow = MOVE RIGHT" << endl;
    cout << "\tSpscebar = Shoot" << endl;
    cout << "RULES:" << endl;
    cout << "\tAvoid enemy bullets and shoot them" << endl;
    cout << "\tFor every bullet you hit the enemy you will get 2 score" << endl;
    cout << "\tIf the enemy bullet hits you , your health will be decremented" << endl;
    cout << "\tTake your score to 100 to win the game" << endl;
    cout << "\tIF your health gets less then 0 game will be over" << endl;
    cout << "\t\t\tBEST OF lucK" << endl;
    cout << "PRESS ANY KEY TO CONTINUE" << endl;
}

void win()
{
    setColor(2);
    cout <<endl<<endl;
    cout << "yyyyyyy           yyyyyyy   ooooooooooo   uuuuuu    uuuuuu       wwwwwww           wwwww           wwwwwww   ooooooooooo   nnnn  nnnnnnnn" << endl;
    cout << " y:::::y         y:::::y  oo:::::::::::oo u::::u    u::::u        w:::::w         w:::::w         w:::::w  oo:::::::::::oo n:::nn::::::::nn  " << endl;
    cout << "  y:::::y       y:::::y  o:::::::::::::::ou::::u    u::::u         w:::::w       w:::::::w       w:::::w  o:::::::::::::::on::::::::::::::nn " << endl;
    cout << "   y:::::y     y:::::y   o:::::ooooo:::::ou::::u    u::::u          w:::::w     w:::::::::w     w:::::w   o:::::ooooo:::::onn:::::::::::::::n" << endl;
    cout << "    y:::::y   y:::::y    o::::o     o::::ou::::u    u::::u           w:::::w   w:::::w:::::w   w:::::w    o::::o     o::::o  n:::::nnnn:::::n" << endl;
    cout << "     y:::::y y:::::y     o::::o     o::::ou::::u    u::::u            w:::::w w:::::w w:::::w w:::::w     o::::o     o::::o  n::::n    n::::n" << endl;
    cout << "      y:::::y:::::y      o::::o     o::::ou::::u    u::::u             w:::::w:::::w   w:::::w:::::w      o::::o     o::::o  n::::n    n::::n" << endl;
    cout << "       y:::::::::y       o::::o     o::::ou:::::uuuu:::::u              w:::::::::w     w:::::::::w       o::::o     o::::o  n::::n    n::::n" << endl;
    cout << "        y:::::::y        o:::::ooooo:::::ou:::::::::::::::uu             w:::::::w       w:::::::w        o:::::ooooo:::::o  n::::n    n::::n" << endl;
    cout << "         y:::::y         o:::::::::::::::o u:::::::::::::::u              w:::::w         w:::::w         o:::::::::::::::o  n::::n    n::::n" << endl;
    cout << "        y:::::y           oo:::::::::::oo   uu::::::::uu:::u               w:::w           w:::w           oo:::::::::::oo   n::::n    n::::n" << endl;
    cout << "       y:::::y              ooooooooooo       uuuuuuuu  uuuu                www             www              ooooooooooo     nnnnnn    nnnnnn" << endl;
    cout << "      y:::::y                                                                                                                                " << endl;
    cout << "     y:::::y                                                                                                                                 " << endl;
    cout << "    y:::::y                                                                                                                                  " << endl;
    cout << "   y:::::y                                                                                                                                   " << endl;
    cout << "  yyyyyyy                                                                                                                                    " << endl;
    setColor(7);
}

void loss()
{
    setColor(4);
    cout<<endl<<endl;
    cout << ":::   :::  ::::::::  :::    :::  :::         ::::::::   ::::::::  :::::::::::" << endl;
    cout << ":+:   :+: :+:    :+: :+:    :+:  :+:        :+:    :+: :+:    :+:     :+:     " << endl;
    cout << " +:+ +:+  +:+    +:+ +:+    +:+  +:+        +:+    +:+ +:+            +:+     " << endl;
    cout << "  +#++:   +#+    +:+ +#+    +:+  +#+        +#+    +:+ +#++:++#++     +#+     " << endl;
    cout << "   +#+    +#+    +#+ +#+    +#+  +#+        +#+    +#+        +#+     +#+     " << endl;
    cout << "   #+#    #+#    #+# #+#    #+#  #+#        #+#    #+# #+#    #+#     #+#     " << endl;
    cout << "   ###     ########   ########   ##########  ########   ########      ###     " << endl;
    setColor(7);
}

void printMaze()
{
    setColor(5);

    cout << "\t\t################################################################################################################################################" << endl;
    cout << "\t\t|                                                                                                                                                |" << endl;
    cout << "\t\t|                                                                                                                                                |" << endl;
    cout << "\t\t|                                                                                                                                                |" << endl;
    cout << "\t\t|                                                                                                                                                |" << endl;
    cout << "\t\t|                                                                                                                                                |" << endl;
    cout << "\t\t|                                                                                                                                                |" << endl;
    cout << "\t\t|                                                                                                                                                |" << endl;
    cout << "\t\t|                                                                                                                                                |" << endl;
    cout << "\t\t|                                                                                                                                                |" << endl;
    cout << "\t\t|                                                                                                                                                |" << endl;
    cout << "\t\t|                                                                                                                                                |" << endl;
    cout << "\t\t|                                                                                                                                                |" << endl;
    cout << "\t\t|                                                                                                                                                |" << endl;
    cout << "\t\t|                                                                                                                                                |" << endl;
    cout << "\t\t|                                                                                                                                                |" << endl;
    cout << "\t\t|                                                                                                                                                |" << endl;
    cout << "\t\t|                                                                                                                                                |" << endl;
    cout << "\t\t|                                                                                                                                                |" << endl;
    cout << "\t\t|                                                                                                                                                |" << endl;
    cout << "\t\t|                                                                                                                                                |" << endl;
    cout << "\t\t|                                                                                                                                                |" << endl;
    cout << "\t\t|                                                                                                                                                |" << endl;
    cout << "\t\t|                                                                                                                                                |" << endl;
    cout << "\t\t|                                                                                                                                                |" << endl;
    cout << "\t\t|                                                                                                                                                |" << endl;
    cout << "\t\t################################################################################################################################################" << endl;
    setColor(7);
}

void printHeader()
{
    setColor(1);
    cout<<endl<<endl;
    cout << "\t\t\t\t.d8888b.         d8888 888             d8888  .d8888b.  88888888888 8888888  .d8888b." << endl;
    cout << "\t\t\t\td88P  Y88b       d88888 888            d88888 d88P  Y88b     888       888   d88P  Y88b" << endl;
    cout << "\t\t\t\t888    888      d88P888 888           d88P888 888    888     888       888   888    888" << endl;
    cout << "\t\t\t\t888            d88P 888 888          d88P 888 888            888       888   888       " << endl;
    cout << "\t\t\t\t888  88888    d88P  888 888         d88P  888 888            888       888   888       " << endl;
    cout << "\t\t\t\t888    888   d88P   888 888        d88P   888 888    888     888       888   888    888" << endl;
    cout << "\t\t\t\tY88b  d88P  d8888888888 888       d8888888888 Y88b  d88P     888       888   Y88b  d88P " << endl;
    cout << "\t\t\t\tY8888P88  d88P     888 88888888 d88P     888   Y8888P       888     8888888   Y8888P" << endl;
    cout << endl
         << endl;

    cout << "\t\t\t\t888       888        d8888 8888888b.  8888888888P  .d88888b.  888b    888 8888888888 " << endl;
    cout << "\t\t\t\t888   o   888       d88888 888   Y88b       d88P   d88P"
            "Y88b  8888b   888 888        "
         << endl;
    cout << "\t\t\t\t888  d8b  888      d88P888 888    888      d88P   888     888 88888b  888 888        " << endl;
    cout << "\t\t\t\t888 d888b 888     d88P 888 888   d88P     d88P    888     888 888Y88b 888 8888888    " << endl;
    cout << "\t\t\t\t888d88888b888    d88P  888 8888888P      d88P     888     888 888 Y88b888 888        " << endl;
    cout << "\t\t\t\t88888P Y88888   d88P   888 888 T88b     d88P      888     888 888  Y88888 888        " << endl;
    cout << "\t\t\t\t8888P   Y8888  d8888888888 888  T88b   d88P       Y88b. .d88P 888   Y8888 888        " << endl;
    cout << "\t\t\t\t888P     Y888 d88P     888 888   T88b d8888888888   Y88888P   888    Y888 8888888888 " << endl;
    setColor(7);
}

void print()
{

    setColor(3);
    cout<<endl<<endl;
    cout << "                                        -+" << endl;
    cout << "                                       -#*+" << endl;
    cout << "                                     -.%+=%:-" << endl;
    cout << "                                     **%+=###:" << endl;
    cout << "                                     #%*==*%%:" << endl;
    cout << "                                     %%*==+%%:" << endl;
    cout << "                                   -##+**+**+ " << endl;
    cout << "                                    ####%%###%:" << endl;
    cout << "                                    .=##%%#**. " << endl;
    cout << "                             :.   ==.-#%###%* =+.   :.  " << endl;
    cout << "                         +=-++=. =%%#*%#*%#%#*%## .:*+=-+: " << endl;
    cout << "                      . :####++*##%#*%%***+%%*#%###++#*##=   " << endl;
    cout << "                    :.+=+#*+==:. .##*%#=*%=*%##%: .:-+=*#*+=-:. " << endl;
    cout << "                    *+*#+=+=+**##*%##%#=*#+*%##%*#%*#+=+=+#**+:  " << endl;
    cout << "                  :=#%@%+=-:..  .-##+%#+#***%**%-:  ..:-=+#%@#*-  " << endl;
    cout << "                 .%#*=-.          ##+%%*#%*#%**%          .:=+#%-  " << endl;
    cout << "                  .              =##-#%+%%+##=+#*               .     " << endl;
    cout << "                                 :::-#+%##%+#+.-:                   " << endl;
    cout << "                                    :*%######-                      " << endl;
    cout << "                                   .-*+*##%=%-:                     " << endl;
    cout << "                                   : . .::: . :                     " << endl;
    setColor(7);
}

void setColor(int color)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

void gotoxy(int x, int y)
{
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}

char getCharATXY(short int x, short int y)
{

    CHAR_INFO ci;
    COORD xy = {0, 0};
    SMALL_RECT rect = {x, y, x, y};
    COORD coordBufsize;
    coordBufsize.X = 1;
    coordBufsize.Y = 1;
    return ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, coordBufsize, xy, &rect) ? ci.Char.AsciiChar : ' ';
}