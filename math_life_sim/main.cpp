#include <iostream>
#include <fstream>
#include <vector>
#include <windows.h>

using namespace std;

void cout_generation(vector<vector<int>>& array, int size_f, int size_s) {
	for (int i = 0; i < size_f; i++) {
		for (int j = 0; j < size_s; j++) {
			if (array[i][j] == 1) {
				cout << "*" << " ";
			}
			else {
				cout << "-" << " ";
			}
		}
		cout << "\n";
	}
}

void universe_completion(ifstream& fin, vector<vector<int>>& array, int size_f, int size_s, int& live_cells) {
	for (int i = 0; i < size_f; i++) {
		for (int j = 0; j < size_s; j++) {
			array[i][j] = 0;
		}
	}

	for (int i; fin >> i; ) {
		for (int j; fin >> j; ) {
			array[i][j] = 1;
			live_cells++;
			break;
		}
	}
}

void step_calcul(vector<vector<int>>& array, int size_f, int size_s, int& live_cells) {
	vector<vector<int>> check_array(size_f, vector<int>(size_s));

	for (int i = 0; i < size_f; i++) {
		for (int j = 0; j < size_s; j++) {
			// расчет угловых клеток
			if (i == 0 && j == 0) {
				if (array[i][j] == 1) {
					if ((array[i + 1][j] + array[i + 1][j + 1] + array[i][j + 1]) >= 2 &&
						(array[i + 1][j] + array[i + 1][j + 1] + array[i][j + 1]) <= 3) {
						check_array[i][j] = 1;
					}
					else {
						check_array[i][j] = 0;
						live_cells--;
					}
				}
				else {
					if ((array[i + 1][j] + array[i + 1][j + 1] + array[i][j + 1]) == 3) {
						check_array[i][j] = 1;
						live_cells++;
					}
					else {
						check_array[i][j] = 0;
					}
				}
			}
			else if (i == (size_f - 1) && j == (size_s - 1)) {

				int check_cells_around = (array[i - 1][j] + array[i - 1][j - 1] + array[i][j - 1]);

				if (array[i][j] == 1) {
					if (check_cells_around >= 2 && check_cells_around <= 3) {
						check_array[i][j] = 1;
					}
					else {
						check_array[i][j] = 0;
						live_cells--;
					}
				}
				else {
					if (check_cells_around == 3) {
						check_array[i][j] = 1;
						live_cells++;
					}
					else {
						check_array[i][j] = 0;
					}
				}
			}
			else if (i == 0 && j == (size_s - 1)) {

				int check_cells_around = (array[i + 1][j] + array[i + 1][j - 1] + array[i][j - 1]);

				if (array[i][j] == 1) {
					if (check_cells_around >= 2 && check_cells_around <= 3) {
						check_array[i][j] = 1;
					}
					else {
						check_array[i][j] = 0;
						live_cells--;
					}
				}
				else {
					if (check_cells_around == 3) {
						check_array[i][j] = 1;
						live_cells++;
					}
					else {
						check_array[i][j] = 0;
					}
				}
			}
			else if (i == (size_f - 1) && j == 0) {

				int check_cells_around = (array[i - 1][j] + array[i - 1][j + 1] + array[i][j + 1]);

				if (array[i][j] == 1) {
					if (check_cells_around >= 2 && check_cells_around <= 3) {
						check_array[i][j] = 1;
					}
					else {
						check_array[i][j] = 0;
						live_cells--;
					}
				}
				else {
					if (check_cells_around == 3) {
						check_array[i][j] = 1;
						live_cells++;
					}
					else {
						check_array[i][j] = 0;
					}
				}
			}
			// расчет граней
			else if (i == 0 && j >= 1 && j <= size_s - 2) {

				int check_cells_around = (array[i][j - 1] + array[i + 1][j - 1] + array[i + 1][j] + array[i + 1][j + 1] + array[i][j + 1]);

				if (array[i][j] == 1) {
					if (check_cells_around >= 2 && check_cells_around <= 3) {
						check_array[i][j] = 1;
					}
					else {
						check_array[i][j] = 0;
						live_cells--;
					}
				}
				else {
					if (check_cells_around == 3) {
						check_array[i][j] = 1;
						live_cells++;
					}
					else {
						check_array[i][j] = 0;
					}
				}
			}
			else if (i >= 1 && i <= size_f - 2 && j == size_s - 1) {

				int check_cells_around = (array[i - 1][j] + array[i - 1][j - 1] + array[i][j - 1] + array[i + 1][j - 1] + array[i + 1][j]);

				if (array[i][j] == 1) {
					if (check_cells_around >= 2 && check_cells_around <= 3) {
						check_array[i][j] = 1;
					}
					else {
						check_array[i][j] = 0;
						live_cells--;
					}
				}
				else {
					if (check_cells_around == 3) {
						check_array[i][j] = 1;
						live_cells++;
					}
					else {
						check_array[i][j] = 0;
					}
				}
			}
			else if (i == size_f - 1 && j >= 1 && j <= size_s - 2) {

				int check_cells_around = (array[i][j + 1] + array[i - 1][j + 1] + array[i - 1][j] + array[i - 1][j - 1] + array[i][j - 1]);

				if (array[i][j] == 1) {
					if (check_cells_around >= 2 && check_cells_around <= 3) {
						check_array[i][j] = 1;
					}
					else {
						check_array[i][j] = 0;
						live_cells--;
					}
				}
				else {
					if (check_cells_around == 3) {
						check_array[i][j] = 1;
						live_cells++;
					}
					else {
						check_array[i][j] = 0;
					}
				}
			}
			else if (i >= 1 && i <= size_f - 2 && j == 0) {

				int check_cells_around = (array[i + 1][j] + array[i + 1][j + 1] + array[i][j + 1] + array[i - 1][j + 1] + array[i - 1][j]);

				if (array[i][j] == 1) {
					if (check_cells_around >= 2 && check_cells_around <= 3) {
						check_array[i][j] = 1;
					}
					else {
						check_array[i][j] = 0;
						live_cells--;
					}
				}
				else {
					if (check_cells_around == 3) {
						check_array[i][j] = 1;
						live_cells++;
					}
					else {
						check_array[i][j] = 0;
					}
				}
			}
			// расчет оставшегося пространства 
			else if (i >= 1 && j >= 1 && i <= size_f - 2 && j <= size_s - 2) {

				int check_cells_around = (array[i - 1][j - 1] + array[i - 1][j + 1] + array[i][j + 1] + array[i + 1][j + 1] + array[i + 1][j] + array[i + 1][j - 1] + array[i - 1][j] + array[i][j - 1]);

				if (array[i][j] == 1) {
					if (check_cells_around >= 2 && check_cells_around <= 3) {
						check_array[i][j] = 1;
					}
					else {
						check_array[i][j] = 0;
						live_cells--;
					}
				}
				else {
					if (check_cells_around == 3) {
						check_array[i][j] = 1;
						live_cells++;
					}
					else {
						check_array[i][j] = 0;
					}
				}
			}
		}
	}

	for (int i = 0; i < size_f; i++) {
		for (int j = 0; j < size_s; j++) {
			array[i][j] = check_array[i][j];
		}
	}
}

