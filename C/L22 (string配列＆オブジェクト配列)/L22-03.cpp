/*
�ۑ�ԍ��@�FL22-3
���e�@�@�@�Fhero�I�u�W�F�N�g�ɂR�̃A�C�e������v�f�Ƃ���A�C�e���z����i�[���āA�q�[���[���Ƃ���
�@�@�@�@�@�@����̃A�C�e������\������B
�@�@�@�@�@�@�A�C�e���z��͗\��main�֐��ŏ���������B
�@�@�@�@�@�@�q�[���[���̓N���X��`�ŏ���������B
�@�@�@�@�@�@�\���̓I�u�W�F�N�g�ōs���B
�t�@�C�����FL22-03.cpp
�쐬���@�@�F2015/11/12
�쐬�ҁ@�@�FBayaSea
*/

#include <string>		//�����񑀍�p
#include <conio.h>
#include <iostream>
using namespace std;

//�q�[���[�N���X��`
class Hero {
	string name = "BERG";	//�q�[���[��
	string item[3];		//�A�C�e�����z��
public:
	//�A�C�e�����ݒ�@sitem[]�F�A�C�e�����z��
	void setItem(string sitem[])
	{
		for (int i = 0; i < 3; i++)
		{
			item[i] = sitem[i];
		}
	}

	//�q�[���[���A�A�C�e�����\��
	void show()
	{
		cout << name << endl;

		for (int i = 0; i < 3; i++)		
		{
			cout << item[i] << endl;
		}

	}
};
////////////////////////////////////////////////////////////
int main()
{
	Hero hero;
	string item[3] = { "mant", "sword", "bomb" };		//string�z��錾�Ə�����

	hero.setItem(item);		//�A�C�e�����ݒ胁�\�b�h�Ăяo��
	hero.show();			//�A�C�e�����\�����\�b�h�Ăяo��

	_getch();
	return 0;
}


