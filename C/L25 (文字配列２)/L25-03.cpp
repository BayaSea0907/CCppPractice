/*
�ۑ�ԍ��@�FL25-3
���e�@�@�@�FL25-2�����������āA�^�C�g�����擾�p�����z��Ƀ^�C�g�������P��������do�`while�����g��
�@�@�@�@�@�@�ăR�s�[���ă^�C�g����\������B
�@�@�@�@�@�@�\����main�֐��ōs���B
�t�@�C�����FL25-03.cpp
�쐬���@�@�F2015/12/21
�쐬�ҁ@�@�FBayaSea
*/

#include <conio.h>
#include <iostream>
using namespace std;

//�Q�[���N���X��`
class Game {
	char name[13];	//�^�C�g��
public:
	//�^�C�g���ݒ�
	void setTitle(){
		strcpy_s(name, 20, "TwilightLove");
	}

	//�^�C�g���擾�@str[]�F�^�C�g���擾�p�z��
	void getTitle(char s[]){
		//�P�������R�s�[
		int i = 0;

		do {
			s[i] = name[i];
			i++;

		} while (s[i] != '\0');
	}
};
////////////////////////////////////////////////////////////
int main()
{
	Game game;		//�Q�[���I�u�W�F�N�g�錾
	char title[13];	//�^�C�g���擾�p

	game.setTitle();			//�^�C�g���ݒ胁�\�b�h�̌Ăяo��
	game.getTitle(title);		//�^�C�g���擾���\�b�h�̌Ăяo��

	cout << title << endl;

	_getch();
	return 0;
}

