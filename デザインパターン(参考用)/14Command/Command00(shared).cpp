//Command（shared）
//命令そのものをメソッドに定義して、命令オブジェクトとして生成する
//命令オブジェクトの実行は、定義したメソッドを呼び出す
//つまり、命令を実行させたい対象オブジェクトに、いずれかの命令オブジェクトを渡せば、
//対象オブジェクトは、渡された命令オブジェクトに定義されている命令どおりに実行される
//
//異なる内容の命令であっても、同じ名前のメソッドを呼び出して実行させたいので
//抽象interfaceクラスとしてCommandクラスを定義し、具体的な命令クラスを派生クラスとして定義する
//そして、この派生クラスオブジェクト（命令オブジェクト）のメソッドを呼び出して実行する

//ひとつひとつの異なる命令に対応した命令オブジェクトを作れるので、命令オブジェクトを組み合わせて
//使うこともできる

//例）飽和食塩水を作る実験
//１）水100gに食塩を1gずつ加えた場合、食塩は何g溶けるか？
//手順
//1.ビーカーに水を100g入れる
//2.ビーカーに食塩を1g入れる
//3.かき混ぜる
//4.完全に溶ければ、2に戻る
//5.食塩が溶け残ったら、そのときの水量、食塩量、濃度を記録する

//２）食塩10gに水を10gずつ加えた場合、水は何g必要か？
//手順
//1.ビーカーに食塩を10g入れる
//2.ビーカーに水を10g入れる
//3.かき混ぜる
//4.完全に溶けなければ、2に戻る
//5.食塩が完全に溶けたら、そのときの水量、食塩量、濃度を記録する

//飽和食塩水を作るために必要なメソッドを実験セットBeakerクラスとして定義する

//実験内容（手順）の抽象interfaceクラスを継承したそれぞれの派生クラスに、具体的な内容（手順）を定義して
//命令オブジェクトとして生成する
//そして、実験セットに、実験内容（手順）を渡して実験を行う

//
//Command00(shared).cpp
//結果
//食塩を1gずつ加える実験
//水：100g
//食塩：36g
//濃度：26.4706%
//
//水を10gずつ加える実験
//水：30g
//食塩：10g
//濃度：25%
//
//
//食塩水を作る実験
//水：90g
//食塩：10g
//濃度：10%

#include <iostream>
#include <string>
#include <memory>
using namespace std::tr1;
using namespace std;

//オブジェクト生成テンプレート関数-----------------------------------
///////////////////////////////////////////////////////////////////
template<class X>
shared_ptr<X> createObject()
{
	return (shared_ptr<X>)(new X);
}
//---------------------------------------------------------------
template<class X, class Y>
shared_ptr<X> createObject(Y n)
{
	return (shared_ptr<X>)(new X(n));
}
//---------------------------------------------------------------
template<class X, class Y>
shared_ptr<X> createObject(Y n, Y m)
{
	return (shared_ptr<X>)(new X(n, m));
}
//--------------------------------------------------------------------

//////////////////////////////////////////////////////////////////
//実験セットクラス定義
class Beaker {
	double water;		//水
	double salt;		//食塩
	bool melted;		//食塩の溶解度（true：すべて溶けた、false：溶け残った）
public:
	Beaker(double bwater = 0.0, double bsalt = 0.0):water(bwater), salt(bsalt), melted(true)
	{
		mix();		//かき混ぜる
	}

	void addSalt(double asalt){ salt += asalt; }		//食塩の追加
	void addWater(double awater){ water += awater; }	//水の追加

	//溶液をかき混ぜる
	void mix()
	{
		//溶けたか溶け残ったかの設定（常温での飽和食塩水の濃度は約26.4%）
		if((salt / (salt + water)) * 100 < 26.4)	melted = true;		//溶けた
		else										melted = false;		//溶け残った
	}

