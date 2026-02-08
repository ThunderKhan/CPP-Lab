#pragma once

#include "grid.h"
#include "Blocks.cpp" 

class Game {
public:
    Game();
    ~Game();

    void Draw();
    void HandleInput();

    bool MoveBlockDown();
    bool IsPlaying() const;
    void Restart();

    bool gameOver;
    int score;
    Music music;

private:
    void MoveBlockLeft();
    void MoveBlockRight();

    Block GetRandomBlock();
    std::vector<Block> GetAllBlocks();

    bool IsBlockOutside();
    void RotateBlock();
    void LockBlock();
    bool BlockFits();
    void Reset();
    void UpdateScore(int LinesCleared, int moveDownPoints);

    std::vector<Block> blocks;
    Block currentBlock;
    Block nextBlock;
    Grid grid;

    Sound rotateSound;
    Sound clearSound;
    Sound gameOverSound;
};
