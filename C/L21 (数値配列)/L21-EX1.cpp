/*
�ۑ�ԍ��@�FL21-ExtraSpecial1
���e�@�@�@�Fseq�I�u�W�F�N�g�Ńt�B�{�i�b�`����i0 1 1 2 3 5 8 13 21 34�j���쐬���ĕ\������B
�@�@�@�@�@�@����̐��l�͂P�O�܂łƂ���B
�@�@�@�@�@�@�t�B�{�i�b�`������i�[����z��́A�v���p�e�B�Ƃ��ėp�ӂ���B
�@�@�@�@�@�@�\�߁A�t�B�{�i�b�`����i�z��j�̗v�f[0]��[1]�ɂ́A0��1�������l�Ƃ��Ċi�[����B
�@�@�@�@�@�@�\���̓I�u�W�F�N�g�ōs���A����̊e���l�͂R���\������B
�t�@�C�����FL21-EX1.cpp
�쐬���@�@�F2015/12/03
�쐬�ҁ@�@�FBayaSea
*/

#include <iomanip>
#include <conio.h>
#include <iostream>
using namespace std;

//����N���X��`
class Sequence {
	int ary[10];		//�t�B�{�i�b�`����p
public:
	//�t�B�{�i�b�`����[0]��[1]�ɏ����l�ݒ�
	void initAry(){
		ary[0] = 0;
		ary[1] = 1;
	}
	//�t�B�{�i�b�`����쐬
	void createAry(){
		for (int i = 2; i < 10; i++) {
			ary[i] = ary[i-2] + ary[i-1];
		}
	}
	//�t�B�{�i�b�`����\��
	void showAry(){
		for (int i = 0; i < 10; i++){
			cout << setw(3) << ary[i];
		}
	}
};
////////////////////////////////////////////////////////////
int main()
{
	Sequence seq;		//����I�u�W�F�N�g�錾

	seq.initAry();		//�t�B�{�i�b�`���񏉊������\�b�h�̌Ăяo��
	seq.createAry();	//�t�B�{�i�b�`����쐬���\�b�h�̌Ăяo��
	seq.showAry();		//�t�B�{�i�b�`����\�����\�b�h�̌Ăяo��

	_getch();
	return 0;
}


