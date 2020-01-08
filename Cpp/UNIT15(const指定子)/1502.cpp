/*---------------------------------------------------------------
 問題15-02	2016.10.6

BayaSea
-----------------------------------------------------------------*/
#include <iostream>
#include <memory>
using namespace std;

//預金者クラス定義
class Depo {
	int depo = 500;			//預金残高（万円）
public:
	int getDepo()const{ return depo; }	//預金残高取得
};
///////////////////////////////////////////////////////////////////
//銀行クラス定義
class Bank {
public:
	//預金残高表示
	void depoShow(shared_ptr<const Depo> const sh_depo)
	{
		cout << "銀行からみた預金残高=" << sh_depo->getDepo() << endl;
	}
};
///////////////////////////////////////////////////////////////////
//オブジェクトを生成するテンプレート外部関数
template<class X>
shared_ptr<X> create(){ return (shared_ptr<X>)(new X); }
///////////////////////////////////////////////////////////////////
int main()
{
	//預金者ポインタ
	shared_ptr<const Depo> const sh_depo(create<Depo>());

	//銀行ポインタ
	shared_ptr<Bank> sh_bank(create<Bank>());

	sh_bank->depoShow(sh_depo);		//銀行クラスメソッド呼び出し

	return 0;
}


