/*
�ۑ�ԍ��@�FL14-special1
���e�@�@�@�F�r�[�J�[beker�I�u�W�F�N�g�ɐ��ig�j�Ɖ��̗ʁi���j�i�d���j��ݒ肵�āA�H�����̔Z�x��\������B
�@�@�@�@�@�@�������A���Ɖ��̗ʓ��́A�Z�x�\����ui�I�u�W�F�N�g�ōs���B
�@�@�@�@�@�@�܂��A�Z�x�v�Z��beker�I�u�W�F�N�g�ōs���A�����ǃI�u�W�F�N�g�Ɋi�[������̂Ƃ���B
�t�@�C�����FL14-S1.cpp
�쐬���@�@�F2015/06/17
�쐬�ҁ@�@�FBayaSea
*/

#include <conio.h>
#include <iostream>
using namespace std;

//�r�[�J�[�N���X��`
class Beker {

	int water;
	int salt;
	double density;

public:
	//���E���̗ʐݒ胁�\�b�h
	void setVar(int swater, int ssalt)
	{
		water = swater;
		salt = ssalt;
	}

    //�Z�x�v�Z���\�b�h
	void calcDensity()
	{
		//�Z�x = �� / �H����
		density = (double)(salt / (double)(water + salt)) * 100.0 ;
	}

    //�Z�x�擾���\�b�h
	double getDensity()
	{
		return density;
	}

};
////////////////////////////////////////////////////////////
//���[�U�C���^�t�F�[�X�N���X��`
class UI {
	Beker beker;		//beker�I�u�W�F�N�g

public:
    //�������䃁�\�b�h
	void processCtrl()
	{
		inp();
		beker.calcDensity();
		show();
	}	

	//���͐ݒ胁�\�b�h
	void inp()
	{
		int water, salt;
		cout << "���̗ʁi���j�Ɖ��̗ʁi���j����́i��  100 20�j >> " ;
		cin >> water >> salt;
		beker.setVar(water, salt);
	}
	
	//�\�����\�b�h
	void show()
	{
		cout << "�H�����̔Z�x�i���j�@= " << beker.getDensity() << endl;
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
