/*
�ۑ�ԍ��@�FL16-Special4
���e�@�@�@�F�͈�region�I�u�W�F�N�g�ɓ��͂��������l���Q�ݒ肵�āA�������l����傫���l�܂ł̑����v
�@�@�@�@�@�@��\������B
�@�@�@�@�@�@���v�͂����ǃI�u�W�F�N�g�Ɋi�[���Ă����B
�@�@�@�@�@�@�����l���͂Ƒ����v�\����main�֐��ōs���B
�t�@�C�����FL16-S4.cpp
�쐬���@�@�F2015/10/15
�쐬�ҁ@�@�FBayaSea
*/

#include <conio.h>
#include <iostream>
using namespace std;

//�͈̓N���X��`
class Region {
	int start;				//�������l
	int end; 				//������l
	int sum = 0;			//���v�p�i0�j
public:
	//�͈͐��l�ݒ胁�\�b�h
	void setVar(int sstart, int send)
	{
		start = sstart;		//����
		end = send;			//���
	}

	//���v�v�Z���\�b�h
	void calcSum()
	{
		int taihi;			//�ޔ�p

		//�������l��ϐ�start�ɐݒ肷��
		if(start > end)
		{
			//end�ƑΔ�����ւ�
			taihi = end;
			end = start;
			start = taihi;
		}

		//���v�����߂�
		for(int i = start; i <= end; i++)
		{
			sum += i;
		}
	}

	//���v�擾���\�b�h
	int getSum()
	{
		return sum;
	}
};
////////////////////////////////////////////////////////////
int main()
{
	Region  region;			//�͈̓I�u�W�F�N�g�錾
	int start;				//�������l���͗p
	int end; 				//������l���͗p

	cout << "�����l���Q����(�� 1 5) >> ";
	cin >> start >> end;
	region.setVar(start, end);		//�͈͐��l�ݒ胁�\�b�h�̌Ăяo��

	region.calcSum();			//���v�v�Z���\�b�h�̌Ăяo��

	cout << "���v=" << region.getSum() << endl;

	_getch();
	return 0;
}
