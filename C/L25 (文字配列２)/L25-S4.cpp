/*
�ۑ�ԍ��@�FL25-Special4
���e�@�@�@�Fgame�I�u�W�F�N�g�Ƀ^�C�g����"STARTREK"��string�^������Ɋi�[������A�P�������\��
�@�@�@�@�@�@����B
�@�@�@�@�@�@�^�C�g�����́A�N���X��`�ŏ���������B
�@�@�@�@�@�@�\���́Agame�I�u�W�F�N�g�ōs���B
�t�@�C�����FL25-S4.cpp
�쐬���@�@�F2016/1/5
�쐬�ҁ@�@�FBayaSea
*/

//���s���Ɋm�F���邱�ƁF
//��string�^�I�u�W�F�N�g�̕�����̊e������[�Y��]�ň����邱�Ƃ��m�F���Ȃ����B
//A.�m�F���܂����B

//��string�^�I�u�W�F�N�g�̕�����ɂ��k�����������邱�Ƃ��m�F���Ȃ����B
//A.�m�F���܂����B

#include <conio.h>
#include <iostream>
using namespace std;

//�Q�[���N���X��`
class Game {
	string title = "STARTREK";		//�^�C�g���p
public:
	//�^�C�g���\���@�P�������\��
	void show() {
		for (int i = 0; title[i] != '\0'; i++)
		{
			cout << title[i];
		}
		cout << endl;

	}
};
////////////////////////////////////////////////////////////
int main()
{
	Game game;

	game.show();		//�^�C�g���\�����\�b�h�̌Ăяo��

	_getch();
	return 0;
}




