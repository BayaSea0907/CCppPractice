/*
�ۑ�ԍ��@�FL25-Special3
���e�@�@�@�Fscore�I�u�W�F�N�g�̃v���p�e�B�z��i�v�f���P�O�j���R���X�g���N�^�łO�ŏ��������āA����
�@�@�@�@�@�@�Ă̗v�f��\������B
�@�@�@�@�@�@�\���́Ascore�I�u�W�F�N�g�ōs���B
�t�@�C�����FL25-S3.cpp
�쐬���@�@�F2016/1/5
�쐬�ҁ@�@�FBayaSea
*/

#include <iomanip>
#include <conio.h>
#include <iostream>
using namespace std;

//�X�R�A�N���X��`
class Score {
	int ten[10];	//�_��
public:
	//�R���X�g���N�^
	Score()
	{
		//�v�f���Ɣ�r
		//for (int i = 0; i < (sizeof(ten) / sizeof(ten[0])); i++) {		
		for (int i = 0; i < 10; i++) {
			ten[i] = 0;
		}
	}

	//�_���\��
	void show() {
		for (int i = 0; i < 10; i++) {
			cout << ten[i] << ' ' ;
		}
	}
};
////////////////////////////////////////////////////////////
int main()
{
	Score score;

	score.show();		//�_���\�����\�b�h�̌Ăяo��

	_getch();
	return 0;
}


