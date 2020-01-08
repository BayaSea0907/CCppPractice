//Singleton(normal：オブジェクト宣言)
//【問題点】
//（Singleton01.cpp）で問題となる、生成したSingletonオブジェクトの解放場所を解決するために、
//Singletonオブジェクトを静的変数として宣言する

//静的変数で宣言したオブジェクトのアドレスをGetInstance()で戻すだけなので、sharedポインタを使う必要はない
//
//Singlton02(normal-declare).cpp
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
public:
	//唯一のアクセス経路
	static Singleton* GetInstance()
	{
		//唯一のSingletonオブジェクト静的変数として宣言する
		static Singleton instance;

		return &instance;
	}

	void show(){ cout << "singleton" << endl; }

	~Singleton(){}
};
//--------------------------------------------------------------------

///////////////////////////////////////////////////////////////////
int main()
{
	Singleton* sP1 = Singleton::GetInstance();		//Singletonオブジェクト生成

	//メソッドの呼び出し方（２通り）
	sP1->show();						//①ポインタを使って呼び出す
	Singleton::GetInstance()->show();	//②唯一のアクセス経路から呼び出す

	return 0;
}
