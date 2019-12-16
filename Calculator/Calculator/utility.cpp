#include "utility.h"

Utility::Utility()
{

}
Utility::Utility(int x, int y)
{
	xPos = x;
	yPos = y;
}
void Utility::RefreshConsole(void)
{
	system("cls");	//erase everythinig in console
	for (int i = 0; i < CONSOLECOLS; i++)
	{
		PrintAt(0, 1, '=');		//print upper line
		PrintAt(0, 18, '=');	//print lower line
	}
}
void Utility::WaitforSec(double seconds)
{
	Sleep(1000 * seconds);
}
void Utility::PrintTitle(double seconds)
{
	MoveCursor(0, 3);
	cout <<
		"  ________   __   _______  ____   ___ __________  ___ \n"
		" / ___/ _ | / /  / ___/ / / / /  / _ /_  __/ __ \\/ _ \\\n"
		"/ /__/ __ |/ /__/ /__/ /_/ / /__/ __ |/ / / /_/ / , _/\n"
		"\\___/_/ |_/____/\\___\/\____/____/_/ |_/_/  \\____/_/|_| \n" << endl;
	cout << "Introduction to Programming(2) Team Project\n19101279 ������\n19101191 �����" << endl;
	WaitforSec(seconds);
	system("cls");
}
int Utility::InstantReadKey(void)
{
	int temp = _getch();

	switch (temp)
	{
	case KEY_UP:
		return KEY_UP;
	case KEY_DOWN:
		return KEY_DOWN;
	case KEY_LEFT:
		return KEY_LEFT;
	case KEY_RIGHT:
		return KEY_RIGHT;
	case SUBMIT:
		return SUBMIT;
	case ESC:
		return ESC;
	case A:
		return A;
	case B:
		return B;
	case 1:
		return 1;
	default:
		return temp;
		break;
	}
}
template <typename contents> void Utility::PrintAt(int xpos, int ypos, contents)
{
	MoveCursor(xpos, ypos);
	cout << contents;		//print something
}
void Utility::PrintGuide(int xpos, int ypos)
{
	//not using virtual in here! "virtual" void Utility::PrintGuide(void)
	PrintAt(xpos, ypos, "����Ű�� ��/�Ʒ��� �̵��ϰ�, ���� Ű�� �����ϼ���.");
}
void Utility::PrintMode(int xpos, int ypos, string mode)
{
	if (mode == "BASIC")
	{
		PrintAt(xpos, ypos, "1. �⺻ ���(���� �Է�)");
		PrintAt(xpos, ypos + 2, "2. Matrix (��� ���)");
		PrintAt(xpos, ypos + 4, "3. Base-N (���� ��ȯ)");
		PrintAt(xpos, ypos + 6, "4. Quit (���α׷� ����)");
	}
	else if (mode == "MATRIX")
	{
		PrintAt(xpos, ypos, "1. ��� ����");
		PrintAt(xpos, ypos + 2, "2. ��� ����");
		PrintAt(xpos, ypos + 4, "3. ��� ����");
	}
	else if (mode == "MATRIX_CALCULATION")
	{
		PrintAt(xpos, ypos, "1. ��� ����");
		PrintAt(xpos, ypos + 2, "2. ��Į�� ��");
		PrintAt(xpos, ypos + 4, "3. ��ġ");
		PrintAt(xpos, ypos + 6, "4. ��� ����");
		PrintAt(xpos, ypos + 8, "5. �����");
	}
}
int Utility::SelectMode(void)
{
	int x = 7, y = 6;
	int x_end, y_end;
	while (1)
	{
		int n = InstantReadKey();
		switch (n) {
		case KEY_UP:
		{
			if (y > 6)
			{
				MoveCursor(x - 3, y);
				cout << " ";
				MoveCursor(x - 3, y -= 2);
				cout << ">";
			}
		}
		break;
		case KEY_DOWN:
		{
			if (y < 14)
			{
				MoveCursor(x - 3, y);
				cout << " ";
				MoveCursor(x - 3, y += 2);
				cout << ">";
			}
		}
		break;
		case SUBMIT:
		{
			if (y == 6)
				return BASICCALC;
			else if (y == 8)
				return ADVANCEDCALC;
			else if (y == 10)
				return MATRIX;
			else if (y == 12)
				return BASE_N;
			else if (y == 14)
				return QUIT;
		}
		break;
		}
	}
}
void Utility::ExitCalc(int xpos, int ypos)
{
	PrintAt(xpos, ypos, "���α׷��� �����մϴ�.");
	PrintTitle(1.5);
	exit(0);
}
void Utility::ExitCalc(int xpos, int ypos, string error)
{
	PrintAt(xpos, ypos, error);
}