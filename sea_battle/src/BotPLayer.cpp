#include "../include/BotPlayer.hpp"

BotPlayer::BotPlayer(int size) : field_(size) {
	field_.GenerateShips();
}


void BotPlayer::MakeMove(Field& opponentField) {
    int x, y;

    x = rand() % opponentField.GetSize();
    y = rand() % opponentField.GetSize();

    Cell& cell = opponentField(y, x);
    if (cell.GetCellStatus() == Cell::CellStatus::SHIP) {
        cell.SetCellStatus(Cell::CellStatus::HIT);
    }
    else if (cell.GetCellStatus() == Cell::CellStatus::EMPTY) {
        cell.SetCellStatus(Cell::CellStatus::MISS);
    }
}


Field& BotPlayer::GetField() {
    return field_;
}


const Field& BotPlayer::GetField() const {
    return field_;
}