/*
�ۑ�ԍ��@�FL26-UltraSperDeluxe1
���e�@�@�@�Fvalopr�I�u�W�F�N�g��int�^�z��̊e�v�f�̃A�h���X���i�[�����|�C���^�z��i�v�f���T�j��
�@�@�@�@�@�@�n���܂��B
�@�@�@�@�@�@�����āA�|�C���^�z����g����int�^�z��������ɕ��ёւ��āA�\�[�g�O��int�^�z��ƃ|�C���^
�@�@�@�@�@�@�z����g���ă\�[�g�������int�^�z���\������v���O�����B
�@�@�@�@�@�@int�^�z�����ёւ��Ă͂����Ȃ��B
�@�@�@�@�@�@main�֐��ŁAint�^�z��i�v�f���T�j�͐錾�Ɠ����ɏ���������B
�@�@�@�@�@�@�\����main�֐��ōs���A�e���l�͂Q���ŕ\������@cout << setw(2)�B
�@�@�@�@�@�@�܂��A�|�C���^�z��̗v�f�i�A�h���X�j��\������킯�ł͂Ȃ��B
�@�@�@�@�@�@�Ȃ��A�|�C���^�z��Ƃ́A�v�f�ɃA�h���X���i�[����z��̂��Ƃ������B
�t�@�C�����FL26-USD1.cpp
�쐬���@�@�F2016/1/28
�쐬�ҁ@�@�FBayaSea
*/

#include <iomanip>
#include <conio.h>
#include <iostream>
using namespace std;

const int MAX = 5;		//�z��v�f��

//�l����N���X��`
class ValOpr {
public:
	//�\�[�g
	//���̒l�z��̒l�������ɕ��ѕς������ɁA�|�C���^�z�����ёւ���
	//	*p[]�@�|�C���^�z��̐擪�A�h���X
	//	�߂�l�F�Ȃ�
	void sort(int *p[]){
		int *taihip;		//�ꎞ�ޔ�p�|�C���^

		for (int i = 0; i < MAX; i++){
			for (int j = i + 1; j < MAX; j++){
				if (*p[i] > *p[j]){
					taihip = p[i];
					p[i] = p[j];
					p[j] = taihip;
				}
			}
		}
	}
};
////////////////////////////////////////////////////
int main()
{
	ValOpr valopr;
	int num[MAX] = { 5, 3, 8, 1, 2 };	//���̒l�z��
	int *p[MAX];						//�|�C���^�z��

	//���̒l�z��̊e�v�f�̃A�h���X���A�|�C���^�z��̓����ԍ��̗v�f�Ɋi�[����
	for (int i = 0; i < MAX; i++){
		p[i] = &num[i];
	}

	//�\�[�g���\�b�h�Ăяo���i�|�C���^�z����g���ă\�[�g�j
	valopr.sort(p);

	//���̒l�z��̕\��
	cout << "�\�[�g�O :";

	for (int i = 0; i < MAX; i++){
		cout << setw(2) << num[i];
	}
	cout << endl;

	//�\�[�g��̎��̒l�z��̕\��
	cout << "�\�[�g�� :";
	for (int i = 0; i < MAX; i++){
		cout << setw(2) << *p[i];
	}
	cout << endl;

	_getch();
	return 0;
}
