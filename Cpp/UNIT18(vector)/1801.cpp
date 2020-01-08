//**********************************************************
// ファイル名		:問題1801.cpp
//**********************************************************
// 作成者			:BayaSea
// 作成日			:2016.11.10
//**********************************************************

#include <iostream>
#include <memory>
#include <string>			//文字列操作用クラス
#include <vector>			//vector操作用用クラス
using namespace std;

//チームクラス定義
class Team {
	string name;
public:
	Team(string tn = "") :name(tn){}
	string getName()const{ return name; }
};
///////////////////////////////////////////////////////////////
//オブジェクトを生成するテンプレート外部関数
template<class X>
shared_ptr<X> create(string n){ return (shared_ptr<X>)(new X(n)); }
////////////////////////////////////////////////////////////////
int main()
{
	vector<shared_ptr<Team>> sh_vTeam;
	
	sh_vTeam.push_back(create<Team>("TENJIN"));
	sh_vTeam.push_back(create<Team>("SAIKA"));

	for (size_t i = 0; i < sh_vTeam.size(); i++)
	{
		cout << sh_vTeam[i]->getName() << endl;
	}

	return 0;
}
