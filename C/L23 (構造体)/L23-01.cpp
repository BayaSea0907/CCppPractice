/*
�ۑ�ԍ��@�FL23-1
���e�@�@�@�Fhero�I�u�W�F�N�g�Ƀq�[���[���ƃA�C�e���\���́i�A�C�e�����Ɣ\�́j���i�[���āA�q�[���[��
�@�@�@�@�@�@�ƃA�C�e���\���̂̃����o��\������B
�@�@�@�@�@�@�i�[�ƕ\���̓I�u�W�F�N�g�ōs���B
�@�@�@�@�@�@L23-1����L23-6�܂ł́A���̃A�C�e���\���̂��g���B
�t�@�C�����FL23-01.cpp
�쐬���@�@�F2015/11/19
�쐬�ҁ@�@�FBayaSea
*/

//�v���O���������������Ċm�F���邱�ƁF
//���\���̕ϐ��̒�`�@Item item;�@���Astruct Item item;�@�̂悤�ɏ��������Ă��A�錾�ł��邱��
//�@���m�F���܂��傤�B
//A. ���܂����B

#include <string>		//�����񑀍�p
#include <conio.h>
#include <iostream>
using namespace std;

//�A�C�e���\���̂̒�`
struct Item {
	string name;		//�A�C�e����
	int power;			//�\��
};

//�q�[���[�N���X��`
class Hero {
	string name;		//�q�[���[��
	Item item;			//�A�C�e���\���̕ϐ�
//	struct Item item;	//�A�C�e���\���̕ϐ�
public:
	//�q�[���[���A�A�C�e���ݒ�
	void setProperty(){
		name = "BERG";			//�q�[���[��
		item.name = "mant";		//�A�C�e�����ݒ�
		item.power = 50;		//�A�C�e���\�͐ݒ�
	}

	//�q�[���[���A�A�C�e���\��
	void show(){
		cout << name << " " << item.name << " " <<	item.power << endl;
	}
};
////////////////////////////////////////////////////////////
int main()
{
	Hero hero;

	hero.setProperty();	//�q�[���[���A�A�C�e���ݒ胁�\�b�h�Ăяo��
	hero.show();		//�q�[���[���A�A�C�e���\�����\�b�h�Ăяo��

	_getch();
	return 0;
}

