#include "calculator.h"

class Base_N : public Calculator
{
private:

public:
	void ChangeDecimal(int binary)
	{
		int sum = 0;
		int temp = 1;
		while (binary != 0)
		{
			if (binary % 10 != 0 && binary % 10 != 1)
			{
				printf("�߸��Է��߽��ϴ�");
				return;
			}

			if (binary % 10 != 0)
			{
				sum = sum + temp;
			}
			binary = binary / 10;
			temp = temp * 2;
		}
		printf("Answer is %d\n", sum);

	}
	void ChangeBinary(int decimal) {
			int i = 99; char c[17] = "0123456789ABCDEF", result[100];

			result[i] = '\0'; // i=99 
			while (decimal != 0) {
				result[--i] = c[decimal % 2]; // result[] <-- ������ 
				decimal /= 2; // �� 
			}
			printf("Answer is %s\n", &result[i]);

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