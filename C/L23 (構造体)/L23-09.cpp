/*
�ۑ�ԍ��@�FL23-9
���e�@�@�@�Fhero�I�u�W�F�N�g�̃q�[���[���ƃA�C�e���\���́i�A�C�e�����Ɣ\�́j�����������āA�q�[���[
�@�@�@�@�@�@���ƃA�C�e���\���̂̃����o��\������B
�@�@�@�@�@�@�q�[���[���̓N���X��`�ŁA�A�C�e���\���͍̂\���̒�`�ŏ���������B
�@�@�@�@�@�@�\���̓I�u�W�F�N�g�ōs���B
�t�@�C�����FL23-09.cpp
�쐬���@�@�F2015/11/19
�쐬�ҁ@�@�FBayaSea
*/

//�v���O�������������Ċm�F���邱�ƁF
//���A�C�e���\���̂̏��������A�\���̒�`�ōs�킸�A�N���X��`�̃A�C�e���\���̐錾���ōs���Ƃǂ��Ȃ�
//�@�ł��傤���H
//A.���s�ł��Ȃ��B�v���p�e�B�̍\���̕ϐ��́A�錾�Ɠ����ɏ��������o���Ȃ�

#include <string>		//�����񑀍�p
#include <conio.h>
#include <iostream>
using namespace std;

//�A�C�e���\���̂̒�`
struct Item {
	string name = "mant";	//�A�C�e����
	int power = 50;			//�\��
};

//�q�[���[�N���X��`
class Hero {
	string name = "BERG";	//�q�[���[��
	Item item;				//�A�C�e���\����
public:
	//�q�[���[���A�A�C�e���\��
	void show(){
		cout << name << endl << item.name << " " << item.power << endl;
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

