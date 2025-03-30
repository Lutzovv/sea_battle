#pragma once
#ifndef _PLAYER_HPP_
#define _PLAYER_HPP_

#include <string>
#include <cctype>
#include "Field.hpp"

class Player {
public:
	Player(int size);
	void MakeMove(Field& opponentField);
	Field& GetField();
	const Field& GetField() const;
private:
	Field field_;

	std::pair<int, int> ParseCoordinate(const std::string& coord) const;
};

#endif // !_PLAYER_HPP_
