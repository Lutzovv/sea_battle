#pragma once
#ifndef _FIELD_HPP_
#define _FIELD_HPP_

#include <cstdlib>
#include <iostream>
#include <algorithm>
#include "Ship.hpp"

class Field {
public:
	Field(int size);

	void GenerateShips();
	void ClearField();

	Cell& operator()(int y, int x);

private:
	int size_;
	std::vector<Ship> ships_;
	std::vector<std::vector<Cell>> field_;
	bool is_ships_destroy_;

	bool CanPlaceShip(int x, int y, int size, bool is_vertical) const;
	void PlaceShip(const Ship& ship);
};

#endif // !_FIELD_HPP_
