//Visitor（shared）
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

//Visitor02(shared).cpp
//結果
//パン屋を訪問
//Bekery『毎度ありー』
//
//郵便局を訪問
//Postoffice『手紙承りました』

#include <iostream>
#include <string>
#include <memory>
using namespace std::tr1;
using namespace std;

class Visitor;

//オブジェクト生成テンプレート関数-----------------------------------
///////////////////////////////////////////////////////////////////
template<class X>
shared_ptr<X> createObject()
{
	return (shared_ptr<X>)(new X);
}
//--------------------------------------------------------------------

//acceptor--------------------------------------------------------------
////////////////////////////////////////////////////////////////////
//訪問先クラスinterfaceクラス定義（抽象クラス）
class Shop {
public:
	virtual void accept(shared_ptr<Visitor> sh_visitor) = 0;		//訪問者受入
	virtual ~Shop(){}
};

//実際の訪問先クラス定義---------------------------------------------
/////////////////////////////////////////////////////////////////////
//パン屋
class Bakery : public Shop {
public:
	void accept(shared_ptr<Visitor> sh_visitor);
	void sellBread(){ cout << "Bekery『毎度ありー』" << endl; }
};
//-------------------------------------------------------------------
//郵便局
class PostOffice : public Shop {
public:
	void accept(shared_ptr<Visitor> sh_visitor);
	void postLetter(){ cout << "Postoffice『手紙承りました』" << endl; }
};
//-----------------------------------------------------------------------

//Visitor----------------------------------------------------------------
////////////////////////////////////////////////////////////////////
//訪問者クラス定義
//acceptorから訪問先のアドレスがthisで渡ってくるので、引数はnormalなポインタで受ける（sharedでは受け取れない）
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
void Bakery::accept(shared_ptr<Visitor> sh_visitor){ sh_visitor->visitBakery(this); }

//郵便局
void PostOffice::accept(shared_ptr<Visitor> sh_visitor){ sh_visitor->visitPostOffice(this); }
//-----------------------------------------------------------------------

/////////////////////////////////////////////////////////////////////
int main()
{
	shared_ptr<Shop> sh_shop1(createObject<Bakery>());			//訪問先パン屋オブジェクト生成
	shared_ptr<Shop> sh_shop2(createObject<PostOffice>());		//訪問先郵便局オブジェクト生成
	shared_ptr<Visitor> sh_visitor(createObject<Visitor>());	//訪問者オブジェクト生成

	cout << "パン屋を訪問" << endl;
	sh_shop1->accept(sh_visitor);		//パン屋を訪問

	cout << endl;
	cout << "郵便局を訪問" << endl;
	sh_shop2->accept(sh_visitor);		//郵便局を訪問

	return 0;
}