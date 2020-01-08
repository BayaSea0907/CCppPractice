/*
課題番号　：L15-13
内容　　　：国語と数学の得点（０点以上１００点以下）を入力して、合否を判定する。
　　　　　　テストtestオブジェクトに得点を設定した後、次の合否判定を行って結果を表示する。
　　　　　　同じ内容（点数は除く）の合否判定表示は１ヵ所とする。
　　　　　　　両科目とも６０点以上を合格とし、合否分類は次の３分類
　　　　　　 　　・合格の場合：総得点と平均値
　　　　　　 　　・不合格の場合：
　　　　　　　　　　　a)１科目のみ６０点未満の場合（その科目の６０点に足りない不足点）
　　　　　　　　　　　b)両科目とも６０点未満の場合
　　　　　　得点入力はuiオブジェクトで行い、判定表示はtestオブジェクトで行う。
ファイル名：L15-B13.cpp
作成日　　：2015/07/15
作成者　　：BayaSea
*/

#include <conio.h>
#include <iostream>
using namespace std;
//テストクラス定義
class Test{
	int kokugo;		//国語用
	int sugaku;		//数学用
public:
    //点数設定メソッド
	void setTen(int skokugo, int ssugaku)
	{
		//点数を設定
		kokugo = skokugo;
		sugaku = ssugaku;
	}
	
	//得点判定メソッド
	void judgeTen()
	{
			//自動変数。総得点を計算
			int ten = kokugo + sugaku;

			//国語と数学が範囲外か調べる。
			if ((kokugo <= 100 && kokugo >= 0) && (sugaku <= 100 && sugaku >= 0))
			{
				//各60点以上なら合格。
				if (kokugo >= 60 && sugaku >= 60)
				{
					cout << "合格:総得点=" << ten << "   平均=" << (double)ten / 2.0 << endl;
				}
				//1科目のみ60点だった場合
				else if (kokugo >= 60 || sugaku >= 60)
				{
					cout << "不合格:";

					//届かなかった科目を調べる。
					if (kokugo < 60)
					{
						cout << "国語が" << 60 - kokugo << "点不足" << endl ;
					}
					else
					{
						cout << "数学" << 60 - sugaku << "点不足" << endl ;
					}
				}
				else
				{
					cout << "不合格:両科目とも６０点未満" << endl;
				}
			}
			//範囲外の科目を調べる
			else
			{
				if (kokugo > 100 || kokugo < 0)
				{
					cout << "国語の点数が範囲外" << endl;
				}
				if (sugaku > 100 || sugaku < 0)
				{
					cout << "数学の点数が範囲外" << endl;
				}
			}
	}
};

////////////////////////////////////////////////////////////
//ユーザインタフェースクラス定義
class UI {
	Test test;		//テストオブジェクト宣言
public:
	//処理制御メソッド
		void processCtrl()
		{
			inpTest();		    //test入力設定
			test.judgeTen();	//得点判定
		}
	//test入力設定メソッド
	void inpTest()
	{	
		//自動変数
		int kokugo, sugaku;

		cout << "国語、数学の点数を０～１００点の間で入力(例: 66 94) >> ";
		cin >> kokugo >> sugaku;

		//testオブジェクトのsetTenメソッド	
		test.setTen(kokugo, sugaku);
	}

};
////////////////////////////////////////////////////////////////
int main()
{
	UI ui;			//ユーザインタフェースオブジェクト宣言

	ui.processCtrl();	//インタフェース処理制御

	_getch();
	return 0;
}
