/*
�ۑ�ԍ��@�FL14-Special4
���e�@�@�@�F�P�ӂP�Ocm�̐����`��p���𒣂荇�킹���ʐς����߂�B
�@�@�@�@�@�@�Q���̉�p���𒣂荇�킹���Ƃ��̂̂��͂Pcm�Ƃ���B
�@�@�@�@�@�@��`rect�I�u�W�F�N�g�ɁA�c�����Ɖ������ɂ��ꂼ�꒣�荇�킹�閇���Ƃ̂���ݒ肵����A
�@�@�@�@�@�@���荇�킹���Ƃ��ɂł����p���̖ʐς�\������B
�@�@�@�@�@�@�c�E���ɂ��ꂼ�꒣�荇�킹�閇���A�̂����́A�ʐϕ\����ui�I�u�W�F�N�g�ōs���B
�@�@�@�@�@�@rect�I�u�W�F�N�g�Ōv�Z����ċ��܂�A���荇�킹�Ăł����`�̏c�E�������A�ʐς́A�I�u�W
�@�@�@�@�@�@�F�N�g�Ɋi�[���Ȃ����̂Ƃ���B
�t�@�C�����FL14-S4.cpp
�쐬���@�@�F2015/06/24
�쐬�ҁ@�@�FBayaSea
*/
#include <conio.h>
#include <iostream>
using namespace std;

//��`�N���X��`
class Rectangle {

	//�v���p�e�B�̐錾
	int tmai;
	int ymai;
	int nori;
public:
    //�c�������E�̂��ݒ胁�\�b�h
	void setVar(int stmai, int symai, int snori)
	{
		tmai = stmai;
		ymai = symai;
		nori = snori;
	}

    //��`�̏c�������v�Z���\�b�h
	int getArea()
	{
		return ((tmai * 10) - nori * (tmai - 1)) * ((ymai * 10) - nori * (ymai - 1));

	}
};
//////////////////////////////////////////////////////
//���[�U�C���^�t�F�[�X�N���X��`
class UI {
	Rectangle rect;          	//��`�I�u�W�F�N�g�錾
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
		//�����ϐ��F�c�����A�������A�̂肵��
		int tmai, ymai, nori;

		cout << "�c�Ɖ������̓���1�i�c5���A��8���̏ꍇ ��F 5  8) >>" ;
		cin >> tmai >> ymai;

		cout << "�̂��(�c������)�̓���(1cm�̏ꍇ  ��F 1) >>";
		cin >> nori;

		rect.setVar(tmai, ymai, nori);

	}
	//�\�����\�b�h
	void show()
	{
		cout << "�̂����������ʐ� = " << rect.getArea() << "cm2" << endl;
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
