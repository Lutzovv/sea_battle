#include "../include/Cell.hpp"

Cell::CellStatus Cell::GetCellStatus() const {
	return status_;
}


int Cell::GetX() const {
	return x_;
}


int Cell::GetY() const {
	return y_;
}


void Cell::SetCellStatus(CellStatus status) {
	status_ = status;
}


std::ostream& operator<<(std::ostream& out, const Cell& obj) {
	if (obj.status_ == Cell::CellStatus::EMPTY) {
		out << ".";
	}
	else if (obj.status_ == Cell::CellStatus::SHIP) {
		out << "#";
	}
	else if (obj.status_ == Cell::CellStatus::HIT) {
		out << "X";
	}
	else if (obj.status_ == Cell::CellStatus::MISS) {
		out << "o";
	}

	return out;
}