#pragma once
#include "raylib.h"

class GameManager
{
public:
    int currentScore;
    bool hasWon = false;
    bool gameOver = false;

    static GameManager* instance;
    
    GameManager();

    void AddScore(int score);
    void Update();
    void EndGame(bool win);
};
