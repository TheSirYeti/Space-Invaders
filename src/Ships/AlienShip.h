#pragma once
#include "Ship.h"

class AlienShip : public Ship
{
    
public:
    float movementOffset;
    bool IsAlive;
    
    AlienShip();
    AlienShip(V2 position);
    ~AlienShip();
    
    void MoveAndDraw(float x, float y) override;
    void Shoot() override;
};
