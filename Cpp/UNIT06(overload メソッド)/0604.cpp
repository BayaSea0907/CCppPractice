/*------------------------------------------------------------
|問題06-04	 BayaSea
| 2つのchgSalesメソッドを、関数引数の初期化を使ったメソッドにする。
--------------------------------------------------------------*/
#include <iostream>
using namespace std;

//店舗クラス定義
class Shop {
	int sales;				//売上高（万円）
public:
	Shop(int sal = 0) :sales(sal){}
//    void chgSales(){ sales += 300; }
//    void chgSales(int num){ sales *= num; }

	void chgSales(int num = 0)
	{
		if (num <= 0)	sales += 300;
		else			sales *= num;

		//三項演算子を使うと
		//sales = (num <= 0) ? sales + 300 : sales * num;
	}
	int getSales(){ return sales; }
};
//////////////////////////////////////////////////////////////
int main()
{
	Shop* shopP(new Shop(100));
	int num;                        //増分入力用

	cout << "増分の入力>> ";
	cin >> num;

	shopP->chgSales(num);

	cout << "売上高=" << shopP->getSales() << endl;

	delete shopP;
	return 0;
}

