/*
�ۑ�ԍ��@�FL21-3
���e�@�@�@�FL21-2�����������āA�e�X�gtest�I�u�W�F�N�g�̔z��ɂT�����̓��_����͂��ĕ\������B
�@�@�@�@�@�@���_�̓��͂ɂ́A���[�v���g��Ȃ��B
�@�@�@�@�@�@���_�̓��͂ƕ\���́Atest�I�u�W�F�N�g�ōs���B
�t�@�C�����FL21-03.cpp
�쐬���@�@�F2015/10/21
�쐬�ҁ@�@�FBayaSea
*/

#include <conio.h>
#include <iostream>
using namespace std;

//�e�X�g�N���X��`
class Test {
	int ten[5];	//���_�z��
public:
	//���_���̓��\�b�h
	void inpTen()
	{
		//�z��v�f�ɓ��_�����
		cout << "���_�����>> ";
		cin >> ten[0];

		cout << "���_�����>> ";
		cin >> ten[1];

		cout << "���_�����>> ";
		cin >> ten[2];

		cout << "���_�����>> ";
		cin >> ten[3];

		cout << "���_�����>> ";
		cin >> ten[4];
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


