/*
�ۑ�ԍ��@�FL12-8
���e�@�@�@�F�����l����͂��āA���̒l�𔼌a�Ƃ���~�̒��a�Ɩʐς������l�ŕ\������B
�@�@�@�@�@�@�~������3.1415926
�@�@�@�@�@�@�v�Z�ŋ��߂����a�Ɩʐς́A���ꂼ��̕ϐ��Ɋi�[����B
�t�@�C�����FL12-08.cpp
�쐬���@�@�F2015/05/13
�쐬�ҁ@�@�FBayaSea
*/

#include <conio.h>
#include <iostream>
using namespace std;

int main()
{
	double radius;		//���a
	double diameter;	//���a
	double area;		//�ʐ�

	cout << "���a�������l�œ��́i��@10.5�j>> ";
	cin >> radius;

	//���a�̌v�Z
	diameter = radius + radius;

	//�ʐς̌v�Z
	area = radius * radius * 3.1415926 ;

	printf(% 10d, area);

	cout << "���a=" << diameter << endl;
	cout << "�ʐ�=" << area << endl;

	_getch();
	return 0;
}
