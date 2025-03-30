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
    std::vector<int> ships = { 4, 3, 3, 2, 2, 2, 1, 1, 1, 1 };
    const int max_attempts = 1000;

    std::sort(ships.begin(), ships.end(), std::greater<int>());

    int totalAttempts = 0;
    bool allPlaced = false;

    while (!allPlaced && totalAttempts < max_attempts * 2) {
        ClearField();
        ships_.clear();
        allPlaced = true;

        for (int size : ships) {
            bool placed = false;
            int attempts = 0;

            bool orientations[2] = { false, true };
            std::random_shuffle(orientations, orientations + 2);

            while (!placed && attempts < max_attempts) {
                attempts++;
                totalAttempts++;

                for (bool is_vertical : orientations) {
                    int maxCoord = size_ - size;
                    if (maxCoord < 0) continue;

                    int x = rand() % (maxCoord + 1);
                    int y = rand() % (maxCoord + 1);

                    if (CanPlaceShip(x, y, size, is_vertical)) {
                        Ship new_ship(size, is_vertical, x, y);
                        ships_.push_back(new_ship);
                        PlaceShip(new_ship);
                        placed = true;
                        break;
                    }
                }
            }

            if (!placed) {
                allPlaced = false;
                break;
            }
        }

        if (allPlaced) {
            return;
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


void Field::PlaceShip(const Ship& ship) {
	for (const Cell& cell : ship.GetShipCells()) {
		int x = cell.GetX();
		int y = cell.GetY();
		if (x >= 0 && x < size_ && y >= 0 && y < size_) {
			field_[y][x].SetCellStatus(Cell::CellStatus::SHIP);
		}
	}
}


void Field::ClearField() {
	for (auto& row : field_) {
		for (Cell& cell : row) {
			cell.SetCellStatus(Cell::CellStatus::EMPTY);
		}
	}
}


bool Field::IsShipsDestroy() const {
    for (const Ship& ship : ships_) {
        if (!ship.IsDestroy()) {
            return false;
        }
    }
    return true;
}


int Field::GetSize() const {
    return size_;
}


std::vector<Ship> Field::GetShips() const {
    return ships_;
}


Cell& Field::operator()(int y, int x) {
	return field_[y][x];
}


const Cell& Field::operator()(int y, int x) const {
    return field_[y][x];
}