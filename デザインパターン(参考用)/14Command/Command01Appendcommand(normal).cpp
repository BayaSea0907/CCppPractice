//Command（normal）AppendCommand
//Command01(normal).cpp　に　実験コマンドを追加する
//
//実験セットのソースコードを変更しなくても、実験を追加することができる
//また、既存の実験内容を組み合わせて、新たな実験を作れる
//新しい実験内容のexecuteメソッドに、既存の実験内容のexecuteメソッドを記述すると、
//新しい実験内容が実行された際、記述した順に既存の実験内容も実行される

//【追加実験】
//濃度10%の食塩水100gに、食塩を1gずつ加えていき、飽和食塩水を作る実験

//
//Command01AppendCommand(normal).cpp
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
using namespace std;

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
	Beaker* beakerP;		//実験セットオブジェクト（ビーカー）管理ポインタ
public:
	void setBeaker(Beaker* sbeakerP){ beakerP = sbeakerP; }		//ビーカーの設定
	virtual void execute() = 0;									//実験の実行
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
		while(beakerP->isMelted())
		{
			beakerP->addSalt(1);		//食塩を1g追加
			beakerP->mix();				//かき混ぜる
		}

		//実験結果の記録
		cout << "食塩を1gずつ加える実験" << endl;
		beakerP->note();
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
		while (!beakerP->isMelted())
		{ 
			beakerP->addWater(10);		//水を10g追加
			beakerP->mix();				//かき混ぜる
		}

		//実験結果の記録
		cout << "水を10gずつ加える実験" << endl;
		beakerP->note(); 
	}
	~AddWaterCommand(){}
};
//------------------------------------------------------------------
//食塩水を作る実験コマンドクラス定義
class MakeSaltWaterCommand : public Command {
public:
	void execute()
	{
		beakerP->mix();		//かき混ぜる

		//実験結果の記録
		cout << "食塩水を作る実験" << endl;
		beakerP->note();
	}
	~MakeSaltWaterCommand(){}
};
//-----------------------------------------------------------------------
//【追加実験】
//作った食塩水に食塩を1gずつ加えて飽和食塩水を作る実験
class MakeSaltWaterAddSaltCommand : public Command {
	list<Command*> lstCommand;							//実験リスト
public:
	//実験リストに実験コマンドを追加
	void addCommand(Command* commandP){ lstCommand.push_back(commandP); }

	void execute()
	{
		list<Command*>::iterator lstCommand_itr = lstCommand.begin();

		//登録済実験コマンドの実行
		while(lstCommand_itr != lstCommand.end())
		{
			(*lstCommand_itr)->execute();		//実験コマンドの実行
			lstCommand_itr++;					//次の実験コマンド
		}

		//実験結果の記録
		cout << "食塩水を作り、それに食塩を1gずつ加える実験" << endl;
		beakerP->note();
	}
	~MakeSaltWaterAddSaltCommand(){}

};

//////////////////////////////////////////////////////////////////
int main()
{
	//実験内容コマンドオブジェクトの生成
	Command* makeSaltWaterP = new MakeSaltWaterCommand;		//食塩水を作る実験
	Command* addSaltP = new AddSaltCommand;					//食塩を1gずつ加える実験

	//作った食塩水に食塩を1gずつ加える実験
	MakeSaltWaterAddSaltCommand* makeSaltWaterAddSaltP = new MakeSaltWaterAddSaltCommand;

	//実験セット（ビーカー）に食塩水を作る（水90g、食塩10g）
	Beaker* beakerP = new Beaker(90, 10);

	//実験セットを実験内容コマンドオブジェクトにセット
	makeSaltWaterP->setBeaker(beakerP);
	addSaltP->setBeaker(beakerP);
	makeSaltWaterAddSaltP->setBeaker(beakerP);

	//実験リストの設定（実験内容コマンドオブジェクトの組み合わせ）
	makeSaltWaterAddSaltP->addCommand(makeSaltWaterP);	//食塩水を作る実験コマンド追加
	makeSaltWaterAddSaltP->addCommand(addSaltP);		//食塩1gずつ加える実験コマンドの追加

	//実験
	//実験リストに登録してある、食塩水を作る実験コマンドと食塩1gずつ加える実験コマンドが実行される
	makeSaltWaterAddSaltP->execute();

	delete makeSaltWaterP;
	delete addSaltP;
	delete makeSaltWaterAddSaltP;
	delete beakerP;

	return 0;
}
