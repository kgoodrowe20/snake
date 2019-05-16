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
  DrawPx(playerX, playerY, Red);
  spawn();
  moveplayer();
  check();
  eatapple();
  DisplaySlate();
  delay(150);
  ClearSlate();
}

void spawn()
{
  DrawPx(appleX, appleY, Yellow);
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
        playerX--;
      }
    if (Button_Right)
      {
        playerX++;
      }
    if (Button_Down)
      {
        playerY--;
      }
    if (Button_Up)
      {
        playerY++;
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
