/*
�ۑ�ԍ��@�FL13-4
���e�@�@�@�F�󂯎���������l���P�O�{���Ė߂��֐����Amain�֐�����Ăяo���B
�@�@�@�@�@�@�֐����󂯎�鐮���l��main�֐��œ��͂��āA�֐�����߂����l��main�֐��ŕ\������B
�t�@�C�����FL13-04.cpp
�쐬���@�@�F2015/05/27
�쐬�ҁ@�@�FBayaSea
*/

//�m�F���邱�ƁF
//���֐����󂯎��l�̌��ƌ^�͂Ȃ�ł����H
//A.1�Aint�^

//���֐����߂��l�̌^�Ɩ߂�l�̌^�͂Ȃ�ł����H
//A.int�^

//���֐����Ăяo���Ă���P���́A�ǂ̂悤�ɏ����Ă���܂����H
//A.ret = calcRet(num);

#include <conio.h>
#include <iostream>
using namespace std;

int calcRet(int knum);	//�֐��̃v���g�^�C�v�錾

int main()
{
	int num; 	//���͗p
	int ret; 	//�֐�����߂��Ă����l�i�[�p

	cout << "�����l�����>> ";
	cin >> num;

	//�֐��̌Ăяo���i�l��n���āA�߂����l���i�[����j
	ret = calcRet(num);

	cout << "�߂����l=" << ret << endl;

	_getch();
	return 0;
}

/*
�֐����FcalcRet
���e�@�F�󂯎���������l���P�O�{���Ė߂�
�����@�Fint knum�@�����l
�߂�l�Fint knum�@�P�O�{���������l
*/
int calcRet(int knum)
{
	knum *= 10; 		//knum = knum * 10�@�Ɠ���

	return knum;	//num�̒l��߂�
}
