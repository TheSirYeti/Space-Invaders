#pragma once
#include "Ship.h"

class Player : public Ship
{
public:
    Player();

    int hp;

    void MoveAndDraw(float x, float y) override;
    void CheckShootingStatus() override;
    void TakeDamage() override;
    
};
