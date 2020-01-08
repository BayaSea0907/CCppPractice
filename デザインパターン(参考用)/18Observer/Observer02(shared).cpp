//Observer（shared）
//オブジェクトの状態変化を、観察者（observer)に通知して状態の同期を取る
//
//【MediatorとObserverでは目的が違う】
//Mediatorでは、状態が変化すると複数のオブジェクト間の調停者（Mediator）へ一旦通知して、
//対象とするオブジェクトへ通知する
//つまり、Mediatorでは、各オブジェクトが直接的にやり取りする相手を調停者のみにして
//やり取りの経路を減らし、構造をすっきりさせる

//Observerは、あらかじめ登録しておいた観察者へ通知する
//Observerでは、状態の変化を、関係のある他のオブジェクトにも通知して状態に矛盾が
//生じないように同期を取ることを目的にする

//ここでは、簡単に、観察対象者の赤ちゃんが泣いたという状態変化に対応して、
//観察者の親（母親と父親）が対応させる（親自身の状態を変化させる）
//観察者（Observer）と観察対象者は、それぞれ抽象クラスを継承させて定義する
//観察者は、観察対象者から状態が変化した通知を受け取るメソッドを定義する
//観察対象者は、すべての観察者をvectorに登録する
//そして、観察対象者の状態が変化したならば、変化したことをvectorに登録した観察者へ通知する
//それぞれの観察者への通知は、観察者対象の抽象クラスに定義しておくと、
//すべての観察対象者共通の通知方法として用意できる

//観察者と観察対象者クラスの定義位置には気を付けること
//観察者interface定義を継承した観察者クラス定義は、観察者interface、観察対象者interface以降に
//定義しなければならない（観察者interface直後に定義するとコンパイルエラーとなる）

//観察者へ通知する時に、観察対象者自身のアドレス（this）を渡すが、thisはsharedポインタではないので、
//通常のポインタで受取る

//Observer02(shared).cpp
//結果
//オギャー　オギャー
//母親はTAROをあやせた
//父親はTAROが泣いてオロオロだ～

#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std::tr1;
using namespace std;

class Child;

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

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//Observer----------------------------------------------------------
//////////////////////////////////////////////////////////////////
//観察者interfaceクラス定義（抽象クラス）
class Parent {
public:
	//観察対象から変化した通知を受け取って、観察者自身を更新する
	virtual void takeCare(Child* childP) = 0;
};
//-------------------------------------------------------------------

//観察対象-----------------------------------------------------------
//////////////////////////////////////////////////////////////////
//観察対象interfaceクラス定義（抽象クラス）
class Child {
protected:
	vector<shared_ptr<Parent>> sh_vParents;		//観察者（親）管理vector
public:
	//観察者を追加
	void addParent(shared_ptr<Parent> sh_parent){ sh_vParents.push_back(sh_parent); }

	//観察者（親）へ現状を通知する
	//（通知メソッドを抽象クラス内で定義するれば、複数の観察対象者共通で使える）
	virtual void notifyParent()
	{
		for(int i = 0; i < (int)sh_vParents.size(); i++)
		{
			sh_vParents[i]->takeCare(this);
		}
	}

	virtual void cry() = 0;
	virtual string getName()const = 0;
};
//-------------------------------------------------------------------
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//Observer観察者定義-------------------------------------------------
//定義位置は、必ず観察対象者クラス定義の後にする
//////////////////////////////////////////////////////////////////
//母親クラス定義
class Mother : public Parent {
public:
	//通知を受け取り、自身を更新する
	void takeCare(Child* childP)
	{
		cout << "母親は" << childP->getName() << "をあやせた" << endl;
	}
};
//----------------------------------------------------------------
//////////////////////////////////////////////////////////////////
//母親クラス定義
class Father : public Parent {
public:
	//通知を受け取り、自身を更新する
	void takeCare(Child* childP)
	{
		cout << "父親は" << childP->getName() << "が泣いてオロオロだ～" << endl;
	}
};
//-------------------------------------------------------------------

//観察対象者定義--------------------------------------------------
//赤ちゃんクラス定義
class Baby : public Child {
	string name;			//名前
public:
	Baby(string sname):name(sname){}

	//（観察対象）赤ちゃん自身が「オギャー」と泣く状態に変化した
	void cry()
	{
		cout << "オギャー　オギャー" << endl;
		notifyParent();					//観察者（親）へ状態が変化したことを通知
	}

	string getName()const{ return name; }
};
//-------------------------------------------------------------------

//////////////////////////////////////////////////////////////////
int main()
{
	//観察者（親）生成
	shared_ptr<Parent> sh_mother(createObject<Mother>());
	shared_ptr<Parent> sh_father(createObject<Father>());

	//観察対象（子ども）生成
	shared_ptr<Child> sh_child(createObject<Baby, string>("TARO"));

	//観察対象（子ども）に観察者（親）を登録
	sh_child->addParent(sh_mother);
	sh_child->addParent(sh_father);

	sh_child->cry();		//赤ちゃんが泣いた（観察対象の状態が変化した）

	return 0;
}