/*
�ۑ�ԍ��@�FL23-5
���e�@�@�@�Fhero�I�u�W�F�N�g�Ƀq�[���[���ƃA�C�e���\���́i�A�C�e�����Ɣ\�́j���i�[���āA�q�[���[��
�@�@�@�@�@�@�ƃA�C�e���\���̂̃����o��\������B
�@�@�@�@�@�@main�֐�����I�u�W�F�N�g�Ƀq�[���[���ƃA�C�e���\���̂�n���Ċi�[����B
�@�@�@�@�@�@�\���̓I�u�W�F�N�g�ōs���B
�t�@�C�����FL23-05.cpp
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
		cout <<	name << " " <<	item.name << " " <<	item.power << endl;
	}
};
////////////////////////////////////////////////////////////
int main()
{
	Hero hero;
	string name; 		//�q�[���[���i�[�p
	Item item;			//�A�C�e���\����

	name = "BERG";			//�q�[���[���i�[
	item.name = "mant";		//�A�C�e�����i�[
	item.power = 50;		//�\�͊i�[

	hero.setName(name);		//�q�[���[���ݒ胁�\�b�h�Ăяo��
	hero.setItem(item);		//�A�C�e���ݒ胁�\�b�h�Ăяo��
	hero.show();			//�q�[���[���A�A�C�e���\�����\�b�h�Ăяo��

	_getch();
	return 0;
}

