/*
�ۑ�ԍ��@�FL14-special2
���e�@�@�@�F��s�@plane�I�u�W�F�N�g�ɖړI�n�܂ł̋����ikm�j�ƕ��ώ����ikm/h�j��ݒ肵�āA���v���ԁi�����j��\������B
�@�@�@�@�@�@�������A�����Ǝ������́A���v���ԕ\����ui�I�u�W�F�N�g�ōs���B
�@�@�@�@�@�@���v���Ԃ�plane�I�u�W�F�N�g�Ōv�Z���A���v���ԁi���ƕ��j�́A�����ǃI�u�W�F�N�g�Ɋi�[������̂Ƃ���B
�@�@�@�@�@�@���v���Ԃ̕������͐؂�̂Ă�B
�t�@�C�����FL14-S2.cpp
�쐬���@�@�F2015/06/17
�쐬�ҁ@�@�FBayaSea
*/

#include <conio.h>
#include <iostream>
using namespace std;

//��s�@�N���X��`
class Plane {

	//�v���p�e�B�̐錾
	int speed;
	int distance;
	int hour;
	int minute;

public:
    //�����E�����ݒ胁�\�b�h�@sspeed�F�����@ sdistance�F����
	void setVar(int sspeed, int sdistancde)
	{
		speed = sspeed;
		distance = sdistancde;
	}

    //���v���Ԍv�Z���\�b�h
	void calcTime()
	{
		//���Ԍv�Z
		hour = distance / speed;

		//���v�Z
		minute = (int)((double)(distance % speed) / ((double)speed / 60.0));
	}

	//���擾���\�b�h
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

	//��s�@�I�u�W�F�N�g�錾
	Plane plane;

public:
    //�������䃁�\�b�h
	void processCtrl()
	{
		inp();
		plane.calcTime();
		show();
	}
	
	//���͐ݒ胁�\�b�h
	void inp()
	{
		int speed;
		int distance;

		cout << "���ώ����i����/���j�Ƌ����i�����j����́i��@740 10850) >> ";
		cin >> speed >> distance;
		plane.setVar(speed, distance);
	}
	
	//�\�����\�b�h
	void show()
	{
		cout << "���菊�v����=" << plane.getHour() << "����" << plane.getMinute() << "��";
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
