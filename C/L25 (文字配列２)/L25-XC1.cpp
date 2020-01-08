/*
課題番号　：L25-ExcellentSpecial1
内容　　　：contStrオブジェクトに入力した文字列の文字（最大文字数１０）がそれぞれ何個あったのかを
　　　　　　調べ、文字コードの小さい順に結果を表示する。
　　　　　　文字パターン配列（要素数１１）と文字個数配列（要素数１０）の２つを文字パターン構造体で
　　　　　　用意し、文字とその個数を同じ配列要素番号で対応させる。
　　　　　　コンストラクタで、文字パターン構造体の文字パターン配列と個数配列をそれぞれヌル文字と０
　　　　　　で初期化する。
　　　　　　入力と表示は、main関数で行う。
　　　　　　文字パターンと個数設定メソッドでは、初めて現れる文字を文字パターン配列に格納して、同じ
　　　　　　文字が現れるごとに文字パターン配列要素に対応した個数格納用配列の要素をインクリメントす
　　　　　　る。
ファイル名：L25-XC1.cpp
作成日　　：2016/1/5
作成者　　：BayaSea
*/

#include <conio.h>
#include <iostream>
using namespace std;

//文字パターン構造体定義
struct Pattern {
	char mozi[11];		//文字パターン格納用
	int kosu[10];		//文字個数格納用
};

//文字列構成文字クラス定義
class ContentStr {
	Pattern pat;		//文字パターン構造体
	char str[11];		//入力文字列用
	int max = 0;		//文字パターン配列に格納した文字数（kosu配列にも使う）
public:
	//コンストラクタ
	ContentStr() {
		int i;

		//0で初期化
		for (i = 0; i < 10; i++) {
			pat.kosu[i] = 0;
		}

		//ヌル文字で初期化
		for (i = 0; i < 11; i++){
			pat.mozi[i] = '\0';
		}
	}


	//文字列設定　s[]：格納文字列
	void setStr(char s[]) {
		strcpy_s(str, 11, s);
	}

	//文字パターンと個数設定
	void searchMoziKosu()
	{
		//nullになるまで繰り返す
		for (int i = 0; str[i] != '\0'; i++)
		{
			max = strlen(pat.mozi);		//文字パターン配列の文字数
			
			//一度mozi配列に格納した文字の検索は行わない
			for (int j = 0; (str[j] != '\0') && (str[i] != pat.mozi[j]); j++)
			{
				//入力文字を見つけた時
				if (str[i] == str[j])
				{
					//文字パターンが格納されていない場合
					if (pat.mozi[max] == '\0') {
						pat.mozi[max] = str[j];
					}
					//pat.mozi[max] = str[j];
					pat.kosu[max]++;
				}
			}
		}
	}

	//文字コード昇順ソート
	void sortMoziCode(){
		char temp;

		for (int i = 0; pat.mozi[i] != '\0'; i++)
		{
			for (int j = i + 1; pat.mozi[j] != '\0'; j++) 
			{
				if (pat.mozi[i] > pat.mozi[j]) 
				{
					temp = pat.mozi[i];
					pat.mozi[i] = pat.mozi[j];
					pat.mozi[j] = temp;

					temp = pat.kosu[i];
					pat.kosu[i] = pat.kosu[j];
					pat.kosu[j] = temp;
				}
			}
		}
	}

	//文字パターン構造体取得　戻り値：文字パターン構造体
	Pattern getPattern() {
		return pat;
	}

};
////////////////////////////////////////////////////////////


int main()
{
	ContentStr contStr;		//文字列構成文字オブジェクト宣言
	char str[11];			//文字列入力用
	Pattern pat;			//文字パターン構造体取得用

	cout << "文字列を入力>> ";
	cin >> str;

	contStr.setStr(str);		//文字列設定メソッドの呼び出し

	contStr.searchMoziKosu();	//文字パターンと個数設定メソッドの呼び出し

	contStr.sortMoziCode();		//文字コード昇順ソートメソッドの呼び出し

	pat = contStr.getPattern();		//文字パターン取得メソッドの呼び出し
	
	for (int i = 0; pat.mozi[i] != '\0'; i++) {
		cout << "文字" << pat.mozi[i] << " 個数=" << pat.kosu[i] << endl;;
	}

	_getch();
	return 0;
}

