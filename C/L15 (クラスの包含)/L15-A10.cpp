/*
�ۑ�ԍ��@�FL15-10
���e�@�@�@�Fman�I�u�W�F�N�g�̔N���\��0�ŏ��������āA���͂���0�Έȏ�̔N���
�@�@�@�@�@�@�i�[������A�N���\������B
�@�@�@�@�@�@�N���X��`�ŁAman�I�u�W�F�N�g�̔N���0�ŏ���������B
�@�@�@�@�@�@����́A�N�0�Έȏ�Ȃ�ΔN���man�I�u�W�F�N�g�Ɋi�[���A0�Ζ����Ȃ��man�I�u�W�F�N�g�̔N���0�ƕ\������B
�@�@�@�@�@�@�N����͂ƔN��\����ui�I�u�W�F�N�g�ōs���B
�t�@�C�����FL15-A10.cpp
�쐬���@�@�F2015/07/01
�쐬�ҁ@�@�FBayaSea
*/

//���s���Ɋm�F���邱�ƁF
//���N��ɕ��l����͂����Ƃ��A0��\�����邱�Ƃ��m�F���Ȃ����B

#include <conio.h>
#include <iostream>
using namespace std;

//�l�N���X��`
class Man {
	int age = 0; //�N��i0�j
public:
    //�N��i�[���\�b�h�@sage�F�N�����p
	void setAge(int sage)
	{
		//0�Έȏォ�ǂ����𔻕�
		if (sage >= 0)
		{ 
			age = sage;
		}
	}

	//�N��擾���\�b�h
	int getAge()
	{
		return age;
	}
};

////////////////////////////////////////////////////////////
//���[�U�C���^�t�F�[�X�N���X��`
class UI {
	Man man;		//�l�I�u�W�F�N�g�錾
public:
	//�������䃁�\�b�h
	void processCtrl(){
		inpMan();		//man���͐ݒ�
		show();			//�\��
	}
	//man���͐ݒ胁�\�b�h
	void inpMan()
	{
		//�����ϐ�
		int age;

		cout << "0�Έȏ�̔N������ >> " ;
		cin >> age;
		man.setAge(age);
	}

	//�\�����\�b�h
	void show()
	{
		cout << "�N���" << man.getAge() << "�΂ł��B" << endl;
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