	double getSalt()const{ return salt; }
	double getWater()const{ return water; }
	bool isMelted()const{ return melted; }		//溶解状態を調べる

	//実験結果の記録
	void note()
	{
		cout << "水：" << water << "g" << endl; 
		cout << "食塩：" << salt << "g" << endl;
		cout << "濃度：" << (salt / (water + salt)) * 100 << "%" << endl;
	}
};

//Command----------------------------------------------------------------
//////////////////////////////////////////////////////////////////
//実験内容コマンドinterfaceクラス定義（抽象クラス）
class Command {
protected:
	shared_ptr<Beaker> sh_beaker;	//実験セットオブジェクト（ビーカー）管理
public:
	void setBeaker(shared_ptr<Beaker> sh_sbeaker){ sh_beaker = sh_sbeaker; }	//ビーカーの設定
	virtual void execute() = 0;									//要求内容の実行
	virtual ~Command(){}
};

//Commandオブジェクトクラス（実際の実験内容クラス）-----------------
//////////////////////////////////////////////////////////////////
//食塩を1gずつ加えて飽和食塩水を作る実験コマンドクラス定義
class AddSaltCommand : public Command {
public:
	void execute()
	{
		//完全に溶けている間は食塩を加える
		while(sh_beaker->isMelted())
		{
			sh_beaker->addSalt(1);		//食塩を1g追加
			sh_beaker->mix();				//かき混ぜる
		}

		//実験結果の記録
		cout << "食塩を1gずつ加える実験" << endl;
		sh_beaker->note();
	}
	~AddSaltCommand(){}
};
//-------------------------------------------------------------------
//水を10gずつ加えて飽和食塩水を作る実験コマンドクラス定義
class AddWaterCommand : public Command {
public:
	void execute()
	{ 
		//溶け残っている間は水を加える
		while (!sh_beaker->isMelted())
		{ 
			sh_beaker->addWater(10);		//水を10g追加
			sh_beaker->mix();				//かき混ぜる
		}

		//実験結果の記録
		cout << "水を10gずつ加える実験" << endl;
		sh_beaker->note(); 
	}
	~AddWaterCommand(){}
};
//------------------------------------------------------------------
//食塩水を作る実験コマンドクラス定義
class MakeSaltWaterCommand : public Command {
public:
	void execute()
	{
		sh_beaker->mix();		//かき混ぜる

		//実験結果の記録
		cout << "食塩水を作る実験" << endl;
		sh_beaker->note();
	}
	~MakeSaltWaterCommand(){}
};
//-----------------------------------------------------------------------

//////////////////////////////////////////////////////////////////
int main()
{
	//実験内容コマンドオブジェクトの生成
	shared_ptr<Command> sh_addSalt(createObject<AddSaltCommand>());		//食塩を1gずつ加える実験
	shared_ptr<Command> sh_addWater(createObject<AddWaterCommand>());	//水を10gずつ加える実験
	shared_ptr<Command> sh_makeSaltWater(createObject<MakeSaltWaterCommand>());		//食塩水を作る実験

	//実験セットの生成
	shared_ptr<Beaker> sh_beaker1(createObject<Beaker, double>(100, 0));	//水100g、食塩0g
	shared_ptr<Beaker> sh_beaker2(createObject<Beaker, double>(0, 10));		//水0g、食塩10g
	shared_ptr<Beaker> sh_beaker3(createObject<Beaker, double>(90, 10));	//水90g、食塩10g

	//実験セットを実験内容コマンドオブジェクトにセット
	sh_addSalt->setBeaker(sh_beaker1);
	sh_addWater->setBeaker(sh_beaker2);
	sh_makeSaltWater->setBeaker(sh_beaker3);

	//実験
	sh_addSalt->execute();			//食塩を加える実験実行
	cout << endl;
	sh_addWater->execute();			//水を加える実験実行
	cout << endl;
	sh_makeSaltWater->execute();		//10%の食塩水100gを作る実験実行

	return 0;
}