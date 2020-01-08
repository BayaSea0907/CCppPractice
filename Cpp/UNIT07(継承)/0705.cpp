/*---------------------------------------------------
|問題07-05	 BayaSea
-----------------------------------------------------*/

#include <iostream>
#include <string>				//文字列操作用クラス
using namespace std;

//商品クラス定義
class Goods {
	string name;				//商品名
public:
	Goods(string gn = "") :name(gn){}
	string getName(){ return name; }
};
/////////////////////////////////////////////////////
//飲み物クラス定義
class Drink : public Goods {
	int num;					//本数
public:
	Drink(string dn = "", int dm = 0):num(dm), Goods(dn){}
	int getNum(){ return num; }
};
/////////////////////////////////////////////////////
int main()
{
	Drink* drinkP(new Drink("TEA", 100));

	cout << drinkP->getName() << "=" << drinkP->getNum() << endl;

	delete drinkP;
	return 0;
}
