#include "calculation.h"
#include "utility.h"
#include "matrix.h"
#include "base_n.h"

int main(void)
{
	Initialize();
	Calculator* CAL = new Calculator;
	Utility* UTL = new Utility;
	UTL->PrintTitle(1.5);

	while (1)
	{
		ptc_u->PrintMode();
		int mode = ptc_u->SelectMode();
		switch (mode)
		{
		case BASICCALC:
			ptc_b = new Calc_Basic();
			ptc_b->PrintGuide(18, 2);
			ptc_b->SetInfixExp(3, 6);
			ptc_b->ConvertToPostfix();
			ptc_b->Calculate();
			ptc_b->PrintResult(3, 10);
			ptc_b->Delay(1.2);
			break;
		case ADVANCEDCALC:
			break;
		case BASE_N:
			break;
		case MATRIX:
			ptc_m->PrintGuide(18, 2);
			ptc_m->PrintMode();
			if (ptc_m->SelectMode() == DEFINEMATRIX)
			{ 
				ptc_m->PrintAt(5, 5, "A, B �� ������ ����� Ű����� �Է��� �ּ���.");
				if (ptc_m->ReadKey() == A)
				{
					ptc_u->RefreshConsole();
					int r_temp, c_temp;
					ptc_m->PrintAt(5, 5, "�� ���� �����ϼ���.(1~3)");
					cin >> r_temp;
					ptc_m->PrintAt(5, 6, "�� ���� �����ϼ���.(1~3)");
					cin >> c_temp;
					Matrix_A = new Matrix(r_temp, c_temp);
					ptc_u->RefreshConsole();
					ptc_m->PrintAt(5, 6, "�� ���е��� �Է��ϼ���. ����� �� �����ϴ�.");
					for (int r = 0; r < Matrix_A->GetRow(); r++)
					{
						for (int c = 0; c < Matrix_A->GetCol(); c++)
						{
							MoveCursor(5, 7);
							cin >> Matrix_A->GetP()[r][c];
						}
					}
				}
				else if (ptc_m->ReadKey() == B)
				{

				}
			}
			else if (ptc_m->SelectMode() == EDITMATRIX)
			{
				ptc_m->RefreshConsole();
				ptc_m->PrintAt(5, 5, "A, B �� ������ ����� Ű����� �Է��� �ּ���.");
			}
			else//�� ���͸� �ι� ������ ����� ����?
			{
				ptc_m->RefreshConsole();
				for (int r = 0; r < Matrix_A->GetRow(); r++)
				{
					for (int c = 0; c < Matrix_A->GetCol(); c++)
					{
						ptc_m->PrintAt(5, 10, "TEST");
						MoveCursor(5 + r, 6 + c);
						cout <<  Matrix_A->GetP()[r][c];
					}
					cout << endl;
				}
				ptc_u->Delay(2);
			}
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
	ptc_u->ExitCalc(5, 5, 1.4, "���� : ������ �� ���� main() �Լ��� ���� �����߽��ϴ�.");
	return 0;
}