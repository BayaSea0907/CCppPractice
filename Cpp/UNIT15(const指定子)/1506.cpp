//**********************************************************
// ファイル名		:問題1505.cpp
//**********************************************************
// 作成者			:BayaSea
// 更新日			:2016.11.10
//**********************************************************
#include <iostream>
#include <memory>
#include <string>
using namespace std;

//商品クラス定義
class Goods {
protected:
	string name;		//商品名
public:
	Goods(string n = " ") :name(n){}
	virtual void show() const = 0;
};
///////////////////////////////////////////////////////////////////
//飲料水クラス定義
class Drink : public Goods {
	int num;	//本数
public:
	Drink(string ds = "TEA", int dn = 100) :num(dn), Goods(ds) {};
	void show() const { cout << name << "=" << num << endl; }
};
///////////////////////////////////////////////////////////////////
//オブジェクトを生成するテンプレート外部関数
template<class X>
shared_ptr<X> create(){ return (shared_ptr<X>)(new X); }
///////////////////////////////////////////////////////////////////
int main()
{
	shared_ptr<Goods> sh_drink(create<Drink>());
	sh_drink->show();

	return 0;
}
