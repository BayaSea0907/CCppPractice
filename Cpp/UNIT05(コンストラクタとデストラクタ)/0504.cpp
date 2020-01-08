/*---------------------------------------------------------------------
|問題05-04	  BayaSea
| プロパティsalesの値を、次の結果のように表示するデストラクタを述べなさい。
-----------------------------------------------------------------------*/
#include <iostream>
using namespace std;

//店舗クラス
class Shop {
	int sales = 300;	//売上高（万円）
public:
	~Shop() { cout << "売上高=" << sales << endl; }
};
///////////////////////////////////////////////////////////////
int main()
{
	Shop* shopP(new Shop);

	delete shopP;

	system("pause");
	return 0;
}


