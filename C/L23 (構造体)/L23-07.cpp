/*
�ۑ�ԍ��@�FL23-7
���e�@�@�@�Fhero�I�u�W�F�N�g�Ƀq�[���[���ƃA�C�e���\���̂��i�[���āA�q�[���[���ƃA�C�e���\���̂̃�
�@�@�@�@�@�@���o��\������B
�@�@�@�@�@�@�A�C�e���\���̂̃����o�́A�A�C�e�����Ɣ\�́B
�@�@�@�@�@�@�q�[���[���ƃA�C�e���\���̂́Amain�֐��Ő錾�Ɠ����ɏ���������B
�@�@�@�@�@�@�\���̓I�u�W�F�N�g�ōs���B
�t�@�C�����FL23-07.cpp
�쐬���@�@�F2015/11/19
�쐬�ҁ@�@�FBayaSea
*/

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
	Item item;			//�A�C�e���\����
public:
	//�q�[���[���ݒ�@str�F�q�[���[��
	void setName(string str){
		name = str;
	}

	//�A�C�e���ݒ�@itm�F�A�C�e���\����
	void setItem(Item itm){
		item = itm;
	}

	//�q�[���[���A�A�C�e���\��
	void show(){
		cout << name << endl;

		cout << item.name << " " << item.power << endl;
	}
};
////////////////////////////////////////////////////////////
int main()
{
	Hero hero;
	string name = "BERG"; 			//�q�[���[���i�[�p�ϐ��̐錾�Ɠ����̏�����
	Item item = { "mant", 50 };		//�A�C�e���\���̕ϐ��̐錾�Ɠ����̏�����

	hero.setName(name);		//�q�[���[���ݒ胁�\�b�h�Ăяo��
	hero.setItem(item);		//�A�C�e���ݒ胁�\�b�h�Ăяo��
	hero.show();			//�q�[���[���A�A�C�e���\�����\�b�h�Ăяo��

	_getch();
	return 0;
}

