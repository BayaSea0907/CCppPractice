/*
�ۑ�ԍ��@�FL27-5
���e�@�@�@�F�A���P�[�V�����������i�\���̗̈�̃����o�ɓ��͂��āA���i�\���̂̃����o��\������B
�@�@�@�@�@�@main�֐��݂̂ōs���B
�t�@�C�����FL27-05.cpp
�쐬���@�@�F2016/1/20
�쐬�ҁ@�@�FBayaSea
*/

#include <string>
#include <conio.h>
#include <iostream>
using namespace std;

//���i�\���̂̒�`
struct Goods {
	string name;		//�i��
	int cost;		//�l�i�i�~�j
};

int main()
{
	Goods* p;		//�A���P�[�V�����\���̗̈�ւ̃|�C���^�錾

	//�������̃A���P�[�V����
	p = new Goods;

	//�A���P�[�V�����ł��Ȃ������ꍇ
	if (p == NULL)
	{
		cout << "�A���P�[�V�������s" << endl;
	}
	//�A���P�[�V�����ł����ꍇ
	else
	{
		//�A���P�[�V�����̈�ɓ���
		cout << "�i������́i��@melon�j>> ";
		cin >> p->name;

		cout << "�l�i����́i��@850�j>> ";
		cin >> p->cost;

		//�A���P�[�V�����̈�̕\��
		cout <<	p->name << " " << p->cost << endl;

		//�A���P�[�V�����̈�̉���i�K���s�����Ɓj
		delete p;

	}

	_getch();
	return 0;
}

