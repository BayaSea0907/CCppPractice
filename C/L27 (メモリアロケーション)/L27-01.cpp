/*
�ۑ�ԍ��@�FL27-1
���e�@�@�@�F�A���P�[�V��������int�^�̈�ɐ����P�O�O���i�[���āA�A���P�[�V�����̈�Ɋi�[����Ă�
�@�@�@�@�@�@��l��\������B
�@�@�@�@�@�@main�֐��݂̂ōs���B
�t�@�C�����FL27-01.cpp
�쐬���@�@�F2016/1/19
�쐬�ҁ@�@�FBayaSea
*/

#include <conio.h>
#include <iostream>
using namespace std;

int main()
{
	int* p;		//�A���P�[�V�����̈�ւ̃|�C���^�錾

	//�������̃A���P�[�V����
	p = new int;

	//�A���P�[�V�����ł��Ȃ������ꍇ
	if (p == NULL)
	{
		cout << "�A���P�[�V�������s" << endl;
	}
	//�A���P�[�V�����ł����ꍇ
	else
	{
		//�A���P�[�V�����̈�ɒl���i�[
		*p = 100;

		//�A���P�[�V�����̈�̒l��\��
		cout << "�A���P�[�V�����̈�̒l=" << *p << endl;

		//�A���P�[�V�����̈�̉���i�K���s�����Ɓj
		delete p;

	}

	_getch();
	return 0;
}




