/*
�ۑ�ԍ��@�FL24-2
���e�@�@�@�FL24-1�����������āAhero�I�u�W�F�N�g�Ƀq�[���[��"BERG"���P�������Afor�����g����
�@�@�@�@�@�@char�^�����z��i�v�f���S�j�ɓ��͂��āA�q�[���[����\������B
�@�@�@�@�@�@for�����g���ĂP�������\�����āA�Ō�ɕK�����s����B
�@�@�@�@�@�@�J�Ԃ�����́A�������ōs���B
�@�@�@�@�@�@���͂ƕ\���́A�I�u�W�F�N�g�ōs���B
�t�@�C�����FL24-02.cpp
�쐬���@�@�F2015/12/10
�쐬�ҁ@�@�FBayaSea
*/

#include <conio.h>
#include <iostream>
using namespace std;

//�q�[���[�N���X��`
class Hero {
	char name[10];		//�q�[���[���i�[�p�����z��
public:
	//�q�[���[�����́@1����������
	void inpName(){
		for (int i = 0; i < 4; i++)
		{
			cout << "�q�[���[���̂P���������>> ";
			cin >> name[i];
		}
	}
	//�q�[���[���\���@�P�������\��
	void show(){
		for (int i = 0; i < 4; i++){
			cout << name[i] ;
		}
		cout << endl;
	}
};
////////////////////////////////////////////////////////////
int main()
{
	Hero hero;

	hero.inpName();		//�q�[���[�����̓��\�b�h�Ăяo��
	hero.show();		//�q�[���[���\�����\�b�h�Ăяo��

	_getch();
	return 0;
}


