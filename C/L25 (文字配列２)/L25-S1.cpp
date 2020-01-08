/*
課題番号　：L25-Special1
内容　　　：数字から数値へ変換するstrToDecオブジェクトに入力した数字列（数字のみの文字列：最大文字
　　　　　　数１０）をchar型文字配列に格納して、１０進整数に変換して表示する。
　　　　　　入力と表示はmain関数で行う。
　　　　　　例えば、文字列として12345を入力した場合、表示する１０進整数は12345（一万二千三百四十
　　　　　　五）となる。
ファイル名：L25-S1.cpp
作成日　　：2015/1/4
作成者　　：BayaSea
*/

#include <conio.h>
#include <iostream>
using namespace std;

//数字から数値へ変換するクラス定義
class StrToDec {
	char str[11];		//入力数字列用
	int num = 0;		//整数値変換用
public:
	//数字列設定　s[]：数字列
	void setStr(char s[]) {
		strcpy_s(str, 11, s);
	}

	//数字列から数値への変換
	void chgStrToDec() {
		for (int i = 0; str[i] != '\0'; i++) 
		{
			//strに10倍して桁をずらしながら格納
			num = (num * 10) + (int)(str[i] - '0');	
		}
	}

	//変換後数値取得
	int getNum() {
		return num;
	}

};
////////////////////////////////////////////////////////////
int main()
{
	StrToDec strToDec;		//数字から数値へ変換オブジェクト宣言
	char str[11];			//数字列入力用

	cout << "数字列を入力>> ";
	cin >> str;
	
	strToDec.setStr(str);		//数字列設定メソッドの呼び出し

	strToDec.chgStrToDec();		//数字列から数値への変換メソッドの呼び出し
	cout << "変換した整数=" << strToDec.getNum() << endl;

	_getch();
	return 0;
}


