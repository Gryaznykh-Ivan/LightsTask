#include <windows.h>
#include <iostream>
#include <bitset>
#include <conio.h>

using namespace std;

void print(unsigned char state)
{
	system("CLS"); // �������� �������
	cout << bitset<8>(state); // ������� ��������� ��������
}

int main()
{
	unsigned char state = 0x0; // ��������� ��������
	unsigned char key = 0x0; // ������� ������ (ascii)
	unsigned char lkey = 0x0; // ��� �������� ����������� � ������� ������
	unsigned char mask = 0x0; // ����� ��� ��������� ��� ���������� ��������

	do {
		print(state); // ���������� ��������� ��������
		key = _getch(); // �������� �������

		if (key < 48 || key >= 58) continue; // ���������� ������ ���� ������ ������� �� 0 �� 9

		lkey = 0x100 >> key - 48; // ���������� ������ � ������� c ����� (0x100 >> 1 == 128, 0x100 >> 2 == 64, ...)
		mask = ~state & lkey; // �������� ������ ( ���� 0x0 ���� �������� ��� �������� ������� ���� �������� )
		state &= ~lkey; // ������� �������� ���� �������� 
		state |= mask; // �������� �����

		if (key == '9') state = 0xFF; // ���� ������ 9 -> ���������� ��� ��������
		if (key == '0') state = 0x0; // ���� ������ 0 -> ��� �������� ������

		Sleep(100); // ������� 0.1 �������
	} while (key != 27); // ���������� ��� ������� �� ESC

	return 0;
}