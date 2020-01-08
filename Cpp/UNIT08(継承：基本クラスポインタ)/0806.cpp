/*------------------------------------------------------
|問題08-06	 BayaSea
--------------------------------------------------------*/
#include <iostream>
#include <ctime>			//システムタイマ用
#include <cstdlib>			//乱数発生用

using namespace std;

//会社クラス定義（基本クラス）
class Company {
public:
	virtual void show(){}		//仮想メソッド
};
////////////////////////////////////////////////////////
//店舗クラス定義（派生クラス）
class Shop : public Company {
public:
	void show(){ cout << "Shop" << endl; }
};
////////////////////////////////////////////////////////
//金融業クラス定義（派生クラス）
class Finance : public Company {
public:
	void show(){ cout << "Finance" << endl; }
};
////////////////////////////////////////////////////////
int main()
{
	Shop* shopP   = NULL;			//派生クラスポインタ宣言
	Finance* finP = NULL;		//派生クラスポインタ宣言

	srand((unsigned)time(NULL));	//乱数の種設定

	for (int i = 0; i < 5; i++)
	{
		//乱数を発生させてオブジェクト生成
		if (rand() % 2) 
		{
			if (shopP != NULL) delete shopP;
			shopP = new Shop;
			shopP->show();
		}
		else
		{
			if (finP != NULL) delete finP;
			finP = new Finance;
			finP->show();
		}
	}

	if (shopP != NULL) delete shopP;
	if (finP  != NULL) delete finP;

	system("pause");
	return 0;
}
