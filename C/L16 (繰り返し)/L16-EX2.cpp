/*
�ۑ�ԍ��@�FL16-ExtraSpecial2
���e�@�@�@�F�}�`fig�I�u�W�F�N�g�ɍs����ݒ肵�āA����\������B
�@�@�@�@�@�@�������A�\�����遖�́A�P�s�ڂɂ͂P�A�Q�s�ڂɂ͂Q�A�E�E�E�ƁA���ꂼ��̍s�ɂ͍s����
�@�@�@�@�@�@������������\������B
�@�@�@�@�@�@���́Acout << "*"; �ŕ\������B
�@�@�@�@�@�@�܂��A���ꂼ��̍s�̍Ō�ɕ\���������̉E�ɂ͋󔒕�����\�����Ă͂����܂���B
�@�@�@�@�@�@�s�����͂�main�֐��ōs���A�\����fig�I�u�W�F�N�g�ōs���B
�t�@�C�����FL16-EX2.cpp
�쐬���@�@�F2015/10/15
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
		int column = line;		//�񐔗p
		int space =  line;		//�󔒐�

		//�c��������@i�F�s����p
		for(int i = 0; i < line; i++)
		{
			int j;				//�󔒕����\���@�F�񐧌�p

			//����������@�ŏ��́��܂łɋ󔒕�����\��
			space -= 1;			//�󔒕����̌��擾

			//�󔒕����\���@j�F�񐧌�p
			for(j = 0; j < space; j++)
			{
				cout << "��";
			}

			//���������\��  (�� - ��)
			for(j = 0; j < (column - space); j++)
			{ 
				cout << "*";

				//���́���\������O�ɋ󔒕�����\��
				//�Ō�́���\�������E�ɂ͋󔒕�����\�����Ȃ����߂�
				//column-1�Ő��� (*�̌�) < (��-1)
				if((j + space) < (column - 1))
				{
					cout << "��";
				}
			}
			cout << endl;
		}
	}
};
////////////////////////////////////////////////////////////
int main()
{
	Figure fig;		//�}�`�I�u�W�F�N�g�錾
	int line;		//�s�����͗p

	cout << "���s�\�����܂����i�T�s�̏ꍇ�@5�j>> ";
	cin >> line;

	fig.setLine(line);	//�s���ݒ胁�\�b�h�Ăяo��

	fig.showFig();		//�}�`�\�����\�b�h�̌Ăяo��

	_getch();
	return 0;
}



