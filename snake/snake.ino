#include <MeggyJrSimple.h>

int appleX, appleY;
int dir;
int marker;
boolean dead;

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
  appleX = random(8);
  appleY = random(8);
  dir = 180;
  marker = 4;
  dead = false;
}

void loop()
{
  if (dead)
    lose();
  else
  {
    eatapple();
    drawApple();  
    drawsnake();
    updatesnake();
    moveplayer();
  }
  DisplaySlate();
  ClearSlate();
  delay(150);
}

void drawApple()
{
    DrawPx(appleX, appleY, Yellow);
}

void eatapple()
{
  if (snakeArray[0].x == appleX && snakeArray[0].y == appleY)
    {
      appleX = random(8);
      appleY = random(8);
      marker++;
    }
}


void drawsnake()
{
  for (int i = 0; i < marker; i++)
    {
     DrawPx(snakeArray[i].x,snakeArray[i].y,Blue);
    }
  for (int i = 1; i < marker; i++)
    {
     DrawPx(snakeArray[i].x,snakeArray[i].y,Red);
    }
  if (ReadPx(snakeArray[0].x, snakeArray[0].y) == 1)
   {
    dead = true;
   }      
}

void lose()
{
  ClearSlate();
  while (dead == true) 
  {
    for (int i = 0; i < 8; i++)
    {
      for (int j = 0; j < 8; j++)
      {
        CheckButtonsPress();
        if (Button_A || Button_B)
        {
          dead = false;
          marker = 4;
          break;
        }
        DrawPx (i, j, 1);
        DisplaySlate();
        //delay(100);
      }
    }
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
