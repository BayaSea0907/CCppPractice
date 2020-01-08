//Command（shared）
//Command00(shared)とCommand01AppendCommand両方をひとつにしたプログラム
//
//実験セットのソースコードを変更しなくても、実験を追加することができる
//また、既存の実験内容を組み合わせて、新たな実験を作れる
//新しい実験内容のexecuteメソッドに、既存の実験内容のexecuteメソッドを記述すると、
//新しい実験内容が実行された際、記述した順に既存の実験内容も実行される

//【追加実験】
//濃度10%の食塩水100gに、食塩を1gずつ加えていき、飽和食塩水を作る実験
//食塩水を作る実験コマンド（MakeSaltWaterCommand）　と　食塩を1gずつ加える実験コマンド（AddSaltCommand）を
//組み合わせた実行コマンドクラスを定義する
//
//Command02(shared).cpp
//結果
//塩を1gずつ加える実験
//水：100g
//塩：36g
//濃度：26.4706%
//
//水を10gずつ加える実験
//水：30g
//塩：10g
//濃度：25%
//
//
//命令の組み合わせ
//塩水を作る実験
//水：90g
//塩：10g
//濃度：10%
//塩を1gずつ加える実験
//水：90g
//食塩：33g
//濃度：26.8293%
//塩水を作り、それに塩を1gずつ加える実験
//水：90g
//食塩：33g
//濃度：26.8293%
//

#include <iostream>
#include <string>
#include <list>			//命令組み合わせ用として
#include <memory>
using namespace std::tr1;
using namespace std;

//オブジェクト生成テンプレート関数------------------------------------
/////////////////////////////////////////////////////////////
template<class X>
shared_ptr<X> createObject()
{
	return (shared_ptr<X>)(new X);
}
//-----------------------------------------------------------
template<class X, class Y>
shared_ptr<X> createObject(Y n)
{
	return (shared_ptr<X>)(new X(n));
}
//-----------------------------------------------------------
template<class X, class Y>
shared_ptr<X> createObject(Y n, Y m)
{
	return (shared_ptr<X>)(new X(n, m));
}
//---------------------------------------------------------------

/////////////////////////////////////////////////////////////
//命令（実験）対象クラス定義
class Beaker {
	double water;		//水
	double salt;		//塩
	bool melted;		//塩の溶解度（true：すべて溶けた、false：溶け残った）
public:
	Beaker(double bwater = 0.0, double bsalt = 0.0)
:water(bwater), salt(bsalt), melted(true)
	{
		mix();		//かき混ぜる
	}

	void addSalt(double asalt){ salt += asalt; }		//塩の追加
	void addWater(double awater){ water += awater; }		//水の追加

	//かき混ぜる
	void mix()
	{
		//溶けたか溶け残ったかの設定（常温での飽和食塩水の濃度は約26.4%）
		if((salt / (salt + water)) * 100 < 26.4)
			melted = true;		//溶けた
		else
			melted = false;		//溶け残った
	}

	double getSalt()const{ return salt; }
	double getWater()const{ return water; }
	bool isMelted()const{ return melted; }		//溶解状態を調べる

	//実験結果の記録
	void note()
	{
		cout << "水：" << water << "g" << endl; 
		cout << "塩：" << salt << "g" << endl;
		cout << "濃度：" << (salt / (water + salt)) * 100 << "%" << endl;
	}
};

//Command++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
/////////////////////////////////////////////////////////////
//命令interfaceクラス定義（抽象クラス）
class Command {
protected:
	shared_ptr<Beaker> sh_beaker;	//命令（実験）対象ビーカー管理
public:
	void setBeaker(shared_ptr<Beaker> sh_sbeaker){ sh_beaker = sh_sbeaker; } 

	virtual void execute() = 0;		//命令（実験）の実行

	//命令組み合わせで使用
	virtual void addCommand(shared_ptr<Command> sh_command){}
	virtual ~Command(){}
};

