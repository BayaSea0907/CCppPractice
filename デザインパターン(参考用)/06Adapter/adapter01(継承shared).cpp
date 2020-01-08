//Adapter（継承使用：sharedポインタ使用）
//あるクラスが提供しているインタフェースを、別のクラス のインタフェースに変換する
//既存のコードを壊すことなく差し替えを行いたいが、以前に使っていたクラスと、
//新しく使うクラスとでは、用意されているメソッドが異なるかもしれない
//こういうときに、間にアダプタを挟み込んで、インタフェースを変換する
//
//古い処理OldDisposalでは「初期化init」「計算と表示run」で、二乗計算と結果を表示するものであった
//今、新しい処理NewDisposalでは、計算と表示を分け、「初期化をコンストラクタ」「計算start」
//「表示stop」で同じ処理を行うものにした
//新しい処理NewDisposalを利用するmain側では、古い処理OldDisposalのメソッド名を流用したい
//この場合、OldDisposalとNewDisposalとのメソッド名との整合性をとるためにadapterクラスを定義することになる
//
//【要注意】
//一般のポインタ変数（IDisposal* disposalP）を使用した場合、
//抽象interfaceクラスにvirtualデストラクタを定義していないと、adapterクラスのデストラクタを
//呼び出せずに実行時エラーを引き起こす
//解決するには、集約を使う（adapter02(集約shared).cppを参照）
//
//adapter01(継承shared).cpp
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
	virtual ~IDisposal(){}		//一般のポインタを使う場合には、必ず必要
};
//--------------------------------------------------------------------

///////////////////////////////////////////////////////////////////
//adapterクラス定義
class Adapter : private NewdDisposal, public IDisposal {
public:
	Adapter(){}
	void init(){}				//抽象interfaceクラスのメソッドを実装するために必要
	void run(){ start(); }		//NewdDisposalのstartメソッドを呼び出す
	~Adapter(){ stop(); }		//NewdDisposalのstopメソッドを呼び出す
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
//一般のポインタ変数を使用した場合、抽象interfaceクラスにvirtualデストラクタを定義していないと
//実行時エラーを引き起こす
	IDisposal* disposalP(new Adapter);		//adapterオブジェクト生成

	disposalP->run();
	delete disposalP;
*/
	return 0;
}
