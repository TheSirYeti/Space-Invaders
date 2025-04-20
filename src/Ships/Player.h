#pragma once
#include "Ship.h"

class Player : public Ship
{
public:
    Player();

    void MoveAndDraw(float x, float y) override;
    void Shoot() override;
    
};
