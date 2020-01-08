//Adapter（包含使用：sharedポインタ使用）
//新しい処理Newdisposalクラスを継承したAdapterオブジェクトに一般のポインタ変数（IDisposal* disposalP）を
//使用した場合、抽象interfaceクラスにvirtualデストラクタを定義していないと、adapterクラスのデストラクタを
//呼び出せずに実行時エラーを引き起こす
//解決するには、adapterクラスにNewdisposalオブジェクトを集約する
//集約にした場合、抽象interfaceクラスにvirtualデストラクタを定義していなくても実行時エラーはおきない
//ただし、Newdisposalのデストラクタは実行されない
//adapter02(集約shared).cpp
//結果
//NewdDisposal:start
//NewdDisposal:stop
//10000

#include <iostream>
#include <string>
#include <memory>
using namespace std::tr1;
using namespace std;

//処理クラス----------------------------------------------------------
//////////////////////////////////////////////////////////////////
//古い処理クラス定義
class OldDisposal {
	int x;
public:
	OldDisposal(){}
	void init(){ x = 100; }					//初期化
	void run(){ cout << x * x << endl; }	//二乗計算結果表示
	~OldDisposal(){}
};
//----------------------------------------------------------------
//新しい処理クラス定義
class NewdDisposal {
	int x;
public:
	NewdDisposal():x(100){}						//初期化
	//二乗計算
	void start()
	{
		cout << "NewdDisposal:start" << endl;
		x *= x;
	}
	//計算結果表示
	void stop()
	{
		cout << "NewdDisposal:stop" << endl;
		cout << x << endl;
	}
	virtual ~NewdDisposal(){}
};
//--------------------------------------------------------------------

//古い処理クラスから新しいクラスとの整合性をとるためにinterfaceクラスを定義する
///////////////////////////////////////////////////////////////////
//共通interfaceクラス定義（抽象interfaceクラス）
//古い処理クラスに対応したinterfaceクラス
class IDisposal {
public:
	virtual void init() = 0;
	virtual void run() = 0;
//	virtual ~IDisposal(){}		//一般のポインタを使う場合には、定義していなくても実行時エラーはおきない
};
//--------------------------------------------------------------------

///////////////////////////////////////////////////////////////////
//adapterクラス定義
class Adapter : public IDisposal {
	shared_ptr<NewdDisposal> sh_newDisposal;	//NewdDisposalを集約
public:
	Adapter():sh_newDisposal(new NewdDisposal){}
	void init(){}				//抽象interfaceクラスのメソッドを実装するために必要
	void run(){ sh_newDisposal->start(); }		//NewdDisposalのstartメソッドを呼び出す
	~Adapter(){ sh_newDisposal->stop(); }		//NewdDisposalのstopメソッドを呼び出す
};
//--------------------------------------------------------------------

///////////////////////////////////////////////////////////////////
//オブジェクト生成テンプレート関数
template<class X>
shared_ptr<X> createObject()
{
	return (shared_ptr<X>)(new X);
}

///////////////////////////////////////////////////////////////////
int main()
{
	shared_ptr<IDisposal> sh_disposal;
	
	sh_disposal = createObject<Adapter>();		//adapterオブジェクト生成

	sh_disposal->run();

/*
//一般のポインタ変数を使用した場合、抽象interfaceクラスにvirtualデストラクタを定義していなくても
//実行時エラーはおきない
//ただし、Newdisposalのデストラクタは実行されない
	IDisposal* disposalP(new Adapter);		//adapterオブジェクト生成

	disposalP->run();
	delete disposalP;
*/

	return 0;
}
