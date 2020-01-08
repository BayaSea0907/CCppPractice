/*------------------------------------------------------------
|問題06-03	BayaSea
| Q.増分に5を入力したら、結果はどうなるでしょうか？
|
| A.引数有りのchgSalesメソッドが呼び出された
--------------------------------------------------------------*/
#include <iostream>
using namespace std;

//店舗クラス定義
class Shop {
	int sales;			//売上高（万円）
public:
	Shop(int sal = 0) :sales(sal){}

	void chgSales(){ sales += 300; }
	void chgSales(int num){ sales *= num; }

	int getSales(){ return sales; }
};
//////////////////////////////////////////////////////////////
int main()
{
	Shop* shopP(new Shop(100));
	int num;		//増分入力用

	cout << "増分の入力>> ";
	cin >> num;

	if (num <= 0)	shopP->chgSales();
	else			shopP->chgSales(num);

	cout << "売上高=" << shopP->getSales() << endl;

	delete shopP;
	return 0;
}


