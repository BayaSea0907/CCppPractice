/*
�ۑ�ԍ��@�FL11-11
���e�@�@�@�F���͂��������l�A�����l�A�������\������B
�@�@�@�@�@�@�P��cin�ł��ׂĂ̒l����͂���B�������string�^�ň����B
�t�@�C�����FL11-B11.cpp
�쐬���@�@�F2015/04/30
�쐬�ҁ@�@�FBayaSea
*/

#include <string>
#include <conio.h>
#include <iostream>
using namespace std;

int main()
{
	//�ϐ��̐錾
	int num;		//�����l�i�[�p
	double zisu;       //�����l�i�[�p
	string str;		//������i�[�p

	cout << "�����l�A�����l�A���������́i��@10 20.5 game�j" << endl << ">> ";

	//�����l�A�����l�A������̓���
	cin >> num >> zisu >> str;


	//�i�[���Ă��鐮���l�A�����l�A������̕\��
	cout << "�����l=" << num << " �����l=" << zisu << " ������=" << str << endl;


	_getch();
	return 0;
}
