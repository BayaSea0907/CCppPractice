/*
�ۑ�ԍ��@�FL22-4
���e�@�@�@�FL22-3�����������āAhero�I�u�W�F�N�g�ɂR�̃A�C�e������v�f�Ƃ���A�C�e���z����i�[
�@�@�@�@�@�@���āA�I�u�W�F�N�g�Ɋi�[�����q�[���[���Ƃ��ꂼ��̃A�C�e������\������B
�@�@�@�@�@�@�A�C�e���z��͗\��main�֐��ŏ���������B
�@�@�@�@�@�@�q�[���[���̓N���X��`�ŏ���������B
�@�@�@�@�@�@�\����main�֐��ōs���B
�t�@�C�����FL22-04.cpp
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
	//�A�C�e�����擾�@sitem[]�F�A�C�e�����z��
	void getItem(string sitem[])
	{
		for (int i = 0; i < 3; i++)
		{
			sitem[i] = item[i];
		}
	}
	//�q�[���[���擾
	string getName()
	{
		return name;
	}
};
////////////////////////////////////////////////////////////
int main()
{
	Hero hero;	
	string item[3] = { "mant", "sword", "bomb" };		//string�z��錾�Ə�����
	string str[3];										//�A�C�e���z��擾�p

	hero.setItem(item);					//�A�C�e�����ݒ胁�\�b�h�Ăяo��
	hero.getItem(str);					//�A�C�e�����擾���\�b�h�Ăяo��

	cout << hero.getName() << endl;		//�q�[���[���擾

	//�A�C�e�����\��
	for (int i = 0; i < 3; i++)
	{
		cout << str[i] << endl;	
	}

	_getch();
	return 0;
}


