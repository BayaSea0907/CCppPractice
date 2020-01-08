/*--------------------------------------------------------------------------------------
|問題05-02	 BayaSea
|
| Q.次のようなオブジェクトを生成した場合、どうなるでしょうか？誤りの場合には修正しなさい。
|   ただし、関数引数の初期化は使わないものとします。
| A.コンストラクタに引数を渡さないといけないのに、shopXPでは渡していなかった。
---------------------------------------------------------------------------------------*/
#include <iostream>
using namespace std;

//店舗クラス定義
class Shop {
	int sales;
public:
	Shop():sales(0){}
	Shop(int sal):sales(sal){}

	int getSales() { return sales; }
};
////////////////////////////////////////////////////////
int main()
{
	Shop* shopXP(new Shop);	
	Shop* shopSP(new Shop(300));

	cout << "shopXP=" << shopXP->getSales() << endl;
	cout << "shopSP=" << shopSP->getSales() << endl;

	delete shopXP;
	delete shopSP;

	system("pause");
	return 0;
}