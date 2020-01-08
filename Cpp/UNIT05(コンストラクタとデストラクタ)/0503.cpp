/*-----------------------------------------------------------------------------------------
|問題05-03	BayaSea
|
| Q.プロパティsalesを初期化するためにinitSalesメソッドをアクセスしていますが、
|   よろしくありません。なぜでしょうか？理由を述べなさい。また、解決策（２通り）も述べなさい。
| 
|A.initSalesを呼び出す前にaddSalesを呼び出すことがあると、salesが不定のまま処理をしてしまう場合がある。
|   解決策1:Shopクラスのコンストラクタであらかじめ初期化をしておく。
|   解決策2:プロパティを宣言と同時に初期化をしておく。
| -----------------------------------------------------------------------------------------*/
#include <iostream>
using namespace std;

//店舗クラス定義
class Shop {
  //int sales = 0;
	int sales;
public:
	//Shop() : sales(0){}
	void initSales(){ sales = 0; }	
	void addSales(int sal){ sales += sal; }

	int getSales() { return sales; }
};
////////////////////////////////////////////////////////
int main()
{
	Shop* shopP(new Shop);

	shopP->initSales();
	shopP->addSales(100);

	delete shopP;

	system("pause");
	return 0;
}
