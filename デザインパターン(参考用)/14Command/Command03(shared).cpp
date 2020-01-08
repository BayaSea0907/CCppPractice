//Command（shared-hero）
//
//Heroのアクションを命令で与えて行わせる

//Command03(shared-hero).cpp
//結果
//ジャンプ
//
//走る
//ジャンプ

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
//--------------------------------------------------------------------
/////////////////////////////////////////////////////////////
//命令対象クラス定義
class Hero {
public:
	void run(){ cout << "走る" << endl; }
	void jump(){ cout << "ジャンプ" << endl; }
};

//Command++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
/////////////////////////////////////////////////////////////
//命令interfaceクラス定義（抽象クラス）
class Command {
protected:
	shared_ptr<Hero> sh_hero;		//命令対象管理
public:
	void setHero(shared_ptr<Hero> sh_shero){ sh_hero = sh_shero; }

	virtual void execute() = 0;		//命令の実行
	virtual void addCommand(shared_ptr<Command> sh_command) = 0;
	virtual ~Command(){}
};

//命令クラス---------------------------------------------------
/////////////////////////////////////////////////////////////
//走るクラス定義
class Run : public Command {
public:
	void execute(){ sh_hero->run(); }
	void addCommand(shared_ptr<Command> sh_command){}
	~Run(){}
};
//------------------------------------------------------------
//ジャンプクラス定義
class Jump : public Command {
public:
	void execute(){ sh_hero->jump(); }
	void addCommand(shared_ptr<Command> sh_command){}
	~Jump(){}
};
//-----------------------------------------------------------
//【命令の組み合わせ用】走ってジャンプクラス定義
class RunJump : public Command {
	list<shared_ptr<Command>> sh_lstCommand;		//命令リスト
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
	}
	~RunJump(){}
};

//////////////////////////////////////////////////////////////////
int main()
{
	//命令オブジェクトの生成---------------------------------------
	shared_ptr<Command> sh_run(createObject<Run>());			//走る命令
	shared_ptr<Command> sh_jump(createObject<Jump>());			//ジャンプ命令
	shared_ptr<Command> sh_runJump(createObject<RunJump>());	//走ってジャンプ命令

	//命令対象オブジェクトの生成-----------------------------------
	shared_ptr<Hero> sh_hero(createObject<Hero>());

	//走る
	sh_jump->setHero(sh_hero);	//命令オブジェクトに命令対象オブジェクトを登録
	sh_jump->execute();			//命令実行
	cout << endl;

	sh_runJump->setHero(sh_hero);

	//走ってジャンプ
	sh_runJump->addCommand(sh_run);		//命令リストへ登録
	sh_runJump->addCommand(sh_jump);

	sh_runJump->execute();			//命令実行

	return 0;
}

