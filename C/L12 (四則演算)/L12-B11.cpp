/*
�ۑ�ԍ��@�FL12-11
���e�@�@�@�F���͂��������l���A�����_�ȉ���P�ʂ̒l���l�̌ܓ����������l�ŕ\������B
�t�@�C�����FL12-B11.cpp
�쐬���@�@�F2015/05/13
�쐬�ҁ@�@�FBayaSea
*/

#include <conio.h>
#include <iostream>
using namespace std;

int main()
{
	double zisu; 		//���͗p
	int num; 		    //�l�̌ܓ��������ʊi�[�p

	cout << "�����l�̓���>> ";
	cin >> zisu;


	num = (int)(zisu + 0.5); 	//�l�̌ܓ�

	cout << "�l�̌ܓ����������l=" << num << endl;

	_getch();
	return 0;
}
