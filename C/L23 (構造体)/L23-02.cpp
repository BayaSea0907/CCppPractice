/*
�ۑ�ԍ��@�FL23-2
���e�@�@�@�FL23-1�����������āAhero�I�u�W�F�N�g�ɓ��͂����q�[���[���ƃA�C�e���\���́i�A�C�e����
�@�@�@�@�@�@�Ɣ\�́j���i�[���āA�q�[���[���ƃA�C�e���\���̂̃����o��\������B
�@�@�@�@�@�@���͂̓I�u�W�F�N�g�ōs���A�\����main�֐��ōs���B
�t�@�C�����FL23-02.cpp
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
	string name;	//�q�[���[��
	Item item;		//�A�C�e���\���̕ϐ�
public:
	//�q�[���[���A�A�C�e������
	void inpProperty(){
		cout << "�q�[���[�������>> ";
		cin >> name;

		cout << "�A�C�e�����Ɣ\�͂����(�� sword 10) >> ";
		cin >> item.name >> item.power;
	}

	//�q�[���[���擾
	string getName(){
		return name;
	}

	//�A�C�e���擾
	Item getItem(){
		return item;
	}
};
////////////////////////////////////////////////////////////
int main()
{
	Hero hero;
	string name;		//�q�[���[���擾�p
	Item item;			//�A�C�e���\���̎擾�p

	hero.inpProperty();			//�q�[���[���A�A�C�e�����̓��\�b�h�Ăяo��
	name = hero.getName();		//�q�[���[���擾���\�b�h�Ăяo��
	item = hero.getItem();		//�A�C�e���擾���\�b�h�Ăяo��

	cout <<	name << " " <<	item.name << " " <<	item.power << endl;

	_getch();
	return 0;
}


