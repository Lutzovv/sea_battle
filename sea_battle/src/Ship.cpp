#include "../include/Ship.hpp"

Ship::Ship(int size, bool is_vertical, int x, int y) {
	if (is_vertical) {
		for (int i{}; i < size; i++) {
			if (y + i >= 0) {
				ship_.push_back(Cell(x, y + i, Cell::CellStatus::SHIP));
			}
		}
	}
	else {
		for (int i{}; i < size; i++) {
			if (x + i >= 0) {
				ship_.push_back(Cell(x + i, y, Cell::CellStatus::SHIP));
			}
		}
	}
	ship_size_ = size;
	is_vertical_ = is_vertical;
	is_destroy_ = false;
}


std::vector<Cell> Ship::GetShipCells() const {
	return ship_;
}


int Ship::GetShipSize() const {
	return ship_size_;
}


bool Ship::IsDestroy() const {
	for (const Cell& cell : ship_) {
		if (cell.GetCellStatus() != Cell::CellStatus::HIT) {
			return false;
		}
	}
	return true;
}