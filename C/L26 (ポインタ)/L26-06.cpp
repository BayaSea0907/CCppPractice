/*
�ۑ�ԍ��@�FL26-6
���e�@�@�@�FL26-5�����������āAshow�֐���int�^�z��݂̂�n���đS�v�f��\������B
�@�@�@�@�@�@main�֐��Ŕz��͐錾�Ɠ����ɏ��������Ă����A�\����main�֐��ōs���B
�t�@�C�����FL26-06.cpp
�쐬���@�@�F2016/1/14
�쐬�ҁ@�@�FBayaSea
*/

//�v���O���������������Ċm�F���邱�ƁF
//��#define�@MAX�@5�@��const�w��q���g�����������ɏ��������āA�������ʂ�\���ł��邱�Ƃ��m�F��
//�@�܂��傤�B
//�@�@�@const�@int MAX = 5;
//A.�m�F���܂����B

#include <conio.h>
#include <iostream>
using namespace std;

const int MAX = 5;		//�z��v�f���̒�`

//#define MAX 5			//�z��v�f���̒�`

void show(int ary[]);		//�֐��̃v���g�^�C�v�錾

//////////////////////////////////////////////////////////////////
int main()
{
	int ary[MAX] = { 30, 20, 50, 10, 40 };

	show(ary);		//�֐��Ăяo��

	_getch();
	return 0;
}

/*
�֐����Fshow
���e�@�F�����������l�z��i�v�f���T�j�̑S�v�f��\������
�����@�Fint ary[]�@int�^�z��̐擪�A�h���X
�߂�l�F�Ȃ�
*/
void show(int ary[])
{
	for (int i = 0;	i < MAX; i++){
		cout << " [" << i << "]=" << ary[i];
	}
	cout << endl;
}

