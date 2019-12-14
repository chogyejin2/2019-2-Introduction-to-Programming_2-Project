#ifndef CALCULATOR
#define CALCULATOR
#define _USE_MATH_DEFINES		//to use M_PI(exact pi value)
#define CONSOLECOLS 60			//�ܼ� â�� ���� ����
#define COMSOLEROWS 20			//�ܼ� â�� ���� ����

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77	//define ASCII code for arrow key
#define SUBMIT 13		//define ASCII code for enter key(\n) -- use enter key to submit something
#define ESC 27			//define ASCII code for ESC key -- use ESC key to cancle something

#define BASICCALC 1
#define ADVANCEDCALC 2
#define MATRIX 3
#define BASE_N 4
#define QUIT 5			//define each mode in integer type (1~5)

#include <iostream>
#include <Windows.h>
#include <conio.h>	//for using _getch()
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <string>
#include <vector>
#include <sstream>

/*
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::stack;
using std::stringstream;
using std::ios_base::eof();
*/

using namespace std;

class Calc {
private:
protected:
public:
	void ClearConsole(void);
	/*
	ȭ���� ��� �����ϴ� ���� Ŭ����
	*/
};

class Calc_basic : public Calc {
private:
protected:
	string InfixExpression;
	string PostfixExpression;
	const string operators = "(+-*/)";	//available opeartors -- parenthes, plus, minus, multiple, divide
	double result;
public:
	Calc_basic() : result(0.0) {};
	void SetInfix(string* str) { InfixExpression = *str; }
	void SetPostfix(string str) { PostfixExpression = str; }

	string GetInfix(void) { return InfixExpression; }
	string GetPostfix(void) { return PostfixExpression; }
	
	void SetResult(double db) { result = db; }
	double GetResult(void) { return result; }
	
	string InputInfixExp(void);
	string ConvertToPostfix(const string* InfixExp);
	double Calculate(const string* PostFixExp);
};

class Calc_Eng : public Calc_basic {
private:
protected:
	const float PI = M_PI;
	const float E = M_E;
public:
	/*
	�⺻ ���п� ���(�� ���� ��� + �߰����� ��ɵ�)
	1. �ﰢ�Լ�, �ְ�Լ�, ���ﰢ�Լ��� �⺻ ����
	2. ����, �α�, ������ ���
	3. ���� ���̴� ���(e, pi ��) �ٷ� ��� �Ŀ� ���� ����
	*/
};

class Calc_Eng_Advanced : public Calc_Eng {
private:
protected:
public:
	/*
	��� ���п� ���(�⺻ ���п� ��� + ���п� ����θ� ������ ��ɵ�)
	*/
};

void Initialize(void);
void MoveCursor(int x, int y);
int ReadKey(void);
void PrintTitle(float Seconds);
void PrintMode(void);
int SelectMode(void);
void PrintLine(int xPos, int yPos, int amount);

#endif