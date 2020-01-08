//State（shared）
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
//State02(shared).cpp
//結果
//おお：ももひき
//おっす！：走る
//おはよう！：マフラー

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
//--------------------------------------------------------------------

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
	shared_ptr<State> sh_state;			//状態
public:
	void changeState(shared_ptr<State> sh_sstate){ sh_state = sh_sstate; }	//状態変更

	string morningGreet(){ return sh_state->morningGreet(); }					//朝のあいさつ
	string getProtectionForCold(){ return sh_state->getProtectionForCold(); }	//防寒対策
};
//--------------------------------------------------------------------

///////////////////////////////////////////////////////////////////
int main()
{
	shared_ptr<StateHero> sh_hero(createObject<StateHero>());
	shared_ptr<State> sh_state;

	//機嫌悪い
	sh_state = createObject<BadMoodState>();
	sh_hero->changeState(sh_state);			//ヒーローに状態を登録
	cout << sh_hero->morningGreet() << "：" << sh_hero->getProtectionForCold() << endl;
	
	//機嫌よい
	sh_state.reset();
	sh_state = createObject<OrdinaryState>();
	sh_hero->changeState(sh_state);			//ヒーローに状態を登録
	cout << sh_hero->morningGreet() << "：" << sh_hero->getProtectionForCold() << endl;
	
	//恋におちた
	sh_state.reset();
	sh_state = createObject<FallingLoveState>();
	sh_hero->changeState(sh_state);			//ヒーローに状態を登録
	cout << sh_hero->morningGreet() << "：" << sh_hero->getProtectionForCold() << endl;

	return 0;
}
