/*
�ۑ�ԍ��@�FL14-Special5
���e�@�@�@�F�{�[�gboat�I�u�W�F�N�g�ɐÐ���̑D�̑��x�ikm/���j�A��̗����ikm/���j�A���`�_��
�@�@�@�@�@�@�쉺�a�_�Ԃ̋����ikm�j��ݒ肵�āA�D���`�_�a�_���������鎞�Ԃ�\������B
�@�@�@�@�@�@�������A�P�������́A1/100���܂ł�؂�グ��B
�@�@�@�@�@�@�Ð���̑D�̑��x�A��̗����A���`�_�Ɛ쉺�a�_�Ԃ̋������́A�������ԕ\����ui�I�u�W�F�N�g�ōs���B
�@�@�@�@�@�@�܂��A���H���ԁA���H���ԁA�������ԁi���Ԃƕ��j�v�Z��boat�I�u�W�F�N�g�̂��ꂼ��̃��\�b
�@�@�@�@�@�@�h�ōs���A�����ǃI�u�W�F�N�g�Ɋi�[������̂Ƃ���B
�t�@�C�����FL14-S5.cpp
�쐬���@�@�F2015/07/21
�쐬�ҁ@�@�FBayaSea
*/
#include <conio.h>
#include <iostream>
using namespace std;

//�{�[�g�N���X��`
class Boat {
	//�v���p�e�B�錾
	int ship;				//�D�̑��x
	int river;				//��̑��x
	int distance;			//A�_����B�X�܂ł̋���
	int downHour;			//���H�̎���
	int downMinute;			//���H�̕�
	int upHour;				//���H�̎���
	int upMinute;			//���H�̕�
	int hour;				//�����̎���
	int minute;				//�����̕�

public:
    //���x�A�����A�����ݒ胁�\�b�h
	void setVar(int sship, int sriver, int sdistance)
	{
		//�v���p�e�B��������
		ship = sship;
		river = sriver;
		distance = sdistance;
	}
    
    //���`�_����쉺�a�_�܂ł̉��H���Ԍv�Z���\�b�h
	void calcOuroTime()
	{
		//���Ԃƕ���ʁX�Ɍv�Z�B1/100���܂Ő؂�グ
		downHour = distance / (ship + river);
		downMinute = (int)(((double)(distance % (ship + river)) / ( (double)(ship + river) / 60.0)) + 0.99);
	}
    
    //�쉺�a�_������`�_�܂ł̕��H���Ԍv�Z���\�b�h
	void calcFukuroTime()
	{
		//���Ԃƕ���ʁX�v�Z�B1/100�܂Ő؂�グ
		upHour = distance / (ship - river);
		upMinute = (int)(((double)(distance % (ship - river)) / ((double)(ship - river) / 60.0)) + 0.99);
	}
    
    //�������Ԍv�Z���\�b�h
	void calcRoundTrip()
	{
		//���H�ƕ��H�̎��Ԃ̍��v�B����60�𒴂��Ă����玞�Ԃ𑝂₷�B
		hour = (downHour + upHour) + ((downMinute + upMinute) / 60);

		//���H�ƕ��H�̕��̍��v�B60���𒴂��Ă�����A60�������]��𕪂Ƃ���B
		minute = (downMinute + upMinute) % 60;
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
	Boat boat;			//�{�[�g�I�u�W�F�N�g�錾
public:
    //�������䃁�\�b�h
	void processCtrl()
	{
		inp();						//���͐ݒ胁�\�b�h
		boat.calcOuroTime();		//���H�̎��Ԃ��v�Z
		boat.calcFukuroTime();		//���H�̎��Ԃ��v�Z
		boat.calcRoundTrip();		//�����̎��Ԃ��v�Z
		show();						//�\�����\�b�h
	}
	//���͐ݒ胁�\�b�h
	void inp()
	{
		//�����ϐ�
		int ship;			//�D�̑��x
		int river;			//��̑��x
		int distance;		//A�_����B�_�܂ł̋���

		cout << "�Ð���̑D�̑��x�̓���(14km/���̏ꍇ  14) >> " ;
		cin >> ship;
		cout << "��̗����̓���(2km/���̏ꍇ  2) >> " ;
		cin >> river;
		cout << "���A�_�Ɛ쉺B�_�Ԃ̋����̓���(36km�̏ꍇ  36) >> ";
		cin >> distance;
		//�D�̑��x�A��̗����A������ݒ�
		boat.setVar(ship, river, distance);
	}
	
	//�\�����\�b�h
	void show()
	{
		//boat�I�u�W�F�N�g�ɋL������Ă��鎞�Ԃƕ���ʁX�ɕ\���B
		cout << " "<< boat.getHour() << "���� " << boat.getMinute() << "��" << endl;
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