//命令クラス---------------------------------------------------
/////////////////////////////////////////////////////////////
//塩を1gずつ加えて飽和食塩水を作るクラス定義
class AddSaltCommand : public Command {
public:
	void execute()
	{
		//完全に溶けている間は塩を加える
		while(sh_beaker->isMelted())
		{
			sh_beaker->addSalt(1);	//塩を1g追加
			sh_beaker->mix();		//かき混ぜる
		}

		//実験結果の記録
		cout << "塩を1gずつ加える実験" << endl;
		sh_beaker->note();
	}
	~AddSaltCommand(){}
};
//-----------------------------------------------------------
//水を10gずつ加えて飽和食塩水を作るクラス定義
class AddWaterCommand : public Command {
public:
	void execute()
	{ 
		//溶け残っている間は水を加える
		while (!sh_beaker->isMelted())
		{ 
			sh_beaker->addWater(10);	//水を10g追加
			sh_beaker->mix();		//かき混ぜる
		}

		//実験結果の記録
		cout << "水を10gずつ加える実験" << endl;
		sh_beaker->note(); 
	}
	~AddWaterCommand(){}
};
//------------------------------------------------------------
//塩水を作るクラス定義
class MakeSaltWaterCommand : public Command {
public:
	void execute()
	{
		sh_beaker->mix();		//かき混ぜる

		//実験結果の記録
		cout << "塩水を作る実験" << endl;
		sh_beaker->note();
	}
	~MakeSaltWaterCommand(){}
};
//-----------------------------------------------------------
//【命令の組み合わせ用】作った塩水に塩を1gずつ加えて飽和食塩水を作るクラス定義
class MakeSaltWaterAddSaltCommand : public Command {
	list<shared_ptr<Command>> sh_lstCommand;		//命令（実験）リスト
public:
	//命令（実験）リストに命令を追加
	void addCommand(shared_ptr<Command> sh_command)
{ sh_lstCommand.push_back(sh_command); }

	void execute()
	{
		list<shared_ptr<Command>>::iterator
 sh_lstCommand_itr = sh_lstCommand.begin();

		//登録済命令（実験）の実行
		while(sh_lstCommand_itr != sh_lstCommand.end())
		{
			(*sh_lstCommand_itr)->execute();	//命令オブジェクトの実行
			sh_lstCommand_itr++;			//次の命令
		}

		//実験結果の記録
		cout << "塩水を作り、それに塩を1gずつ加える実験" << endl;
		sh_beaker->note();
	}
	~MakeSaltWaterAddSaltCommand(){}

};

//////////////////////////////////////////////////////////////////
int main()
{
	//命令オブジェクトの生成---------------------------------------
	//塩を1gずつ加える命令
	shared_ptr<Command> sh_addSalt(createObject<AddSaltCommand>());

	//水を10gずつ加える命令
	shared_ptr<Command> sh_addWater(createObject<AddWaterCommand>()); 

	//塩水を作る命令
	shared_ptr<Command> sh_makeSaltWater
(createObject<MakeSaltWaterCommand>());	

	//命令対象オブジェクト（初期状態）の生成--------------------------
	//水100g、塩0g
	shared_ptr<Beaker> sh_beaker1(createObject<Beaker, double>(100, 0));

	//水0g、塩10g	
shared_ptr<Beaker> sh_beaker2(createObject<Beaker, double>(0, 10));

	//----------------------------------------------------------
	//命令オブジェクトに命令対象オブジェクトを登録
	sh_addSalt->setBeaker(sh_beaker1);
	sh_addWater->setBeaker(sh_beaker2);

	//----------------------------------------------------------
	//命令実行
	sh_addSalt->execute();		//塩を加える
	cout << endl;
	sh_addWater->execute();		//水を加える
	cout << endl;

	//----------------------------------------------------------
	cout << endl << "命令の組み合わせ" << endl;

	//作った塩水に塩を1gずつ加える命令-----------
	shared_ptr<Command> sh_makeSaltWaterAddSalt
(createObject<MakeSaltWaterAddSaltCommand>());

	//水90g、塩10g--------------------------
	shared_ptr<Beaker> sh_beaker3(createObject<Beaker, double>(90, 10));

	//命令の組み合わせ用--------------------------------------
	sh_makeSaltWater->setBeaker(sh_beaker3);
	sh_addSalt->setBeaker(sh_beaker3);
	sh_makeSaltWaterAddSalt->setBeaker(sh_beaker3);

	//命令の組み合わせ（命令登録）
	sh_makeSaltWaterAddSalt->addCommand(sh_makeSaltWater); 	//塩水を作る
	sh_makeSaltWaterAddSalt->addCommand(sh_addSalt); 	//塩1gずつ加える

	sh_makeSaltWaterAddSalt->execute();	//命令実行（登録済命令の実行）


	return 0;
}

