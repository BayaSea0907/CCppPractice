/*
�ۑ�ԍ��@�FL14-ExtraSpecial2
���e�@�@�@�F�`�ǁA�a�ǂ��ꂼ��݂̂��g���ă^���N�𖞔t�ɂł��鎞�Ԃ���͂��āA���ǂ𓯎��Ɏg���Ė�
�@�@�@�@�@�@�t�ɂł��鎞�Ԃ�\������B
�@�@�@�@�@�@�`�ǂƂa�ǂ����ꂼ��I�u�W�F�N�g�ɂ��āA���̊ǂ݂̂Ŗ��t�ɂł��鎞�Ԃ�ݒ肷��B
�@�@�@�@�@�@�����āAtank�I�u�W�F�N�g�ɁA�`�ǂƂa�ǂ̃I�u�W�F�N�g��ݒ肵�āA���ǂ𓯎��Ɏg���Ė��t
�@�@�@�@�@�@�ɂł��鎞�Ԃ�\������B
�@�@�@�@�@�@�`�ǂƂa�ǂ��ꂼ��Ŗ��t�ɂł��鎞�Ԃ̓��́A���ǂ𓯎��Ɏg���Ė��t�ɂł��鎞�ԁi���Ԃ�
�@�@�@�@�@�@���j�\����ui�I�u�W�F�N�g�ōs���B
�@�@�@�@�@�@�������A���ǂ𓯎��Ɏg���Ė��t�ɂł��鎞�Ԍv�Z��tank�I�u�W�F�N�g�̃��\�b�h�ōs���A����
�@�@�@�@�@�@�ǃI�u�W�F�N�g�Ɋi�[������̂Ƃ���B
�t�@�C�����FL14-EX2.cpp
�쐬���@�@�F2015/07/21
�쐬�ҁ@�@�FBayaSea
*/
#include <conio.h>
#include <iostream>
using namespace std;

//�ǃN���X��`
class Tube {
	int Hour;
public:
	//���t�ɂł��鎞�Ԑݒ胁�\�b�h
	void setHour(int shour)
	{
		Hour = shour;
	}

	//���t���Ԏ擾���\�b�h
	int getHour()
	{
		return Hour;
	}

};
////////////////////////////////////////////////
//�^���N�N���X��`
class Tank {
	Tube tubeA, tubeB;			//A�ǁAB�ǃI�u�W�F�N�g
	int hour;					//����
	int minute;					//��
public:
	//�`�ǁA�a�ǃI�u�W�F�N�g�ݒ胁�\�b�h
	void setTube(Tube stubeA, Tube stubeB)
	{
		//UI�N���X�Ŏg����tube�I�u�W�F�N�g�����B
		tubeA = stubeA;
		tubeB = stubeB;
	}
    
    //�`�ǂƂa�Ǘ����g���Ė��t�ɂł��鎞�Ԍv�Z���\�b�h
	void calcTime()
	{
		//�����ϐ��BA�̂݁AB�݂̂Ŗ��t�ɂł��鎞�Ԃ����B
		int A = tubeA.getHour();
		int B = tubeB.getHour();

		//A��B�Ǘ����g���Ė��t�ɂȂ鎞�Ԃ��v�Z�B
		hour = (int)(1.0 / ((1.0 / (double)A) + (1.0 / (double)B)));
		//A��B�Ǘ������g���Ė��t�ɂȂ镪���v�Z�B�l�̌ܓ����Ă܂��B
		minute = (int)((((1.0 / ((1.0 / (double)A) + (1.0 / (double)B))) - (double)hour) * 60.0) + 0.5);
	}
    
    //���Ԏ擾���\�b�h
	int getHour()
	{
		return hour;
	}

    //���擾���\�b�h
	int getMinute()
	{
		return minute;
	}

};
//////////////////////////////////////////////////////
//���[�U�C���^�t�F�[�X�N���X��`
class UI {
	Tube tubeA, tubeB;				//Tube�N���X�̃I�u�W�F�N�g�錾
	Tank tank;						//Tank�N���X�m�I�u�W�F�N�g�錾
public:
	//�������䃁�\�b�h
	void processCtrl()
	{
		inputTube();						//���̓��\�b�h
		tank.setTube(tubeA, tubeB);			//tank�I�u�W�F�N�g��A��B�ǂ̃I�u�W�F�N�g�ݒ胁�\�b�h���Ăяo���B
		tank.calcTime();					//tank�I�u�W�F�N�g�̎��Ԍv�Z���\�b�h���Ăяo���B
		show();								//�\�����\�b�h
	}

	//tube���͐ݒ胁�\�b�h
	void inputTube()
	{
		//�����ϐ�
		int A, B;

		cout << "A�ǂ݂̂Ŗ��t�ɂł��鎞�Ԃ̓���(6���Ԃ̏ꍇ 6) >> ";
		cin >> A;
		cout << "B�ǂ݂̂Ŗ��t�ɂł��鎞�Ԃ̓���(9���Ԃ̏ꍇ 9) >> ";
		cin >> B;

		//Tube�I�u�W�F�N�g�̎��Ԑݒ胁�\�b�h���Ăяo���B
		tubeA.setHour(A);
		tubeB.setHour(B);
	}

	//�\�����\�b�h
	void show()
	{
		cout << "A�AB�ǂ��g����" << tank.getHour() << "���� " << tank.getMinute() << "��" << endl;
	}

};
////////////////////////////////////////////////////////////////
int main()
{
	UI ui;			//���[�U�C���^�t�F�[�X�I�u�W�F�N�g�錾

	ui. processCtrl();	//�C���^�t�F�[�X��������

	_getch();
	return 0;
}
