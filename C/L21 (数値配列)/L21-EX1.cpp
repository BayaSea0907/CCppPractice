/*
課題番号　：L21-ExtraSpecial1
内容　　　：seqオブジェクトでフィボナッチ数列（0 1 1 2 3 5 8 13 21 34）を作成して表示する。
　　　　　　数列の数値は１０個までとする。
　　　　　　フィボナッチ数列を格納する配列は、プロパティとして用意する。
　　　　　　予め、フィボナッチ数列（配列）の要素[0]と[1]には、0と1を初期値として格納する。
　　　　　　表示はオブジェクトで行い、数列の各数値は３桁表示する。
ファイル名：L21-EX1.cpp
作成日　　：2015/12/03
作成者　　：BayaSea
*/

#include <iomanip>
#include <conio.h>
#include <iostream>
using namespace std;

//数列クラス定義
class Sequence {
	int ary[10];		//フィボナッチ数列用
public:
	//フィボナッチ数列[0]と[1]に初期値設定
	void initAry(){
		ary[0] = 0;
		ary[1] = 1;
	}
	//フィボナッチ数列作成
	void createAry(){
		for (int i = 2; i < 10; i++) {
			ary[i] = ary[i-2] + ary[i-1];
		}
	}
	//フィボナッチ数列表示
	void showAry(){
		for (int i = 0; i < 10; i++){
			cout << setw(3) << ary[i];
		}
	}
};
////////////////////////////////////////////////////////////
int main()
{
	Sequence seq;		//数列オブジェクト宣言

	seq.initAry();		//フィボナッチ数列初期化メソッドの呼び出し
	seq.createAry();	//フィボナッチ数列作成メソッドの呼び出し
	seq.showAry();		//フィボナッチ数列表示メソッドの呼び出し

	_getch();
	return 0;
}


