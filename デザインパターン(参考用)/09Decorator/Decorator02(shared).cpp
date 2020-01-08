//Decorator（shared）
//既存のクラスに対する追加機能を、そのクラス自身に追加せずに、
//飾り付ける（Decorateする）感覚（コアとなるものにかぶせていくイメージ）で実装する。
//例）既存の処理の前後に新たな処理を付け加えることができる

//一番上位に、飾りとなるクラスと、飾られる側のクラスの共通interfaceクラスを定義する
//飾りクラスに今、飾っている対象（飾られる側のオブジェクト）を記憶させる
//
//【プログラム内容】
//デフォルトアイスクリームにトッピングをつける
//デフォルトアイスクリームは、バニラ、抹茶、カシューナッツ付バニラ
//トッピングは、カシューナッツ、スライスアーモンド
//デフォルトアイスクリームとトッピングクラスの共通interfaceクラスは、Icecreamクラス
//
//Decorator02(shared).cpp
//結果
//カシューナッツtoppingバニラアイスクリームはバニラ味
//カシューナッツtopping抹茶アイスクリームは抹茶味
//スライスアーモンドtoppingカシューナッツtoppingバニラアイスクリームはバニラ味

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

//////////////////////////////////////////////////////////////////
//アイスクリームinterfaceクラス定義
class Icecream {
public:
	virtual string getName() = 0;
	virtual string howSweet() = 0;
};

//Decorator定義----------------------------------------------------------
//基本アイスクリーム
//////////////////////////////////////////////////////////////////
//バニラアイスクリームクラス定義
class VanillaIcecream : public Icecream {
public:
	string getName(){ return "バニラアイスクリーム"; }
	string howSweet(){ return "バニラ味"; }
};
//------------------------------------------------------------
//抹茶アイスクリームクラス定義
class GreenTeaIcecream : public Icecream {
public:
	string getName(){ return "抹茶アイスクリーム"; }
	string howSweet(){ return "抹茶味"; }
};
//------------------------------------------------------------
//カシューナッツ付きバニラアイスクリーム定義
class CashewNutsVanillaIcecream : public VanillaIcecream {
public:
	string getName(){ return "カシューナッツバニラアイスクリーム"; }
};
//------------------------------------------------------------

//トッピング定義----------------------------------------------
//カシューナッツトッピングクラス定義
class CashewNutsToppingIcecream : public Icecream {
	shared_ptr<Icecream> sh_orgIce;			//トッピングするアイスクリーム
public:
	CashewNutsToppingIcecream(shared_ptr<Icecream> sh_ice){ sh_orgIce = sh_ice; }

	string getName()
	{
		string name = "カシューナッツtopping";
		name += sh_orgIce->getName();
		return name;
	}

	string howSweet(){ return sh_orgIce->howSweet(); }
};
//------------------------------------------------------------
//カシューナッツトッピングクラス定義
class SliceAlmondToppingIcecream : public Icecream {
	shared_ptr<Icecream> sh_orgIce;			//トッピングするアイスクリーム
public:
	SliceAlmondToppingIcecream(shared_ptr<Icecream> sh_ice){ sh_orgIce = sh_ice; }

	string getName()
	{
		string name = "スライスアーモンドtopping";
		name += sh_orgIce->getName();
		return name;
	}

	string howSweet(){ return sh_orgIce->howSweet(); }
};
//-----------------------------------------------------------------------

///////////////////////////////////////////////////////////////////
int main()
{
	shared_ptr<Icecream> sh_baseIce1(createObject<VanillaIcecream>());
	shared_ptr<Icecream> sh_ice1;
	sh_ice1 = createObject<CashewNutsToppingIcecream, shared_ptr<Icecream>>(sh_baseIce1);

	shared_ptr<Icecream> sh_baseIce2(createObject<GreenTeaIcecream>());
	shared_ptr<Icecream> sh_ice2;
	sh_ice2 = createObject<CashewNutsToppingIcecream, shared_ptr<Icecream>>(sh_baseIce2);

	shared_ptr<Icecream> sh_ice3(createObject<SliceAlmondToppingIcecream, shared_ptr<Icecream>>(sh_ice1));

	cout << sh_ice1->getName() << "は" << sh_ice1->howSweet() << endl;
	cout << sh_ice2->getName() << "は" << sh_ice2->howSweet() << endl;
	cout << sh_ice3->getName() << "は" << sh_ice3->howSweet() << endl;

	return 0;
}
