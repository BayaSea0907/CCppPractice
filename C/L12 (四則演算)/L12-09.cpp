/*
�ۑ�ԍ��@�FL12-9
���e�@�@�@�F��������Q���͂��āA���̕�����ǂ��������Z�i�{�j�����������\������B
�t�@�C�����FL12-09.cpp
�쐬���@�@�F2015/05/13
�쐬�ҁ@�@�FBayaSea
*/

//���s���Ɋm�F���邱�ƁF
//��������ǂ��������Z����Ƃǂ��Ȃ�ł��傤���H
//str1�ɑ�������������str2�ɑ�����������񂪂Ȃ����āA��̕�����Ƃ��ĕ\������܂����B

#include <string>
#include <conio.h>
#include <iostream>
using namespace std;

int main()
{
	string str1;		//string�^������
	string str2;		//string�^������
	string str3;		//string�^������

	cout << "��������Q���́i��@game CU�j>> ";
	cin >> str1 >> str2;

	//������̌v�Z
	str3 =   str1 + str2           ;

	cout << "���Z����������=" << str3 << endl;

	_getch();
	return 0;
}
