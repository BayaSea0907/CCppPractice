/*
�ۑ�ԍ��@�FL15-12
���e�@�@�@�F�����vlamp�I�u�W�F�N�g�ɐF�P������n������A���̐F�P�����ɑΉ�����F�𔻒肵�����ʂ�
�@�@�@�@�@�@switch�����g���ĕ\������B
�@�@�@�@�@�@����́A�������eR�f�Ȃ�gRed�h�A�eG�f�Ȃ�gGreen�h�A�eB�f�Ȃ�gBlue�h�A�e$�f��e#�f�Ȃ�g�␳�F�h�A
�@�@�@�@�@�@�����ȊO�̕����̏ꍇ�ɂ́g���̑��̐F�h�ƕ\������B
�@�@�@�@�@�@switch���łP�������i�[�����ϐ��𑽕��򂷂�ɂ́A�P�������i�[����ϐ��̌^��char�^�ɂ���B
�@�@�@�@�@�@�F�P�������͂�ui�I�u�W�F�N�g�ōs���A����\����lamp�I�u�W�F�N�g�ōs���B
�t�@�C�����FL15-A12.cpp
�쐬���@�@�F2015/07/08
�쐬�ҁ@�@�FBayaSea
*/

#include <conio.h>
#include <iostream>
using namespace std;

//�����v�N���X��`
class Lamp {
public:
    //���x���胁�\�b�h
	void Judg(char scoller)
	{
		//�����ϐ�
		char coller = scoller;

		//�F�̔���
		switch (coller)
		{
		case 'R':	cout << "Red";
			break;
		case 'G': cout << "Green";
			break;
		case 'B': cout << "Blue";
			break;
		case '$':
		case '#': cout << "�␳�F";
			break;
		default: cout << "���̑��̐F";
			break;
		}
	}


};
////////////////////////////////////////////////////////////
//���[�U�C���^�t�F�[�X�N���X��`
class UI {
	Lamp lamp;	//�����v�I�u�W�F�N�g�錾
public:
	//�������䃁�\�b�h
	void processCtrl(){
		inpLampJudg();		//lamp���́E����
	}
	//lamp���͐ݒ胁�\�b�h
	void inpLampJudg()
	{
		char coller;

		cout << "�F�����(��: R) >> ";
		cin >> coller;
		//lamp�I�u�W�F�N�g��Judg���\�b�h�Ăяo��
		lamp.Judg(coller);
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
