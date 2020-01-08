/*--------------------------------------------------------------
| 問題04-04	  BayaSea
----------------------------------------------------------------*/
#include <iostream>
using namespace std;

//店舗クラス定義
class Shop {
	int discount;		//割引価格（円）

	//割引価格計算（pr：価格）割引率２０％
	void calcDiscount(int pr){ discount = (int)(pr * 0.8); }
public:
	void receivePrice(int pr) { calcDiscount(pr); }		//価格受け取り
	int getDiscount(){ return discount; }				//割引価格取得
};
////////////////////////////////////////////////////////////////
int main()
{
	Shop* shopP(new Shop);

	shopP->receivePrice(1000);		//価格受取りメソッド呼び出し

	//割引価格取得メソッド呼び出し
	cout << "割引価格=" << shopP->getDiscount() << endl;

	delete shopP;
	system("pause");
	return 0;
}
