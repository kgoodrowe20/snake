#include <MeggyJrSimple.h>

int playerX, playerY;
int appleX, appleY;
boolean gotApple = false;
int dir;
int marker;

struct Point
{
  int x;
  int y;
};

Point s1 = {3,4};
Point s2 = {4,4};
Point s3 = {5,4};
Point s4 = {6,4};

Point snakeArray[64] = {s1, s2, s3, s4};

void setup()
{
  MeggyJrSimpleSetup();
  playerX = 3;
  playerY = 4;
  appleX = random(8);
  appleY = random(8);
  dir = 90;
  marker = 4;
}

void loop()
{
  spawn();
  drawsnake();
  updatesnake();
  eatapple();
  moveplayer();
  movee();
  check();
  DisplaySlate();
  ClearSlate();
  delay(120);
}

void spawn()
{
  DrawPx(appleX, appleY, Yellow);
  if (gotApple == true)
    {
      appleX = random(8);
      appleY = random(8);
      DrawPx(appleX, appleY, Yellow);
      gotApple = false;
    }
}

void eatapple()
{
  if (playerX == appleX && playerY == appleY)
    {
      gotApple = true;
      
    }
}

void drawsnake()
{
  for (int i = 0; i < marker; i++)
    {
     DrawPx(snakeArray[i].x,snakeArray[i].y,1);
    }
}

void updatesnake()
{
  for (int i = marker - 1; i > 0; i--)
  {
    snakeArray[i] = snakeArray[i-1];
  }
  if (dir == 0)
  {
    if (snakeArray[0].y > 6)
    {
      snakeArray[0].y = 0;
    }
    else snakeArray[0].y++;
  }
  if (dir == 180)
  {
    if (snakeArray[0].y < 1 )
    {
      snakeArray[0].y = 7;
    }
    else snakeArray[0].y--;
  }
  if (dir == 90)
  {
    if (snakeArray[0].x > 6)
    {
      snakeArray[0].x = 0;
    }
    else snakeArray[0].x++;
  }
    if (dir == 270)
  {
    if (snakeArray[0].x < 1)
    {
      snakeArray[0].x = 7;
    }
    else snakeArray[0].x--;
  }
}

void moveplayer()
{
  CheckButtonsPress(); 
    if (Button_Left)
      {
        dir = 270;
      }
    if (Button_Right)
      {
        dir = 90;
      }
    if (Button_Down)
      {
        dir = 180;
      }
    if (Button_Up)
      {
        dir = 0;
      }
}

void movee()
{
 if (dir == 270)
    {
      playerX--;   
    }
 if (dir == 90)
    {
      playerX++; 
    }
 if (dir == 0)
    {
      playerY++;
    }
 if (dir == 180)
    {
      playerY--; 
    }
}
  
void check()
{
  if(playerX > 7)
  {
    playerX = 0;
  }
  if(playerX < 0)
  {
    playerX = 7;
  }
  if(playerY > 7)
  {
    playerY = 0;
  }
  if(playerY < 0)
  {
    playerY = 7;
  }
}
