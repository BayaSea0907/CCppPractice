/*
課題番号　：L21-ExtraSpecial2
内容　　　：regiオブジェクトに、入力した金額を格納して、金種と枚数を表示する。
　　　　　　金額を金種配列の金種で割りながら金種枚数を求めては、金種に対応する枚数配列に格納する。
　　　　　　金種は5桁、枚数は2桁で表示する。
　　　　　　予め、クラス定義で金種配列を金種で、そして枚数配列を0で初期化する。
　　　　　　入力と表示はmain関数で行う。
ファイル名：L21-EX2.cpp
作成日　　：2015/12/03
作成者　　：BayaSea
*/

#include <iomanip>
#include <conio.h>
#include <iostream>
using namespace std;

//レジスタークラス定義
class Regi {
	int kinsyu[9];		//金種用
	int maisu[9];		//枚数用
public:
	//金種、枚数配列に初期値設定
	void initProperty()
	{
		kinsyu[0] = 10000;
		kinsyu[1] = 5000;
		kinsyu[2] = 1000;
		kinsyu[3] = 500;
		kinsyu[4] = 100;
		kinsyu[5] = 50;
		kinsyu[6] = 10;
		kinsyu[7] = 5;
		kinsyu[8] = 1;

		//枚数用配列の初期化
		for (int i = 0; i < 9; i++){
			maisu[i] = 0;
		}
	}
	//金種枚数計算　kingaku：金額
	void calcMaisu(int kingaku)
	{
		//枚数を求める
		for (int i = 0; kingaku != 0; i++)
		{
			//入力した金額が金種より多い場合のみ処理を行う
			//小さい金額を入力する事が多い場合は　ifを入れる
			//if (kingaku >= kinsyu[i]) {}

			maisu[i] = kingaku / kinsyu[i];		//枚数を求める
			kingaku %= kinsyu[i];			//残りの金額を求める
		}
	}

	//金種枚数表示
	void showMaisu(){
		for (int i = 0; i < 9; i++)
		{
			cout << setw(5) << kinsyu[i] << "円"
				 << setw(2) << maisu[i] << "枚" << endl;
		}
	}
};
////////////////////////////////////////////////////////////


int main()
{
	Regi regi;			//レジスターオブジェクト宣言
	int kingaku;		//金額入力用

	regi.initProperty();		//金種枚数配列初期化メソッドの呼び出し

	cout << "金額を入力>> ";
	cin >> kingaku;

	regi.calcMaisu(kingaku);	//金種枚数計算メソッドの呼び出し
	regi.showMaisu();			//金種枚数表示メソッドの呼び出し

	_getch();
	return 0;
}



