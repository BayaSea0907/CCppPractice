//Bridge（shared）
//クラスを機能と実装に分ける際の橋渡しを行う
//Bridgeを使うことによって、機能や実装の拡張が行いやすくなる
//
//例えば、アイテムの獲得手段として、交換、略奪、購買の３種類があるものとする
//これが実装部分となり、アイテム獲得interfaceクラスAcquireを継承させる
//そして、獲得者には、悪人、善人、商人の３人がおり、それぞれアイテムを獲得する
//３人は同じ方法getItemメソッド呼び出しで獲得するものとする
//この際、３人の獲得と実装の獲得手段を結びつけるために、３人をBridge　interfaceクラスを継承させて定義する
//このinterceクラスが、機能部分となる
//このように実装と機能を分離させることによって、追加等の拡張が容易になる

//Bridge00(shared).cpp
//結果
//善人は　交換して手に入れた
//悪人は　略奪して手に入れた
//商人は　買って手に入れた

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
//------------------------------------------------------------------
template<class X, class Y>
shared_ptr<X> createObject()
{
	return (shared_ptr<X>)(new X(createObject<Y>()));
}
//------------------------------------------------------------------

//アイテム獲得クラス------------------------------------------------
//////////////////////////////////////////////////////////////////
//アイテム獲得interfaceクラス定義（抽象クラス）
class Acquire {
public:
	virtual void getItem() = 0;
};

//獲得手段クラス--------------------------------------------------
//////////////////////////////////////////////////////////////////
//交換クラス定義
class Exchange : public Acquire {
public:
	void getItem(){ cout << "交換して手に入れた" << endl; }
};
//----------------------------------------------------------------
//略奪クラス定義
class Plunder : public Acquire {
public:
	void getItem(){ cout << "略奪して手に入れた" << endl; }
};
//------------------------------------------------------------------
//購買クラス定義
class purchase : public Acquire {
public:
	void getItem(){ cout << "買って手に入れた" << endl; }
};
//------------------------------------------------------------------

//////////////////////////////////////////////////////////////////
//Bridge　interfaceクラス定義（抽象クラス）
class Bridge {
protected:
	shared_ptr<Acquire> sh_Acquire;			//獲得手段オブジェクト管理
public:
	Bridge(shared_ptr<Acquire> sh_bacqire):sh_Acquire(sh_bacqire){}
	virtual void getItem()const = 0;
	virtual ~Bridge(){}
};

//////////////////////////////////////////////////////////////////
//悪人欲求クラス定義
class Villain : public Bridge {
public:
	//獲得手段をBridgeに登録
	Villain(shared_ptr<Acquire> sh_bacqire):Bridge(sh_bacqire){}
	void getItem()const{ sh_Acquire->getItem(); }				//アイテム獲得
	~Villain(){}
};
//--------------------------------------------------------------------
//善人欲求クラス定義
class Virtue : public Bridge {
public:
	//獲得手段をBridgeに登録
	Virtue(shared_ptr<Acquire> sh_bacqire):Bridge(sh_bacqire){}
	void getItem()const{ sh_Acquire->getItem(); }				//アイテム獲得
	~Virtue(){}
};
//--------------------------------------------------------------------
//商人欲求クラス定義
class Dealer : public Bridge {
public:
	//獲得手段をBridgeに登録
	Dealer(shared_ptr<Acquire> sh_bacqire):Bridge(sh_bacqire){}
	void getItem()const{ sh_Acquire->getItem(); }				//アイテム獲得
	~Dealer(){}
};
//--------------------------------------------------------------------

///////////////////////////////////////////////////////////////////
int main()
{
	//獲得手段の生成
	shared_ptr<Bridge> sh_bridge1(createObject<Virtue, Exchange>());	//善人は交換
	shared_ptr<Bridge> sh_bridge2(createObject<Villain, Plunder>());	//悪人は略奪
	shared_ptr<Bridge> sh_bridge3(createObject<Dealer, purchase>());	//商人は購買

	//アイテムの獲得
	cout << "善人は　";
	sh_bridge1->getItem();

	cout << "悪人は　";
	sh_bridge2->getItem();

	cout << "商人は　";
	sh_bridge3->getItem();

	return 0;
}
