/*
�ۑ�ԍ��@�FL22-2
���e�@�@�@�FL22-1�����������āAhero�I�u�W�F�N�g�ɓ��͂����R�̃A�C�e�������i�[���āA�q�[���[��
�@�@�@�@�@�@�Ƃ��ꂼ��̃A�C�e������\������B
�@�@�@�@�@�@���͂ƕ\���̓I�u�W�F�N�g�ōs���B
�t�@�C�����FL22-02.cpp
�쐬���@�@�F2015.10.1
�쐬�ҁ@�@�FBayaSea
*/

#include <string>		//�����񑀍�p
#include <conio.h>
#include <iostream>
using namespace std;

//�q�[���[�N���X��`
class Hero {
	string name = "BERG";		//�q�[���[��
	string item[3];			//�A�C�e�����z��
public:
	//�A�C�e��������
	void inpItem(){
		for (int i = 0; i < 3; i++)
		{
			cout << "�A�C�e���������>> ";
			cin >> item[i];
		}
	}

	//�q�[���[���A�A�C�e�����\��
	void show(){
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

	hero.inpItem();		//�A�C�e�������̓��\�b�h�̌Ăяo��
	hero.show();		//�q�[���[���A�A�C�e�����\�����\�b�h�̌Ăяo��

	_getch();
	return 0;
}


