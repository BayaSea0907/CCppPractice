/*
�ۑ�ԍ��@�FL21-2
���e�@�@�@�FL21-1�����������āA�e�X�gtest�I�u�W�F�N�g�̔z��Ɋi�[�����T�����̓��_���A
�@�@�@�@�@�@���[�v���g���ē������ʂ�\������B
�@�@�@�@�@�@���_�̊i�[�ƕ\���́Atest�I�u�W�F�N�g�ōs���B
�t�@�C�����FL21-02.cpp
�쐬���@�@�F2015/10/21
�쐬�ҁ@�@�FBayaSea
*/

#include <conio.h>
#include <iostream>
using namespace std;

//�e�X�g�N���X��`
class Test {
	int ten[5];		//���_�z��
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
		//�z��v�f�̕\���@cnt�F���[�v�J�E���^
		for(int cnt = 0; cnt < 5; cnt++)
		{
			cout << ten[cnt] << endl;
		}
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



