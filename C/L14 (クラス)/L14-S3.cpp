/*
�ۑ�ԍ��@�FL14-special3
���e�@�@�@�F�R�K�i�����Wm�j���삯�����̂Ƃ��āA�����̔n�͂����߂�B
�@�@�@�@�@�@�lman�I�u�W�F�N�g�ɑ̏d�i�s�j�Ƌ삯���̂ɗv�������ԁi�b�j��ݒ肵����A�n�́idouble�^�j��\������B
�@�@�@�@�@�@�������A�̏d�Ǝ��ԓ��́A�n�͕\����ui�I�u�W�F�N�g�ōs���B
�@�@�@�@�@�@�܂��Aman�I�u�W�F�N�g�Ōv�Z�����n�͂̓I�u�W�F�N�g�Ɋi�[���Ȃ����̂Ƃ���B
�t�@�C�����FL14-S3.cpp
�쐬���@�@�F 2015/06/17
�쐬�ҁ@�@�F BayaSea
*/

#include <conio.h>
#include <iostream>
using namespace std;

//�l�N���X��`
class Man {

	//�v���p�e�B�̐錾
	//�̏d�A����
	double wight;
	double time;

public:
    //�̏d�E���Ԑݒ胁�\�b�h
	void setVar(double sweight, double stime)
	{
		wight = sweight;
		time = stime;
	}
    //�n�͎擾���\�b�h
	double getBariki()
	{
		double bariki;

		//�n�͌v�Z (�̏d * �d�� * ����) / ���� / ���n��
		bariki = (wight * 9.8 * 8.0) / time / 736.0;

		return bariki;
	}

};
//////////////////////////////////////////////////////
//���[�U�C���^�t�F�[�X�N���X��`
class UI {
	Man man;     		//�I�u�W�F�N�g�錾

public:
    //�������䃁�\�b�h
	void processCtrl()
	{
		inp();
		show();
	}
	//���͐ݒ胁�\�b�h
	void inp()
	{	
		//�̏d�Ǝ��Ԃ����
		double weight, time;
		cout << "�̏d�ikg�j����́i��@60.0�j>>" ;
		cin >> weight;
		cout << "�삯�オ��̂ɗv�����b���̓��́i��@6.0�j>>" ;
		cin >> time;

		// man�I�u�W�F�N�g�̔n�͎擾���\�b�h��U����
		man.setVar(weight, time);
	}
	//�\�����\�b�h
	void show()
	{
		cout << "�n��(PS) = " << man.getBariki() << endl;
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
