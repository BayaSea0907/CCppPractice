//問題０７－０４【プログラムA】 BayaSea
#include <iostream>
#include <string>				//文字列操作用クラス
using namespace std;

//金融業クラス定義
class Finance {
	string name;				//会社名
	int loan;					//貸出高（億円）
public:
	Finance(string fn = "", int fl = 0) :name(fn), loan(fl){}
	string getName(){ return name; }
	int getLoan(){ return loan; }
};
/////////////////////////////////////////////////////
//製造業クラス定義
class Production {
	string name;				//会社名
	string product;				//製造物
public:
	Production(string pn = "", string pr = "") :name(pn), product(pr){}
	string getName(){ return name; }
	string getProduct(){ return product; }
};
/////////////////////////////////////////////////////
int main()
{
	Finance* finP(new Finance("AIFL", 2000));
	Production* prodP(new Production("TADANO", "crane"));

	cout << finP->getName() << "=" << finP->getLoan() << endl;

	cout << prodP->getName() << "=" << prodP->getProduct() << endl;

	delete finP;
	delete prodP;
	return 0;
}
