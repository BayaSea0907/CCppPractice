/*
�ۑ�ԍ��@�FL15-Special1
���e�@�@�@�F�e�X�gtest�I�u�W�F�N�g�ɓ��_��ݒ肵����A0�`59���h�s���i�h�A60�`74���h�h�A75�`89���h�ǁh�A90�`100���g�D�h�ƕ\������B
�@�@�@�@�@�@���_��0�`100�ɔ͈͌��肵�Ĕ��肵�āA0�������邢��100���̏ꍇ��"0�ȏ�100�ȉ��̒l�ł͂�
�@�@�@�@�@�@���̂ŕ]���ł��܂���"�ƕ\������B
�@�@�@�@�@�@���_���͂�ui�I�u�W�F�N�g�ōs���A����\����test�I�u�W�F�N�g�ōs���B
�t�@�C�����FL15-S1.cpp
�쐬���@�@�F2015/07/22
�쐬�ҁ@�@�FBayaSea
*/
#include <conio.h>
#include <iostream>
using namespace std;
//�e�X�g�N���X��`
class Test{
	int ten;
public:
    //�_���ݒ胁�\�b�h
	void setTen(int sten)
	{
		ten = sten;
	}

    //���_���胁�\�b�h
	void judgeTen()
	{
		if ((ten < 0) || (ten > 100))
		{
			cout << "0�ȏ�100�_�ȉ��̒l�ł͂Ȃ��̂ŕ]���ł��܂���";
		}
		else if (ten < 60)
		{
			cout << "�s���i";
		}
		else if (ten < 75)
		{
			cout << "��";
		}
		else if (ten < 90)
		{
			cout << "��";
		}
		else
		{
			cout << "�D";
		}
	}

};
////////////////////////////////////////////////////////////
//���[�U�C���^�t�F�[�X�N���X��`
class UI {
	Test test;
public:
	//�������䃁�\�b�h
	void processCtrl()
	{
		inpTest();
		test.judgeTen();
	}
	//test���͐ݒ胁�\�b�h
	void inpTest()
	{
		//�����ϐ��B���_
		int ten;

		cout << "���_�����(�� 75) >> ";
		cin >> ten;

		//�e�X�g�I�u�W�F�N�g�̓_���ݒ胁�\�b�h
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
