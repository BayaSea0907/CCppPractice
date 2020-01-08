//**********************************************************
// ファイル名		:問題1802.cpp
//**********************************************************
// 作成者			:BayaSea
// 作成日			:2016.11.10
//**********************************************************
#include <iostream>
#include <memory>
#include <string>			//文字列操作用クラス

#include <vector>			//vector操作用用クラス
using namespace std;

//レンタルクラス定義
class Rental {
	int mem;		//会員数
public:
	Rental(int rm = 0) :mem(rm){}
	int getMem()const{ return mem; }
};
///////////////////////////////////////////////////////////////
//オブジェクトを生成するテンプレート外部関数
template<class X>
shared_ptr<X> create(int n){ return (shared_ptr<X>)(new X(n)); }
///////////////////////////////////////////////////////////////
//①sharedポインタを初期値にもつvector宣言

/*
int main()
{
	vector<shared_ptr<Rental>> sh_vRent(3, create<Rental>(100));

	for (size_t i = 0; i < sh_vRent.size(); i++)
	{
		cout << "[" << i << "]=" << sh_vRent[i]->getMem() << endl;
		cout << "&" << sh_vRent[i] << endl;
	}

	return 0;
}
*/
///////////////////////////////////////////////////////////////
//②ポインタを初期値にもつvector宣言
int main()
{
	vector<Rental*> vRentP(3, new Rental(100));

	for (size_t i = 0; i < vRentP.size(); i++)
	{
		cout << "[" << i << "]=" << vRentP[i]->getMem() << endl;
	}

	delete vRentP[0];	
	//----------------------------------------------------------
	// A.2重開放エラーが起きている。
	//   全ての要素で領域を共有しているため。
	//	 shared_ptrは参照回数をカウントしてるのでエラーは起きない。
	//----------------------------------------------------------

	return 0;
}
