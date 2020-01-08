/*
�ۑ�ԍ��@�FL14-ExcellentSpecial1
���e�@�@�@�F�d�ԁi���}�Ɖ����j�����݂��ɔ��Ε����ɑ����Ă��܂��B
�@�@�@�@�@�@���}�Ɖ����d�Ԃ̑��x�ikm/���j�Ǝԗ���������͂��āA�o����Ă��炷��Ⴄ�܂łɂ����鎞�ԁi�b�j��\������B
�@�@�@�@�@�@���}�Ɖ��������ꂼ��I�u�W�F�N�g�ɂ��āA���x�Ǝԗ�������ݒ肵�܂��B
�@�@�@�@�@�@�����āA����Ⴂcross�I�u�W�F�N�g�ɁA���}�Ɖ����̃I�u�W�F�N�g��ݒ肵�āA�o����Ă���
�@�@�@�@�@�@����Ⴄ�܂łɂ����鎞�Ԃ�\������B
�@�@�@�@�@�@�������A�P�b�����́i1/10�j�b�܂ł�؂�グ��B
�@�@�@�@�@�@���}�Ɖ����d�Ԃ̑��x�Ǝԗ������̓��́A����Ⴄ�܂ł̎��ԕ\����ui�I�u�W�F�N�g�ōs���B
�@�@�@�@�@�@�������A����Ⴂ���Ԍv�Z��cross�I�u�W�F�N�g�̃��\�b�h�ōs���A�����ǃI�u�W�F�N�g�Ɋi�[������̂���B
�t�@�C�����FL14-XC1.cpp
�쐬���@�@�F2015/07/22
�쐬�ҁ@�@�FBayaSea
*/
#include <conio.h>
#include <iostream>
using namespace std;

//�d�ԃN���X��`
class Train {
	int speed;					//���x(km/��)
	int len;					//����(m)
public:
	//���x�ݒ胁�\�b�h
	void setSpeed(int sspeed)
	{
		speed = sspeed;
	}

	//���x�擾���\�b�h
	int getSpeed()
	{
		return speed;
	}

    //�����ݒ胁�\�b�h
	void setLen(int slen)
	{
		len = slen;
	}

	//�����擾���\�b�h
	int getLen()
	{
		return len;
	}

};
////////////////////////////////////////////////////
//����Ⴂ�N���X��`
class Cross {
	Train exp;					//���}�I�u�W�F�N�g
	Train rap;					//�����I�u�W�F�N�g
	int second;					//����Ⴄ����(�b)
public:
	//���}�Ɖ����I�u�W�F�N�g�ݒ胁�\�b�h
	void setVar(Train sexp, Train srap)
	{
		//UI�N���X�Ŏg����Train�I�u�W�F�N�g����
		exp = sexp;
		rap = srap;
	}
    
    //����Ⴄ���Ԍv�Z���\�b�h
	void calcTime()
	{
		//km/�����Am/�b�ɒ����v�Z
		double ESpeed = (double)exp.getSpeed() / 3600.0 * 1000.0;
		double RSpeed = (double)rap.getSpeed() / 3600.0 * 1000.0;
		
		//����Ⴄ���Ԃ��v�Z
		second = (int)((double)(exp.getLen() + rap.getLen()) / (ESpeed + RSpeed) + 0.9);
	}
    
    //����Ⴂ���Ԏ擾���\�b�h
	int getSecond()
	{
		return second;
	}

};
//////////////////////////////////////////////////////
//���[�U�C���^�t�F�[�X�N���X��`
class UI {
	Train exp, rap;				//���}�A�����I�u�W�F�N�g
	Cross cross;				//����Ⴂ�I�u�W�F�N�g
public:
	//�������䃁�\�b�h
	void processCtrl()
	{
		inputTrain();				//���̓��\�b�h
		cross.setVar(exp, rap);		//�I�u�W�F�N�g�ݒ胁�\�b�h
		cross.calcTime();			//���Ԍv�Z���\�b�h
		show();						//�\�����\�b�h
	}

	//train���͐ݒ胁�\�b�h
	void inputTrain()
	{
		//�����ϐ�
		int speedExp, speedRap;					//���x
		int lenExp, lenRap;						//�ԗ��̒���

		cout << "���}�̑��x�ƒ����̓���(���x90km/���A����250m�̏ꍇ 90 250) >> ";
		cin >> speedExp >> lenExp;
		cout << "�����̑��x�ƒ����̓���(���x72km/���A����200m�̏ꍇ 72 200) >> ";
		cin >> speedRap >> lenRap;

		//Train�I�u�W�F�N�g�̑��x�ݒ胁�\�b�h�Ăяo��
		exp.setSpeed(speedExp);
		rap.setSpeed(speedRap);

		//Train�I�u�W�F�N�g�̒����ݒ胁�\�b�h�Ăяo��
		exp.setLen(lenExp);
		rap.setLen(lenRap);

	}

	//�\�����\�b�h
	void show()
	{
		cout << cross.getSecond() << "�b" << endl;
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
