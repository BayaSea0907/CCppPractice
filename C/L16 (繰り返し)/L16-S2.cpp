/*
課題番号　：L16-Special2
内容　　　：無限ループを使って、０が入力されるまで入力した値の絶対値を表示する。
　　　　　　数値入力と絶対値表示の繰返し制御（while文）は、main関数で行う。
　　　　　　ただし、入力した値が0の場合には、break文を使って無限ループを抜けてもよい。
ファイル名：L16-S2.cpp
作成日　　：2015/10/01
作成者　　：BayaSea
*/

#include <conio.h>
#include <iostream>
using namespace std;

//絶対値対応クラス定義
class Abs {
public:
	//絶対値取得メソッド
	int getAbs(int n)
	{
		//絶対値が負の値か調べる
		if (n < 0)
		{	
			n *= -1;			//絶対値が負の値だった場合、整数に戻す
		}			
		return n;				//絶対値が整数だった場合、そのまま返す
	}	
};
////////////////////////////////////////////////////////////
int main()
{
	Abs abs;					//絶対値対応オブジェクト宣言
	int num;					//入力用
		
	//無限ループ
	while(1)
	{
		cout << "整数値の入力（終了　0）>> ";
		cin >> num;

		//入力数値が０の場合、強制的にループを抜ける
		if (num == 0)
		{
			cout << endl << "ループを抜けます..." << endl;
			break;
		}
		cout << "絶対値=" << abs.getAbs(num) << endl;		//絶対値表示メソッドの呼び出し
	}

	_getch();
	return 0;
}


