/*
�ۑ�ԍ��FL21-Special3
���e�@�@�Ftest�I�u�W�F�N�g�ɁA���͂����T�̓��_��v�f�ɂ����_�z��i�v�f���T�j���i�[���āA���v
�@�@�@�@�@�ƕ��ϓ_�A�e���_�ƕ��ϓ_�Ƃ̕΍��̌v�Z���ʂ�\������B
	  �@�@���v�ƕ��ϓ_�́A�����ǃI�u�W�F�N�g�Ɋi�[����B
		  ���͂�main�֐��ōs���A�\���̓I�u�W�F�N�g�ōs���B
�t�@�C�����FL21-S3.cpp
�쐬���@�@�F2015/12/03
�쐬�ҁ@�@�FBayaSea
*/

#include <conio.h>
#include <iostream>
using namespace std;

//�e�X�g�N���X��`
class Test {
	int ten[5];			//���_�z��
	int total = 0;		//���v�p�i0�j
	double ave;			//���ϗp
public:

	//���_�ݒ�@n[]�F���_�z��
	void setTen(int n[]){
		for (int i = 0; i < 5; i++){
			ten[i] = n[i];
		}
	}

	//���v�E���όv�Z
	void calcAveTotal(){
		int i;			//���[�v�J�E���^

		//���v�����߂�v�Z
		for (i = 0; i < 5; i++){
			total += ten[i];
		}

		//���ς����߂�v�Z
		ave = (double)total / (double)i;
	}

	//�\��
	void show(){
		cout << "���v=" << total << " ����=" << ave << endl;

		//�΍��̕\���ƌv�Z
		for (int i = 0; i < 5; i++){
			cout << "[" << i << "]�̒l�ƕ��ςƂ̕΍�="
				<< (double)ten[i] - ave << endl;
		}
	}
};
////////////////////////////////////////////////////////////
int main()
{
	Test test;	//�e�X�g�I�u�W�F�N�g�錾
	int ten[5];	//���_���͗p

	for (int i = 0; i < 5; i++)
	{
		cout << "���_�����>> ";
		cin >> ten[i];
	}

	test.setTen(ten); 		//���_�ݒ胁�\�b�h�̌Ăяo��
	test.calcAveTotal();	//���v�E���όv�Z���\�b�h�̌Ăяo��
	test.show();			//���ʕ\�����\�b�h�̌Ăяo��

	_getch();
	return 0;
}


