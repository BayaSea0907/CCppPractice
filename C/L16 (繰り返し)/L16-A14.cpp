/*
�ۑ�ԍ��@�FL16-14
���e�@�@�@�F���͂��������l�����ׂĊ|�����킹���l��\������B
�@�@�@�@�@�@���͂�ui�I�u�W�F�N�g�ōs���A�v�Zcalc�I�u�W�F�N�g�ɓ��͒l��n���Ċ|�����킹��B
�@�@�@�@�@�@�������A���͂�while�����g����0�����͂����܂ōs���A0�łȂ��ꍇ�̂�ui�I�u�W�F�N�g����
�@�@�@�@�@�@calc�I�u�W�F�N�g�֓��͒l��n�����̂Ƃ���B
�@�@�@�@�@�@�����āA0�����͂��ꂽ�Ƃ��A����܂łɊ|�����킹���l��\������B
�t�@�C�����FL16-A14.cpp
�쐬���@�@�F2015/10/01
�쐬�ҁ@�@�FBayaSea
*/

//�m�F���邱�ƁF
//��L16-2�ƈقȂ�A���͂�ui�I�u�W�F�N�g�A�|���Z��calc�I�u�W�F�N�g�ōs���Ă���̂ŁAcalc�I�u�W�F
//�@�N�g���A�v�Z�@�\�����ɓ������Ă��邱�Ƃ��m�F���Ȃ����B

#include <conio.h>
#include <iostream>
using namespace std;

//�v�Z�N���X��`
class Calc {
	int mul = 1;        //��Z���ʗp(1)
public:
	//��Z���\�b�h�iint num�F���͒l�j
	void multiply(int num)
	{
		mul *= num; //�|���Z
	}

	//��Z���ʎ擾���\�b�h
	int getMul()
	{
		return mul;
	}
};
////////////////////////////////////////////////////////////
//���[�U�C���^�t�F�[�X�N���X��`
class UI {
	Calc calc;		//�v�Z�I�u�W�F�N�g�錾
public:
	//�������䃁�\�b�h
	void processCtrl()
	{
		inpNum();      //����
		show();		//�\��
	}

	//���̓��\�b�h
	void inpNum()
	{
		int num;            //���͗p
		int sw = 1;        //�J�Ԑ���p�i�P�F�J�Ԃ��j

		//���͒l�����Z����
		while(sw != 0)
		{
			cout << "�����l����́i�I���F0�j>> ";
			cin >> num;

			//���͒l����
			if(num == 0)
			{
				sw = 0; 		//�J�Ԃ�����߂�
			}
			else
			{
				calc.multiply(num);	//��Z���\�b�h�Ăяo��
			}
		}
	}

	//�\�����\�b�h
	void show()
	{
		cout << "��Z����=" << calc.getMul() << endl;
	}
};
////////////////////////////////////////////////////////////////
int main()
{
	UI ui;				//���[�U�C���^�t�F�[�X�I�u�W�F�N�g�錾

	ui.processCtrl();	//�C���^�t�F�[�X��������

	_getch();
	return 0;
}

