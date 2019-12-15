#include "calculator.h"

int main(void)
{
	Calc* ptc = new Calc;
	Calc_Util* ptc_u = new Calc_Util;
	Calc_Basic* ptc_b = new Calc_Basic;

	Initialize();
	ptc_u->PrintTitle(3);

	while (1)
	{
		ptc_u->PrintMode();
		int mode = ptc_u->SelectMode();
		switch (mode)
		{
		case BASICCALC:
			ptc_u->ClearConsole();
			ptc_b->PrintGuide(18, 2);
			ptc_b->SetInfixExp(3, 6);
			ptc_b->ConvertToPostfix();
			ptc_b->Calculate();
			ptc_b->PrintResult(3, 10);
			ptc_u->Delay(1);
			break;
		case ADVANCEDCALC:
			break;
		case BASE_N:
			break;
		case MATRIX:
			break;
		case QUIT:
			ptc_u->ExitCalc(5, 5, 1.4);
			return 0;
		default:
			break;
		}
		ptc_u->ClearConsole();
	}
	//Unknown error -- in normal input, cannot reach this point
	ptc_u->ExitCalc(5, 5, 1.4, "������ �� ���� main() �Լ��� ���� �����߽��ϴ�.");
	return 0;
}