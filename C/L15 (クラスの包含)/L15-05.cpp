/*
�ۑ�ԍ��@�FL15-5
���e�@�@�@�F�e�X�gtest�I�u�W�F�N�g�ɓ��_��ݒ肵����A�I�u�W�F�N�g�̓��_������i�ȏォ�ǂ�����
�@�@�@�@�@�@���茋�ʂ�\������B
�@�@�@�@�@�@����́A����������i�_�ȏ�Ȃ�΁h���i�h�A����ȊO�̒l�Ȃ�΁g�s���i�h�ƕ\������B
�@�@�@�@�@�@���_�Ɗ���i�_���͂�ui�I�u�W�F�N�g�ōs���A����\����test�I�u�W�F�N�g�ōs���B
�t�@�C�����FL15-05.cpp
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
    //���_���胁�\�b�h  border�F����i�_����p
    void judgeTen(int sborder){
		int border = sborder;

		//�_����border�ȏォ�ǂ����𔻕�
		if (ten >= border){ cout << "���i" << endl; }
		
		//�{�[�_�[�ȉ��̏ꍇ�s���i
		else{ cout << "�s���i" << endl; }
	}
};
////////////////////////////////////////////////////////////
//���[�U�C���^�t�F�[�X�N���X��`
class UI {
	Test test;		//�e�X�g�I�u�W�F�N�g�錾
public:
	//�������䃁�\�b�h
	void processCtrl(){
		inpScore();		//���_���͐ݒ�
		inpBdrJudg();	//��_���́E����
	}
	//���_���͐ݒ胁�\�b�h
	void inpScore(){
		int score;		//���_���͗p

		cout << "���_����́i��@100�j>> ";
		cin >> score;
		test.setTen(score);		//���_�ݒ�
	}
	//��_���́E���胁�\�b�h
	void inpBdrJudg(){
		int border;		//����i�_���͗p

		cout << "����i�_����́i��@60�j>> ";
		cin >> border;

		//���_���胁�\�b�h�Ăяo��
		test.judgeTen(border);

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
