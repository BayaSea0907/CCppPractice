/*
�ۑ�ԍ��@�FL24-10
���e�@�@�@�F�p�啶��'A'�`'Z'�Ɖp������'a'�`'z'�̊e�����̂P�O�i������\������B
�@�@�@�@�@�@main�֐��݂̂ōs���B
�t�@�C�����FL24-B10.cpp
�쐬���@�@�F2015/12/10
�쐬�ҁ@�@�FBayaSea
*/

#include <conio.h>
#include <iostream>
using namespace std;

int main()
{
	char c;

	//�p�啶�����l�ϊ��\��
	for (c = 'A'; c <= 'Z'; c++){
		cout << c << "=" << (int)c << endl;
	}

	cout << endl;

	//�p���������l�ϊ��\��
	for (c = 'a'; c <= 'z'; c++){
		cout << c << '=' << (int)c << endl;
	}

	_getch();
	return 0;
}




