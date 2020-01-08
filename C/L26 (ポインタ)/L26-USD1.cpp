/*
課題番号　：L26-UltraSperDeluxe1
内容　　　：valoprオブジェクトにint型配列の各要素のアドレスを格納したポインタ配列（要素数５）を
　　　　　　渡します。
　　　　　　そして、ポインタ配列を使ってint型配列を昇順に並び替えて、ソート前のint型配列とポインタ
　　　　　　配列を使ってソートした後のint型配列を表示するプログラム。
　　　　　　int型配列を並び替えてはいけない。
　　　　　　main関数で、int型配列（要素数５）は宣言と同時に初期化する。
　　　　　　表示はmain関数で行い、各数値は２桁で表示する　cout << setw(2)。
　　　　　　また、ポインタ配列の要素（アドレス）を表示するわけではない。
　　　　　　なお、ポインタ配列とは、要素にアドレスを格納する配列のことをいう。
ファイル名：L26-USD1.cpp
作成日　　：2016/1/28
作成者　　：BayaSea
*/

#include <iomanip>
#include <conio.h>
#include <iostream>
using namespace std;

const int MAX = 5;		//配列要素数

//値操作クラス定義
class ValOpr {
public:
	//ソート
	//実体値配列の値を昇順に並び変える代わりに、ポインタ配列を並び替える
	//	*p[]　ポインタ配列の先頭アドレス
	//	戻り値：なし
	void sort(int *p[]){
		int *taihip;		//一時退避用ポインタ

		for (int i = 0; i < MAX; i++){
			for (int j = i + 1; j < MAX; j++){
				if (*p[i] > *p[j]){
					taihip = p[i];
					p[i] = p[j];
					p[j] = taihip;
				}
			}
		}
	}
};
////////////////////////////////////////////////////
int main()
{
	ValOpr valopr;
	int num[MAX] = { 5, 3, 8, 1, 2 };	//実体値配列
	int *p[MAX];						//ポインタ配列

	//実体値配列の各要素のアドレスを、ポインタ配列の同じ番号の要素に格納する
	for (int i = 0; i < MAX; i++){
		p[i] = &num[i];
	}

	//ソートメソッド呼び出し（ポインタ配列を使ってソート）
	valopr.sort(p);

	//実体値配列の表示
	cout << "ソート前 :";

	for (int i = 0; i < MAX; i++){
		cout << setw(2) << num[i];
	}
	cout << endl;

	//ソート後の実体値配列の表示
	cout << "ソート後 :";
	for (int i = 0; i < MAX; i++){
		cout << setw(2) << *p[i];
	}
	cout << endl;

	_getch();
	return 0;
}
