/*------------------------------------------------------------------------
|課題3 bitfield
| float型の32bit変数の内容を2進数と16進数で表示し、また、符号ビット
| 指数部・仮数部を2進数で表示するプログラムを作る。
| 2進数での表示にはマスクデータを使う。16進表示は、書式指定で行う。
| 符号ビット・指数部・仮数部の2進数で表示には、ビットフィールドとマスクデータを使う。
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
	
	cout << "実数値を入力(例: -118.625) >>";
	cin >> floatPoint.f;

	cout << "10進:" << floatPoint.f << "	" 
		 << "16進:" << hex << floatPoint.uInt  << endl << endl;;

	//符号部表示
	cout << floatPoint.bitField.sign << " ";

	//指数部表示
	for (int i = 0; i < INDEXLENGTH; i++)
	{
		maskDate = souceDate << (INDEXLENGTH - (i + 1));

		(floatPoint.bitField.index & maskDate) ? cout << 1 : cout << 0;
	}

	cout << " ";
	
	//仮数部表示
	for (int i = 0; i < MANTISSALENGTH; i++)
	{
		maskDate = souceDate << (MANTISSALENGTH - (i + 1));

		(floatPoint.bitField.mantissa & maskDate) ? cout << 1 : cout << 0;
	}

	cout << endl;

	system("pause");
	return 0;
}