/*
�ۑ�ԍ��@�FL12-10
���e�@�@�@�FL12-8�̂��ׂĂ̕ϐ��𐮐��^�ɕύX����ƃR���p�C���G���[��������B
�@�@�@�@�@�@�R���p�C���G���[�����������ɁA���a�Ɩʐς𐮐��l�ŕ\���ł���悤�Ɍ^�𑵂��ďC������B
�t�@�C�����FL12-A10.cpp
�쐬���@�@�F2015/05/13
�쐬�ҁ@�@�FBayaSea
*/

#include <conio.h>
#include <iostream>
using namespace std;

int main()
{
	int radius;		//���a
	int diameter;	//���a
	int area;		//�ʐ�

	//���a�̓���
	cout << "���a�𐮐��l�œ��́i��@10�j>> ";
	cin >> radius;

	//���a�̌v�Z
	diameter = radius + radius;

	//�ʐς̌v�Z
	area = (int)((double)(radius * radius) * 3.1415926);

	//���a�Ɩʐς̕\��
	cout << "���a=" << diameter << endl;
	cout << "�ʐ�=" << area << endl;

	_getch();
	return 0;
}
