#include "../include/Player.hpp"


Player::Player(int size) : field_(size) {
	field_.GenerateShips();
}


void Player::MakeMove(Field& opponentField) {
	int x, y;
    std::string input;
    bool validInput = false;

    while (!validInput) {
        std::cout << "Введите номер клетки (например, A1 или b4): ";
        std::getline(std::cin, input, '\n');

        std::pair<int, int> coords = ParseCoordinate(input);
        x = coords.first - 1;
        y = coords.second - 1;

        if (!(x == -1)) {
            if (x < 0 || x >= opponentField.GetSize() || y < 0 || y >= opponentField.GetSize()) {
                std::cout << "Координаты вне поля. Попробуйте снова.\n";
                continue;
            }

            Cell& cell = opponentField(y, x);
            if (cell.GetCellStatus() == Cell::CellStatus::SHIP) {
                cell.SetCellStatus(Cell::CellStatus::HIT);
                std::cout << "Попадание!\n";
                validInput = true;
            }
            else if (cell.GetCellStatus() == Cell::CellStatus::EMPTY) {
                cell.SetCellStatus(Cell::CellStatus::MISS);
                std::cout << "Промах!\n";
                validInput = true;
            }
            else {
                std::cout << "Вы уже атаковали эту клетку. Попробуйте снова.\n";
                validInput = false;
            }
        }
        else {
            std::cout << "Неверный формат ввода. Используйте формат типа 'A1' или 'b4'.\n";
        }
    }
}


std::pair<int, int> Player::ParseCoordinate(const std::string& coord) const {
    if (coord.empty() || !isalpha(coord[0])) {
        return { -1, -1 };
    }

    char letter = tolower(coord[0]);
    int row = letter - 'a' + 1;

    int col = 0;
    try {
        col = stoi(coord.substr(1));
    }
    catch (...) {
        return { -1, -1 }; 
    }

    if (row < 1 || row > 10 || col < 1 || col > 10) {
        return { -1, -1 };
    }

    return { row, col };
}


Field& Player::GetField() {
    return field_;
}

const Field& Player::GetField() const {
    return field_;
}