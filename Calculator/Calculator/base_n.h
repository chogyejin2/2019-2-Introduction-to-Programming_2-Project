#include "calculator.h"

class Base_N : public Calculator
{
private:

public:
	void ChangeDecimal(int binary) {} //����
	void ChangeBinary(int decimal) {} // ����
};

/*
int main()
{
	int numSystem;
	int n, i = 99; char c[17] = "0123456789ABCDEF", result[100];
	cout << "��ȯ�� ���ڸ� �Է��ϼ���: ";
	scanf("%d", &n);
	cout << "��ȯ�� ���� �Է�(2����, 10����): ";
	scanf("%d", &numSystem);
	if (numSystem == 2) {
		ChangeBinary(n);
	}
	else if (numSystem == 10) {
		ChangeDecimal(n);
	}
	numSystem = 0;
};
*/