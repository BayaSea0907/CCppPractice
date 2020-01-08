/*
�ۑ�ԍ��@�FL14-ExcellentSpecial2
���e�@�@�@�F�g���l���ƓS����ʉ߂���Ƃ��͑��x�i16m/�b�j�A����ȊO�̂Ƃ���ł͑��x�i18m/�b�j�ő���
�@�@�@�@�@�@�K���ɂȂ��Ă����Ԃ��A�g���l���𔲂��Ă��΂炭����A���ɓS����n��܂��B
�@�@�@�@�@�@��Ԃ̒����im�j�ƃg���l���ɂ������Ă���S����ʉ߂��I����܂ł̎��ԁi���j����͂��āA�g
�@�@�@�@�@�@���l���̏o������S���̓����܂ł̋����i�g���l���S���Ԃ̋����j��\������B
�@�@�@�@�@�@��Ԃ��I�u�W�F�N�g�ɂ��āA�ԗ������ƃg���l���ƓS����ʉ߂���Ƃ��͑��x�A����ȊO�̂Ƃ�
�@�@�@�@�@�@��ł̑��x��ݒ肷��B
�@�@�@�@�@�@�g���l���ƓS����ʉ߂���Ƃ��̑��x�Ƃ���ȊO�̂Ƃ���ł̑��x�́A�N���X��`�ŏ��������Ă����B
�@�@�@�@�@�@�����āA�ʉߌv��passTime�I�u�W�F�N�g�ɁA��ԃI�u�W�F�N�g��ݒ肵�āA�g���l���S���Ԃ̋�����\������B
�@�@�@�@�@�@�g���l���ƓS���̒����͂��ꂼ��1000���Ƃ��āA�N���X��`�ŏ��������Ă����B
�@�@�@�@�@�@�g���l���S���Ԃ̋����́i1/10�j�����l�̌ܓ�����B
�@�@�@�@�@�@��Ԃ̒����A�g���l���ɂ������Ă���S����ʉ߂��I����܂ł̎��ԓ��́A�g���l���S���Ԃ̋�
�@�@�@�@�@�@���\����ui�I�u�W�F�N�g�ōs���B
�@�@�@�@�@�@�������A�g���l���S���Ԃ̋����v�Z��passTime�I�u�W�F�N�g���\�b�h�ōs���A�g���l���S����
�@�@�@�@�@�@�̋����̓I�u�W�F�N�g�Ɋi�[���Ȃ���ui�I�u�W�F�N�g�ɖ߂����̂Ƃ���B
�t�@�C�����FL14-XC2.cpp
�쐬���@�@�F2015/07/22
�쐬�ҁ@�@�FBayaSea
*/
#include <conio.h>
#include <iostream>
using namespace std;

//��ԃN���X��`
class Train {
	int tbSpeed;				//�g���l���S�����x(16m/�b)
	int speed;					//�ʏ푬�x(18m/�b)
	int len;					//����(m)
public:
	//�R���X�g���N�^�@tbSpeed��16�Aspeed��18�ŏ�����
	Train():tbSpeed(16), speed(18){}

	//�g���l���S�����x�擾���\�b�h
	int getTbSpeed()
	{
		return tbSpeed;
	}

	//�ʏ푬�x�擾���\�b�h
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
//////////////////////////////////////////////////////
//�ʉߌv���N���X��`
class PassTime {
	Train train;				//��ԃI�u�W�F�N�g
	int len;					//��Ԃ̒���(m)
	int time;					//�g���l���n��n�߂���S���n��I���܂ł̎���(��)
	int distance;				//�g���l���S���Ԃ́A����(m)
	int tunnel;					//�g���l������(1000m)
	int bridge;					//�S������(1000m)
public:
	//�R���X�g���N�^ tunnel��1000�Abridge��1000�ŏ�����
	PassTime() :tunnel(1000), bridge(1000)
	{

	}
	//��Ԓ����E���Ԑݒ胁�\�b�h
	void setVar(int strain, int stime)
	{
		len = strain;
		time = stime;
	}
    
    //�g���l���S���Ԓ����擾���\�b�h
	int getDistance()
	{
		return distance;
	}

};
//////////////////////////////////////////////////////
//���[�U�C���^�t�F�[�X�N���X��`
class UI {
	Train train;
	PassTime pTime;
public:
	//�������䃁�\�b�h
	void processCtrl()
	{
		inputTrain();				//��Ԃ̒����ݒ胁�\�b�h
		inputPassTime();			//�g���l���S���ԓn��I����܂ł̎��ԃ��\�b�h
		pTime.PassTime();			//�g���l���S���Ԃ̋����v�Z���\�b�h
		show();						//�\�����\�b�h
	}

	//train���͐ݒ胁�\�b�h
	void inputTrain()
	{
		//�����ϐ��B��Ԃ̒���
		int len;

		cout << "��Ԃ̒����̓���(����200m�̏ꍇ 200) >> ";
		cin >> len;

		//train�I�u�W�F�N�g�̒����ݒ胁�\�b�h
		train.setLen(len);
	}

	//passTime���͐ݒ胁�\�b�h
	void inputPassTime()
	{
		//�����ϐ��B�n��I����܂ł̎���
		int time;

		cout << "�g���l���n�菉�߂���S���n��I����܂ł̎��Ԃ̓���(6���̏ꍇ 6) >> ";
		cin >> time;

		//pTime�I�u�W�F�N�g�̗�Ԃ̒����A���Ԑݒ胁�\�b�h�Ăяo��
		pTime.setVar(train.getLen(), time);
	}
		
	//�\�����\�b�h
	void show()
	{
		cout << pTime.getDistance() << "m" << endl;
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
