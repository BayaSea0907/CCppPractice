//Decorator（normal）
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
//Decorator01(normal).cpp
//結果
//カシューナッツtoppingバニラアイスクリームはバニラ味
//カシューナッツtopping抹茶アイスクリームは抹茶味
//スライスアーモンドtoppingカシューナッツtoppingバニラアイスクリームはバニラ味

#include <iostream>
#include <string>
using namespace std;

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
	Icecream* orgIceP;				//トッピングするアイスクリーム管理用ポインタ
public:
	CashewNutsToppingIcecream(Icecream* iceP){ orgIceP = iceP; }

	string getName()
	{
		string name = "カシューナッツtopping";
		name += orgIceP->getName();
		return name;
	}

	string howSweet(){ return orgIceP->howSweet(); }
};
//------------------------------------------------------------
//カシューナッツトッピングクラス定義
class SliceAlmondToppingIcecream : public Icecream {
	Icecream* orgIceP;				//トッピングするアイスクリーム管理用ポインタ
public:
	SliceAlmondToppingIcecream(Icecream* iceP){ orgIceP = iceP; }

	string getName()
	{
		string name = "スライスアーモンドtopping";
		name += orgIceP->getName();
		return name;
	}

	string howSweet(){ return orgIceP->howSweet(); }
};
//-----------------------------------------------------------------------

///////////////////////////////////////////////////////////////////
int main()
{
	Icecream* iceP1 = new CashewNutsToppingIcecream(new VanillaIcecream());
	Icecream* iceP2 = new CashewNutsToppingIcecream(new GreenTeaIcecream());
	Icecream* iceP3 = new SliceAlmondToppingIcecream(
						new CashewNutsToppingIcecream(new VanillaIcecream()));

	cout << iceP1->getName() << "は" << iceP1->howSweet() << endl;
	cout << iceP2->getName() << "は" << iceP2->howSweet() << endl;
	cout << iceP3->getName() << "は" << iceP3->howSweet() << endl;

	delete iceP1;
	delete iceP2;
	delete iceP3;

	return 0;
}
