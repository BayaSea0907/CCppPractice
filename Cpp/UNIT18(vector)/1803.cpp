//**********************************************************
// ファイル名		:問題1803.cpp
//**********************************************************
// 作成者			:BayaSea
// 作成日			:2016.11.10
//**********************************************************
// Q.結果はどうなりますか？
//
// A.YoronとTrisimaの間に、Aosimaが2つ挿入された。
//   
//	実行結果
//	 Yoron
//	 Aosima
//	 Aosima
//	 Trisima
//**********************************************************
#include <iostream>
#include <memory>
#include <string>			//文字列操作用クラス
#include <vector>			//vector操作用用クラス
using namespace std;

//島クラス定義
class Island {
	string name;			//島名
public:
	Island(string in = "") :name(in){}
	string getName()const{ return name; }
};
///////////////////////////////////////////////////////////////
//オブジェクトを生成するテンプレート外部関数
template<class X>
shared_ptr<X> create(string n){ return (shared_ptr<X>)(new X(n)); }
////////////////////////////////////////////////////////////////
int main()
{
	vector<shared_ptr<Island>> sh_vIsland;
	vector<shared_ptr<Island>>::iterator sh_vIslandItr;

	sh_vIsland.push_back(create<Island>("Yoron"));
	sh_vIsland.push_back(create<Island>("Torisima"));
	sh_vIslandItr = sh_vIsland.begin();
	sh_vIsland.insert(sh_vIslandItr + 1, 2, create<Island>("Aosima"));
	sh_vIslandItr = sh_vIsland.begin();

	for (size_t i = 0; i < sh_vIsland.size(); i++)
	{
		cout << sh_vIsland[i]->getName() << endl;
	}

	return 0;
}

