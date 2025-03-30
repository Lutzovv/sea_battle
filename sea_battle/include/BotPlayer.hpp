#pragma once
#ifndef _BOTPLAYER_HPP_
#define _BOTPLAYER_HPP_

#include "Field.hpp"

class BotPlayer {
public:
	BotPlayer(int size);
	void MakeMove(Field& opponentField);
	Field& GetField();
	const Field& GetField() const;
private:
	Field field_;
};

#endif // !_BOTPLAYER_HPP_
