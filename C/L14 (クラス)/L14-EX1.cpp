/*
�ۑ�ԍ��@�FL14-ExtraSpecial1
���e�@�@�@�F�r�̂P�������i���j�AA�NB�N�̕������x�i���^���j����͂��āA�r�𔽑Ε����ɕ���A�N��B�N��
�@�@�@�@�@�@�Ăяo��͉̂����ォ��\������B
�@�@�@�@�@�@A�N��B�N�����ꂼ��̃I�u�W�F�N�g�ɂ��āA�������x��ݒ肷��B
�@�@�@�@�@�@�����āA�Ăяo����Ԃ��v�����郉���f�u�[rendezvous�I�u�W�F�N�g�ɁAA�N��B�N�̃I�u�W
�@�@�@�@�@�@�F�N�g�ƒr�̎�������ݒ肵�ďo����ԁi���j��\������B
�@�@�@�@�@�@A�N��B�N�̑��x�ƒr�̎��������́A�Ăяo����ԕ\����ui�I�u�W�F�N�g�ōs���B
�@�@�@�@�@�@�������Arendezvous�I�u�W�F�N�g�Ōv�Z�����o����Ԃ́Arendezvous�I�u�W�F�N�g�Ɋi�[
�@�@�@�@�@�@���Ȃ����̂Ƃ��A�Ăяo����ԁi���j�̂P�������͐؂�̂Ă�B
�t�@�C�����FL14-EX1.cpp
�쐬���@�@�F2015/07/21
�쐬�ҁ@�@�FBayaSea
*/

#include <conio.h>
#include <iostream>
using namespace std;

//�l�N���X��`
class Man {
	int speed;			//�v���p�e�B�錾
public:
	//���x�ݒ胁�\�b�h�@sspeed�F���x
	void setSpeed(int sspeed)
	{
		speed = sspeed;
	}

	//���x�擾���\�b�h
	int getSpeed()
	{
		return speed;
	}

};
////////////////////////////////////////////
//�����f�u�[�N���X��`
class Rendezvous {
	//�I�u�W�F�N�g�錾
	Man manA, manB;				//�I�u�W�F�N�g�錾
	int distance;				//�v���p�e�B�錾
public:
	//�r�P�������EA�N��B�N�I�u�W�F�N�g�ݒ胁�\�b�h
	void setVar(int sdistance, Man smanA, Man smanB)
	{
		//A�NB�N�I�u�W�F�N�g�ɁAUI�N���X�Ŏg����A�NB�N�I�u�W�F�N�g�����B
		manA = smanA;
		manB = smanB;

		//�r�̂P�T�̋���
		distance = sdistance;
	}
    
    //�Ăяo����Ԏ擾���\�b�h
	int getTime()
	{
		//�����ϐ�
		int Time;

		//A�N��B�N���o����Ԃ��v�Z�Bdouble�Ōv�Z���āA�Ō��int�^�ɒ�����1��������؂�̂Ă�B
		Time = (int)((double)distance / (double)(manA.getSpeed() + manB.getSpeed()));

		return Time;
	}

};
//////////////////////////////////////////////////////
//���[�U�C���^�t�F�[�X�N���X��`
class UI {
	Rendezvous rende;			//�����f�u�[�N���X���I�u�W�F�N�g�錾
	Man manA, manB;				//Man�N���X��A��B�ɕ����ăI�u�W�F�N�g�錾
public:
    //�������䃁�\�b�h
	void processCtrl()
	{
		inputMan();				//man���̓��\�b�h
		input();				//���̓��\�b�h
		show();					//�\�����\�b�h
	}
public:
	//man���͐ݒ胁�\�b�h
	void inputMan()
	{
		//�����ϐ�
		int A, B;

		//A�N��B�N�̕������x�����
		cout << "A�����B�N�̑��x�����(36m/�� 40m/���̏ꍇ  36 40) >> ";
		cin >> A >> B;

		//Man�N���X�̑��x�ݒ胁�\�b�h���Ăяo���B
		manA.setSpeed(A);
		manB.setSpeed(B);
	}

	//���͐ݒ胁�\�b�h
	void input()
	{
		//�����ϐ�
		int distance;

		//�r�̂P�T�̋��������
		cout << "�r�̂P�T�̋��������(1368m�̏ꍇ 1368) >> ";
		cin >> distance;

		//�����ް�׽�̒r�̋����AA�NB�N�̑��x�ݒ胁�\�b�h���Ăяo���B
		rende.setVar(distance, manA, manB);
	}
	//�\�����\�b�h
	void show()
	{
		cout << "�o��̂�" << rende.getTime() << "����" << endl;
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
