/*
�ۑ�ԍ��@�FL24-9
���e�@�@�@�Fgame�I�u�W�F�N�g�ɓ��͂����ő�P�O�����܂ł̃^�C�g����"DEADKINDS"��char�^�����z���
�@�@�@�@�@�@�i�[���āA���̃^�C�g�����Ɋ܂܂��p�啶��'D'��'#'�ɒu�������^�C�g������\������B
�@�@�@�@�@�@�u�����ɂ�for�����g���A�v�f���e���I�[�����i�k�������j�ɂȂ�܂ŌJ�Ԃ��B
�@�@�@�@�@�@���͂�main�֐��ōs���A�\���̓I�u�W�F�N�g�łP�̕�����Ƃ��čs���B
�t�@�C�����FL24-A9.cpp
�쐬���@�@�F2015/12/10
�쐬�ҁ@�@�FBayaSea
*/

#include <conio.h>
#include <iostream>
using namespace std;

//�Q�[���N���X��`
class Game {
	char title[11];	//�^�C�g��
public:
	//�^�C�g���ݒ�@str[]�F�^�C�g���z��
	void setTitle(char str[]){
		strcpy_s(title, 11, str);
	}

	//�����̒u����
	void chgTitle(){
		//������̏I�[����'\0'�𗘗p
		for (int i = 0; title[i] != '\0'; i++){
			if (title[i] == 'D'){
				title[i] = '#';
			}
		}
	}
	//�^�C�g���\��
	void show(){
		cout << title << endl;
	}
};
////////////////////////////////////////////////////////////
int main()
{
	Game game;		//�Q�[���I�u�W�F�N�g�錾
	char title[11];	//�^�C�g�����͗p

	cout << "10�����܂ł̃^�C�g���������>> ";
	cin >> title;

	game.setTitle(title);		//�^�C�g���ݒ胁�\�b�h�̌Ăяo��

	game.chgTitle();		//�����̒u�������\�b�h�̌Ăяo��
	game.show();			//�^�C�g���\�����\�b�h�̌Ăяo��

	_getch();
	return 0;
}

