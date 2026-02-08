#include "game.h"
#include <random>

Game::Game() {
    grid = Grid();
    blocks = GetAllBlocks();
    currentBlock = GetRandomBlock();
    nextBlock = GetRandomBlock();
    gameOver = false;
    score = 0;

    InitAudioDevice();

    music = LoadMusicStream("SFX/tetris.mp3");
    PlayMusicStream(music);

    rotateSound   = LoadSound("SFX/rotate.mp3");
    clearSound    = LoadSound("SFX/clear.mp3");
    gameOverSound = LoadSound("SFX/over.mp3");
}

Game::~Game() {
    UnloadMusicStream(music);
    UnloadSound(rotateSound);
    UnloadSound(clearSound);
    UnloadSound(gameOverSound);
    CloseAudioDevice();
}

bool Game::IsPlaying() const {
    return !gameOver;
}

Block Game::GetRandomBlock() {
    if (blocks.empty()) {
        blocks = GetAllBlocks();
    }

    int randomIndex = rand() % blocks.size();
    Block block = blocks[randomIndex];
    blocks.erase(blocks.begin() + randomIndex);

    return block;
}

std::vector<Block> Game::GetAllBlocks() {
    return { IBlock(), JBlock(), LBlock(), OBlock(),
             SBlock(), TBlock(), ZBlock() };
}

void Game::Draw() {
    grid.Draw();
    currentBlock.Draw(11, 11);

    switch (nextBlock.id) {
        case 3:
            nextBlock.Draw(255, 290);
            break;
        case 4:
            nextBlock.Draw(255, 280);
            break;
        default:
            nextBlock.Draw(270, 270);
    }
}

void Game::HandleInput() {
    int keyPressed = GetKeyPressed();

    if (gameOver && keyPressed != 0) {
        gameOver = false;
        Reset();
        return;
    }

    switch (keyPressed) {
        case KEY_LEFT:
            MoveBlockLeft();
            break;

        case KEY_RIGHT:
            MoveBlockRight();
            break;

        case KEY_DOWN:
            if (MoveBlockDown()) {
                UpdateScore(0, 1);
            }
            break;

        case KEY_UP:
            RotateBlock();
            break;
    }
}

void Game::MoveBlockLeft() {
    if (!IsPlaying()) return;

    currentBlock.Move(0, -1);
    if (IsBlockOutside() || !BlockFits()) {
        currentBlock.Move(0, 1);
    }
}

void Game::MoveBlockRight() {
    if (!IsPlaying()) return;

    currentBlock.Move(0, 1);
    if (IsBlockOutside() || !BlockFits()) {
        currentBlock.Move(0, -1);
    }
}

bool Game::MoveBlockDown() {
    if (!IsPlaying()) return false;

    currentBlock.Move(1, 0);

    if (IsBlockOutside() || !BlockFits()) {
        currentBlock.Move(-1, 0);
        LockBlock();
        return false;
    }

    return true;
}

bool Game::IsBlockOutside() {
    const std::vector<Position> tiles = currentBlock.GetCellPositions();

    for (const Position& item : tiles) {
        if (grid.isCellOutside(item.row, item.column)) {
            return true;
        }
    }

    return false;
}

void Game::RotateBlock() {
    if (!IsPlaying()) return;

    currentBlock.Rotate();

    if (IsBlockOutside() || !BlockFits()) {
        currentBlock.UndoRotation();
    } else {
        PlaySound(rotateSound);
    }
}

void Game::LockBlock() {
    const std::vector<Position> tiles = currentBlock.GetCellPositions();

    for (const Position& item : tiles) {
        grid.grid[item.row][item.column] = currentBlock.id;
    }

    currentBlock = nextBlock;

    if (!BlockFits() && !gameOver) {
        gameOver = true;
        StopMusicStream(music);
        PlaySound(gameOverSound);
        return;
    }

    nextBlock = GetRandomBlock();

    int rowsCleared = grid.ClearFullRows();

    if (rowsCleared > 0) {
        PlaySound(clearSound);
        UpdateScore(rowsCleared, 0);
    }
}

bool Game::BlockFits() {
    const std::vector<Position> tiles = currentBlock.GetCellPositions();

    for (const Position& item : tiles) {
        if (!grid.IsCellEmpty(item.row, item.column)) {
            return false;
        }
    }

    return true;
}

void Game::Reset() {
    grid.Initialize();
    blocks = GetAllBlocks();
    currentBlock = GetRandomBlock();
    nextBlock = GetRandomBlock();
    score = 0;

    StopMusicStream(music);
    PlayMusicStream(music);
}

void Game::UpdateScore(int LinesCleared, int moveDownPoints) {
    switch (LinesCleared) {
        case 1: score += 100; break;
        case 2: score += 200; break;
        case 3: score += 300; break;
        case 4: score += 400; break;
        default: break;
    }

    score += moveDownPoints;
}

void Game::Restart() {
    gameOver = false;
    Reset();
}