/*
�ۑ�ԍ��@�FL15-7
���e�@�@�@�F�o�X�P�b�g�̒��݂̂���Ƃ�񂲂̌��𔻒肷��B
�@�@�@�@�@�@�o�X�P�b�gbasket�I�u�W�F�N�g�ɂ݂���Ƃ�񂲂̌���ݒ肵����A���̑����𔻒肵�����ʂ�\������B
�@�@�@�@�@�@����́A�����������̉ʕ����A�����Ȃ�΁g�����h�ƕ\������B
�@�@�@�@�@�@���ꂼ��̉ʕ��̌����͂�ui�I�u�W�F�N�g�ōs���A����\����basket�I�u�W�F�N�g�ōs���B
�t�@�C�����FL15-07.cpp
�쐬���@�@�F2015/07/01
�쐬�ҁ@�@�FBayaSea
*/
#include <conio.h>
#include <iostream>
using namespace std;

//�o�X�P�b�g�N���X��`
class Basket {
	int orange;	//�݂����
	int apple;	//��񂲌�
public:
    //�݂���E��񂲌��ݒ胁�\�b�h
	void setVar(int sorange, int sapple){
		orange = sorange;
		apple = sapple;
    }
    //���召���胁�\�b�h
    void judgeVar(){

		//�召����
		if (apple > orange){ cout << "��񂲂̕�������" << endl; }
		else if (apple < orange){ cout << "�݂���̕�������" << endl; }
		else{ cout << "����" << endl; }
	}
};
////////////////////////////////////////////////////////////
//���[�U�C���^�t�F�[�X�N���X��`
class UI {
	Basket basket;		//�o�X�P�b�g�I�u�W�F�N�g�錾
public:
	//�������䃁�\�b�h
	void processCtrl(){
		inpBasket();		//basket���͐ݒ�
		basket.judgeVar();	//������
	}
	//basket���͐ݒ胁�\�b�h
	void inpBasket(){
		int orange;		//�݂�������͗p
		int apple;		//��񂲌����͗p

		cout << "�݂���Ƃ�񂲂̌�����́i��@100 200�j>> ";
		cin >> orange >> apple;
		basket.setVar(orange, apple);
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
