/*
�ۑ�ԍ��@�FL21-1
���e�@�@�@�F�e�X�gtest�I�u�W�F�N�g�̔z��Ɋi�[�����T�����̓��_��\������B
�@�@�@�@�@�@�z��Ɋi�[���链�_�́A8, 33, 96, 2, 48
�@�@�@�@�@�@���[�v�͎g�p���Ȃ��B
�@�@�@�@�@�@���_�̊i�[�ƕ\���́Atest�I�u�W�F�N�g�ōs���B
�t�@�C�����FL21-01.cpp
�쐬���@�@�F2015/10/21
�쐬�ҁ@�@�FBayaSea
*/

//�v���O���������������Ċm�F���邱�ƁF
//���z��̗v�f����4�ɂ��Đ錾����Ƃǂ��Ȃ�ł��傤���H
//A.�G���[���N������

//���z��̗v�f����6�ɂ��Đ錾����Ƃǂ��Ȃ�ł��傤���H
//A.���ׂĕ\�������

#include <conio.h>
#include <iostream>
using namespace std;

//�e�X�g�N���X��`
class Test {
	int ten[5];		//���_�z��錾
public:
	//���_�ݒ胁�\�b�h
	void setTen()
	{
		//�z��v�f�ɓ��_���i�[
		ten[0] = 8;
		ten[1] = 33;
		ten[2] = 96;
		ten[3] = 2;
		ten[4] = 48;
	}

	//���_�\�����\�b�h
	void showTen()
	{
		//�z��v�f�̕\��
		cout << ten[0] << endl;
		cout << ten[1] << endl;
		cout << ten[2] << endl;
		cout << ten[3] << endl;
		cout << ten[4] << endl;
	}
};
////////////////////////////////////////////////////////////
int main()
{
	Test test;			//�e�X�g�I�u�W�F�N�g�錾

	test.setTen();		//���_�ݒ胁�\�b�h�̌Ăяo��
	test.showTen();		//���_�\�����\�b�h�̌Ăяo��

	_getch();
	return 0;
}