int main() {
	ifstream fin;

	fin.open("in.txt");

	if (fin.is_open()) {

		int universe_size_f, universe_size_s, score_generaion = 1, live_cells = 0;

		fin >> universe_size_f;
		fin >> universe_size_s;

		vector<vector<int>> universe(universe_size_f, vector<int>(universe_size_s));

		vector<vector<int>> repeat_universe(universe_size_f, vector<int>(universe_size_s));

		universe_completion(fin, universe, universe_size_f, universe_size_s, live_cells);

		while (true) {
			cout_generation(universe, universe_size_f, universe_size_s);
			cout << "Generation: " << score_generaion << ". Alive cells: " << live_cells << "\n\n";

			step_calcul(universe, universe_size_f, universe_size_s, live_cells);

			if (live_cells == 0) {
				Sleep(1000);
				system("cls");
				cout_generation(universe, universe_size_f, universe_size_s);
				cout << "Generation: " << ++score_generaion << ". Alive cells: " << live_cells << "\n\n";
				cout << "All cells are dead. Game over!";
				break;
			}
			else if (repeat_universe == universe) {
				Sleep(1000);
				system("cls");
				cout_generation(universe, universe_size_f, universe_size_s);
				cout << "Generation: " << ++score_generaion << ". Alive cells: " << live_cells << "\n\n";
				cout << "The world has stagneted. Game over!";
				break;
			}
			for (int i = 0; i < universe_size_f; i++) {
				for (int j = 0; j < universe_size_s; j++) {
					repeat_universe[i][j] = universe[i][j];
				}
			}
			score_generaion++;
			Sleep(1000);
			system("cls");
		}
	}
	else {
		cout << "File isn't open.";
	}

	fin.close();

	return 0;
}