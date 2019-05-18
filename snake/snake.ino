#include <MeggyJrSimple.h>

int playerX, playerY;
int appleX, appleY;
boolean gotApple = false;
int dir;

void setup()
{
  MeggyJrSimpleSetup();
  playerX = 3;
  playerY = 4;
  appleX = random(8);
  appleY = random(8);
  dir = 0;
}

void loop()
{
  spawn();
  DrawPx(playerX, playerY, Red);
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

//struct point
