/*
�ۑ�ԍ��@�FL15-2
���e�@�@�@�F�e�X�g�̓��_�𔻒肷��B
�@�@�@�@�@�@L15-1�����������āAtest�I�u�W�F�N�g�ɓ��_���i�[������A���_��80�_�ȏォ�ǂ����̔��茋�ʂ�\������B
�@�@�@�@�@�@����́A���_��80�_�ȏ�Ȃ�΁h�n�j�h�ƕ\�����A80�_�����Ȃ�Ή����\�����Ȃ��B
�@�@�@�@�@�@���_���͂�ui�I�u�W�F�N�g�ōs���A���茋�ʕ\����test�I�u�W�F�N�g�ōs���B
�t�@�C�����FL15-02.cpp
�쐬���@�@�F2015/07/01
�쐬�ҁ@�@�FBayaSea
*/
//���s���Ɋm�F���邱�ƁF
//��80�_�A100�_����͂����Ƃ��A�h�n�j�h�ƕ\������邱�Ƃ��m�F���Ȃ����B
//A.���܂����B
//��79�_�A-10�_����͂����Ƃ��A�����\������Ȃ����Ƃ��m�F���Ȃ����B
//A.���܂����B

#include <conio.h>
#include <iostream>
using namespace std;

//�e�X�g�N���X��`
class Test {
	int ten;	//���_
public:
    //���_�ݒ胁�\�b�h  sten�F���_����p
	void setTen(int sten){
        ten = sten;
    }
    //���_���胁�\�b�h
	void judgeTen(){

		//���_��80�_�ȏォ�ǂ����𔻕�
		if(ten >= 80){
            cout << "�n�j" << endl;
        }
	}
};
////////////////////////////////////////////////////////////
//���[�U�C���^�t�F�[�X�N���X��`
class UI {
	Test test;		//�e�X�g�I�u�W�F�N�g�錾
public:
	//�������䃁�\�b�h
	void processCtrl(){
		inpTest();		    //test���͐ݒ�
		test.judgeTen();	//���_����
	}
	//test���͐ݒ胁�\�b�h
	void inpTest(){
		int score; 		    //���_���͗p

		cout << "���_�����>> ";
		cin >> score;

		//���_�ݒ胁�\�b�h�Ăяo��
		test.setTen(score);

	}
};
////////////////////////////////////////////////////////////////
int main()
{
	UI ui;			//���[�U�C���^�t�F�[�X�I�u�W�F�N�g�錾

	ui. processCtrl();	//�C���^�t�F�[�X��������

	_getch();
	return 0;
}
