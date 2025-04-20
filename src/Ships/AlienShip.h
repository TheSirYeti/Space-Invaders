#pragma once
#include "Ship.h"
#include "Managers/GameManager.h"

class AlienShip : public Ship
{
    
public:
    float movementOffset;
    float currentFireRate = 0;
    float maxRandInterval = 25;
    bool IsAlive;
    
    AlienShip();
    AlienShip(V2 position);
    ~AlienShip();
    
    void MoveAndDraw(float x, float y) override;
    void CheckShootingStatus() override;
    void TakeDamage() override;
};
