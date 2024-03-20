#include <iostream>
#include <Windows.h>
#include <vector>
#include <stack>
#include <conio.h>
using namespace std;

void gotoxy(int x, int y) {
	COORD p = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
}
const int BORDER = 100; // границы поля
const int EMPTY_CELL = 0; // пустая ячейка
const int MINE = 10; // мина

class Map {
private:
	int COUNT_MINE; // количество мин
	const int BORDER = 100; // границы поля
	const int EMPTY_CELL = 0; // пустая ячейка
	const int MINE = 10; // мина
	int size; //размер поля
	int count; //количество ячеек
	vector < vector<int>> map;
	vector < vector<int>> mask;
public:
	int getCount() {
		return count;
	}
	int getCM() {
		return COUNT_MINE;
	}
	Map() {
		cout << "Введите размер поля: ";
		cin >> size;
		size += 2;
		cout << "Введите количество мин: ";
		cin >> COUNT_MINE;
		count = size * size;
	}
	int openCell(int x, int y) {
		int result = 1;
		mask[x][y] = 1;
		if (map[x][y] == MINE) {
			result = MINE;
		}
		else if (map[x][y] == EMPTY_CELL) {
			result = EMPTY_CELL;
		}
		show();
		return result;
	}
	bool isBorder(int x, int y) {

		if (x < 0 || x >= size)
			return false;

		if (y < 0 || y >= size)
			return false;

		if (map[x][y] == BORDER) {
			return true;
		}
		return false;
	}
	void initMap() {
		for (int i = 0; i < size; i++)
		{
			vector <int> temp;
			for (int j = 0; j < size; j++) {
				if (i == 0 || j == 0 || i == size - 1 || j == size - 1)
					temp.push_back(BORDER);
				else
					temp.push_back(EMPTY_CELL);
			}
			map.push_back(temp);
		}
	}

	void initMask() {
		for (int i = 0; i < size; i++)
		{
			vector <int> temp;
			for (int j = 0; j < size; j++) {
				if (i == 0 || j == 0 || i == size - 1 || j == size - 1)
					temp.push_back(BORDER);
				else
					temp.push_back(EMPTY_CELL);
			}
			mask.push_back(temp);
		}
	}

	void show() {
		system("cls");
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {

				if (mask[j][i] == EMPTY_CELL) {
					cout << ". ";
					continue;
				}

				if (map[j][i] == BORDER)
					cout << "# ";
				else if (map[j][i] == EMPTY_CELL)
					cout << "+ ";
				else if (map[j][i] == MINE)
					cout << "* ";
				else if (map[j][i] >= 1 && map[j][i] <= 8)
					cout << map[j][i] << " ";
			}
			cout << endl;
		}
	}
	// случайная расстановка
	void setRandMines(int numMines) {
		// контроль количества мин можное устоновить
		if (numMines >= count) {
			cout << "Слишком много мин" << endl;
			return;
		}
		for (int i = 0; i < numMines; i++) {
			int x = 0;
			int y = 0;
			do {
				x = rand() % (size - 2) + 1;
				y = rand() % (size - 2) + 1;
			} while (map[x][y] == MINE);
			map[x][y] = MINE;
		}
	}
	//расстановка чисел на игровом поле
	void serDigits() {
		int d = 0;
		for (int i = 1; i < size - 1; i++) {
			for (int j = 1; j < size - 1; j++) {
				if (map[j][i] == MINE)
					continue;
				if (map[j][i + 1] == MINE)
					d++;
				if (map[j][i - 1] == MINE)
					d++;
				if (map[j + 1][i + 1] == MINE)
					d++;
				if (map[j + 1][i - 1] == MINE)
					d++;
				if (map[j - 1][i + 1] == MINE)
					d++;
				if (map[j - 1][i - 1] == MINE)
					d++;
				if (map[j + 1][i] == MINE)
					d++;
				if (map[j - 1][i] == MINE)
					d++;
				map[j][i] = d;
				d = 0;
			}
		}
	}

	void fill(int px, int py) {
		stack <int> stk;
		stk.push(px);
		stk.push(py);

		int x = 0, y = 0;

		while (true) {
			y = stk.top();
			stk.pop();
			x = stk.top();
			stk.pop();
			if (map[x][y + 1] == EMPTY_CELL && mask[x][y + 1] == 0) {
				stk.push(x);
				stk.push(y + 1);
				mask[x][y + 1] = 1;
			}
			if (map[x][y - 1] == EMPTY_CELL && mask[x][y - 1] == 0) {
				stk.push(x);
				stk.push(y - 1);
				mask[x][y - 1] = 1;
			}
			if (map[x + 1][y + 1] == EMPTY_CELL && mask[x + 1][y + 1] == 0) {
				stk.push(x + 1);
				stk.push(y + 1);
				mask[x + 1][y + 1] = 1;
			}
			if (map[x + 1][y - 1] == EMPTY_CELL && mask[x + 1][y - 1] == 0) {
				stk.push(x + 1);
				stk.push(y - 1);
				mask[x + 1][y - 1] = 1;
			}
			if (map[x - 1][y + 1] == EMPTY_CELL && mask[x - 1][y + 1] == 0) {
				stk.push(x);
				stk.push(y + 1);
				mask[x - 1][y + 1] = 1;
			}
			if (map[x - 1][y - 1] == EMPTY_CELL && mask[x - 1][y - 1] == 0) {
				stk.push(x - 1);
				stk.push(y - 1);
				mask[x - 1][y - 1] = 1;
			}
			if (map[x - 1][y] == EMPTY_CELL && mask[x - 1][y] == 0) {
				stk.push(x - 1);
				stk.push(y);
				mask[x - 1][y] = 1;
			}
			if (map[x + 1][y] == EMPTY_CELL && mask[x + 1][y] == 0) {
				stk.push(x + 1);
				stk.push(y + 1);
				mask[x + 1][y] = 1;
			}


			if (stk.empty())
				break;
		}
		show();
	}
};

