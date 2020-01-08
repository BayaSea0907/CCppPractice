/*-----------------------------------------------------------------
|問題13-01	 BayaSea
 ------------------------------------------------------------------*/
#include <iostream>
#include <memory>
using namespace std;

//店舗クラス定義
class Shop {
	int sales;			//売上高（万円）
public:
	Shop(int sal = 0) :sales(sal){}
	int getSales(){ return sales; }
};
///////////////////////////////////////////////////////////////////
//オブジェクトを生成するテンプレート外部関数
template<class X, class Y>
shared_ptr<X> create(Y n){ return shared_ptr<X>(new X(n)); }
///////////////////////////////////////////////////////////////////
//オブジェクトの情報を表示する外部関数
//内容：sharedポインタで参照している生成オブジェクトを共有管理する
//引数：shared_ptr<Shop> sh_shop　生成オブジェクトのsharedポインタ
void Hyouzi(shared_ptr<Shop> sh_shop)
{
	cout << "売上高=" << sh_shop->getSales() << endl;
}
///////////////////////////////////////////////////////////////////
int main()
{
	shared_ptr<Shop> sh_shop(create<Shop>(777));		//sharedポインタ宣言

	Hyouzi(sh_shop);	//sharedポインタを関数に渡す

	cout << "値渡しで受けた関数を抜けても売上高="
		<< sh_shop->getSales() << endl;

	system("pause");
	return 0;
}
