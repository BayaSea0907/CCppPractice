//State（normal）
//「状態」をクラスとして表現して、状態の変化に応じて振る舞いが変わるようにする
//例えば、「機嫌のいい状態」「機嫌が悪い状態」の2つの状態に応じた振舞いが変わる

//Stateパターンの構造は、Strategyパターンと似ているが、目的が異なる
//Strategyパターンは、アルゴリズムの切り替えを行うので、基本的にそれぞれの戦略クラスの処理は同じ。
//戦略クラスの切り替えはそれほど頻繁に行わない
//Stateパターンは、今の「状態」に応じて振る舞いが異なる

//ヒーローの状態（機嫌悪い、機嫌よい、恋愛中）に応じて、朝の挨拶、防寒対策を切り替える
//状態interfaceクラスを継承した各状態クラスを定義し、状態対象オブジェクトに今の状態を登録して
//振舞う
//
//State01(normal).cpp
//結果
//おお：ももひき
//おっす！：走る
//おはよう！：マフラー

#include <iostream>
#include <string>
using namespace std;

//Sate定義----------------------------------------------------------
/////////////////////////////////////////////////////////////////
//状態interfaceクラス定義
class State {
public:
	virtual string morningGreet() = 0;				//朝のあいさつを定義
	virtual string getProtectionForCold() = 0;		//防寒対策を定義
};

//---------------------------------------------------------------
/////////////////////////////////////////////////////////////////
//機嫌悪い状態クラス定義
class BadMoodState : public State {
public:
	string morningGreet(){ return "おお"; }					//朝の挨拶（ぶっきらぼう）
	string getProtectionForCold(){ return "ももひき"; }		//防寒対策
};
//---------------------------------------------------------------
//機嫌良い状態（平常日）クラス定義
class OrdinaryState : public State {
public:
	string morningGreet(){ return "おっす！"; }			//朝の挨拶（男らしく）
	string getProtectionForCold(){ return "走る"; }		//防寒対策
};
//---------------------------------------------------------------
//恋している状態クラス定義
class FallingLoveState : public State {
public:
	string morningGreet(){ return "おはよう！"; }			//朝の挨拶（女の子らしく）
	string getProtectionForCold(){ return "マフラー"; }		//防寒対策
};
//--------------------------------------------------------------------

//状態対象クラス-------------------------------------------------------
//////////////////////////////////////////////////////////////////
//ヒーロー状態クラス定義
class StateHero {
	State* stateP;			//状態
public:
	void changeState(State* sstateP){ stateP = sstateP; }			//状態変更

	string morningGreet(){ return stateP->morningGreet(); }					//朝のあいさつ
	string getProtectionForCold(){ return stateP->getProtectionForCold(); }	//防寒対策
};
//--------------------------------------------------------------------

///////////////////////////////////////////////////////////////////
int main()
{
	StateHero* heroP = new StateHero;
	State* stateP;

	//機嫌悪い
	stateP = new BadMoodState();
	heroP->changeState(stateP);			//ヒーローに状態を登録
	cout << heroP->morningGreet() << "：" << heroP->getProtectionForCold() << endl;
	
	//機嫌よい
	delete stateP;
	stateP = new OrdinaryState();
	heroP->changeState(stateP);			//ヒーローに状態を登録
	cout << heroP->morningGreet() << "：" << heroP->getProtectionForCold() << endl;
	
	//恋におちた
	delete stateP;
	stateP = new FallingLoveState();
	heroP->changeState(stateP);			//ヒーローに状態を登録
	cout << heroP->morningGreet() << "：" << heroP->getProtectionForCold() << endl;
	
	delete stateP;
	delete heroP;

	return 0;
}
