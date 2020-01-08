/*
課題番号　：L16-11
内容　　　：丸maruオブジェクトのメソッドで、２重ループを使って横に５列、縦に３行の”○”を表示する。
ファイル名：L16-A11.cpp
作成日　　：2015/10/01
作成者　　：BayaSea
*/

#include <conio.h>
#include <iostream>
using namespace std;

//丸クラス定義
class Maru {
public:
    //○表示メソッド
    void showMaru()
	{
		//縦（行）方向の制御　gyo：縦（行）用ループカウンタ
		for(int gyo = 0; gyo < 3; gyo++)
		{
			//１行当りの横（列）方向の制御　retu：横（列）用ループカウンタ
			for(int retu = 0; retu < 5; retu++)
			{
				cout << "○";
			}
				
			cout << endl;		//行末（１行の終わり）の改行
		}
	}
};
////////////////////////////////////////////////////////////
int main()
{
	Maru maru;			//丸オブジェクト宣言

	maru.showMaru();	//丸表示メソッドの呼び出し

	_getch();
	return 0;
}
