/*
�ۑ�ԍ��@�FL15-3
���e�@�@�@�F�N��𔻒肷��B
�@�@�@�@�@�@�lman�I�u�W�F�N�g�ɔN���ݒ肵����A�N�20�Έȏォ�ǂ����𔻒肵�����ʂ�\������B
�@�@�@�@�@�@����́A�N�20�Έȏ�Ȃ�΁h���l�h�ƕ\�����A20�Ζ����Ȃ�Ή����\�����Ȃ��B
�@�@�@�@�@�@�N����͂�ui�I�u�W�F�N�g�ōs���A���茋�ʕ\����man�I�u�W�F�N�g�ōs���B
�t�@�C�����FL15-03.cpp
�쐬���@�@�F2015/07/01
�쐬�ҁ@�@�FBayaSea
*/

#include <conio.h>
#include <iostream>
using namespace std;

//�l�N���X��`
class Man {
	int age;	//�N��
public:
    //�N��ݒ胁�\�b�h  sage�F�N�����p
	void setAge(int sage){
		age = sage;
    }
    //�N��胁�\�b�h
	void judgeAge(){

		//20�Έȏォ�ǂ����𔻕�
		if (age >= 20)
		{
			cout << "���l" << endl;
		}

	}
};
////////////////////////////////////////////////////////////
//���[�U�C���^�t�F�[�X�N���X��`
class UI {
	Man man;		//�l�I�u�W�F�N�g�錾
public:
	//�������䃁�\�b�h
	void processCtrl(){
		inpMan();		//man���͐ݒ�
		man.judgeAge();	//�N���
	}
	//man���͐ݒ胁�\�b�h
	void inpMan(){
		int old;		//�N����͗p

		cout << "�N������>> ";
		cin >> old;
		man.setAge(old);	//�N��ݒ胁�\�b�h�Ăяo��
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
