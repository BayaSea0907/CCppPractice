/*
�ۑ�ԍ��@�FL11-special1
���e�@�@�@�F�ϐ��inum1��num2�j�ɐ����l����͂����l���A����ւ���i��������j
�t�@�C�����FL11-S1.cpp
�쐬���@�@�F2015/04/30
�쐬�ҁ@�@�FBayaSea
*/

#include <conio.h>
#include <iostream>
using namespace std;

int main()
{
	int num1; 		//���͗p
	int num2; 		//���͗p
	int taihi;		//�ޔ�p

	cout << "�ϐ�num1�ɐ����l�����>> ";
	cin >> num1;

	cout << "�ϐ�num2�ɐ����l�����>> ";
	cin >> num2;

	taihi = num1;
	num1  = num2;
	num2  = taihi;


		cout << "����ւ����num1�̒l=" << num1 << " num2�̒l=" << num2 << endl;

	_getch();
	return 0;
}
