/*
�ۑ�ԍ��@�FL15-1
���e�@�@�@�F�e�X�gtest�I�u�W�F�N�g�ɓ��_��ݒ肵����A���_��100�_���ǂ����̔��茋�ʂ�\������B
�@�@�@�@�@�@����́A���_��100�_�Ȃ�΁h�n�j�h�ƕ\�����A100�_�ȊO�Ȃ�Ή����\�����Ȃ��B
�@�@�@�@�@�@�������A���_�̓��͂�ui�I�u�W�F�N�g�ōs���A���茋�ʕ\����test�I�u�W�F�N�g�ōs���B
�t�@�C�����FL15-01.cpp
�쐬���@�@�F2015/07/01
�쐬�ҁ@�@�FBayaSea
*/
//���s���Ɋm�F���邱�ƁF
//��100�_����͂����Ƃ��A�h�n�j�h�ƕ\������邱�Ƃ��m�F���Ȃ����B
//A.���܂����B

//��99�_�A101�_����͂����Ƃ��A�����\������Ȃ����Ƃ��m�F���Ȃ����B
//A.���܂����B

//�����_�̓��͂��Atest�I�u�W�F�N�g�̃��\�b�h�ł͂Ȃ��A�t�h�p�I�u�W�F�N�g�ōs���Ă��邱�Ƃ��m�F���Ȃ����B
//A.���܂����B

//��test�I�u�W�F�N�g���A�t�h�p�I�u�W�F�N�g����n���ꂽ���_�������Ă��邱�Ƃ��m�F���Ȃ����B
//A.���܂����B

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

		//���_��100�Ɠ��������ǂ����𔻕�
		if(ten == 100){

			//������������ok��\��
            cout << "�n�j" << endl;
        }
	}
};
////////////////////////////////////////////////////////////
//���[�U�C���^�t�F�[�X�N���X��`
class UI {
	Test test;	//�e�X�g�I�u�W�F�N�g�錾
public:
	//�������䃁�\�b�h
	void processCtrl(){
		inpTest();		    //test���͐ݒ�
		test.judgeTen();	//���_���胁�\�b�h�Ăяo��
	}
	//test���͐ݒ胁�\�b�h
	void inpTest(){
		int ten;	    //���_���͗p

		cout << "���_����́i��@100�j>> ";
		cin >> ten;

		//���_�ݒ胁�\�b�h�Ăяo��
		test.setTen(ten);

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
