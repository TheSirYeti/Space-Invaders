#include "GameManager.h"

#include <string>

GameManager* GameManager::instance = nullptr;

GameManager::GameManager()
{
    instance = this;
    currentScore = 0;
}


void GameManager::AddScore(int score)
{
    currentScore += score;
}

void GameManager::Update()
{
    std::string scoreText = "SCORE: " + std::to_string(currentScore);
    DrawText(scoreText.c_str(), 0, 0, 24, WHITE);
}

void GameManager::EndGame(bool win)
{
    hasWon = win;
    gameOver = true;
}


