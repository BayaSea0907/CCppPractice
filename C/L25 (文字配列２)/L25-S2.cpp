/*
�ۑ�ԍ��@�FL25-Special2
���e�@�@�@�Fgame�I�u�W�F�N�g�Ƀ^�C�g����"STARTREK"���R���X�g���N�^��char�^�����z��i�v�f���P�O�j
�@�@�@�@�@�@�Ɋi�[���āA�^�C�g������\������B
�@�@�@�@�@�@�������A�z��v�f���͕K�v�Œ���Ƃ���B
�@�@�@�@�@�@�\���́Agame�I�u�W�F�N�g�ōs���B
�t�@�C�����FL25-S2.cpp
�쐬���@�@�F2016/1/4
�쐬�ҁ@�@�FBayaSea
*/

#include <conio.h>
#include <iostream>
using namespace std;

//�Q�[���N���X��`
class Game {
	char title[10];	//�^�C�g���p
public:
	//�R���X�g���N�^
	Game() {
		strcpy_s(title, 10, "STARTREK");
	}

	//�^�C�g���\��
	void showTitle() {
		cout << title << endl;
	}

};
////////////////////////////////////////////////////////////
int main()
{
	Game game;

	game.showTitle();		//�^�C�g���\�����\�b�h�̌Ăяo��

	_getch();
	return 0;
}


