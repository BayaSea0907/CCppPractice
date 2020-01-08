/*-------------------------------------------------------
|問題03-02	 BayaSea
---------------------------------------------------------*/
#include <iostream>
using namespace std;

//商品構造体定義
struct Goods {
	int num;        //個数
	int tanka;      //単価（円）
};
////////////////////////////////////////////////////////////////
//店舗クラス定義
class Shop {
	Goods goods;			//商品構造体変数宣言
public:
	//個数単価設定　sg：個数、st：単価
	void setGoods(int sg, int st)
	{
		goods.num   = sg;
		goods.tanka = st;
	}
	int getNum()  { return goods.num; }		//個数取得
	int getTanka(){ return goods.tanka; }	//短歌取得
};
////////////////////////////////////////////////////////////////
int main()
{
	//ポインタ宣言と同時のアロケーション
	Shop* shop(new Shop);

	//個数（100個）、単価（50円）の設定
	shop->setGoods(100, 50);

	//商品情報の表示
	cout << "商品="  << shop->getNum()
		 << " 単価=" <<	shop->getTanka() << endl;

	//アロケーション領域の解放
	delete shop;

	system("pause");
	return 0;
}
