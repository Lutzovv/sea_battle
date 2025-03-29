#include "../include/Field.hpp"

Field::Field(int size) {
	field_.resize(size);
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			field_[i].push_back(Cell(i, j));
		}
	}
	size_ = size;
	is_ships_destroy_ = false;
}


void Field::GenerateShips() {
	srand(time(NULL));
	int ships[9] = { 4, 3, 3, 2, 2, 1, 1, 1, 1 };
	const int max_attempts = 100;

	for (int i : ships) {
		bool placed = false;
		int attempts = 0;

		while (!placed && attempts < max_attempts) {
			attempts++;

			bool is_vertical = rand() % 2;
			int x = rand() % size_ + 1;
			int y = rand() % size_ + 1;

			if (CanPlaceShip(x, y, i, is_vertical)) {
				Ship new_ship(i, is_vertical, x, y);
				ships_.push_back(new_ship);
				std::cout << "ship create " << new_ship.GetShipSize() << "\n";
				placed = true;
			}
		}
	}
}


bool Field::CanPlaceShip(int x, int y, int size, bool is_vertical) const {
	if (is_vertical) {
		if (y + size > size_) return false;
	}
	else {
		if (x + size > size_) return false;
	}

	for (int i = -1; i <= size; i++) {
		for (int j = -1; j <= 1; j++) {
			int check_x = is_vertical ? x + j : x + i;
			int check_y = is_vertical ? y + i : y + j;

			if (check_x >= 0 && check_x < size_ && check_y >= 0 && check_y < size_) {
				if (field_[check_y][check_x].GetCellStatus() != Cell::CellStatus::EMPTY) {
					return false;
				}
			}
		}
	}

	return true;
}


void Field::ClearField() {
	std::cout << "\n";
}


Cell& Field::operator()(int y, int x) {
	return field_[y][x];
}