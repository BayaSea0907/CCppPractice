/*---------------------------------------------------
問題15-01	2016.10.6

BayaSea
-----------------------------------------------------*/
#include <iostream>
using namespace std;

//預金者クラス定義
class Depo {
	int depo = 500;			//預金残高（万円）
public:
	int getDepo()const{ return depo; }		//預金残高取得
};
///////////////////////////////////////////////////////////////////
//銀行クラス定義
class Bank {
public:
	//預金残高表示
	void depoShow(const Depo* depoP)
	{
		cout << "銀行からみた預金残高=" << depoP->getDepo() << endl;
	}
};
///////////////////////////////////////////////////////////////////
int main()
{
	Depo* depoP(new Depo);		//預金者クラスポインタ
	Bank* bankP(new Bank);		//銀行クラスポインタ

	bankP->depoShow(depoP);		//銀行クラスメソッド呼び出し

	delete depoP;
	delete bankP;
	return 0;
}
