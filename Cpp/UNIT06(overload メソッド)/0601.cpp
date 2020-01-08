/*----------------------------------------------------------------
|問題06-01	 BayaSea
------------------------------------------------------------------*/
#include <iostream>
using namespace std;

//Heroクラス定義
class Hero {
	int hp;			
public:
	
	/* 
	Hero() :hp(50){ cout << "HP=" << hp << "で生成" << endl; }			//①コンストラクタ
	Hero(int ch) :hp(ch){ cout << "HP=" << hp << "で生成" << endl; }	//②コンストラクタ（ch：HP）
	*/

	//コンストラクタ③　問題06-01の解答欄
	Hero(int ch = 50) : hp(ch){
		cout << "HP=" << hp << "で生成" << endl;
	}

	//休息
	void rest(){ cout << "一休み 一休み" << endl; }
	void rest(int rh){ hp += rh; }		//（rhp：HP増加量）

	int getHp(){ return hp; }		//HP取得

	~Hero(){ cout << "オブジェクト消滅" << endl << endl; }
};
/////////////////////////////////////////////////////////////////
int main()
{
	Hero* heroP(new Hero);		//オブジェクトのアロケーション

	heroP->rest();			//休息（デフォルト）メソッド呼び出し
	cout << "HP=" << heroP->getHp() << endl;

	delete heroP;			//アロケーション領域解放
//---------------------------------------------------------------
	heroP = new Hero(200);		//HP200でアロケーション

	heroP->rest(100);		//休息（HP増加指定）メソッド呼び出し
	cout << "HP=" << heroP->getHp() << endl;

	delete heroP;			//アロケーション領域解放
	return 0;
}



