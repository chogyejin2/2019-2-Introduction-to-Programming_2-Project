#include "arithmetic.h"
#include "utility.h"
#include "matrix.h"
#include "base_n.h"

int main(void)
{
	Initialize();
	Utility* UTL = new Utility();
	Arithmetic* ARI = NULL;
	Matrix* Matrix_A = NULL;
	Matrix* Matrix_B = NULL;
	Base_N* BN = NULL;

	UTL->PrintTitle();
	UTL->WaitforSec(1.5);

	while (1)
	{
		UTL->RefreshConsole();
		UTL->SetPos(5, 1);
		UTL->PrintGuide("BASIC");
		UTL->SetPos(5, 5);
		UTL->PrintModes("BASIC");
		switch (UTL->SelectMode("BASIC"))
		{
		case ARITHMETIC:
			UTL->RefreshConsole();
			ARI = new Arithmetic();
			UTL->SetPos(10, 10);
			UTL->PrintGuide("ARITHMETIC");
			ARI->SetInfixExpression();
			ARI->ConvertExpression();
			ARI->Calculate();
			UTL->RefreshConsole();
			UTL->SetPos(12, 10);
			UTL->PrintConsole(ARI->GetResult());
			UTL->WaitforSec(1.5);
			break;
		case MATRIX:
			/*ptc_m->PrintGuide(18, 2);
			ptc_m->PrintModes();
			if (ptc_m->SelectMode() == DEFINEMATRIX
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
}*/
			break;
		case BASE_N:
			break;
		case QUIT:
			UTL->ExitCalc();
			return 0;
		default:
			break;
		}
	}
	//Unknown error -- in normal input, cannot reach this point
	//ptc_u->ExitCalc(5, 5, 1.4, "���� : ������ �� ���� main() �Լ��� ���� �����߽��ϴ�.");
	return 0;
}