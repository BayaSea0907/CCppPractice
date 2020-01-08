/*
課題番号　：L21-Special2
内容　　　：testオブジェクトに５つの得点を要素にもつ得点配列を格納して、入力した検索得点があるかど
　　　　　　うかを検索する。検索得点がある場合には“見つかりました”、なかった場合には“見つかりません
　　　　　　でした”と表示する。
　　　　　　得点配列は、main関数で宣言と同時に初期化する。初期値は、3, 10, 6, 8, 14　の順。
　　　　　　検索するにあたり、予め、検索結果用変数を０（見つからない）で初期化しておき、入力した検
　　　　　　索得点があった場合には、検索結果用変数を検索結果（１：あった）に変更する。
　　　　　　得点を検索する繰返し制御では、break文を使わない。
　　　　　　入力と表示は、main関数で行う。
　　　　　　表示は、検索結果の値（１あるいは０）を判別して、結果を表示する。
ファイル名：L21-S2.cpp
作成日　　：2015/11/22
作成者　　：BayaSea
*/

#include <conio.h>
#include <iostream>
using namespace std;

//テストクラス定義
class Test {
	int ten[5];		//得点配列
public:
	//得点設定　n[]：得点配列
	void setTen(int n[]){
		//配列に得点を格納
		for (int i = 0; i < 5; i++){
			ten[i] = n[i];
		}
	}

	//得点検索取得　score：検索得点
	int getSearchTen(int score){
		int result = 0;			//検索結果用（0）（０：見つからない　１：見つけた）

		//配列を検索
		for (int i = 0; i < 5 && result == 0; i++){

			//検索値を見つけた場合
			if (ten[i] == score)
			{	
				//検索結果を見つけた状態にする
				result = 1;
			}
		}
		return result;
	}
};
////////////////////////////////////////////////////////////
int main()
{
	Test test;							//テストオブジェクト宣言
	int ten[5] = { 3, 10, 6, 8, 14 };	//配列宣言と同時の初期化
	int score;							//検索得点入力用

	test.setTen(ten);		//得点設定メソッドの呼び出し

	cout << "検索得点の入力>> ";
	cin >> score;

	//検索結果の表示
	//得点検索取得メソッドの呼び出し
	if (test.getSearchTen(score)){
		cout << "見つかりました" << endl;
	}
	else{
		cout << "見つかりませんでした" << endl;
	}

	_getch();
	return 0;
}

