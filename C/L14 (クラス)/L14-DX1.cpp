/*
�ۑ�ԍ��@�FL14-DeluxeSpecial1
���e�@�@�@�F�����Ƃ�A�N��B�N�̂Q�l�ō�Ƃ��邱�ƂɂȂ�A�ŏ�A�N�݂̂ō�Ƃ��A���̌�B�N�ЂƂ�ō�Ƃ���B
�@�@�@�@�@�@A�N�AB�N���ꂼ��P�l�Ŋ����ł�������ƍŏ��`�N�ЂƂ�ō�Ƃ����������͂��āA�Q�l�ō�
�@�@�@�@�@�@�Ƃ������ł��鑍������\������B
�@�@�@�@�@�@A�N��B�N�����ꂼ��I�u�W�F�N�g�ɂ��āA�P�l�Ŋ����ł��������ݒ肷��B
�@�@�@�@�@�@�����āA���work�I�u�W�F�N�g�ɁAA�N��B�N�̃I�u�W�F�N�g�ƍŏ��`�N�ЂƂ�ō�Ƃ��������
�@�@�@�@�@�@�ݒ肵�āA�Q�l�ō�Ƃ������ł��鑍������\������B
�@�@�@�@�@�@A�N��B�N���ꂼ��P�l�Ŋ����ł�������ƍŏ�A�N�ЂƂ�ō�Ƃ�������̓��́A�Q�l�ō�Ƃ���
�@�@�@�@�@�@���ł��鑍�����\����ui�I�u�W�F�N�g�ōs���B
�@�@�@�@�@�@�������A�Q�l�ō�Ƃ������AB�N���ЂƂ�ō�Ƃ�������v�Z��work�I�u�W�F�N�g�̃��\�b�h��
�@�@�@�@�@�@�s���A�����ǃI�u�W�F�N�g�Ɋi�[������̂Ƃ���B
�t�@�C�����FL14-DX1.cpp
�쐬���@�@�F2015/07/21
�쐬�ҁ@�@�FBayaSea
*/

#include <conio.h>
#include <iostream>
using namespace std;

//�l�N���X��`
class Man {
	int day;					//�ЂƂ�Ŋ����ł�������i���j
	int onlyDay;				//�ЂƂ�ō�Ƃ������
public:
	//�ЂƂ�Ŋ����ł�������ݒ胁�\�b�h
	void setDay(int sday)
	{
		day = sday;
	}

	//�ЂƂ�Ŋ����ł�������擾���\�b�h
	int getDay()
	{
		return day;
	}

	//�ЂƂ�ō�Ƃ���������\�b�h
	void setOnlyDay(int sonlyDay)
	{
		onlyDay = sonlyDay;
	}

	//�ЂƂ�ō�Ƃ�������擾���\�b�h
	int getOnlyDay()
	{
		return onlyDay;
	}

};
//////////////////////////////////////////////////
//��ƃN���X��`
class Work {
	//�I�u�W�F�N�g�錾
	Man manA, manB;
	//�v���p�e�B�B
	int ABDay;
public:
	//A�N�AB�N�I�u�W�F�N�g�ݒ胁�\�b�h
	void setVar(Man smanA, Man smanB)
	{
		//UI�N���X�Ŏg����man�I�u�W�F�N�g����
		manA = smanA;
		manB = smanB;
	}
    
    //�`�N�Ƃa�N��l�łł��鎞�Ԍv�Z���\�b�h
	void calcTime()
	{
		//���Ԍv�Z�B
		ABDay = manA.getOnlyDay() + (int)(((1.0 - ((1.0 / (double)manA.getDay()) * (double)manA.getOnlyDay())) / (1.0 / (double)manB.getDay())) + 0.99999f);
		//ABDay = manA.getOnlyDay() + (int)((1.0 - ((double)manA.getOnlyDay() / (double)manA.getDay())) * (double)manB.getDay() + 0.99999f);
	}
    
    //�`�a������Ɠ����擾���\�b�h
	int getABDay()
	{
		return ABDay;
	}
};
//////////////////////////////////////////////////////
//���[�U�C���^�t�F�[�X�N���X��`
class UI {
	//�I�u�W�F�N�g�錾
	Man manA, manB;
	Work work;
public:
	//�������䃁�\�b�h
	void processCtrl()
	{
		inputMan();						//���̓��\�b�h�Ăяo��
		work.setVar(manA, manB);		//A�N�AB�N�I�u�W�F�N�g�ݒ胁�\�b�h�Ăяo��
		work.calcTime();				//A�N��B�N�ӂ���ō�Ƃ��鎞�Ԍv�Z
		show();							//�\�����\�b�h�Ăяo��
	}

	//man���͐ݒ胁�\�b�h
	void inputMan()
	{
		//�����ϐ�
		int A, B;					//��l�Ŋ����ł������
		int onlyDay;				//A�N���ŏ���l�ō�Ƃ������

		cout << "A�N�ЂƂ�Ŋ����ł�������̓���(30���̏ꍇ 30) >> ";
		cin >> A;
		cout << "B�N�ЂƂ�Ŋ����ł�������̓���(20���̏ꍇ 20) >> ";
		cin >> B;
		cout << "�ŏ���A�N�ЂƂ�ō�Ƃ�������̓���(6���̏ꍇ 6) >> ";
		cin >> onlyDay;

		//man�I�u�W�F�N�g�̈�l�ō�Ƃł�������ݒ胁�\�b�h���Ăяo���B
		manA.setDay(A);
		manB.setDay(B);
		//man�I�u�W�F�N�g��A�N���ŏ��ЂƂ�ō�Ƃ�������ݒ胁�\�b�h���Ăяo���B
		manA.setOnlyDay(onlyDay);
	}

	//�\�����\�b�h
	void show()
	{
		cout << "�d�����n�܂��Ă���I���܂ł̓���=" << work.getABDay() << "��" << endl;
	}

};
////////////////////////////////////////////////////////////////
int main()
{
	UI ui;			    //���[�U�C���^�t�F�[�X�I�u�W�F�N�g�錾

	ui.processCtrl();	//�C���^�t�F�[�X��������

	_getch();
	return 0;
}
