/*
�ۑ�ԍ��@�FL15-9
���e�@�@�@�F�lman�I�u�W�F�N�g�ɐ��ʎ��ʐ��l��ݒ肵����A���̐��l��ǂݎ���Đ��ʂ𔻒�\������B
�@�@�@�@�@�@����́Aswitch�����g���Đ��ʎ��ʂ�0�Ȃ�g�j�h�A1�Ȃ�g���h�A����ȊO�Ȃ�g�s���h�ƕ\������B
�@�@�@�@�@�@���ʎ��ʐ��l���͂�ui�I�u�W�F�N�g�ōs���A����\����man�I�u�W�F�N�g�ōs���B
�t�@�C�����FL15-09.cpp
�쐬���@�@�F2015/07/08
�쐬�ҁ@�@�FBayaSea
*/

//�v���O���������������Ċm�F���邱�ƁF
//��case 0��break�����폜�i�R�����g���ɂ���j������ǂ��Ȃ�ł��傤���H
//A.�j�Ə��̗������\�����ꂽ�B

//�����ʎ��ʂ��i�[����ϐ��̌^���A�����^�ɏ�����������ǂ��Ȃ�ł��傤���H
//switch�Ɏ������g���ƃG���[���N����

#include <conio.h>
#include <iostream>
using namespace std;

//�l�N���X��`
class Man {
	int sex;	//���ʎ���
public:
    //���ʎ��ʐݒ胁�\�b�h
	void setSex(int ssex){
		sex = ssex;
    }
    //�����胁�\�b�h
    void judgeSex(){

		//���ʂ̔���
		switch (sex)
		{
			case 0:	cout << "�j" << endl;
				break;

			case 1:	cout << "��" << endl;
				break;

			default: cout << "�s��" << endl;
				break;
		}
	}
};
////////////////////////////////////////////////////////////
//���[�U�C���^�t�F�[�X�N���X��`
class UI {
	Man man;	//�l�I�u�W�F�N�g�錾
public:
	//�������䃁�\�b�h
	void processCtrl(){
		inpMan();		    //man���͐ݒ�
		man.judgeSex();	    //������
	}
	//man���͐ݒ胁�\�b�h
	void inpMan(){
		int sex;	//���ʎ��ʓ��͗p

		cout << "���ʂ���́i�j��0�A����1�j>> ";
		cin >> sex;
		man.setSex(sex);
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
