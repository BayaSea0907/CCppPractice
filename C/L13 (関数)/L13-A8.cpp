/*
�ۑ�ԍ��@�FL13-8
���e�@�@�@�F�󂯎�����Q�̐����l�̕��ϒl��߂��֐����Amain�֐�����Ăяo��
�@�@�@�@�@�@�֐����󂯎��Q�̐����l��main�֐��œ��͂��āA�֐�����߂镽�ϒl��main�֐��ŕ\������B
�t�@�C�����FL13-A8.cpp
�쐬���@�@�F2015/05/27
�쐬�ҁ@�@�FBayaSea
*/

#include <conio.h>
#include <iostream>
using namespace std;

double calcAve(int num1, int num2);	//�֐��̃v���g�^�C�v�錾

int main()
{
	int num1, num2;					//���͗p
	double ave;						//�֐�����߂������ϊi�[�p

	ave = 0;

	cout << "�����l���Q���́i��@100 200�j>> ";

	cin >> num1 >> num2;

	ave = calcAve(num1, num2);		//�֐��̌Ăяo���i�Q�̐����l��n���Ė߂������ς��i�[�j


	cout << "���ϒl="  << ave << endl;

	_getch();
	return 0;
}

/*
�֐����FcalcAve
���e�@�F�����Ŏ󂯎�����Q�̐����l�̕��ς��v�Z����
�����@�Fint num1�@�����l
�@�@�@�@int num2�@�����l
�߂�l�Fdouble�@���ϒl
*/
double calcAve(int num1, int num2)
{
	double ave;

	ave = (double)(num1 + num2) / 2.0;

	return ave;

}
