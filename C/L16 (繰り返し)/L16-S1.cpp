/*
�ۑ�ԍ��@�FL16-Special1
���e�@�@�@�F�O���tgraph�I�u�W�F�N�g�ɓ_����ݒ肵�āA�O���t��\������B
�@�@�@�@�@�@10�́��A1�́{�ŕ\�����̂Ƃ���B
�@�@�@�@�@�@���_�ɉ������\����ށ��Ɓ{�̊e���͕ʂ̃��\�b�h�Ōv�Z���āA�����ǃI�u�W�F�N�g�Ɋi�[���Ă����B
�@�@�@�@�@�@���_���͂�main�֐��ōs���A�O���t�\����graph�I�u�W�F�N�g�ōs���B
�t�@�C�����FL16-S1.cpp
�쐬���@�@�F2015/10/01
�쐬�ҁ@�@�FBayaSea
*/

#include <conio.h>
#include <iostream>
using namespace std;

//�O���t�N���X��`
class Graph {	
	int score;						// �_��
	int dec;						//�\�̌��p
public:
	//���_�ݒ胁�\�b�h
	void setTen(int ten)
	{
		score = ten;				//���_�ݒ�
	}

	//�\�̌����v�Z���\�b�h
	void calcDec()
	{
		dec = score / 10;			//�\�̌�
		
	}

	//�O���t�\�����\�b�h
	void showGraph()
	{
		//�\�̌����\��
		for (int maru = 0; maru < dec; maru++)
		{
			cout << "��";
		}

		//��̌��{�\��
		for (int tasu = 0; tasu < score%10; tasu++)
		{
			cout << "�{";
		}
		cout << endl;
	}
};
////////////////////////////////////////////////////////////
int main()
{
	Graph graph;					//�I�u�W�F�N�g�錾
	int score;						//�_�����͗p

	cout << "�_������́i27�_�̏ꍇ�@27�j>> ";
	cin >> score;

	graph.setTen(score);			//���_�ݒ胁�\�b�h�̌Ăяo��

	graph.calcDec();				//�\�̌��v�Z���\�b�h�̌Ăяo��
	graph.showGraph();				//�O���t�\�����\�b�h�̌Ăяo��

	_getch();
	return 0;
}


