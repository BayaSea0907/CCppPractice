/*
�ۑ�ԍ��@�FL15-8
���e�@�@�@�F�e�X�g�̌��ʂ𔻒肷��B
�@�@�@�@�@�@�e�X�gtest�I�u�W�F�N�g�ɓ��_��ݒ肵����A�_�����Z�q���g����0�`59���h�s���i�h�A60�`74
�@�@�@�@�@�@���h�h�A75�`89���h�ǁh�A90�ȏ���g�D�h�ƕ\������B
�@�@�@�@�@�@���_���͂�ui�I�u�W�F�N�g�ōs���A����\����test�I�u�W�F�N�g�ōs���B
�t�@�C�����FL15-08.cpp
�쐬���@�@�F2015/07/08
�쐬�ҁ@�@�FBayaSea
*/

#include <conio.h>
#include <iostream>
using namespace std;

//�e�X�g�N���X��`
class Test{
	int ten;	//���_
public:
//�_���ݒ胁�\�b�h
	void setTen(int sten){
		ten = sten;
    }
    //���_���胁�\�b�h
	void judgeTen(){

		//�_���̔���
		if (0 <= ten && ten < 60)
		{
			cout << "�s���i" << endl;
		}
		else if (60 <= ten && ten < 75)
		{
			cout << "��" << endl;
		}
		else if (75 <= ten && ten < 90)
		{
			cout << "��" << endl;
		}
		else if (90 <= ten)
		{
			cout << "�D" << endl;
		}
		else
		{
			cout << "���̒l�̂��ߕ]���ł��܂���" << endl;
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
		inpTest();		//test���͐ݒ�
		test.judgeTen();	//���_����
	}
	//test���͐ݒ胁�\�b�h
	void inpTest(){
		int ten;	//���_���͗p

		cout << "���_����́i��@75�j>> ";
		cin >> ten;
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
