/*
課題番号　：L21-DeluxeSpecial1
内容　　　：marathonオブジェクトに、入力した3Kmマラソン完走者人数と完走者タイムを要素とする配列を
　　　　　　格納して、平均タイムを表示する。参加者は最大10人。
　　　　　　タイムは実数（例えば、13分20秒であれば13.2、12分5秒であれば12.05）で入力する。
　　　　　　まず、完走者人数（0人以上10人以下）を入力して、範囲外ならば再入力する。
　　　　　　範囲内ならば、完走者タイムをタイム入力用配列に入力して、完走者数と完走者タイム配列をオ
　　　　　　ブジェクトに格納する。
　　　　　　そして、平均タイムを計算して、いちどオブジェクトに格納する。
　　　　　　完走者人数が０人の場合は、"登録タイムはありません"と表示する。
　　　　　　入力と完走者０人の場合の表示はmain関数で行い、平均タイムの表示はオブジェクトで行う。
ファイル名：L21-DX1.cpp
作成日　　：2015/12/03
作成者　　：BayaSea
*/

#include <conio.h>
#include <iostream>
using namespace std;

//マラソンクラス定義
class Marathon {
	int person = 0;		//完走者数（0）
	double time[10];	//完走者タイム用
	int heikin = 0;		//平均タイム秒
public:
	//完走者数設定　n：完走者数
	void setPerson(int n){
		person = n;
	}

	//完走者タイム設定　t[]：タイム配列
	void setTime(double t[]){
		for (int i = 0; i < person; i++) {
			time[i] = t[i];
		}
	}

	//平均タイム計算
	void calcAveTime(){
		//タイムを整数に直す
		for (int i = 0; i < person; i++){
			//タイムを整数に直して合計を求める
			heikin += (int)(time[i] * 100.0);

			//下2桁(秒)が60を超えたら桁を上げる
			if (60 <= (heikin % 100)){
				heikin += 40;
			}
		}

		//合計タイム ÷ 登録人数
		heikin /= person;
		//下2桁が 秒/100となっているので 秒/60に直す
		heikin = ((heikin - (heikin % 100)) + ((int)((double)(heikin % 100) * 0.6) + 0.9999));
	}

	//平均タイム表示
	void showAveTime(){
		cout << person << "人の平均タイム="
			 <<	heikin / 100 << "分" <<	heikin % 100 << "秒" << endl;
	}
};
////////////////////////////////////////////////////////////
int main()
{
	Marathon marathon;	//マラソンオブジェクト宣言
	double time[10];	//タイム入力用
	int person;			//人数入力用

	while (1){
		cout << "登録する人数の入力（０以上１０人以下）>> ";
		cin >> person;

		//範囲内だったらループを抜ける
		if (0 <= person && person <= 10) { break; }

		cout << "入力人数が違います。再入力してください" << endl;

	}

	//完走者が１人以上いた場合
	if(person != 0)
	{
		//完走者タイム入力
		for (int i = 0; i < person ; i++){
			cout << i + 1 << "人目のタイム（分．秒）の入力>> ";
			cin >> time[i];
		}

		marathon.setPerson(person);	//完走者数設定メソッドの呼び出し
		marathon.setTime(time);		//完走者タイム設定メソッドの呼び出し
		marathon.calcAveTime();		//平均計算メソッドの呼び出し
		marathon.showAveTime();		//平均タイム表示メソッドの呼び出し
	}
	else{
		cout << "登録タイムはありません" << endl;
	}

	_getch();
	return 0;
}

