/*
�ۑ�ԍ��@�FL14-1
���e�@�@�@�F�q�[���[hero�I�u�W�F�N�g��HP��ݒ肵����AHP��\������B
�@�@�@�@�@�@HP��hero�I�u�W�F�N�g�̃��\�b�h�ő�����AHP�\���p���\�b�h�ŕ\��������̂Ƃ���B
�t�@�C�����FL14-01.cpp
�쐬���@�@�F2015/06/10
�쐬�ҁ@�@�FBayaSea
*/

//���s���Ɋm�F���邱�ƁF
//��hero�I�u�W�F�N�g�̑厖�ȏ��ł���HP���A�C���X�^���X�ϐ�hp�Ɋi�[����Ă��邱�Ƃ��m�F���Ȃ�
//�@���B
//A.�m�F���܂����Bhp�ɑ�����Ă��鐔�l��ς��܂����B

//��hero�I�u�W�F�N�g���U�������e�iHP�̑���A�\���j�́A���\�b�h�ɒ�`����Ă��邱�Ƃ��m�F���Ȃ����B
//A.�m�F���܂����BHero�N���X��showHp���\�b�h�ȊO�̕��@�ŕ\�����邱�Ƃ͏o���Ȃ��B

//��hero�I�u�W�F�N�g��U���킹��ɂ́A���\�b�h���Ăяo���Ȃ���΂Ȃ�Ȃ����Ƃ��m�F���Ȃ����B
//A.�m�F���܂����Bhero���Ă񂾂Ƃ���ŉ�������̂��킩��Ȃ��B

//�v���O���������������Ċm�F���邱�ƁF
//�����\�b�h�Ăяo�����A�I�u�W�F�N�g���D�����Ȃ��ŏ�������ǂ��Ȃ�ł��傤���H
//	setHp();
//	show();
//A.�m�F���܂����B�I�u�W�F�N�g��ʂ����ɕʂ̃N���X�Ɏ���o���Ă͂����Ȃ��B

//��setHp���\�b�h���Ăяo������ɁA���̂悤�ȂQ�ʂ�ŏ�������ǂ��Ȃ�ł��傤���H
//	hp = 100;
//	hero.hp = 100;
//A.hp = 100�E�E�E�ϐ�hp��main�֐��̒��ɂ͂Ȃ��̂ŃG���[�ɂȂ�B
//A.hero.hp = 100�E�E�E�I�u�W�F�N�g���Ăяo�Ă��A���\�b�h��ʂ����ɃI�u�W�F�N�g�̏��Ɏ���o���Ă͂����Ȃ��B

#include <conio.h>
#include <iostream>
using namespace std;

//HERO�N���X��`
class Hero {

	int hp;		//HP�i�C���X�^���X�ϐ��j

public:

	//HP�i�[���\�b�h
	void setHp(){
			hp = 100;		//�C���X�^���X�ϐ�hp��100����
	}
	//HP�\�����\�b�h
	void showHp(){
		cout << "HP=" << hp << endl;	//�C���X�^���X�ϐ�hp�̕\��
	}
};

////////////////////////////////////////////////////////////


int main()
{
	Hero hero;		//�q�[���[�I�u�W�F�N�g�錾

	hero.setHp();		//HP�i�[���\�b�h�̌Ăяo��
	hero.showHp();		//HP�\�����\�b�h�̌Ăяo��

	_getch();
	return 0;
}
