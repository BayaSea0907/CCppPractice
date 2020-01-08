/*------------------------------------------------------------
|問題04-03	 BayaSea
|
|設問.	Set関数で、->の代わりに .(ピリオド)を使ってsetNumメソッドを呼び出しなさい。
|		->の左側と . の左側は、それぞれ何を表していますか？
-------------------------------------------------------------*/
#include <iostream>
using namespace std;

//店舗クラス定義
class Shop {
	int num;		//個数
public:
	void setNum(int sn){ num = sn; }	//個数設定
	int getNum(){ return num; }			//個数取得
};
//////////////////////////////////////////////////////////////
//外部関数 個数に100個を設定
void Set(Shop* shopP){
	//shopP->setNum(100);			//設問　->の左側は、オブジェクトのアドレス
	 (*shopP).setNum(100);			//設問　．の左側は、オブジェクトの領域
}
//////////////////////////////////////////////////////////////
int main()
{
	Shop* shopP(new Shop);

	Set(shopP);		//外部関数呼び出し
	cout << "個数=" << shopP->getNum() << endl;

	delete shopP;
	system("pause");
	return 0;
}
