/*
�ۑ�ԍ��@�FL26-DeluxeSpecial3
���e�@�@�@�Fchar�^�����z��ɓ��͂����Q�̕�����i�ő啶�����P�O�j���A���������̏����Ŕ�r�����召
�@�@�@�@�@�@�֌W��\������B
�@�@�@�@�@�@������̑召��r�́A�ŏ��ɓ��͂����P�ꂪ�@"!"�@�ɂȂ�܂ŌJ�Ԃ��B
�@�@�@�@�@�@������̔�r�ɂ́A�������r�p�W���֐�strcmp�֐����g���B
�@�@�@�@�@�@main�֐��݂̂ōs���B
�t�@�C�����FL26-DX3.cpp
�쐬���@�@�F2016/1/28
�쐬�ҁ@�@�FBayaSea
*/

//�m�F���邱�ƁF
//����������r����֐��́A���ɕW���֐��ŗp�ӂ���Ă��邱�Ƃ��m�F���Ȃ����B
//A.�m�F���܂����B

#include <conio.h>
#include <iostream>
using namespace std;
int main()
{
	char str1[11];		//�ő�10�������i�[
	char str2[11];		//�ő�10�������i�[
	int ret;			//�߂�l�p
	

	while (1){
		cout << "���������́i�ő�P�O�����j�j�F�I���� !>> ";
		cin >> str1;
		if (strcmp("!", str1) == 0)break;

		cout << "���������́i�ő�P�O�����j>> ";
		cin >> str2;

		ret = strcmp(str1, str2);

		switch (ret)
		{	
			case -1: cout << str1 << "<" << str2 << endl;
				break;
			case 1: cout << str1 << ">" << str2 << endl;
				break;
			case 0: cout << str1 << "=" << str2 << endl;
				break;
		}
	}
	_getch();
	return 0;
}
