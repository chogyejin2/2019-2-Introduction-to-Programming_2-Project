#ifndef CALCULATOR
#define CALCULATOR
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
#include <stack>
#include <vector>
#include <sstream>

class Calc {
private:
protected:
public:
	/*
	�߻����� ���� Ŭ����
	*/
};

class Calc_basic : public Calc {
private:
protected:
	string InfixExp;
	string PostfixExp;
	const string symbol = "(+-*/)";
public:
	string ConvertintoPostFix(const string InfixExp);
	double Calculate(const string PostFixExp);
};

class Calc_Eng : public Calc_basic {
private:
protected:
	const float PI = M_PI;
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
void PrintTitle(float);
void PrintMode(void);
int SelectMode(void);
void PrintLine(int, int, int);
#endif