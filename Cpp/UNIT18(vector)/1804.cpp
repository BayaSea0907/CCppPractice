//**********************************************************
// ファイル名		:問題1803.cpp
//**********************************************************
// 作成者			:BayaSea
// 作成日			:2016.11.10
//**********************************************************
// Q.どうなりますか？
//
// A.DAISONとPLAZAの間に、EMIONを3つ挿入して、
//	 ループでsh_vShopの最初から最後までの要素を表示した。
//	 表示の際に、*sh_vShopItrとやっていたので、sh_vShopのポインタを共有しているらしい。
//**********************************************************
#include <iostream>
#include <memory>
#include <string>
#include <vector>
using namespace std;

//店舗クラス定義
class Shop {
	string name;                    //店名
public:
	Shop(string sn = "") :name(sn){}
	string getName()const{ return name; }
};
///////////////////////////////////////////////////////////////
//オブジェクトを生成するテンプレート外部関数
template<class X>
shared_ptr<X> create(string n){ return (shared_ptr<X>)(new X(n)); }
///////////////////////////////////////////////////////////////
int main()
{
	shared_ptr<Shop> sh_shop[2] =
	{
		create<Shop>("DAISO"),
		create<Shop>("PLAZA")
	};

	shared_ptr<Shop> sh_appendShop(create<Shop>("EMION"));

	vector<shared_ptr<Shop>> sh_vShop;
	vector<shared_ptr<Shop>>::iterator sh_vShopItr;

	for (size_t i = 0; i < 2; i++)    sh_vShop.push_back(sh_shop[i]);

	sh_vShopItr = sh_vShop.begin();

	sh_vShop.insert(sh_vShopItr + 1, 3, sh_appendShop);    //要素を挿入

	for (sh_vShopItr = sh_vShop.begin();
		sh_vShopItr != sh_vShop.end(); sh_vShopItr++)
	{
		cout << (*sh_vShopItr)->getName() << endl;
	}

	return 0;
}

