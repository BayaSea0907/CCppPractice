/*
�ۑ�ԍ��@�FL12-5
���e�@�@�@�F�����l���Q���͂��āA����Z�������̗]���\������B
�t�@�C�����FL12-05.cpp
�쐬���@�@�F2015/04/13
�쐬�ҁ@�@�FBayaSea
*/

#include <conio.h>
#include <iostream>
using namespace std;

int main()
{
	int num1; 		//���͗p
	int num2; 		//���͗p
	int amari;		//�]��p

	cout << "�������Q���́i��@100 3�j>> ";

	cin >> num1 >> num2;

	amari = num1 % num2;		//�]��v�Z

	//�������]��̕\��
	cout << "����Z�����]��=" << amari << endl;

	_getch();
	return 0;
}
