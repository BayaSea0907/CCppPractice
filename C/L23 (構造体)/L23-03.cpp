/*
�ۑ�ԍ��@�FL23-3
���e�@�@�@�Fhero�I�u�W�F�N�g�Ƀq�[���[���ƃA�C�e���\���̔z��i�v�f���Q�j���i�[���āA�q�[���[���ƃA
�@�@�@�@�@�@�C�e���\���̂̃����o��\������B
�@�@�@�@�@�@�A�C�e���\���̂̃����o�́A�A�C�e�����Ɣ\�́B
�@�@�@�@�@�@�J�Ԃ�����͍s��Ȃ��B
�@�@�@�@�@�@�i�[�ƕ\���̓I�u�W�F�N�g�ōs���B
�t�@�C�����FL23-03.cpp
�쐬���@�@�F2015/11/19
�쐬�ҁ@�@�FBayaSea
*/

#include <string>		//�����񑀍�p
#include <conio.h>
#include <iostream>
using namespace std;

//�A�C�e���\���̂̒�`
struct Item {
	string name;	//�A�C�e����
	int power;		//�\��
};

//�q�[���[�N���X��`
class Hero {
	string name;		//�q�[���[��
	Item item[2];		//�A�C�e���\���̔z��
public:
	//�q�[���[���ݒ�
	void setName(){
		name = "BERG";
	}
	//�A�C�e���ݒ�
	void setItem(){
		item[0].name = "mant";
		item[0].power = 50;
		item[1].name = "sword";
		item[1].power = 200;
	}
	//�q�[���[���A�A�C�e���\��
	void show(){
		cout << name << endl;

		for (int i = 0; i < 2; i++){
			cout <<	item[i].name << " " <<	item[i].power << endl;
		}
	}
};
////////////////////////////////////////////////////////////
int main()
{
	Hero hero;

	hero.setName();	//�q�[���[���ݒ胁�\�b�h�Ăяo��
	hero.setItem();	//�A�C�e���ݒ胁�\�b�h�Ăяo��
	hero.show();	//�q�[���[���A�A�C�e���\�����\�b�h�Ăяo��

	_getch();
	return 0;
}

