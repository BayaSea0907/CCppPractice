/*
�ۑ�ԍ��@�FL15-14
���e�@�@�@�F�q�[���[hero�I�u�W�F�N�g�Ƀq�[���[����ݒ肵����A���߂ē��͂������O�Ɠ������ǂ����𔻒肵�����ʂ�\������B
�@�@�@�@�@�@�q�[���[���Ɩ��O�́Astring�^������Ƃ���B
�@�@�@�@�@�@�q�[���[���Ɩ��O�̓��͂́Aui�I�u�W�F�N�g�ōs���A����\����hero�I�u�W�F�N�g�ōs���B
�t�@�C�����FL15-B14.cpp
�쐬���@�@�F2015/07/21
�쐬�ҁ@�@�FBayaSea
*/
//�v���O���������������Ċm�F���邱�ƁF
//����r���Z�q��ے�@!=�@�ɂ��āA�قȂ閼�O����͂���Ƃǂ��Ȃ�ł��傤���H
//�@��r���Z�q�̓����i�@==�@�j�Ɣے�i�@!=�@�j�Ƃ̔�r�]���̈Ⴂ���m�F���܂��傤�B

#include <string>		//string�I�u�W�F�N�g���g�����߂ɕK�v
#include <conio.h>
#include <iostream>
using namespace std;

//HERO�N���X��`
class Hero {
	string name;		//�q�[���[��
public:
    //�q�[���[���ݒ胁�\�b�h
	void setName(string sname)
	{
		name = sname;
	}

	//�q�[���[�����胁�\�b�h
	void judgeName(string str)
	{
		//�ŏ��ƁA�m�F�œ��͂������O���r
		if (name == str)
		{
			cout << "�q�[���[�̖��O��" << name << "����ō����Ă܂��B" << endl;
		}
		else
		{
			cout << name << "����ƁA" << str << "����͕ʐl�ł��B" << endl;
		}
	}
};
////////////////////////////////////////////////////////////
//���[�U�C���^�t�F�[�X�N���X��`
class UI {
	Hero hero;		//hero�I�u�W�F�N�g�錾
public:
	//�������䃁�\�b�h
	void processCtrl(){
		inpHero();		    //hero���͐ݒ�
		inpStrJudge();		//��r��������͔���
	}
	//hero���͐ݒ胁�\�b�h
	void inpHero()
	{
		//�����ϐ�
		string name;

		cout << "�q�[���[�̖��O��ݒ�B >> ";
		cin >> name;

		hero.setName(name);
	}
	//��r�����͔��胁�\�b�h
	void inpStrJudge()
	{
		//�����ϐ�
		string name;

		cout << "������x�q�[���[�̖��O����͂��Ă��������B >>";
		cin >> name;

		//�q�[���[����r���\�b�h���Ăяo��
		hero.judgeName(name);
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
