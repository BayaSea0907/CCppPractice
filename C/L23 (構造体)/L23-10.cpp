/*
�ۑ�ԍ��@�FL23-10
���e�@�@�@�Fhero�I�u�W�F�N�g�̃q�[���[���ƃA�C�e���\���̔z��i�v�f���Q�j�j�����������āA�q�[���[��
�@�@�@�@�@�@�ƃA�C�e���\���̂̃����o��\������B
�@�@�@�@�@�@�q�[���[���ƃA�C�e���\���̔z��̓R���X�g���N�^�ŏ���������B
�@�@�@�@�@�@�\���̓I�u�W�F�N�g�ōs���B
�t�@�C�����FL23-10.cpp
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
	Item item[2];		//�A�C�e���\���̔z��
public:
	//�R���X�g���N�^�i�q�[���[���A�\���̔z�񏉊����j
	Hero(){
		name = "BERG";
		item[0].name = "mant";
		item[0].power = 50;
		item[1].name = "sword";
		item[1].power = 200;
	}

	//�q�[���[���A�A�C�e���\��
	void show(){
		cout << name << endl;
		for (int i = 0; i < 2; i++){
			cout << item[i].name << " " <<	item[i].power << endl;
		}
	}
};
////////////////////////////////////////////////////////////
int main()
{
	Hero hero;

	hero.show();		//�q�[���[���A�A�C�e���\�����\�b�h�Ăяo��

	_getch();
	return 0;
}

