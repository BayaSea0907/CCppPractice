/*
�ۑ�ԍ��@�FL15-4
���e�@�@�@�F�e�X�g�̓��_�𔻒肷��B
�@�@�@�@�@�@�e�X�gtest�I�u�W�F�N�g�ɓ��_��ݒ肵����A���_��70�_�ȏォ�ǂ����̔��茋�ʂ�\������B
�@�@�@�@�@�@����́A70�ȏ�̒l����͂���Ɓh���i�h�A����ȊO�̒l�Ȃ�΁g�s���i�h�ƕ\������B
�@�@�@�@�@�@�������A���_���͂�ui�I�u�W�F�N�g�ōs���A����\����test�I�u�W�F�N�g�ōs���B
�t�@�C�����FL15-04.cpp
�쐬���@�@�F2015/07/01
�쐬�ҁ@�@�FBayaSea
*/
#include <conio.h>
#include <iostream>
using namespace std;
//�e�X�g�N���X��`
class Test {
	int ten;	//���_
public:
    //���_�ݒ胁�\�b�h
	void setTen(int sten){
	    ten = sten;
    }
    //���_���胁�\�b�h
	void judgeTen(){

		//�_����70�ȏォ�ǂ����𔻕�
		if (ten >= 70){ cout << "���i" << endl; }

		//����ȊO�̐��l�̏ꍇ�s���i��\��
		else{ cout << "�s���i" << endl; }

	}
};
////////////////////////////////////////////////////////////
//���[�U�C���^�t�F�[�X�N���X��`
class UI {
	Test test;	//�e�X�g�I�u�W�F�N�g�錾
public:
	//�������䃁�\�b�h
	void processCtrl(){
		inpTest();		//test���͐ݒ�
		test.judgeTen();	//���_����
	}
	//test���͐ݒ胁�\�b�h
	void inpTest(){
		int ten;	//���_���͗p

		cout << "���_����́i��@100�j>> ";
		cin >> ten;
		test.setTen(ten);	//�ݒ胁�\�b�h�Ăяo��
	}
};
////////////////////////////////////////////////////////////////
int main()
{
	UI ui;			//���[�U�C���^�t�F�[�X�I�u�W�F�N�g�錾

	ui.processCtrl();	//�C���^�t�F�[�X��������

	_getch();
	return 0;
}
