//問題０２－０２		BayaSea
#include <iostream>
using namespace std;

//店舗クラス定義
class Shop {
	int num;		//個数
public:
	//個数入力
	void inp() { 
		cout << "個数を入力 >>";
		cin >> num;
	}

	//個数取得
	int getNum() { return num; }
};
//////////////////////////////////////////////////////////////
int main()
{
	Shop shop; 		//オブジェクト宣言

	shop.inp();									//個数入力メソッド呼び出し
	cout << "個数=" << shop.getNum() << endl;	//個数取得メソッド呼び出し

	system("pause");
	return 0;
}
