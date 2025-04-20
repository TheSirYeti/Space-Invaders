#pragma once
#include "Ships/AlienShip.h"
#include "Bullets/BulletPool.h"

class AlienManager
{
public:
    AlienShip* aliens;
    int Amount;
    float MaxPerLine;

    AlienManager();
    AlienManager(int amount, int max);
    ~AlienManager();

    void UpdateAliens();
    void InitializeAliens();
    void CheckForCollisions(BulletPool* bulletPool);
};
