/*
�ۑ�ԍ��@�FL11-10
���e�@�@�@�F�Q�̕�����i�X�����ȓ��j����͂��āA�����̕������\������B
�@�@�@�@�@�@�P��cin�ŗ����̕��������͂���B�������string�^�ň����B
�t�@�C�����FL11-A10.cpp
�쐬���@�@�F2015/04/30
�쐬�ҁ@�@�FBayaSea
*/

#include <string>
#include <conio.h>
#include <iostream>
using namespace std;

int main()
{
	//��������i�[����̈�̐錾
	string str1;
	string str2;

	cout << "�Q�̕��������́i��@game jec�j" << endl << ">> ";

	//�Q�̕�������P�x�ɓ���
	cin >> str1 >> str2;

	//�i�[����Ă��镶����̕\��
	cout << "�������" << str1 << "��" << str2 << "�ł�";

	_getch();
	return 0;
}
