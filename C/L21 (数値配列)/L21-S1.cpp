/*
�ۑ�ԍ��@�FL21-Special1
���e�@�@�@�Ftest�I�u�W�F�N�g�ɁA���͂����T�̓��_��v�f�ɂ����_�z��i�v�f���T�j���i�[���āA�ō�
�@�@�@�@�@�@�_�ƍŒ�_��\������B
�@�@�@�@�@�@�ō��_�ƍŒ�_�����v�f�ԍ����A�����ǃI�u�W�F�N�g�Ɋi�[����B
�@�@�@�@�@�@�ō��_�ƍŒ�_�̗v�f�ԍ��i�[�p�v���p�e�B�ϐ��́A�N���X��`��0�ŏ���������B
�@�@�@�@�@�@���͂ƕ\����main�֐��ōs���B
�t�@�C�����FL21-S1.cpp
�쐬���@�@�F2015/11/12
�쐬�ҁ@�@�FBayaSea
*/

#include <conio.h>
#include <iostream>
using namespace std;

//�e�X�g�N���X��`
class Test {
	int ten[5];		//���_�z��
	int max = 0;	//�ō��_�̗v�f�ԍ��i�[�p�i0�j
	int min = 0;	//�Œ�_�̗v�f�ԍ��i�[�p�i0�j
public:
	//���_�ݒ�@n[]�F���_�z��
	void setTen(int n[]){
		for (int i = 0; i < 5; i++){
			ten[i] = n[i];
		}
	}

	//�ō��_�E�Œ�_����
	void searchMaxMin(){
		for (int i = 0; i < 5; i++)
		{
			//�ō��_�̌���
			if (ten[max] < ten[i])
			{
				max = i;
			}
			//�Œ�_�̌���
			if (ten[min] > ten[i])
			{
				min = i;
			}
		}
	}

	int getMax(){ return ten[max]; }	//�ō��_�擾
	int getMin(){ return ten[min]; }	//�Œ�_�擾
};
////////////////////////////////////////////////////////////
int main()
{
	Test test;		//�e�X�g�I�u�W�F�N�g�錾
	int ten[5];		//���_���͗p

	//�_����
	for (int i = 0; i < 5; i++){
		cout << "���_�����>> ";
		cin >> ten[i];
	}

	test.setTen(ten);		//���_���̓��\�b�h�̌Ăяo��
	test.searchMaxMin();	//�ō��_�E�Œ�_�������\�b�h�̌Ăяo��

	cout << "�ō��_=" << test.getMax() << endl;
	cout << "�Œ�_=" << test.getMin() << endl;

	_getch();
	return 0;
}

