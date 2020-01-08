/*
課題番号　：L23-11
内容　　　：subjオブジェクトに入力した数人分の成績構造体配列（要素数５）を格納して、登録人数とそれ
　　　　　　ぞれの成績を表示する。
　　　　　　成績構造体のメンバは、学籍番号と点数。
　　　　　　学籍番号に０以下の値が入力されるまで、点数（０点以上１００点以下）の入力を繰り返す。
　　　　　　プログラムを簡潔にするために、break文やontinue文を使ってよい。
　　　　　　入力と表示は、オブジェクトで行う。
ファイル名：L23-A11.cpp
作成日　　：2015/11/19
作成者　　：BayaSea
*/

#include <string>		//文字列操作用
#include <conio.h>
#include <iostream>
using namespace std;

//成績構造体定義
struct Exam {
	int id;		//学籍番号
	int score;	//点数
};

const int MAX = 5;	//構造体配列要素数

//科目クラス定義
class Subj {
	Exam exam[MAX];		//成績構造体配列
	int man = 0;		//登録人数
public:
	//成績入力
	void inpExam()
	{
		Exam temp;		//入力情報確認用

		//全ての構造体配列に入力する
		while (man < MAX)
		{
			//学籍番号入力
			cout << man + 1 << "人目の学籍番号の入力(終了は0以下)>> ";
			cin >> temp.id;

			//学籍番号が0以下の場合入力をやめる
			if (temp.id <= 0){break;}

			//点数入力
			while (true)
			{
				cout << man + 1 << "人目の点数の入力>> ";
				cin >> temp.score;

				//点数範囲判定 0~100の範囲内だった場合
				if ((0 <= temp.score) && (temp.score <= 100)){
					exam[man] = temp;
					break;
				}
				//範囲外だった場合
				else{
					cout << "点数が0以上100以下ではありません。" << "再入力してください" << endl;
				}
			}
			man++;
		}
	}

	//表示
	void show()
	{
		//１人目の学籍番号が0以下だったら
		if (man == 0){
			cout << "１人も登録されていません" << endl;
		}
		else{
			cout << "登録人数=" << man << endl;

			//登録情報の表示
			for (int i = 0; i < man; i++){
				cout << exam[i].id << "番 = " << exam[i].score << "点" << endl;
			}
		}
	}
};
////////////////////////////////////////////////////////////
int main()
{	
	Subj subj;			//科目オブジェクト宣言

	subj.inpExam();		//成績入力メソッドの呼び出し
	subj.show();		//成績表示メソッドの呼び出し

	_getch();
	return 0;
}


