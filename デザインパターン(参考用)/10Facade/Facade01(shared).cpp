//Facade(shared)
//クラスの利用者が、その処理内容を知らなくても、かつ、オブジェクトを生成しなくても
//ただ１つの窓口となるメソッドを呼び出すだけで処理したい場合に使う
//利用者に、複雑な処理内容を意識させないことを目的で利用する
//
//Facade01(shared).cpp
//結果
//314.159

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
//--------------------------------------------------------------------

//////////////////////////////////////////////////////////////////
//面積計算クラス定義
class CalcArea {
	int radius;			//半径
public:
	CalcArea():radius(10){ calcHyouzi(); }
	void calcHyouzi(){ cout << radius * radius * 3.141592 << endl; }
	~CalcArea(){}
};

//-------------------------------------------------------------------
//////////////////////////////////////////////////////////////////
//Facadeクラス定義
class Facade {
public:
	static void run()
	{
		shared_ptr<CalcArea> sh_calc(createObject<CalcArea>());
	}
};
//-------------------------------------------------------------------

///////////////////////////////////////////////////////////////////
int main()
{
	//面積計算処理も意識しないし、オブジェクトも生成しないで処理する
	Facade::run();

/*
	//いちいちFacadeオブジェクトを生成している
	shared_ptr<Facade> sh_facade(createObject<Facade>());
	sh_facade->run();

	//面積計算処理を意識してオブジェクト生成している
	shared_ptr<CalcArea> sh_calcArea(createObject<CalcArea>());
*/

	return 0;
}
