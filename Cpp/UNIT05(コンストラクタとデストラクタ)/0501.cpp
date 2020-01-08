/*------------------------------------------------------
|問題05-01	 BayaSea
|
| Q.何か変です。不具合が生じる理由を述べて修正しなさい。
| A.salesが初期化されていないのに、addSalesで売り上げを追加しようとしていた。
--------------------------------------------------------*/
#include <iostream>
using namespace std;

//店舗クラス定義
class Shop{
	int sales;		//売上高
public:
	Shop() : sales(0){}

	void initSales(int sal) { sales = 0; } 
	void addSales (int sal) { sales += sal; }
	int getSales() { return sales; }
};
////////////////////////////////////////////////////////
int main()
{
	Shop* shopP(new Shop);

	//売上加算
	shopP->addSales(100);
	cout << "売上=" << shopP->getSales() << endl;

	delete shopP;

	system("pause");
	return 0;
}
