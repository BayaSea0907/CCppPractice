/*---------------------------------------------------
|���07-05	 BayaSea
-----------------------------------------------------*/

#include <iostream>
#include <string>				//�����񑀍�p�N���X
using namespace std;

//���i�N���X��`
class Goods {
	string name;				//���i��
public:
	Goods(string gn = "") :name(gn){}
	string getName(){ return name; }
};
/////////////////////////////////////////////////////
//���ݕ��N���X��`
class Drink : public Goods {
	int num;					//�{��
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
