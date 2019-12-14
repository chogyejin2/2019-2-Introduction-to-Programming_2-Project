#include "calculator.h"


int main(void)
{
	Calc* ptc;
	Calc_basic* ptc_b = new Calc_basic;
	string temps;
	string* ptrs = new string;

	Initialize();
	PrintTitle(1.2);
	PrintMode();

	while (1)
	{
		int i = SelectMode();
		switch (i)
		{
		case BASICCALC:
		{
			ptc_b->ClearConsole();
			cout << "����ǥ���(Infix Notation)���� �ۼ��� ���� �Է��ϼ���. ������ ������ �Ұ����մϴ�.\n";
			cin >> temps;	//null pointer error, why?
			cout << "cin done" << endl;

			*ptrs = temps;

			ptc_b->SetInfix(ptrs);

			ptc_b->SetPostfix(ptc_b->ConvertToPostfix(&ptc_b->GetInfix()));	//null pointer error, why?

			ptc_b->setResult(ptc_b->Calculate(&ptc_b->GetPostfix()));

			cout << ptc_b->getResult() << endl;

			Sleep(10000);
		}
			break;
		case ADVANCEDCALC:
			break;
		case BASE_N:
			break;
		case MATRIX:
			break;
		case QUIT:
			return 0;
		default:
			break;
		}
		system("cls");
	}
	getchar();
	return 0;
}