class Keyboard {
private:
	int ch = 0;
public:
	Keyboard() {
		ch = 0;
	}
	void waitKey() {
		ch = _getch();
	}
	int getKey() {
		return ch;
	}
};
class Cursor {
private:
	int x = 2;
	int y = 1;

	int tx = 1;
	int ty = 1;
public:
	void save() {
		tx = x;
		ty = y;
	}
	void undo() {
		x = tx;
		y = ty;
	}
	void incX() {
		x += 2;
	}
	void decX() {
		x -= 2;
	}
	void incY() {
		y++;
	}
	void decY() {
		y--;
	}
	int getX() {
		return x;
	}
	int getY() {
		return y;
	}
	void move() {
		gotoxy(x, y);
	}
};
class Game {
private:
	void showLogo() {
		gotoxy(40, 9);
		cout << "Seper" << endl;
		Sleep(2000);
		system("cls");
	}
public:
	void youWin() {
		//gotoxy(40, 9);
		cout << "You win!" << endl;
		Sleep(2000);
		//gotoxy(0, 15);
		system("pause");
	}
	void gameOver() {
		gotoxy(40, 9);
		cout << "Game over" << endl;
		Sleep(2000);
		gotoxy(0, 15);
		system("pause");
	}

	void run() {
		//showLogo
		Map map;
		map.initMap();
		map.initMask();
		map.setRandMines(map.getCM());
		map.serDigits();
		map.show();

		Keyboard kb;
		Cursor cs;

		cs.move();

		bool exit = false;

		while (!exit) {
			kb.waitKey();
			cs.save();

			switch (kb.getKey()) {
			case 77: cs.incX(); break;//вправо
			case 80: cs.incY(); break;//вниз
			case 75: cs.decX(); break;//влево
			case 72: cs.decY(); break;//вверх
			case 13:
				int result = map.openCell(cs.getX() / 2, cs.getY());
				if (result == MINE) {
					gameOver();
					exit = true;
				}
				if (result == EMPTY_CELL) {
					map.fill(cs.getX() / 2, cs.getY());
				}
				//if (map.getCount() == map.getCM()) {
				//	youWin();
				//	exit = true;
				//}

				break;// вверх
			}

			if (map.isBorder(cs.getX() / 2, cs.getY())) {
				cs.undo();
			}
			cs.move();
		}
	}
};

int main()
{
	setlocale(LC_ALL, "");
	srand(time(NULL));
	Game game;
	while (true)
	{
		system("cls");
		game.run();
	}

}