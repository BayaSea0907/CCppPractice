/*
�ۑ�ԍ��@�FL22-6
���e�@�@�@�FL22-4�����������āAhero�I�u�W�F�N�g�ɂR�̃A�C�e������v�f�Ƃ���A�C�e���z����i�[
�@�@�@�@�@�@���āA�I�u�W�F�N�g�Ɋi�[�����q�[���[���ƃA�C�e���z����P�̃��\�b�h�Ŏ擾���āA�q�[��
�@�@�@�@�@�@�[���Ƃ��ꂼ��̃A�C�e������\������B
�@�@�@�@�@�@�A�C�e���z��͗\��main�֐��ŏ���������B
�@�@�@�@�@�@�q�[���[���̓N���X��`�ŏ���������B
�@�@�@�@�@�@�\����main�֐��ōs���B
�t�@�C�����FL22-A6.cpp
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
	//�R���X�g���N�^ item�z���������
	Hero(){
		item[0] = "mant" ;
		item[1] = "sword";
		item[2] = "bomb" ;
	}

	//�q�[���[���A�A�C�e�����擾�@sitem[]�F�A�C�e�����z��
	//�@�@�@�@�@�@�@�@�@�@�@�@�@�@�߂�l�F�q�[���[��
	string getNameItem(string sitem[])
	{
		for (int i = 0; i < 3; i++)
		{
			sitem[i] = item[i];
		}

		return name;
	}
};
////////////////////////////////////////////////////////////
int main()
{
	Hero hero;
	string str[3];			//�A�C�e���z��擾�p
	string name;			//�q�[���[���擾�p

	name = hero.getNameItem(str);					//�q�[���[���A�A�C�e�����擾���\�b�h�Ăяo��

	cout << name << endl; 	//�q�[���[���\��

	//�A�C�e�����\��
	for (int i = 0; i < 3; i++)
	{
		cout << str[i] << endl;
	}

	_getch();
	return 0;
}

