/*
�ۑ�ԍ��@�FL25-5
���e�@�@�@�Fgame�I�u�W�F�N�g��char�^�����z��Ɋi�[�����^�C�g����"XYZ123"�ɁA���̕�����"ABC"���^
�@�@�@�@�@�@�C�g�����̌��ɘA���������āA�A�������^�C�g������\������B
�@�@�@�@�@�@�A�����镶����"ABC"�́Amain�֐���char�^�����z��̐錾�Ɠ����ɏ���������B
�@�@�@�@�@�@���ꂼ��̕����z��̗v�f���́A�K�v�Œ���̗v�f���Ƃ���i�z��̃T�C�Y�ɒ��ӂ��܂��傤�j�B
�@�@�@�@�@�@�i�[�̓I�u�W�F�N�g�ōs���A�\����main�֐��ōs���B
�t�@�C�����FL25-05.cpp
�쐬���@�@�F2016/1/4
�쐬�ҁ@�@�FBayaSea
*/

#include <conio.h>
#include <iostream>
using namespace std;

//�Q�[���N���X��`
class Game {
	char title[12];		//�^�C�g��
public:
	//�^�C�g���ݒ�
	void setTitle(){
		strcpy_s(title, 7, "XYZ123");
	}

	//�^�C�g���A���@str[]�F�A��������
	void concatTitle(char str[])
	{
		//�^�C�g��������̕������J�E���g
		int len1 = 0;
		for (; title[len1] != '\0'; len1++);

		//�^�C�g���̘A��
		int len2 = 0;

		for (; str[len2] != '\0'; len1++,len2++) {
			title[len1] = str[len2];
		}

		//�A�������^�C�g���̏I���ɏI�[����'\0'������
		title[len1] = '\0';
	}

	//�^�C�g���擾�@str[]�F�^�C�g���擾�p�z��
	void getTitle(char str[]){
		strcpy_s(str, 12, title);
	}
};
////////////////////////////////////////////////////////////
int main()
{
	Game game;
	char str[4] = "ABC";		//���ɘA�����镶����
	char title[12];				//�A����^�C�g���擾�p

	game.setTitle();			//�^�C�g���ݒ胁�\�b�h�̌Ăяo��

	game.concatTitle(str);		//�^�C�g���A�����\�b�h�̌Ăяo��
	game.getTitle(title);		//�^�C�g���擾���\�b�h�̌Ăяo��

	cout << "�A����̕�����=" << title << endl;

	_getch();
	return 0;
}
