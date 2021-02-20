#include <windows.h>
#include <iostream>
#include <bitset>
#include <conio.h>

using namespace std;

void print(unsigned char state)
{
	system("CLS"); // отчищаем консоль
	cout << bitset<8>(state); // печатам состояние лампочек
}

int main()
{
	unsigned char state = 0x0; // состояние лампочек
	unsigned char key = 0x0; // нажатая кнопка (ascii)
	unsigned char lkey = 0x0; // бит лампочки относящийся к нажатой кнопке
	unsigned char mask = 0x0; // маска для включения или выключения лампочки

	do {
		print(state); // отображаем состояние лампочек
		key = _getch(); // получаем нажатие

		if (key < 48 || key >= 58) continue; // продолжаем только если нажата клавиша от 0 до 9

		lkey = 0x100 >> key - 48; // возведение двойки в степень c конца (0x100 >> 1 == 128, 0x100 >> 2 == 64, ...)
		mask = ~state & lkey; // получаем макску ( либо 0x0 либо содежрит бит лампочки которую надо включить )
		state &= ~lkey; // Убираем значение бита лампочки 
		state |= mask; // применям маску

		if (key == '9') state = 0xFF; // если нажата 9 -> загораются все лампочки
		if (key == '0') state = 0x0; // если нажата 0 -> все лапмочки тухнут

		Sleep(100); // Ожидаем 0.1 секунду
	} while (key != 27); // Завершение при нажатии на ESC

	return 0;
}