/*
�ۑ�ԍ��@�FL15-11
���e�@�@�@�F��box�I�u�W�F�N�g�ɐ����l��n���Ƌ��̔��茋�ʂ�\������B
�@�@�@�@�@�@����́Aswitch�����g���ċ��𔻒肵�āA0�Ƌ����Ȃ�΁h�����h�A����ȊO�̒l�Ȃ�΁g��h�ƕ\������B
�@�@�@�@�@�@�����l���͂�ui�I�u�W�F�N�g�ōs���A����\����box�I�u�W�F�N�g�ōs���B
�t�@�C�����FL15-A11.cpp
�쐬���@�@�F2015/07/08
�쐬�ҁ@�@�FBayaSea
*/

#include <conio.h>
#include <iostream>
using namespace std;

//���N���X��`
class Box {
public:
    //�����胁�\�b�h
	void Judg(int shantei)
	{
		int hantei = shantei % 2;
		switch (hantei)
		{
			case 0:	cout << "����" << endl;
				break;
			case 1: cout << "�" << endl;
				break;
			default: break;
		}
	}

};
////////////////////////////////////////////////////////////
//���[�U�C���^�t�F�[�X�N���X��`
class UI {
	Box box;		//���I�u�W�F�N�g�錾
public:
	//�������䃁�\�b�h
	void processCtrl(){
		inpManJudg();		//man���́E����
	}
	//man���͐ݒ胁�\�b�h
	void inpManJudg()
	{
		int hantei;
		cout << "������������肵�܂��B���l����� >> " ;
		cin >> hantei;
		box.Judg(hantei);
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
