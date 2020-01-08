/*
課題番号　：L16-ExtraSpecial1
内容　　　：反転reverseオブジェクトに設定した正の整数値の桁を反転した整数値を表示する。
　　　　　　反転はreverseオブジェクトのメソッドで行い、反転した数値はいちどオブジェクトに格納する。
　　　　　　整数値入力と反転数値表示はmain関数で行う。
ファイル名：L16-EX1.cpp
作成日　　：2015/10/15
作成者　　：BayaSea
*/

#include <conio.h>
#include <iostream>
using namespace std;

//反転クラス定義
class Reverse {
	int suti;		//入力数値用
	int rev = 0;	//反転後用（0）
public:
	//数値設定メソッド
	void setSuti(int ssuti)
	{
		suti = ssuti;
	}

	//数値反転メソッド
	void reverseSuti()
	{
		//数値を反転する
		do
		{
			//既に反転設定した値の桁を１つ左にずらす（１桁は10倍値）
			rev *= 10;

			//反転設定した値の一の位に、まだ反転していない入力値の最上位桁の値を設定
			rev +=(suti % 10);

			//まだ反転していない値を求める
			suti /= 10;


		}while(0 < suti);
	}

	//反転数値取得メソッド
	int getRev()
	{
		return rev;
	}
};
////////////////////////////////////////////////////////////
int main()
{
	Reverse reverse;	//反転オブジェクト宣言
	int suti;		//入力用

	cout << "正の整数値を入力>> ";
	cin >> suti;
	reverse.setSuti(suti);	//数値入力メソッドの呼び出し

	reverse.reverseSuti();	//数値反転メソッドの呼び出し
	cout << "反転した値=" << reverse.getRev() << endl;

	_getch();
	return 0;
}
