#pragma once
#ifndef _CELL_HPP_
#define _CELL_HPP_

#include <iostream>

class Cell {
public:
	enum class CellStatus
	{
		EMPTY,
		SHIP,
		HIT,
		MISS
	};

	Cell(int x, int y) : x_(x), y_(y) {
		status_ = CellStatus::EMPTY;
	}
	Cell(int x, int y, CellStatus status) : x_(x), y_(y), status_(status) {}

	CellStatus GetCellStatus() const;
	void SetCellStatus(CellStatus status_);

	friend std::ostream& operator<<(std::ostream& out, const Cell& obj);

private:
	int x_;
	int y_;
	CellStatus status_;
};

#endif // !_CELL_HPP_
