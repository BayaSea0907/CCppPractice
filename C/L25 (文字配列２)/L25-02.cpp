/*
�ۑ�ԍ��@�FL25-2
���e�@�@�@�Fgame�I�u�W�F�N�g�Ƀ^�C�g����"TwilightLove"��char�^�����z��i�v�f���Q�P�j�Ɋi�[����
�@�@�@�@�@�@�^�C�g������\������B
�@�@�@�@�@�@�W���֐�strcpy_s�֐����g�킸�ɁA�^�C�g�����擾�p�����z��Ƀ^�C�g�������P��������while
�@�@�@�@�@�@�����g���ăR�s�[����B
�@�@�@�@�@�@�\����main�֐��ōs���B
�t�@�C�����FL25-02.cpp
�쐬���@�@�F2015/12/20
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
		strcpy_s(title, 21, "TwilightLove");
	}

	//�^�C�g���擾�@str[]�F�^�C�g���擾�p�z��
	void getTitle(char str[]) {
		//�P�������R�s�[�@������̏I�[����'\0'�𗘗p
		int i = 0;

		for (; title[i] != '\0'; i++)
		{
			str[i] = title[i];
		}

		//�R�s�[����������̏I���ɏI�[����'\0'������
		str[i] = '\0';
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

