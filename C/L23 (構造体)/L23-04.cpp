/*
�ۑ�ԍ��@�FL23-4
���e�@�@�@�FL23-3�����������āAhero�I�u�W�F�N�g�ɓ��͂����q�[���[���ƃA�C�e���\���̔z��i�v�f��
�@�@�@�@�@�@�Q�j���i�[���āA�q�[���[���ƃA�C�e���\���̂̃����o��\������B
�@�@�@�@�@�@�A�C�e���\���̂̃����o�́A�A�C�e�����Ɣ\�́B
�@�@�@�@�@�@�q�[���[���ƃA�C�e���\���̔z��ւ̓��͂́A�قȂ郁�\�b�h�ōs���B
�@�@�@�@�@�@�A�C�e���\���̔z��ւ̓��͂ɂ́A�J�Ԃ�������g���B
�@�@�@�@�@�@���͂ƕ\���̓I�u�W�F�N�g�ōs���B
�t�@�C�����FL23-04.cpp
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
	//�q�[���[������
	void inpName(){
		cout << "�q�[���[�������>> ";
		cin >> name;
	}
	//�A�C�e������
	void inpItem(){
		for (int i = 0; i < 2; i++){
			cout << "�A�C�e�����Ɣ\�͂����(�� sword 10) >> ";
			cin >> item[i].name >> item[i].power;
		}
		cout << endl;
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

	hero.inpName();	//�q�[���[�����̓��\�b�h�Ăяo��
	hero.inpItem();	//�A�C�e�����̓��\�b�h�Ăяo��
	hero.show();	//�q�[���[���A�A�C�e���\�����\�b�h�Ăяo��

	_getch();
	return 0;
}
