/*
�ۑ�ԍ��@�FL26-8
���e�@�@�@�F�A�C�e���\���̕ϐ��̃A�h���X�������ă����o�ɓ��͂���inpItem�֐����쐬���āA�A�C�e��
�@�@�@�@�@�@�\���̂̃����o��\������B
�@�@�@�@�@�@�\����main�֐��ōs���B
�t�@�C�����FL26-08.cpp
�쐬���@�@�F2016/1/14
�쐬�ҁ@�@�FBayaSea
*/

#include <string>
#include <conio.h>
#include <iostream>
using namespace std;

//�A�C�e���\���̒�`
struct Item {
	string name;	//�A�C�e����
	int power;		//�\��
};

void inpItem(Item* p);		//�֐��̃v���g�^�C�v�錾

/////////////////////////////////////////////////////////////
int main()
{
	Item item;

	inpItem(&item);		//�֐��Ăяo��

	cout << "�A�C�e����= " << item.name << endl;
	cout << "�\��= " <<	item.power << endl;

	_getch();
	return 0;
}
/*
�֐����FinpItem
���e�@�F�A�C�e���\���̂̃����o����
�����@�FItem* p�@�A�C�e���\���̕ϐ��̃A�h���X
�߂�l�F�Ȃ�
*/
void inpItem(Item* p)
{
	cout << "�A�C�e�����Ɣ\�͂����>> ";
	cin >> p->name >> p->power;
}




