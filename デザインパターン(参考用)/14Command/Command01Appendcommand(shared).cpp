//Command（shared）AppendCommand
//Command01(shared).cpp　に　実験コマンドを追加する
//
//実験セットのソースコードを変更しなくても、実験を追加することができる
//また、既存の実験内容を組み合わせて、新たな実験を作れる
//新しい実験内容のexecuteメソッドに、既存の実験内容のexecuteメソッドを記述すると、
//新しい実験内容が実行された際、記述した順に既存の実験内容も実行される

//【追加実験】
//濃度10%の食塩水100gに、食塩を1gずつ加えていき、飽和食塩水を作る実験

//
//Command01AppendCommand(shared).cpp
//結果
//食塩水を作る実験
//水：90g
//食塩：10g
//濃度：10%
//食塩を1gずつ加える実験
//水：90g
//食塩：33g
//濃度：26.8293%
//食塩水を作り、それに食塩を1gずつ加える実験
//水：90g
//食塩：33g
//濃度：26.8293%
//

#include <iostream>
#include <string>
#include <list>				//追加実験コマンド用として
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
	shared_ptr<Beaker> sh_beaker;		//実験セットオブジェクト（ビーカー）管理ポインタ
public:
	void setBeaker(shared_ptr<Beaker> sh_sbeaker){ sh_beaker = sh_sbeaker; }	//ビーカーの設定
	virtual void execute() = 0;													//実験の実行
	virtual void addCommand(shared_ptr<Command> sh_command){}					//追加コマンドで使用
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
//【追加実験】
//作った食塩水に食塩を1gずつ加えて飽和食塩水を作る実験
class MakeSaltWaterAddSaltCommand : public Command {
	list<shared_ptr<Command>> sh_lstCommand;					//実験リスト
public:
	//実験リストに実験コマンドを追加
	void addCommand(shared_ptr<Command> sh_command){ sh_lstCommand.push_back(sh_command); }

	void execute()
	{
		list<shared_ptr<Command>>::iterator sh_lstCommand_itr = sh_lstCommand.begin();

		//登録済実験コマンドの実行
		while(sh_lstCommand_itr != sh_lstCommand.end())
		{
			(*sh_lstCommand_itr)->execute();		//実験コマンドの実行
			sh_lstCommand_itr++;					//次の実験コマンド
		}

		//実験結果の記録
		cout << "食塩水を作り、それに食塩を1gずつ加える実験" << endl;
		sh_beaker->note();
	}
	~MakeSaltWaterAddSaltCommand(){}

};

//////////////////////////////////////////////////////////////////
int main()
{
	//実験内容コマンドオブジェクトの生成
	shared_ptr<Command> sh_makeSaltWater(createObject<MakeSaltWaterCommand>());	//食塩水を作る実験
	shared_ptr<Command> sh_addSalt(createObject<AddSaltCommand>());				//食塩を1gずつ加える実験

	//作った食塩水に食塩を1gずつ加える実験
	shared_ptr<Command> sh_makeSaltWaterAddSalt(createObject<MakeSaltWaterAddSaltCommand>());

	//実験セット（ビーカー）に食塩水を作る（水90g、食塩10g）
	shared_ptr<Beaker> sh_beaker(createObject<Beaker, double>(90, 10));

	//実験セットを実験内容コマンドオブジェクトにセット
	sh_makeSaltWater->setBeaker(sh_beaker);
	sh_addSalt->setBeaker(sh_beaker);
	sh_makeSaltWaterAddSalt->setBeaker(sh_beaker);

	//実験リストの設定（実験内容コマンドオブジェクトの組み合わせ）
	sh_makeSaltWaterAddSalt->addCommand(sh_makeSaltWater);	//食塩水を作る実験コマンド追加
	sh_makeSaltWaterAddSalt->addCommand(sh_addSalt);		//食塩1gずつ加える実験コマンドの追加

	//実験
	//実験リストに登録してある、食塩水を作る実験コマンドと食塩1gずつ加える実験コマンドが実行される
	sh_makeSaltWaterAddSalt->execute();

	return 0;
}
