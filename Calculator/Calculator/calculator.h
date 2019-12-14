#ifndef CALCULATOR
#define CALCULATOR
#define COLS 60			//columns size of console
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77	//define ASCII code for arrow key
#define SUBMIT 13		//define ASCII code for enter key(\n)
#define ESC 27
#define CALCULATE 1
#define TRIGONOMETRIC 2
#define BASE_N 3
#define MATRIX 4		//define each calculate mode in int(1~5)
#define QUIT 5

#include <iostream>
#include <Windows.h>
#include <conio.h>	//for using _getch()
#include <cstdlib>
#include <ctime>
#include <string>
#include <stack>

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
public:
	/*
	�⺻ ���(�� ���� �Ѹ� �ٷ� ����)
	1. �Ǽ� ��Ģ����
	2. �ۼ�Ʈ ����
	3. ��ȣ ������ ����
	4. ���� ��µǰ� �ִ� ȭ�� �����
	*/
};

class Calc_Eng : public Calc_basic {
private:
protected:
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
void ShowTitle(float);
void ShowMode(void);
int SelectMode(void);
#endif