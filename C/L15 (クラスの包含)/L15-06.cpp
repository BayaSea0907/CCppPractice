/*
�ۑ�ԍ��@�FL15-6
���e�@�@�@�F��box�I�u�W�F�N�g�ɓn���������l�̋��̔��茋�ʂ�\������B
�@�@�@�@�@�@����́A�����Ȃ�΁h�����h�A����ȊO�̒l�Ȃ�΁g��h�ƕ\������B
�@�@�@�@�@�@�����l���͂�ui�I�u�W�F�N�g�ōs���A�\����box�I�u�W�F�N�g�ōs���B
�t�@�C�����FL15-06.cpp
�쐬���@�@�F2015/07/01
�쐬�ҁ@�@�FBayaSea
*/

#include <conio.h>
#include <iostream>
using namespace std;

//���N���X��`
class Box {
public:
    //���胁�\�b�h
    void judge(int num){

		//�����A��̔���
		if (num % 2){ cout << "�" << endl; }

		else{ cout << "����" << endl; }
	}
};
////////////////////////////////////////////////////////////
//���[�U�C���^�t�F�[�X�N���X��`
class UI {
	Box box;		//���I�u�W�F�N�g�錾
public:
	//�������䃁�\�b�h
	void processCtrl(){
		inpBoxJudg();		//���l���́E����
	}
	//���l���́E���胁�\�b�h
	void inpBoxJudg(){
		int num;		//���͗p

		cout << "�����l����́i��@15�j>> ";
		cin >> num;
		box.judge(num);	//����
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
