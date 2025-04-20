#include "AlienManager.h"

#include <iostream>

AlienManager::AlienManager(){}

AlienManager::AlienManager(int amount, int max)
{
    aliens = new AlienShip[amount];
    MaxPerLine = max;
    Amount = amount;
}

AlienManager::~AlienManager()
{
    delete[] aliens;
}


void AlienManager::UpdateAliens()
{
    for (int i = 0; i < Amount; i++)
    {
        if(aliens[i].IsAlive)
        {
            aliens[i].MoveAndDraw(0,0);
        }
    }
}

void AlienManager::InitializeAliens()
{
    int count = MaxPerLine;
    
    float offset = 60;
    float separation = (GetScreenWidth() -  (offset * 2)) / (MaxPerLine - 1);
    float padding = 40;
    
    float currentPosX = offset;
    float currentPosY = offset;
    
    for (int i = 0; i < Amount; i++)
    {
        std::cout << currentPosX << " " << currentPosY << std::endl;
        aliens[i] = AlienShip(V2(currentPosX, currentPosY));
        currentPosX += separation;
        
        if(currentPosX > GetScreenWidth() - offset)
        {
            currentPosX = offset;
            currentPosY += padding;
        }
    }
}

void AlienManager::CheckForCollisions(BulletPool* bulletPool)
{
    for(int i = 0; i < bulletPool->Amount; i++)
    {
        if(!bulletPool->bullets[i].IsActive) continue;

        for(int j = 0; j < Amount; j++)
        {
            if(CheckCollisionCircles(V2::CastToVector2(bulletPool->bullets[i].Center), 4, V2::CastToVector2(aliens[j].GetPosition()), aliens[j].GetRadius()))
            {
                aliens[j].IsAlive = false;
                aliens[j].SetPosition(V2(-100, -100));
                bulletPool->Pool(i);
                break;
            }
        }
    }
}




