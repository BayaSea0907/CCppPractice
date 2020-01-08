/*
課題番号　：L21-7
内容　　　：L21-4を書き換えて、testオブジェクトに５件分の得点を要素にもつ配列を格納して、配列要素
　　　　　　（得点）を降順ソートする。ソート前後の配列要素を表示する。
　　　　　　オブジェクトの得点配列を並び替える。
　　　　　　降順ソートとは、大きい値が前に、小さい値が後にくるように並び変えることをいう。
　　　　　　５件分の得点をもつ配列は、main関数で予め配列を宣言すると同時に初期化する。
　　　　　　表示はオブジェクトで行う。
ファイル名：L21-A7.cpp
作成日　　：2015/11/12
作成者　　：BayaSea
*/

#include <iomanip>
#include <conio.h>
#include <iostream>
using namespace std;

//テストクラス定義
class Test {
	int ten[5];		//得点配列の宣言
public:
	//得点設定　n[]：得点配列
	void setTen(int n[])
	{
		//配列要素に得点を設定　cnt：ループカウンタ
		for (int cnt = 0; cnt < 5; cnt++)
		{
			ten[cnt] = n[cnt];
		}
	}
	//降順ソート
	void sortTen(){
		int taihi;	//一時退避用

		//比較する基準要素の制御
		//i：基準用ループカウンタ
		for (int i = 0; i < 4; i++){

			//比較対象要素の制御　j：ループカウンタ
			for (int j = i + 1; j < 5 ; j++){
				//基準要素と比較対象要素の値の交換
				if (ten[i] < ten[j]){
					taihi = ten[i];
					ten[i] = ten[j];
					ten[j] = taihi;
				}
			}
		}
	}
	//得点表示
	void showTen(){
		//配列要素の表示　i：ループカウンタ
		for (int i = 0; i < 5; i++){
			cout << setw(3) << ten[i];
		}

	}
};
////////////////////////////////////////////////////////////


int main()
{
	Test test;							//テストオブジェクト宣言
	int ten[5] = { 3, 5, 20, 7, 15 };	//得点配列宣言と同時の初期化

	test.setTen(ten);	//得点設定メソッドの呼び出し

	cout << "ソート前：";
	test.showTen();		//得点表示メソッドの呼び出し

	test.sortTen();		//降順ソートメソッドの呼び出し

	cout << endl << "ソート後：";
	test.showTen();		//得点表示メソッドの呼び出し

	_getch();
	return 0;
}


