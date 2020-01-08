//Singleton(normal)
//オブジェクトが、プログラム全体でただひとつであることを保証し、
//かつ、そのオブジェクトへの唯一のアクセス経路を提供する

//ただひとつのオブジェクトを作るためには、静的変数（incetanceP）と唯一のアクセス経路（GetInstance()）を定義する
//オブジェクト生成のタイミングは、初めてGetInstance()を呼び出したときとなる
//そのため、プログラムの開始から終わりまでの間に、一度もGetInstance()が呼び出されなければ、
//オブジェクトは生成されることなく終了する

//メソッドの呼び出し方（２通り）
//Singleton* sP1 = Singleton::GetInstance();	//Singletonオブジェクト生成
//sP1->show();									//①ポインタを使って呼び出す
//Singleton::GetInstance()->show();				//②唯一のアクセス経路から呼び出す

//【問題点】
//静的変数や唯一のアクセス経路を定義しても、このままではいくつものオブジェクト生成（宣言）や
//宣言と同時の初期化や関数への値渡し、オブジェクトの代入等ができてしまう
//そこで、コンストラクタ、コピーコンストラクタ、代入演算子overloadをpublic以外の扱いにする
//
//Singleton* sP1 = Singleton::GetInstance();	//Singletonオブジェクト生成
//
//publicにした場合
//①いくつものオジェクトが生成（宣言）できてしまう
//Singleton* sXP(new Singleton);

//②デフォルトのコピーコンストラクタが起動してしまう
//Singleton* sP2 = new Singleton(*sP1);
//Singleton single = *sP2;

//③デフォルトの代入演算子overloadが起動してしまう
//Singleton* sP2;
//*sP2 = *sP1;

//④そのほか、生成したSingletonオブジェクトを別のポインタでも管理した場合、
//不用意にポインタの２重解放（エラー）を行ってしまう可能性がある
//Singleton* p2;
//p2 = p1;
//delete p1;
//delete p2;

//【問題点】
//生成したSingletonオブジェクトの解放場所について、静的変数を使っているが
//proxyパターンを流用できる
//しかし、一般には集約で対応させる（Singleton02.cpp）
//Singlton01(normal-pointer).cpp
//結果
//singleton
//singleton

#include <iostream>
#include <string>
using namespace std;

///////////////////////////////////////////////////////////////////
//Singletonクラス定義
class Singleton {

	//生成やコピーを禁止する
	Singleton(){}									//生成禁止
	Singleton(const Singleton& rhs){}				//コピーコンストラクタ禁止
	Singleton& operator=(const Singleton& rhs){}	//代入演算子overload禁止

	static Singleton* incetanceP;			//唯一のインスタンスを管理するポインタ

public:
	//唯一のアクセス経路
	static Singleton* GetInstance()
	{
		//未だSingletonオブジェクトが生成されていない場合
		if(incetanceP == 0)
		{
			incetanceP = new Singleton;
		}
		return incetanceP;
	}

	void show(){ cout << "singleton" << endl; }

	~Singleton(){}
};

//staticインスタンス変数の実体
Singleton* Singleton::incetanceP = 0;

//--------------------------------------------------------------------

///////////////////////////////////////////////////////////////////
int main()
{
	Singleton* sP1 = Singleton::GetInstance();		//Singletonオブジェクト生成

	//メソッドの呼び出し方（２通り）
	sP1->show();						//①ポインタを使って呼び出す
	Singleton::GetInstance()->show();	//②唯一のアクセス経路から呼び出す

	delete sP1;

	return 0;
}
