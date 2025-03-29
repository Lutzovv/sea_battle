#pragma once
#ifndef _SHIP_HPP_
#define _SHIP_HPP_

#include <vector>
#include "Cell.hpp"

class Ship {
public:
	Ship(int size, bool is_vertical, int x, int y);

	std::vector<Cell> GetShipCells() const;
	int GetShipSize() const;
	bool IsDestroy() const;

private:
	std::vector<Cell> ship_;
	int ship_size_;
	bool is_vertical_;
	bool is_destroy_;
};

#endif // !_SHIP_HPP_
