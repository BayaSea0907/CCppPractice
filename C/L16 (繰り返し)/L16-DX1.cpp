/*
課題番号　：L16-DeluxeSpecial1
内容　　　：ユークリッド互除法eucオブジェクトに２つの整数値（０以外）を設定した後、ユークリッドの
　　　　　　互除法を使って最大公約数を求める。
　　　　　　整数値入力と最大公約数表示はmain関数で行い、eucオブジェクトで計算した最大公約数はいち
　　　　　　どオブジェクトに格納しておくものとする。
　　　　　　またuiオブジェクトでの整数値入力は、０以外の整数値が入力されるまで繰返し入力する。
　　　　　　ユークリッド互除法を使うと、最大公約数は除数（割る数）用の変数に格納される。
			   例）２３１と１５の最大公約数は３
					  ２３１　÷　１５　＝　１５　・・・　６
					    １５　÷　　６　＝　　２　・・・　３
					      ６　÷　　３　＝　　０
ファイル名：L16-DX1.cpp
作成日　　：2015/11/22
作成者　　：BayaSea
*/

#include <conio.h>
#include <iostream>
using namespace std;

//ユークリッド互除法クラス定義
class Euclidean {
	int dividend;		//被除数（割られる数）
	int divisor;		//除数（割る数）
public:
	//整数値設定メソッド
	void setVar(int sdividend, int sdivisor)
	{
		dividend = sdividend;	//割られる数
		divisor = sdivisor;		//割る数
	}

	//最大公約数計算メソッド
	void calcGrcomDiv()
	{
		int remainder;		//余り用
		int taihi;			//退避用

		//小さい方の数を除数（divisor）に入れ替える
		if(divisor > dividend)
		{
			taihi = divisor;
			divisor = dividend;
			dividend = taihi;
		}

		//ユークリッドの互除法（余りが０になるまで）
		while(1)
		{
			remainder = dividend % divisor;		//余りを求める

			//余りが0になったらループをやめる
			if (remainder == 0){
				break;
			}
			dividend = divisor;				//除を被除数に入れる
			/*ﾘﾒｲﾝﾀﾞｰ比較してるんだから
			ﾘﾒｲﾝﾀﾞｰ求めたところの真下にif持ってきたほうがいい
			if (remainder == 0){
				break;
			}*/
			divisor = remainder;		//余りを除数に入れる
		}
	}

	//最大公約数取得メソッド
	int getGrComDiv()
	{
		return divisor;
	}
};
////////////////////////////////////////////////////////////
int main()
{
	Euclidean euc;		//ユークリッド互除法オブジェクト宣言
	int dividend;		//被除数（割られる数）入力用
	int divisor;		//除数（割る数）入力用

	do{
		cout << "０以外の整数値を２つ入力(例 10 20) >> ";
		cin >> dividend >> divisor;
	//どちらかの数値が0だったら入力し直し
	}while((dividend == 0) || (divisor == 0));

	euc.setVar(dividend, divisor);		//整数値設定メソッド呼び出し

	euc.calcGrcomDiv();					//最大公約数計算メソッドの呼び出し

	cout << "最大公約数=" << euc.getGrComDiv() << endl;

	_getch();
	return 0;
}
