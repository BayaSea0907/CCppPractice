/*
�ۑ�ԍ��@�FL23-11
���e�@�@�@�Fsubj�I�u�W�F�N�g�ɓ��͂������l���̐��э\���̔z��i�v�f���T�j���i�[���āA�o�^�l���Ƃ���
�@�@�@�@�@�@����̐��т�\������B
�@�@�@�@�@�@���э\���̂̃����o�́A�w�Дԍ��Ɠ_���B
�@�@�@�@�@�@�w�Дԍ��ɂO�ȉ��̒l�����͂����܂ŁA�_���i�O�_�ȏ�P�O�O�_�ȉ��j�̓��͂��J��Ԃ��B
�@�@�@�@�@�@�v���O�������Ȍ��ɂ��邽�߂ɁAbreak����ontinue�����g���Ă悢�B
�@�@�@�@�@�@���͂ƕ\���́A�I�u�W�F�N�g�ōs���B
�t�@�C�����FL23-A11.cpp
�쐬���@�@�F2015/11/19
�쐬�ҁ@�@�FBayaSea
*/

#include <string>		//�����񑀍�p
#include <conio.h>
#include <iostream>
using namespace std;

//���э\���̒�`
struct Exam {
	int id;		//�w�Дԍ�
	int score;	//�_��
};

const int MAX = 5;	//�\���̔z��v�f��

//�ȖڃN���X��`
class Subj {
	Exam exam[MAX];		//���э\���̔z��
	int man = 0;		//�o�^�l��
public:
	//���ѓ���
	void inpExam()
	{
		Exam temp;		//���͏��m�F�p

		//�S�Ă̍\���̔z��ɓ��͂���
		while (man < MAX)
		{
			//�w�Дԍ�����
			cout << man + 1 << "�l�ڂ̊w�Дԍ��̓���(�I����0�ȉ�)>> ";
			cin >> temp.id;

			//�w�Дԍ���0�ȉ��̏ꍇ���͂���߂�
			if (temp.id <= 0){break;}

			//�_������
			while (true)
			{
				cout << man + 1 << "�l�ڂ̓_���̓���>> ";
				cin >> temp.score;

				//�_���͈͔��� 0~100�͈͓̔��������ꍇ
				if ((0 <= temp.score) && (temp.score <= 100)){
					exam[man] = temp;
					break;
				}
				//�͈͊O�������ꍇ
				else{
					cout << "�_����0�ȏ�100�ȉ��ł͂���܂���B" << "�ē��͂��Ă�������" << endl;
				}
			}
			man++;
		}
	}

	//�\��
	void show()
	{
		//�P�l�ڂ̊w�Дԍ���0�ȉ���������
		if (man == 0){
			cout << "�P�l���o�^����Ă��܂���" << endl;
		}
		else{
			cout << "�o�^�l��=" << man << endl;

			//�o�^���̕\��
			for (int i = 0; i < man; i++){
				cout << exam[i].id << "�� = " << exam[i].score << "�_" << endl;
			}
		}
	}
};
////////////////////////////////////////////////////////////
int main()
{	
	Subj subj;			//�ȖڃI�u�W�F�N�g�錾

	subj.inpExam();		//���ѓ��̓��\�b�h�̌Ăяo��
	subj.show();		//���ѕ\�����\�b�h�̌Ăяo��

	_getch();
	return 0;
}


