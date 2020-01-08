/*------------------------------------------------------------------------
|�ۑ�3 bitfield
| float�^��32bit�ϐ��̓��e��2�i����16�i���ŕ\�����A�܂��A�����r�b�g
| �w�����E��������2�i���ŕ\������v���O���������B
| 2�i���ł̕\���ɂ̓}�X�N�f�[�^���g���B16�i�\���́A�����w��ōs���B
| �����r�b�g�E�w�����E��������2�i���ŕ\���ɂ́A�r�b�g�t�B�[���h�ƃ}�X�N�f�[�^���g���B
|
| 2016/5/23		BayaSea
--------------------------------------------------------------------------*/
#include <iostream>

#define SIGNLENGTH 1
#define INDEXLENGTH 8
#define MANTISSALENGTH 23

using namespace std;

struct BitField
{
	unsigned int mantissa	:23;	
	unsigned int index		:8;
	unsigned int sign		:1;
} bitField;

union FloatPoint
{
	BitField bitField;
	unsigned int uInt;
	float f;
};

int main()
{
	FloatPoint floatPoint;

	unsigned int maskDate  = 0;
	unsigned int souceDate = 1;
	
	cout << "�����l�����(��: -118.625) >>";
	cin >> floatPoint.f;

	cout << "10�i:" << floatPoint.f << "	" 
		 << "16�i:" << hex << floatPoint.uInt  << endl << endl;;

	//�������\��
	cout << floatPoint.bitField.sign << " ";

	//�w�����\��
	for (int i = 0; i < INDEXLENGTH; i++)
	{
		maskDate = souceDate << (INDEXLENGTH - (i + 1));

		(floatPoint.bitField.index & maskDate) ? cout << 1 : cout << 0;
	}

	cout << " ";
	
	//�������\��
	for (int i = 0; i < MANTISSALENGTH; i++)
	{
		maskDate = souceDate << (MANTISSALENGTH - (i + 1));

		(floatPoint.bitField.mantissa & maskDate) ? cout << 1 : cout << 0;
	}

	cout << endl;

	system("pause");
	return 0;
}