/*
�ۑ�ԍ��@�FL14-2
���e�@�@�@�FL14-1�����������āA�q�[���[hero�I�u�W�F�N�g��hp�ɓ��͂�����AHP��\������B
�@�@�@�@�@�@Hero�N���X��HP���͗p���\�b�h��hp��100����͂���B
�@�@�@�@�@�@�������A���͂���HP�́A�����ǃC���X�^���X�ϐ��Ɋi�[�i�I�u�W�F�N�g�Ɋi�[�j������̂Ƃ���B
�t�@�C�����FL14-02.cpp
�쐬���@�@�F2015/06/10
�쐬�ҁ@�@�FBayaSea
*/

//���s���Ɋm�F���邱�ƁF
//��hero�I�u�W�F�N�g�̃��\�b�h��HP����͂��Ă��邱�Ƃ��m�F���Ȃ����B
//A.�m�F���܂����B���̓��\�b�h�̒���cin >> hp������������͂ł��Ȃ��Ȃ�B

#include <conio.h>
#include <iostream>
using namespace std;

//HERO�N���X��`
class Hero {

	int hp;		//HP

public:

	//HP���̓��\�b�h
	void inputHp(){
		cout << "HP�𐮐��l�œ��́i��@100�j>> ";
		cin >> hp;									//�C���X�^���X�ϐ�hp�ɓ���
	}
	//HP�\�����\�b�h
	void showHp(){
		cout << "HP=" << hp << endl; 				//�C���X�^���X�ϐ�hp��\��
	}
};

////////////////////////////////////////////////////////////

int main()
{
	Hero hero;										//�I�u�W�F�N�g�錾
	
	hero.inputHp();									//HP���̓��\�b�h�̌Ăяo��
	hero.showHp();									//HP�\�����\�b�h�̌Ăяo��

	_getch();
	return 0;
}
