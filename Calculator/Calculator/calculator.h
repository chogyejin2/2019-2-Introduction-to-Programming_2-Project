#include <iostream>

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
