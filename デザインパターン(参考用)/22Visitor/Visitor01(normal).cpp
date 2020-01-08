//Visitor（normal）
//Visitorでは、「処理」を訪問者であるVisitorオブジェクトに記述することで、処理の追加を簡単する
//処理対象のacceptorオブジェクトは、Visitorオブジェクトを受け入れるacceptメソッドを実装する

//訪問先に訪問者が訪れる－＞訪問先－＞訪問者（訪問目的の処理）－＞訪問先　という流れで処理が行われ

//例えば、訪問者Visitorがパン屋を訪問してパンを買うものとする
//Visitorパターンの処理の流れは次のようになる
//①パン屋が訪問者を受入れる
//	main()の	sh_shop1->accept(sh_visitor);
//②すると、訪問を受けたパン屋は訪問者の訪問目的を受入れる
//	パン屋のaaceptor定義
//	void Bakery::accept(shared_ptr<Visitor> sh_visitor){ sh_visitor->visitBakery(this); }
//③次に訪問者が訪問目的である（パンを買う）行為を行う
//	Visitorクラスのパン屋訪問（パンを買う）定義
//	void visitBakery(Bakery* bakeryP){ bakeryP->sellBread(); }
//④最後に、訪問先のパン屋が訪問者の行為に対して反応する
//	パン屋クラス
//	void sellBread(){ cout << "Bekery『毎度ありー』" << endl; }

//Visitor01(normal).cpp
//結果
//パン屋を訪問
//Bekery『毎度ありー』
//
//郵便局を訪問
//Postoffice『手紙承りました』

#include <iostream>
#include <string>
using namespace std;

class Visitor;

//acceptor--------------------------------------------------------------
////////////////////////////////////////////////////////////////////
//訪問先クラスinterfaceクラス定義（抽象クラス）
class Shop {
public:
	virtual void accept(Visitor* visitorP) = 0;		//訪問者受入
	virtual ~Shop(){}
};

//実際の訪問先クラス定義---------------------------------------------
/////////////////////////////////////////////////////////////////////
//パン屋
class Bakery : public Shop {
public:
	void accept(Visitor* visitorP);
	void sellBread(){ cout << "Bekery『毎度ありー』" << endl; }
};
//-------------------------------------------------------------------
//郵便局
class PostOffice : public Shop {
public:
	void accept(Visitor* visitorP);
	void postLetter(){ cout << "Postoffice『手紙承りました』" << endl; }
};
//-----------------------------------------------------------------------

//Visitor----------------------------------------------------------------
////////////////////////////////////////////////////////////////////
//訪問者クラス定義
class Visitor {
public:
	//パン屋訪問（パンを買う）
	void visitBakery(Bakery* bakeryP){ bakeryP->sellBread(); }

	//郵便局訪問（手紙を出す）
	void visitPostOffice(PostOffice* postOfficeP){ postOfficeP->postLetter(); }
};
//-----------------------------------------------------------------------

//訪問先クラスのacceptor定義---------------------------------------------
//ここの位置に定義しないとcompaileError
/////////////////////////////////////////////////////////////////////
//パン屋
void Bakery::accept(Visitor* visitorP){ visitorP->visitBakery(this); }

//郵便局
void PostOffice::accept(Visitor* visitorP){ visitorP->visitPostOffice(this); }
//-----------------------------------------------------------------------

/////////////////////////////////////////////////////////////////////
int main()
{
	Shop* shopP1 = new Bakery;			//訪問先パン屋オブジェクト生成
	Shop* shopP2 = new PostOffice;		//訪問先郵便局オブジェクト生成
	Visitor* visitorP = new Visitor;	//訪問者オブジェクト生成

	cout << "パン屋を訪問" << endl;
	shopP1->accept(visitorP);			//パン屋を訪問

	cout << endl;
	cout << "郵便局を訪問" << endl;
	shopP2->accept(visitorP);			//郵便局を訪問

	delete shopP1;
	delete shopP2;
	delete visitorP;

	return 0;
}