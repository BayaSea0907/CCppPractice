/*
�ۑ�ԍ��@�FL13-5
���e�@�@�@�Fmain�֐���hyouzi�֐����ꂼ��Ő錾�����������O�inum�j�̕ϐ��Ɋi�[�����l��\�����āA
�@�@�@�@�@�@�֐����قȂ�΁A�������O�̕ϐ��ł����Ă��܂������ʕ��ł��邱�Ƃ��m�F����B
�@�@�@�@�@�@�m�F���邽�߂ɁAhyouzi�֐��̕ϐ���\��������Amain�֐��̕ϐ���\������B
�t�@�C�����FL13-05.cpp
�쐬���@�@�F2015/05/27
�쐬�ҁ@�@�FBayaSea
*/

//���s���Ċm�F���邱�ƁF
//�����s���ʂ���A�֐��Ő錾�����ϐ��i�����ϐ��Ƃ����j�́A�錾�����֐��̒��ł̂ݎg����i�L���ł���j
//�@���Ƃ��m�F���Ȃ����B
//A.�m�F���܂����B

#include <conio.h>
#include <iostream>
using namespace std;

void hyouzi();			//�֐��̃v���g�^�C�v�錾

int main()
{
	int num;		//main�֐��Ő錾�����ϐ��i�����ϐ��j

	num = 100;
	cout << "main�֐���num=" << num << endl;

	hyouzi();		//�֐��̌Ăяo��

	cout << "main�֐���num=" << num << endl;

	_getch();
	return 0;
}

/*
�֐����Fhyouzi
���e�@�F�֐����Ő錾�����ϐ��̒l��\������
�����@�F�Ȃ�
�߂�l�F�Ȃ�
*/
void hyouzi()
{
	int num; 		//hyouzi�֐��Ő錾�����ϐ��i�����ϐ��j

	num = 200;
	cout << "hyouzi�֐���num=" << num << endl;
}
