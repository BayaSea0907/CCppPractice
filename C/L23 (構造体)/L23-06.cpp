/*
�ۑ�ԍ��@�FL23-6
���e�@�@�@�Fhero�I�u�W�F�N�g�ɓ��͂����q�[���[���ƃA�C�e���\���̔z��i�v�f���Q�j���i�[���āA�q�[��
�@�@�@�@�@�@�[���ƃA�C�e���\���̂̃����o��\������B
�@�@�@�@�@�@�A�C�e���\���̂̃����o�́A�A�C�e�����Ɣ\�́B
�@�@�@�@�@�@���͂�main�֐��ōs���A�\���̓I�u�W�F�N�g�ōs���B
�t�@�C�����FL23-06.cpp
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
	Item item[2];			//�A�C�e���\���̔z��
public:
	//�q�[���[���ݒ�@str�F�q�[���[��
	void setName(string str){
		name = str;
	}

	//�A�C�e���ݒ�@itm[]�F�A�C�e���\���̔z��
	void setItem(Item itm[]){

		for (int i = 0; i < 2; i++){
			item[i] = itm[i];
		}
	}

	//�q�[���[���A�A�C�e���\��
	void show(){
		cout << name << endl;

		for (int i = 0; i < 2; i++){
			cout << item[i].name << " " << item[i].power << endl;
		}
	}
};
////////////////////////////////////////////////////////////
int main()
{
	Hero hero;
	string name; 		//�q�[���[���i�[�p
	Item item[2];		//�A�C�e���\���̔z��

	cout << "�q�[���[�������>> ";
	cin >> name;

	for (int i = 0; i < 2; i++){
		cout << "�A�C�e�����Ɣ\�͂����>> ";
		cin >> item[i].name >> item[i].power;
	}

	hero.setName(name);		//�q�[���[���ݒ胁�\�b�h�Ăяo��
	hero.setItem(item);		//�A�C�e���ݒ胁�\�b�h�Ăяo��
	hero.show();			//�q�[���[���A�A�C�e���\�����\�b�h�Ăяo��

	_getch();
	return 0;
}

