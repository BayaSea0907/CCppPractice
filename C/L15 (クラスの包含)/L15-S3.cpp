/*
�ۑ�ԍ��@�FL15-Special3
���e�@�@�@�F�e�X�gtest�I�u�W�F�N�g�ɓ��_��ݒ肵����A0�`59���h�s���i�h�A60�`74���h�h�A75�`89���h�ǁh�A
�@�@�@�@�@�@90�ȏ���g�D�h�ƕ\������B
�@�@�@�@�@�@�_�����Z�q���g�킸�ɔ��肵�āA0�����̏ꍇ��"���̒l�̂��ߕ]���ł��܂���"�ƕ\������B
�@�@�@�@�@�@���_���͂�ui�I�u�W�F�N�g�ōs���A����\����test�I�u�W�F�N�g�ōs�����̂Ƃ���B
�@�@�@�@�@�@�傫���l���画�ʂ���
�t�@�C�����FL15-S3.cpp
�쐬���@�@�F2015/08/23
�쐬�ҁ@�@�FBayaSea
*/

#include <conio.h>
#include <iostream>
using namespace std;

//�e�X�g�N���X��`
class Test{
	int ten;					//�v���p�e�B
public:
    //�_���ݒ胁�\�b�h
	void setTen(int sten)
	{
		sten = ten;				//�v���p�e�B�Ɉ���sten����
	}

    //���_���胁�\�b�h
	void judgeTen()
	{
		//90�_�ȏ�Ȃ�D
		if (ten >= 90)
		{
			cout << "�D" << endl;
		}
		//89~75�_�̊Ԃ��������
		else if (ten >= 75)
		{
			cout << "��" << endl;
		}
		//74~60�_�̊Ԃ��������
		else if (ten >= 60)
		{
			cout << "��" << endl;
		}
		//59~0�_�̊Ԃ�������s���i
		else if (ten >= 0)
		{
			cout << "�s���i" << endl;
		}
		//0�_�����̒l�͕]�����Ȃ�
		else
		{
			cout << "���̒l�̂��ߕ]���ł��܂���" << endl;
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
		inpTest();				//���͐ݒ胁�\�b�h�Ăяo��
		test.judgeTen();		//���T���胁�\�b�h�Ăяo��
	}

	//test���͐ݒ胁�\�b�h
	void inpTest()
	{
		int ten;				//�����ϐ�

		//�_���̓���
		cout << "���_�����(�� 75) >> ";
		cin >> ten;

		test.setTen(ten);		//�_���ݒ胁�\�b�h�Ăяo��
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
