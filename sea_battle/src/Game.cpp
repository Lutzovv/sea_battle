#include "../include/Game.hpp"

void Game::StartGame() {
    system("chcp 1251>NUL");
    srand(time(NULL));

    player = Player(field_size);
    bot_player = BotPlayer(field_size);

    bool game_over = false;
    bool player_turn = true;

    while (!game_over) {
        system("cls");

        DrawFields();

        if (player_turn) {
            std::cout << "\nВаш ход:\n";
            player.MakeMove(bot_player.GetField());


            bool all_destroyed = true;
            for (const Ship& ship : bot_player.GetField().GetShips()) {
                if (!ship.IsDestroy()) {
                    all_destroyed = false;
                    break;
                } 
            }


            if (all_destroyed) {
                std::cout << "Вы победили! Все корабли противника уничтожены.\n";
                game_over = true;
                continue;
            }
        }
        else {
            bot_player.MakeMove(player.GetField());

            if (player.GetField().IsShipsDestroy()) {
                std::cout << "Вы проиграли! Все ваши корабли уничтожены.\n";
                game_over = true;
                continue;
            }
        }

        player_turn = !player_turn;
    }

    DrawFields();
    std::cout << "\nИгра окончена. Нажмите Enter для выхода...";
    std::cin.ignore();
}


void Game::DrawFields() {
    system("cls");

    std::cout << "  ВАШЕ ПОЛЕ\t\t\t  ПОЛЕ ПРОТИВНИКА\n";

    std::cout << "   ";
    for (int i = 0; i < field_size; i++) {
        std::cout << static_cast<char>('A' + i) << " ";
    }
    std::cout << "\t\t   ";
    for (int i = 0; i < field_size; i++) {
        std::cout << static_cast<char>('A' + i) << " ";
    }
    std::cout << "\n";

    for (int i = 0; i < field_size; i++) {
        if (i < 9) std::cout << " ";
        std::cout << i + 1 << " ";

        for (int j = 0; j < field_size; j++) {
            std::cout << player.GetField()(i, j) << " ";
        }

        std::cout << "\t\t";

        if (i < 9) std::cout << " ";
        std::cout << i + 1 << " ";

        for (int k = 0; k < field_size; k++) {
            Cell cell = bot_player.GetField()(i, k);
            if (cell.GetCellStatus() == Cell::CellStatus::SHIP) {
                std::cout << "." << " ";
            }
            else {
                std::cout << cell << " ";
            }
        }
        std::cout << "\n";
    }
}