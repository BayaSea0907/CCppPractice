/*------------------------------------------------------------
|問題14-03		 BayaSea
--------------------------------------------------------------*/
#include <iostream>
#include <memory>
using namespace std;

//メソッドのオーバーロードは引数の型と個数で判断されるので、
//型が同じint型だったのでバグが出た。

//商品クラス定義
class Goods {
	int cost;			//費用（円）
public:
	Goods() :cost(100){}
	void chgCost(int ccost){ cost += ccost; }
	void chgCost(int* ccost){ cost -= *ccost; }
	int getCost(){ return cost; }
};
///////////////////////////////////////////////////////////
//オブジェクトを生成するテンプレート外部関数
template<class X>
shared_ptr<X> create(){ return (shared_ptr<X>)(new X); }
///////////////////////////////////////////////////////////
int main()
{
	shared_ptr<Goods> sh_goods(create<Goods>());
	int cost = 50;

	sh_goods->chgCost(cost);
	cout << "費用=" << sh_goods->getCost() << endl;

	return 0;
}
