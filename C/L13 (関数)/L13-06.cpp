/*
�ۑ�ԍ��@�FL13-6
���e�@�@�@�F���a�i�����l�j���󂯎���ĉ~�̖ʐρi�����l�j��߂�calcArea�֐����Amain�֐�����Ăяo���B
�@�@�@�@�@�@�֐����󂯎�锼�a��main�֐��œ��͂��āA�֐�����߂�ʐς�main�֐��ŕ\��������̂Ƃ���B
�@�@�@�@�@�@�~������3.1415926
�t�@�C�����FL13-06.cpp
�쐬���@�@�F2015/05/27
�쐬�ҁ@�@�FBayaSea
*/

#include <conio.h>
#include <iostream>
using namespace std;

double calcArea(double radius); 	//�֐��̃v���g�^�C�v�錾

int main()
{
	double radius;		//���a���͗p
	double area;		//�֐�����߂��Ă����ʐϊi�[�p

	cout << "���a�������l�œ��́i��@10.5�j>> ";
	cin >> radius;

	//�֐��̌Ăяo���i���a��n���Ė߂����ʐς��i�[����j

	area = calcArea(radius);

	cout << "�ʐ�=" << area << endl;

	_getch();
	return 0;
}

/*
�֐����FcalcArea
���e�@�F�����Ŏ󂯎�������a�̉~�̖ʐς��v�Z����
�����@�Fdouble radius�@���a
�߂�l�Fdouble area�@�ʐ�
*/
double calcArea(double radius)
{
	double area; 		//hyouzi�֐��Ő錾�����ϐ��i�����ϐ��j

	area = radius * radius * 3.1415926 ;
    
	return area;

	//���̂P�������ł��悢�i�ʐόv�Z�����l��߂��j
    //return radius * radius * 3.1415926;
}
