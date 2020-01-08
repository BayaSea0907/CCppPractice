/*
課題番号　：L16-DeluxeSpecial2
内容　　　：カレンダーcalendarオブジェクトで、2015年８月のカレンダーを表示する。
　　　　　　数字は４桁で表示する。
　　　　　　但し、break文を使ってもよい。
　　　　　　また、次のような曜日用列挙型を定義すると、かなり汎用的なものとなる。
ファイル名：L16-DX2.cpp
作成日　　：2015/11/22
作成者　　：BayaSea
*/

#include <iomanip>
#include <conio.h>
#include <iostream>
using namespace std;

//曜日用列挙型
enum YOUBI
{
	Sun,
    Mon,
    Tue,
    Wed,
    Thur,
    Fri,
    Sat
};

//カレンダークラス定義
class Calendar {
    int maxDay = 31;	    //８月最大日数（31日）
    int day = 1;	        //日付（初日は１日）
    YOUBI youbi = Sat;	    //８月初めカレンダー開始曜日（土曜日設定）
			                //（Satの値を複数回使用しているためyoubi変数に格納）
public:
    //カレンダー表示メソッド
    void showCalendar()
	{
        int week;		//週数

		week								//月が何週あるかを求める

		cout << "  日  月  火  水  木  金  土" << endl;

	    //週制御　i：週制御用ループカウンタ
		for(                        )
		{
			int j;		//曜日制御用ループカウンタ

		    //第１週の月初めまでの制御
			if(                 )
			{
		        //月初までの空白表示と月初（第１週）のカレンダー開始曜日取得
		        for(                       )
				{
		                cout << setw(4) << ' ';
		        }
		    }
		    //第２週のカレンダー開始曜日取得
			else
			{
				     = Sun;      //カレンダー開始曜日（日曜日）設定
		    }

			//週単位の日付表示
			for(    ;          ;      )
			{
				//月末までの日付表示
				if(                  )
				{
					cout << setw(4) << day;
		  			
		 		}
				else
				{
		 		 	
		 		}
			}
		 	cout << endl;
		}
	}
};
////////////////////////////////////////////////////////////
int main()
{
	Calendar calendar;			//カレンダーオブジェクト宣言

	calendar.showCalendar();	//カレンダー表示メソッドの呼び出し

	_getch();
	return 0;
}
