/*
�ۑ�ԍ��@�FL25-1
���e�@�@�@�Fgame�I�u�W�F�N�g�ɓ��͂����^�C�g�����i�ő�Q�O�����j��char�^�����z��Ɋi�[���āA�^�C
�@�@�@�@�@�@�g�����̕�������\������B
�@�@�@�@�@�@���͂ƕ\����main�֐��ōs���B
�@�@�@�@�@�@�t�@�C�����FL25-01.cpp
	  �쐬���@�@�F2015/12/20
	  �쐬�ҁ@�@�FBayaSea
	  */

#include <conio.h>
#include <iostream>
using namespace std;

//�Q�[���N���X��`
class Game {
	char name[21];		//�^�C�g���p
public:
	//�^�C�g���ݒ�@str[]�F�^�C�g�������z��
	void setTitle(char str[]){
		strcpy_s(name, 21, str);
	}
	//�������擾
	int getLen(){
		int len = 0;		//�������i�[�p

		//������̏I�[����'\0'�𗘗p
		for (; name[len] != '\0'; len++);

		return len;
	}
};
////////////////////////////////////////////////////////////
int main()
{
	Game game;
	char title[21];	//�^�C�g�����͗p

	cout << "20�����܂ł̃^�C�g���������>> ";
	cin >> title;

	game.setTitle(title);		//�^�C�g���ݒ胁�\�b�h�̌Ăяo��

	cout << "������=" << game.getLen() << endl;

	_getch();
	return 0;
}


