/*
�ۑ�ԍ��@�FL13-7
���e�@�@�@�Fstring�^�̕�������󂯎���ĕ�����"CU"��t���������������߂��֐����Amain�֐�����Ăяo���B
�@�@�@�@�@�@�֐����󂯎�镶�����main�֐��œ��͂��āA�֐�����߂镶�����main�֐��ŕ\������B
�t�@�C�����FL13-07.cpp
�쐬���@�@�F2015/05/27
�쐬�ҁ@�@�FBayaSea
*/

#include <string>
#include <conio.h>
#include <iostream>
using namespace std;

string addStr(string str); 	//�֐��̃v���g�^�C�v�錾

int main()
{
	string str;		//string�^������
	string ret;		//�֐�����߂��Ă���string�^������

	cout << "���������́i��@game�j>> ";
	cin >> str;

	ret = addStr(str);		//�֐��̌Ăяo���i�������n���Ė߂�����������i�[����j


	cout << "������=" << ret << endl;

	_getch();
	return 0;
}

/*
�֐����FaddStr
���e�@�F�����Ŏ󂯎����������ɕ������t��������
�����@�Fstring str�@������
�߂�l�Fstring�@������
*/
string addStr(string str)
{
	string strWa; 		//addStr�֐��Ő錾�����ϐ��i�����ϐ��j

	strWa = "CU" + str;


	return strWa;

	//���̂P�������ł��悢�i�������t���������������߂��j
    //return str + "CU";
}
