#include "calculator.h"

void Initialize(void)
{
	srand((unsigned int)time(NULL));
	system("mode con cols=60 lines=20 | title Calculator");

	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);	//Get ConsoleHandle
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = 0;	//false or 0 : Hide cursor
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(consoleHandle, &ConsoleCursor);
}

void MoveCursor(int x, int y)
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandle, pos);
}

void PrintLine(int xpos, int ypos, int amount)
{
	MoveCursor(xpos, ypos);
	for (int i = 0; i < amount; i++)
		cout << "=";
}

int ReadKey(void)
{
	int temp = _getch();

	switch (temp)
	{
	case 72:
		return KEY_UP;
	case 80:
		return KEY_DOWN;
	case 75:
		return KEY_LEFT;
	case 77:
		return KEY_RIGHT;
	case 13:
		return SUBMIT;
	case 27:
		return ESC;
	default:
		break;
	}
}

void PrintTitle(float Seconds)
{
	MoveCursor(0, 2);
	cout << endl;
	cout <<
		"  ________   __   _______  ____   ___ __________  ___ \n"
		" / ___/ _ | / /  / ___/ / / / /  / _ /_  __/ __ \\/ _ \\\n"
		"/ /__/ __ |/ /__/ /__/ /_/ / /__/ __ |/ / / /_/ / , _/\n"
		"\\___/_/ |_/____/\\___\/\____/____/_/ |_/_/  \\____/_/|_| \n" << endl;
	cout << "Introduction to Programming(2) ���� �� ������Ʈ : ���п� ���� ����" << endl;
	int seconds = 1000 * Seconds;
	Sleep(seconds);	//convert millliseconds[ms] to sencods[s]
	system("cls");
}

void PrintMode(void)
{
	PrintLine(0, 1, CONSOLECOLS);
	PrintLine(0, 18, CONSOLECOLS);

	PrintAt(24, 3, "���� �ȳ�");
	PrintAt(2, 4, "����Ű�� ��/�Ʒ��� �̵��ϰ� ���� Ű�� �̿��� �����մϴ�.");
	PrintAt(5, 6, "1. Basic Calculation (�⺻ ���)");
	PrintAt(5, 8, "2. Advanced Calculation (��� ���:�ﰢ/����/�α��Լ� ����)");
	PrintAt(5, 10, "3. Matrix (��� ���)");
	PrintAt(5, 12, "4. Base-N (���� ��ȯ)");
	PrintAt(5, 14, "5. Quit (���α׷� ����)");
}

int SelectMode(void)
{
	int x = 7, y = 6;
	while (1)
	{
		int n = ReadKey();
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

void PrintAt(int xpos, int ypos, string contents)
{
	MoveCursor(xpos, ypos);
	cout << contents;
}

void PrintAt(int xpos, int ypos, double db)
{
	MoveCursor(xpos, ypos);
	cout << db;
}

void Calc::ClearConsole(void)
{
	system("cls");
}

void Calc_basic::PrintGuide(int xpos, int ypos)
{
	PrintLine(0, 1, CONSOLECOLS);
	PrintLine(0, 18, CONSOLECOLS);
	MoveCursor(xpos, ypos);
	cout <<
		"<�� �Է� �ȳ�>\n"
		"   ����ǥ���(Infix Notation)���� �ۼ��� ���� �Է��ϼ���.\n"
		"   ������ ������ �Ұ����մϴ�.\n";
}

void Calc_basic::GetInfixExp(void)
{
	cin >> tempExpression;	//null pointer error, why?
}

void Calc_basic::SetInfixExp(void)
{
	InfixExpression = tempExpression;
}

void Calc_basic::ConvertToPostfix(void)	//if parameter is const string --> Error C2440
{
	string* ptrs = new string;
	*ptrs = InfixExpression;
	string InfixExp = *ptrs;

	string Post_temp;

	string::iterator itr_ind = InfixExp.begin();	//iterator used in index

	vector<char> stack;	//using vector as a stack!

	for (; itr_ind != InfixExp.end(); ++itr_ind)
	{
		//if stream value is not an operator -- pass
		if (operators.find(*itr_ind) == string::npos)
		{
			Post_temp += *itr_ind;
			continue;
		}

		//operator processing
		Post_temp += " ";
		switch (*itr_ind)
		{
		case'(':
			stack.push_back('(');
			break;
		case')':	//starting parenthetical calculation
			while (stack.back() != '(')
			{
				Post_temp += stack.back();
				Post_temp += " ";
				stack.pop_back();
			}
			stack.pop_back();
			break;
		case'+':
		case'-':	//starting add/subtract calculation
			while (stack.size() != 0 && stack.back() != '(')
			{
				Post_temp += stack.back();
				Post_temp += " ";
				stack.pop_back();
			}
			stack.push_back(*itr_ind);
			break;
		case'*':
		case'/':	//starting multiply/divide calculation
			while (stack.size() != 0 && (stack.back() == '*' || stack.back() == '/'))
			{
				Post_temp += stack.back();
				Post_temp += " ";
				stack.pop_back();
			}
			stack.push_back(*itr_ind);
			break;
		case' ':
			break;
		default:
			//unknown error
			cout << "����ġ ���� ������ �߻��߽��ϴ�. ���α׷��� �����մϴ�." << endl;
		}
		Post_temp += " ";
	}

	size_t stacksize = stack.size();
	for (size_t i = 0; i < stacksize; ++i)
	{
		Post_temp += " ";
		Post_temp += stack.back();
		stack.pop_back();
	}

	*ptrs = Post_temp;
	PostfixExpression = *ptrs;
	delete ptrs;
}

void Calc_basic::Calculate(void)
{
	string* ptrs = new string;
	*ptrs = PostfixExpression;
	string PostfixExp;
	PostfixExp = *ptrs;

	vector<double> stack;
	string str = "";
	stringstream temp(PostfixExp);

	while (!temp.eof())
	{
		temp >> str;

		if (operators.find(str) == string::npos)
		{
			double dtemp;
			stringstream(str) >> dtemp;
			stack.push_back(dtemp);
		}
		else
		{
			double d1, d2;
			d2 = stack.back();
			stack.pop_back();
			d1 = stack.back();
			stack.pop_back();

			switch (operators[operators.find(str)])
			{
			case '+':
				stack.push_back(d1 + d2);
				break;
			case '-':
				stack.push_back(d1 - d2);
				break;
			case '*':
				stack.push_back(d1 * d2);
				break;
			case '/':
				stack.push_back(d1 / d2);
				break;
			}
		}
	}
	double* ptd = new double;
	*ptd = stack.back();
	result = *ptd;
	delete ptd;
}