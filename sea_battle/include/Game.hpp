#pragma once
#ifndef _GAME_HPP_
#define _GAME_HPP_

#include <ctime>
#include "Player.hpp"
#include "BotPlayer.hpp"

class Game {
public:
	Game(int field_size) : player(field_size), bot_player(field_size), field_size(field_size) {}

	void StartGame();
private:
	int field_size;
	Player player;
	BotPlayer bot_player;

	void DrawFields();
};

#endif // !_GAME_HPP_
