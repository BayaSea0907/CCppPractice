//templateMethod（interfaceクラス使用）
//派生クラスに一連の処理手順を実装するメソッドがない場合、あるいは
//処理のデフォルト処理だけがある場合には、
//interfaceクラスの仮想メソッドにデフォルト処理を定義したりする
//
//ここでは
//interfaceクラスの前処理FrontProcにデフォルト処理を定義
//Concertクラスの前処理FrontProcを未定義とする
//
//templateMethod01(normal-default).cpp
//前処理のデフォルト処理
//実装した前処理後の処理
//Concert 「祭」
//実装した前処理後の処理
//Concert 「ありがとう」
//実装した後処理後の処理

//Game opennning
//実装した前処理後の処理
//Game playing
//実装した本処理後の処理
//Game closing
//実装した後処理後の処理

#include <iostream>
using namespace std;

//一連の処理の流れを定義したクラス----------------------------------
///////////////////////////////////////////////////////////////////////
//templateMmethod　interfaceクラス定義
//すべての処理が、派生クラスで「実装」される
class CProcBase
{
	//②派生クラスの実装メソッド③で上書きされる（実装される）
	virtual bool FrontProc()
	{
		cout << "前処理のデフォルト処理" << endl;
		return true;
	}
	virtual bool MainProc(){ return true; }
	virtual bool EndProc(){ return true; }
public:
	//①ここに定義した処理の順番に、仮想メソッドを呼び出す
	void processFlowList(CProcBase* pflP)
	{
		//前処理
		if( pflP->FrontProc() )	//②の仮想メソッドを呼び出す
		{
			//falseが返ってきた場合
			cout << "実装した前処理後の処理" << endl;
		}
		//本処理
		if( pflP->MainProc() )		//②の仮想メソッドを呼び出す
		{
			//falseが返ってきた場合
			cout << "実装した本処理後の処理" << endl;
		}
		//後処理
		if( pflP->EndProc() )		//②の純粋仮想メソッドを呼び出す
		{
			//falseが返ってきた場合
			cout << "実装した後処理後の処理" << endl;
		}
	}
};
///////////////////////////////////////////////////////////////////////

//一連の実装処理クラス生成---------------------------------------------
///////////////////////////////////////////////////////////////////////
//コンサート処理クラス定義
class Concert : public CProcBase {
/*
	//前処理
	bool FrontProc()
	{
		cout << "Concert 「よってらっしゃい　みてらっしゃい」" << endl;
		return false;
	}
*/
	//本処理
	bool MainProc()
	{
		cout << "Concert 「祭」" << endl;
		return true;
	}
	//後処理
	bool EndProc()
	{
		cout << "Concert 「ありがとう」" << endl;
		return true;
	}
};
//------------------------------------------------------------------
//Game処理クラス定義
class Game : public CProcBase {
	//前処理
	bool FrontProc()
	{
		cout << "Game opennning" << endl;
		return true;
	}
	//本処理
	bool MainProc()
	{
		cout << "Game playing" << endl;
		return true;
	}
	//後処理
	bool EndProc()
	{
		cout << "Game closing" << endl;
		return true;
	}
};
//-----------------------------------------------------------------------

///////////////////////////////////////////////////////////////////////
int main()
{
	CProcBase* concertP(new Concert);
	CProcBase* gameP(new Game);

	//それぞれの一連の処理を実行する
	concertP->processFlowList(concertP);	//コンサート
	cout << endl;
	gameP->processFlowList(gameP);			//ゲーム

	delete concertP;
	delete gameP;

	return 0;
}
