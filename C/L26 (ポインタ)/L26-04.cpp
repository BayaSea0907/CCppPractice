/*
�ۑ�ԍ��@�FL26-4
���e�@�@�@�Fint�^�ϐ��̃A�h���X�������āA�������A�h���X����n�܂�̈�̒l���P�O�{����multi10
�@�@�@�@�@�@�֐����쐬���ĕ\������B
�@�@�@�@�@�@main�֐���int�^�ϐ��͐錾�Ɠ����ɏ��������Ă����A�\����main�֐��ōs���B
�@�@�@�@�@�@swap�֐��ł�return�����g��Ȃ��B
�t�@�C�����FL26-04.cpp
�쐬���@�@�F2016/1/13
�쐬�ҁ@�@�FBayaSea
*/

#include <conio.h>
#include <iostream>
using namespace std;

void swap(int* p1, int* p2);	//�֐��̃v���g�^�C�v�錾

int main()
{
	int num1 = 100;
	int num2 = 200;

	swap(&num1, &num2);			//�֐��Ăяo��

	cout << "num1=" << num1 << " num2=" << num2 << endl;

	_getch();
	return 0;
}

/*
�֐����Fswap
���e�@�F�������Q�A�h���X����n�܂�̈�Ɋi�[����Ă�������ւ���
�����@�Fint* p1�@int�^�̈�̃A�h���X
int* p2�@int�^�̈�̃A�h���X
�߂�l�F�Ȃ�
*/
void swap(int* p1,	int* p2)
{
	int temp;

	temp = *p1;
	*p1  = *p2;
	*p2  = temp;
}

