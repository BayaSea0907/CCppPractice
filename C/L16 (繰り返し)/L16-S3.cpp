/*
�ۑ�ԍ��@�FL16-Special3
���e�@�@�@�F�}�`fig�I�u�W�F�N�g�ɍs����ݒ肵�āA����\������B
�@�@�@�@�@�@�������A�\�����遖�́A�P�s�ڂɂ͂P�A�Q�s�ڂɂ͂Q�A�E�E�E�ƁA���ꂼ��̍s�ɂ͍s����
�@�@�@�@�@�@������������\������B
�@�@�@�@�@�@�܂��A���́Acout << "*"; �ŕ\������B
�@�@�@�@�@�@�s�����͂�main�֐��ōs���A�}�`�\����fig�I�u�W�F�N�g�ōs���B
�t�@�C�����FL16-S3.cpp
�쐬���@�@�F2015/10/08
�쐬�ҁ@�@�FBayaSea
*/

#include <conio.h>
#include <iostream>
using namespace std;

//�}�`�N���X��`
class Figure {
	int line;		//�s��
public:
	//�s���ݒ胁�\�b�h
	void setLine(int sline)
	{
		line = sline;
	}

	//�}�`�\�����\�b�h
	void showFig()
	{
		int column = line;			//�P�s�̕\�����ő��
		int space = line;			//�󔒐�

		//�c��������@i�F�s����p
		for (int i = 0; i < line; i++)
		{
			int j;					//�󔒕����\���@�F�񐧌�p

			//����������@���܂łɋ󔒕�����\��
			space -= 1;				//�󔒕����̌��擾

			//�󔒕����\���@int j�F�񐧌�p
			for (j = 0; j < space; j++)
			{
				cout << "A";
			}
			
			//���������\��
			for (j = 0; j < (column - space); j++)
			{
				cout << "*";
			}

			cout << endl;
		}
	}
};
////////////////////////////////////////////////////////////
int main()
{
	Figure fig;			//�}�`�I�u�W�F�N�g�錾
	int line;			//�s�����͗p

	cout << "���s�\�����܂����i�T�s�̏ꍇ�@5�j>> ";
	cin >> line;
	fig.setLine(line);		//�s���ݒ胁�\�b�h�Ăяo��

	fig.showFig();			//�}�`�\�����\�b�h�̌Ăяo��
	_getch();
	return 0;
}

