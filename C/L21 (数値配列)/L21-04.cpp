/*
�ۑ�ԍ��@�FL21-4
���e�@�@�@�FL21-3�����������āA�e�X�gtest�I�u�W�F�N�g�̔z��ɂT�����̓��_���A
�@�@�@�@�@�@���[�v���g���ē��͂��ĕ\������B
�@�@�@�@�@�@���_�̓��͂ƕ\���́Atest�I�u�W�F�N�g�ōs���B
�t�@�C�����FL21-04.cpp
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
	//���_���̓��\�b�h
	void inpTen()
	{
		//�z��v�f�ɓ��_����́@cnt�F���[�v�J�E���^
		for(int cnt = 0; cnt < 5; cnt++)
		{
			cout << "���_�����>> ";
			cin >> ten[cnt] ;
		}
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

	test.inpTen();		//���_���̓��\�b�h�̌Ăяo��
	test.showTen();		//���_�\�����\�b�h�̌Ăяo��

	_getch();
	return 0;
}



