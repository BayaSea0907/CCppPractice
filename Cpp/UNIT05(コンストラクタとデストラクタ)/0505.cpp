/*------------------------------------------------
|問題05-05	  BayaSea
--------------------------------------------------*/
#include <iostream>
using namespace std;

//店舗クラス
class Shop {
	int sales = 0;
public:
	Shop(int sal) : sales(sal) { cout << "オブジェクト生成" << endl; }
	~Shop() { cout << "オブジェクト消滅" << endl; }

	int getSales() { return sales; }
};
///////////////////////////////////////////////////////////////
int main()
{
	Shop* shopP(new Shop(100));

	cout << "売上高=" << shopP->getSales() << endl;

	delete shopP;
	
	system("pause");
	return 0;
}
