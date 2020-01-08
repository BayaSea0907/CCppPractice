/*---------------------------------------------------
|問題07-04【プログラムB】	BayaSea
-----------------------------------------------------*/
#include <iostream>
#include <string>					//文字列操作用クラス
using namespace std;

//会社クラス定義
class Company {
	string name;					//会社名
public:
	Company(string sn = ""):name(sn){}
	string getName() { return name; }
};
/////////////////////////////////////////////////////
//金融業クラス定義
class Finance : public Company {
	int loan;						//貸出高（億円）
public:
	Finance(string fn = "", int sl = 0):loan(sl), Company(fn){}
	int getLoan() { return loan; }
};
/////////////////////////////////////////////////////
//製造業クラス定義
class Production : public Company {
	string product;					//製造物
public:
	Production(string pn = "", string pp = ""):product(pp), Company(pn){}
	string getProduct() { return product; }
};
/////////////////////////////////////////////////////
int main()
{
	Finance* finP(new Finance("AIFL", 2000));
	Production* prodP(new Production("TADANO", "crane"));

	cout << finP->getName()  << "貸出高=" << finP->getLoan()     << endl;
	cout << prodP->getName() << "製造物=" << prodP->getProduct() << endl;

	delete finP;
	delete prodP;
	return 0;
}