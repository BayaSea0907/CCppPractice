/*
�ۑ�ԍ��@�FL25-4
���e�@�@�@�FL25-3�����������āA�^�C�g�����擾�p�����z��Ƀ^�C�g�������P��������for�����g���ăR�s
�@�@�@�@�@�@�[���ă^�C�g����\������B
�@�@�@�@�@�@�\����main�֐��ōs���B
�t�@�C�����FL25-04.cpp
�쐬���@�@�F2016/1/4
�쐬�ҁ@�@�FBayaSea
*/

#include <conio.h>
#include <iostream>
using namespace std;

//�Q�[���N���X��`
class Game {
	char title[13];	//�^�C�g��
public:
	//�^�C�g���ݒ�
	void setTitle(){
		strcpy_s(title, 20, "TwilightLove");
	}

	//�^�C�g���擾�@str[]�F�^�C�g���擾�p�z��
	void getTitle(char str[]){
		//�P�������R�s�[
		int i = 0;

		for(; str[i] != '\0'; i++)
		{
			str[i] = title[i];
		}
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

