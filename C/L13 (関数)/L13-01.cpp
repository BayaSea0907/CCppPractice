/*
�ۑ�ԍ��@�FL13-1
���e�@�@�@�F���͂��������l���P�O�{���ĕ\������֐����Amain�֐�����Ăяo���B
�t�@�C�����FL13-01.cpp
�쐬���@�@�F2015/05/20
�쐬�ҁ@�@�FBayaSea
*/

//�m�F���邱�ƁF
//��()���̈������т������Ă��܂���B���̂��Ƃ͉���\���Ă��܂����H
//A.�����Ȃ�

//���߂�l�̌^��void�͉���\���Ă��܂����H
//�߂�l�Ȃ�

//���֐��̌Ăяo���́A�ǂ̂悤�ɏ����Ă���܂����H
//�����͂Ȃ��̂ł��̂܂܊֐����Ăяo���Ă���B

#include <conio.h>
#include <iostream>
using namespace std;

void inputHyouzi();		//�֐��̃v���g�^�C�v�錾

int main()
{
	//�֐��̌Ăяo��
	inputHyouzi();

	_getch();
	return 0;
}

/*
�֐����FinputHyouzi
���e�@�F���͂��������l���P�O�{���ĕ\������
�����@�F�Ȃ�
�߂�l�F�Ȃ�
*/
void inputHyouzi()
{
	int num; 		//���͗p

	printf("�����l�����>> ");
	cin >> num;

	num *= 10; 		//num = num * 10�@�Ɠ���

	cout << "�P�O�{�����l=" << num << endl;
}
