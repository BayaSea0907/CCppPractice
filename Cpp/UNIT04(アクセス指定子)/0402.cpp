/*-----------------------------------------------------------
|問題04-02	 BayaSea
-------------------------------------------------------------*/
#include <iostream>
using namespace std;

//店舗クラス定義
class Shop {
	int sales;			//売上高（万円）
public:
	void setSales(){ sales = 100; }	//売上高設定
	int getSales(){ return sales; }	//売上高取得
};
//////////////////////////////////////////////////////////////
int main()
{
	Shop* shopP(new Shop);

	shopP->setSales();
	cout << "売上高=" << shopP->getSales() << endl;

	delete shopP;
	system("pause");
	return 0;
}