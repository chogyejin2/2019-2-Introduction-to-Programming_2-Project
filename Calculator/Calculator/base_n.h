#include "calculator.h"

class Base_N : public Calculator
{
private:
	int sum = 0;
	int temp = 1;
	int binary;
	int decimal;

public:
	void ChangeDecimal(int binary);  //����
	void ChangeBinary(int decimal); // ����
	int getBinary() {
		return binary;
	}
	int getDecimal() {
		return decimal;
	}


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