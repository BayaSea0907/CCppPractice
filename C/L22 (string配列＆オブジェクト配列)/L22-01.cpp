/*
�ۑ�ԍ��@�FL22-1
���e�@�@�@�Fhero�I�u�W�F�N�g�Ƀq�[���[���ƂR�̃A�C�e�����istring������j���i�[���āA�q�[���[��
�@�@�@�@�@�@�Ƃ��ꂼ��̃A�C�e������\������B
�@�@�@�@�@�@�q�[���[���̓N���X��`�ŏ���������B
�@�@�@�@�@�@�i�[�ƕ\���̓I�u�W�F�N�g�ōs���B
�t�@�C�����FL22-01.cpp
�쐬���@�@�F2015/11/12
�쐬�ҁ@�@�FBayaSea
*/

#include <string>		//�����񑀍�p
#include <conio.h>
#include <iostream>
using namespace std;

//�q�[���[�N���X��`
class Hero {
	int* item;			//�A�C�e�����z��
public:
	//�A�C�e�����ݒ�
	void setItem(int* n)
	{
		item = n;
	}
	//�q�[���[���A�A�C�e�����\��
	void show(){
		cout << (unsigned char)item << endl;


	}
};
////////////////////////////////////////////////////////////
int main()
{
	Hero hero;
	int item = 15;

	hero.setItem(&item);		//�A�C�e�����ݒ胁�\�b�h�̌Ăяo��
	hero.show();		//�q�[���[���A�A�C�e�����\�����\�b�h�̌Ăяo��

	_getch();
	return 0;
}

