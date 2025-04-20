#include "AlienManager.h"

#include <iostream>

AlienManager::AlienManager(){}

AlienManager::AlienManager(int amount, int max)
{
    aliens = new AlienShip[amount];
    bulletPool = new BulletPool(amount * 3);
    MaxPerLine = max;
    Amount = amount;
}

AlienManager::~AlienManager()
{
    delete[] aliens;
}


void AlienManager::UpdateAliens()
{
    bool flag = false;
    
    for (int i = 0; i < Amount; i++)
    {
        if(aliens[i].IsAlive)
        {
            flag = true;
            
            aliens[i].CheckShootingStatus();

            if(aliens[i].currentFireRate <= 0)
            {
                bulletPool->ActivateBullet(aliens[i].GetPosition(), V2_DOWN, RED);
                aliens[i].currentFireRate = aliens[i].GetFireRate() + GetRandomValue(0, aliens[i].maxRandInterval);
            }
            
            aliens[i].MoveAndDraw(0,0);
        }
    }

    bulletPool->UpdateBullets();

    if(!flag)
    {
        GameManager::instance->EndGame(true);
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
        aliens[i].currentFireRate = aliens[i].GetFireRate() + GetRandomValue(0, aliens[i].maxRandInterval);
        
        currentPosX += separation;
        
        if(currentPosX > GetScreenWidth() - offset)
        {
            currentPosX = offset;
            currentPosY += padding;
        }
    }
}

void AlienManager::CheckForAlienCollisions(BulletPool* playerBulletPool)
{
    for(int i = 0; i < playerBulletPool->Amount; i++)
    {
        if(!playerBulletPool->bullets[i].IsActive) continue;

        for(int j = 0; j < Amount; j++)
        {
            if(CheckCollisionCircles(V2::CastToVector2(playerBulletPool->bullets[i].Center), 4, V2::CastToVector2(aliens[j].GetPosition()), aliens[j].GetRadius()))
            {
                aliens[j].TakeDamage();
                playerBulletPool->Pool(i);
                break;
            }
        }
    }
}

void AlienManager::CheckForPlayerCollisions(Player* player)
{
    for(int i = 0; i < bulletPool->Amount; i++)
    {
        if(CheckCollisionCircles(V2::CastToVector2(bulletPool->bullets[i].Center), 4, V2::CastToVector2(player->GetPosition()), player->GetRadius()))
        {
            player->TakeDamage();
            bulletPool->Pool(i);
            break;
        }
    }
}




