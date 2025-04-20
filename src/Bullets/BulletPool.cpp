#include <iostream>
#include <Bullets/BulletPool.h>

BulletPool::BulletPool(int amount)
{
    Amount = amount;
    bullets = new Bullet[amount];

    for (int i = 0; i < amount; i++)
    {
        bullets[i] = Bullet(-900, -600, V2_ZERO, RED);
    }
}

BulletPool::BulletPool(){}

void BulletPool::ActivateBullet(V2 Position, V2 Direction, Color color)
{
    for(int i = 0; i < Amount; i++)
    {
        if(!bullets[i].IsActive)
        {
            std::cout<< bullets[i].IsActive << std::endl;
            bullets[i].Initialize(Position.x, Position.y, Direction, color);

            return;
        }
    }
}

void BulletPool::Pool(int id)
{
    std::cout<< "POOL" << std::endl;
    bullets[id] = Bullet(-900, -600, V2_ZERO, RED);
}

void BulletPool::UpdateBullets()
{
    for(int i = 0; i < Amount; i++)
    {
        //std::cout << "IS ACTIVE: " << bullets[i].IsActive << " " << i << std::endl;
        if(bullets[i].IsActive)
        {
            bullets[i].MoveAndDraw();
            if(bullets[i].Position.y < -10) Pool(i);
        }
    }
}





