/*
�ۑ�ԍ��@�FL15-13
���e�@�@�@�F����Ɛ��w�̓��_�i�O�_�ȏ�P�O�O�_�ȉ��j����͂��āA���ۂ𔻒肷��B
�@�@�@�@�@�@�e�X�gtest�I�u�W�F�N�g�ɓ��_��ݒ肵����A���̍��۔�����s���Č��ʂ�\������B
�@�@�@�@�@�@�������e�i�_���͏����j�̍��۔���\���͂P�����Ƃ���B
�@�@�@�@�@�@�@���ȖڂƂ��U�O�_�ȏ�����i�Ƃ��A���ە��ނ͎��̂R����
�@�@�@�@�@�@ �@�@�E���i�̏ꍇ�F�����_�ƕ��ϒl
�@�@�@�@�@�@ �@�@�E�s���i�̏ꍇ�F
�@�@�@�@�@�@�@�@�@�@�@a)�P�Ȗڂ݂̂U�O�_�����̏ꍇ�i���̉Ȗڂ̂U�O�_�ɑ���Ȃ��s���_�j
�@�@�@�@�@�@�@�@�@�@�@b)���ȖڂƂ��U�O�_�����̏ꍇ
�@�@�@�@�@�@���_���͂�ui�I�u�W�F�N�g�ōs���A����\����test�I�u�W�F�N�g�ōs���B
�t�@�C�����FL15-B13.cpp
�쐬���@�@�F2015/07/15
�쐬�ҁ@�@�FBayaSea
*/

#include <conio.h>
#include <iostream>
using namespace std;
//�e�X�g�N���X��`
class Test{
	int kokugo;		//����p
	int sugaku;		//���w�p
public:
    //�_���ݒ胁�\�b�h
	void setTen(int skokugo, int ssugaku)
	{
		//�_����ݒ�
		kokugo = skokugo;
		sugaku = ssugaku;
	}
	
	//���_���胁�\�b�h
	void judgeTen()
	{
			//�����ϐ��B�����_���v�Z
			int ten = kokugo + sugaku;

			//����Ɛ��w���͈͊O�����ׂ�B
			if ((kokugo <= 100 && kokugo >= 0) && (sugaku <= 100 && sugaku >= 0))
			{
				//�e60�_�ȏ�Ȃ獇�i�B
				if (kokugo >= 60 && sugaku >= 60)
				{
					cout << "���i:�����_=" << ten << "   ����=" << (double)ten / 2.0 << endl;
				}
				//1�Ȗڂ̂�60�_�������ꍇ
				else if (kokugo >= 60 || sugaku >= 60)
				{
					cout << "�s���i:";

					//�͂��Ȃ������Ȗڂ𒲂ׂ�B
					if (kokugo < 60)
					{
						cout << "���ꂪ" << 60 - kokugo << "�_�s��" << endl ;
					}
					else
					{
						cout << "���w" << 60 - sugaku << "�_�s��" << endl ;
					}
				}
				else
				{
					cout << "�s���i:���ȖڂƂ��U�O�_����" << endl;
				}
			}
			//�͈͊O�̉Ȗڂ𒲂ׂ�
			else
			{
				if (kokugo > 100 || kokugo < 0)
				{
					cout << "����̓_�����͈͊O" << endl;
				}
				if (sugaku > 100 || sugaku < 0)
				{
					cout << "���w�̓_�����͈͊O" << endl;
				}
			}
	}
};

////////////////////////////////////////////////////////////
//���[�U�C���^�t�F�[�X�N���X��`
class UI {
	Test test;		//�e�X�g�I�u�W�F�N�g�錾
public:
	//�������䃁�\�b�h
		void processCtrl()
		{
			inpTest();		    //test���͐ݒ�
			test.judgeTen();	//���_����
		}
	//test���͐ݒ胁�\�b�h
	void inpTest()
	{	
		//�����ϐ�
		int kokugo, sugaku;

		cout << "����A���w�̓_�����O�`�P�O�O�_�̊Ԃœ���(��: 66 94) >> ";
		cin >> kokugo >> sugaku;

		//test�I�u�W�F�N�g��setTen���\�b�h	
		test.setTen(kokugo, sugaku);
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
