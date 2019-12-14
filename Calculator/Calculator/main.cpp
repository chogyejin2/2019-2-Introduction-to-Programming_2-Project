#include "calculator.h"

/*int main(void)
{
	Initialize();
	ShowTitle(1);
	ShowMode();
	while (1)
	{
		switch (SelectMode())
		{
		case CALCULATE:
			break;
		case TRIGONOMETRIC:
			break;
		case BASE_N:
			break;
		case MATRIX:
			break;
		case QUIT:
			break;
		default:
			break;
		}
		system("cls");
	}
	getchar();
	return 0;
}
*/
// String Calculator
#include <iostream>
#include <string>
#include <stack>
#include <sstream>

using namespace std;

struct oper {
	int p; // ������ �켱����
	string o; // ������
};

stack<int> num; // ���� ����
stack<oper> op; // ������ ����

void calc() {
	int a, b, result;
	b = num.top();
	num.pop();
	a = num.top();
	num.pop();
	string oper = op.top().o;
	op.pop();

	if (oper == "*")
		result = a * b;
	else if (oper == "/")
		result = a / b;
	else if (oper == "+")
		result = a + b;
	else if (oper == "-")
		result = a - b;
	// ��� �� ���ÿ� �ٽ� ����
	num.push(result);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string input = "15 + 32 * ( 1 - 8 ) / 2"; // -97
	stringstream ss(input);

	// ������ �켱������ ���� ���ÿ� push
	// 0 : ( )
	// 1 : + -
	// 2 : * /
	string tok;
	while (ss >> tok) {
		// ( �� ������ ������ ���ÿ� push
		if (tok == "(") {
			op.push({ 0, tok });
		} // ) �� ������ ( �� ���� �� ���� ���
		else if (tok == ")") {
			while (op.top().o != "(")
				calc();
			op.pop();
		}
		else if (tok == "*" || tok == "/" || tok == "+" || tok == "-") {
			int prior; // ������ �켱����
			if (tok == "*")
				prior = 2;
			else if (tok == "/")
				prior = 2;
			else if (tok == "+")
				prior = 1;
			else if (tok == "-")
				prior = 1;

			// ������ �켱 ���� ������ top���� �� ������ ���
			while (!op.empty() && prior <= op.top().p)
				calc();
			// ���ÿ� ������ push
			op.push({ prior, tok });
		}
		else // ������ ��� ���� ���ÿ� push
			num.push(stoi(tok));
	}
	// ���� ������ ���
	while (!op.empty())
		calc();

	cout << num.top();
	getchar();
	return 0;
}
