/*
�ۑ�ԍ��@�FL15-Special2
���e�@�@�@�F�����l�̊���Z���ʂ𔻒肷��B
�@�@�@�@�@�@����ZDivision�I�u�W�F�N�g�ɐ����l���Q�ݒ肵�āA�傫�����̐������������̐��Ŋ��������ʂ������l�ŕ\������B
�@�@�@�@�@�@�������A�������̏ꍇ�ł��A���������ʂ������l�ŕ\��������̂Ƃ���B
�@�@�@�@�@�@�܂��A�����i���鐔�j�A�܂菬���������O�̏ꍇ�ɂ́A"�O�Ŋ���܂���"�ƕ\������B
�@�@�@�@�@�@�����l���͂�ui�I�u�W�F�N�g�ōs���A����\����Division�I�u�W�F�N�g�ōs���B
�t�@�C�����FL15-S2.cpp
�쐬���@�@�F2015/08/23
�쐬�ҁ@�@�FBayaSea
*/
//�����s���ɓ��͂���l�ɂ��āA���̂T�p�^�[����K���`�F�b�N���邱�ƁB
//>> 100 200
//>> 200 100
//>> 100 100
//>> 100 0
//>> 0 100

#include <conio.h>
#include <iostream>
using namespace std;

//����Z�N���X��`
class Division {
	int dividend;
	int divisor;
public:
    //�폜���E�����ݒ胁�\�b�h
	void setVar(int sdividend, int sdivisor)
	{
		//�ǂ���̐��l���傫������r���A�傫������dividend�ɓ���āA����������divisor�ɓ����
		if (sdividend > sdivisor)
		{
			dividend = sdividend;		//�����鐔
			divisor = sdivisor;			//���鐔
		}
		else
		{
			dividend = sdivisor;		//���鐔
			divisor = sdividend;		//�����鐔
		}
	}

    //����Z���胁�\�b�h
	void judge()
	{
			//������0��������v�Z���Ȃ��B
			if (dividend != 0 || divisor != 0)
			{
				cout << "0�Ŋ���܂���" << endl;
			}
			//�傫����(dividend)���A��������(divisor)�Ŋ���B
			else
			{
				cout << dividend << "��" << divisor << "=" << (double)dividend / (double)divisor << endl;
			}
	}
};
////////////////////////////////////////////////////////////
//���[�U�C���^�t�F�[�X�N���X��`
class UI {
	Division division;
public:
	//�������䃁�\�b�h
	void processCtrl()
	{
		inpDiv();				//���̓��\�b�h
		division.judge();		//����Z���胁�\�b�h
	}

	//division���͐ݒ胁�\�b�h
	void inpDiv()
	{
		//�����ϐ�
		int divident;			//�폜��(�����鐔)
		int divisior;			//����(���鐔)

		cout << "�����l���Q����(�� 100 200) >> ";
		cin >> divident >> divisior;

		//division�I�u�W�F�N�g�̔폜���A�����ݒ胁�\�b�h
		division.setVar(divident, divisior);
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
