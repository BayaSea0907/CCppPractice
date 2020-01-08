/*
�ۑ�ԍ��@�FL23-12
���e�@�@�@�Fhealth�I�u�W�F�N�g�ɁA�T�l���̌��f�\���̔z��i�v�f���T�j���i�[���āA�g���͍~���ɁA����
			�g���������ꍇ�ɂ͑̏d�������ɕ��ёւ��ĕ\������B
			���f�\���̂̃����o�́A���O�Ɛg���A�̏d�B
			�\���̔z���main�֐��ŏ���������B
			�v�f����const�w��q���g���Ē�`����B
			�\���̔z��̃\�[�g�O�ƃ\�[�g��̏�Ԃ�health�I�u�W�F�N�g�ŕ\������B
			�\���́A�I�u�W�F�N�g�ōs���B
�t�@�C�����FL23-B12.cpp
�쐬���@�@�F2015/11/26
�쐬�ҁ@�@�FBayaSea
*/

#include <iomanip>		//�}�j�s�����[�^�p
#include <string>		//�����񑀍�p
#include <conio.h>
#include <iostream>
using namespace std;

//���f�\���̂̒�`
struct Exam {
	string name;	//���O
	int tall;		//�g��
	int weight;		//�̏d
};

const int MAX = 5;	//�\���̔z��v�f��

//���N�N���X��`
class Health {
	Exam exam[MAX];		//���f�\���̔z��
public:
	//���f�ݒ�@ex[]�F���f�\���̔z��
	void setExam(Exam ex[])
	{
		for (int i = 0; i < MAX; i++)
		{
			exam[i] = ex[i];
		}
	}

	//���f�\�[�g
	void sortExam()
	{
		Exam taihi;		//�ޔ�p�\����

		//�\�[�g��2�d���[�v
		for (int i = 0; i < MAX - 1; i++)
		{
			for (int j = i + 1; j < MAX; j++)
			{
				//�g�����~���ɕ��ёւ��A�g���������������ꍇ�̏d�̏����ɕ��ёւ�
				if ((exam[i].tall < exam[j].tall) || 
					((exam[i].tall == exam[j].tall) && (exam[i].weight > exam[j].weight))) 
				{
					taihi = exam[i];
					exam[i] = exam[j];
					exam[j] = taihi;
				}
			}
		}
	}

	//���f�\��
	void show()
	{
		for (int i = 0; i < MAX; i++){
			cout << "[" << i << "]" << setw(10) << left << exam[i].name << setw(4) << right << exam[i].tall << "cm " << setw(4) << exam[i].weight << "kg" << endl;
		}
	}

};
////////////////////////////////////////////////////////////
int main()
{
	Health health;		//health�I�u�W�F�N�g

	//���f�\���̔z��錾
	Exam exam[MAX] = {
		{ "GUNMO", 160, 80 },
		{ "BERZEB",80, 30 },
		{ "HARY", 170, 70 },
		{ "TRINITY", 160, 50 },
		{ "ROBO", 170, 90 }
	};

	health.setExam(exam);		//���f�ݒ胁�\�b�h�Ăяo��
	health.show(); 				//�\�[�g�O�i���f�\���j���\�b�h�Ăяo��
	cout << endl;				//���₷��������s

	health.sortExam();			//�\�[�g���\�b�h�Ăяo��
	health.show(); 				//�\�[�g��i���f�\���j���\�b�h�Ăяo��

	_getch();
	return 0;
}
