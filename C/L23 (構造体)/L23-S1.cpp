/*
�ۑ�ԍ��@�FL23-Special1
���e�@�@�@�F��ero�I�u�W�F�N�g�Ƀq�[���[���ƃA�C�e���\���̂��i�[���āA�q�[���[���ƃA�C�e���\���̂�
�@�@�@�@�@�@�����o��\������B
�@�@�@�@�@�@�A�C�e���\���̂̃����o�́A�A�C�e�����Ɣ\�́A���̃A�C�e�������ʂ�^����Ώۂ̗L���\���́B
�@�@�@�@�@�@�L���\���̂̃����o�́A���ʂ�^����G���ƃ_���[�W�́B
�@�@�@�@�@�@�\���̂̃����o�ɑ��̍\���̂������Ƃ��A�\���̂̓���q���邢�̓l�X�e�B���O�Ƃ����B
�@�@�@�@�@�@�q�[���[���ƃA�C�e���\���̂̃����o�́A�R���X�g���N�^���g���ď���������B
�E�@�@�@�@�@�\���́A�I�u�W�F�N�g�ōs���B
�t�@�C�����FL23-S1.cpp
�쐬���@�@�F2015/11/21
�쐬�ҁ@�@�FBayaSea
*/

#include <string>		//�����񑀍�p
#include <conio.h>
#include <iostream>
using namespace std;

//�L���\���̒�`
struct Effect {
	string enemy;	//�L���G��
	int damage;		//�_���[�W��
};

//�A�C�e���\���̒�``
struct Item {
	string name; 	//�A�C�e����
	int power;		//�\��
	Effect efc;		//�L���\����
};

////////////////////////////////////////////////////////////////
//�q�[���[�N���X��`
class Hero {
	string name;	//�q�[���[��
	Item itm;		//�A�C�e��
public:
	//�R���X�g���N�^�@�q�[���[���ƃA�C�e���\���̏�����
	Hero()
	{
		//�q�[���[��
		name = "BERG";
		//�A�C�e���\���̏�����
		itm = { "sword",200,{"Satan", 30} };
	}

	//�\��
	void show()
	{
		cout << "�A�C�e����" << itm.name << " �\�́�" << itm.power << endl 
			 << "�L���G=" << itm.efc.enemy << " �_���[�W��=" 
			 << itm.efc.damage << endl;
	}

};
////////////////////////////////////////////////////////////////
int main()
{
	Hero hero;

	hero.show();	//�\�����\�b�h�Ăяo��

	_getch();
	return 0;
}

