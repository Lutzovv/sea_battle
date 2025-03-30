#include "./include/Field.hpp"

int main() {
	int size = 10;
	Field f(10);
	f.GenerateShips();

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			std::cout << f(i, j);
		}
		std::cout << "\n";
	}
}