/*---------------------------------------------------------
|問題14-02		 BayaSea
-----------------------------------------------------------*/
#include <iostream>
#include <memory>
using namespace std;

//交換クラス定義
class Swap {
public:
	//値の交換（sn1：値、sn2：値）
	void swap(int& sn1, int& sn2)
	{
		std::swap(sn1, sn2);
	}
};
///////////////////////////////////////////////////////////
//オブジェクトを生成するテンプレート外部関数
template<class X>
shared_ptr<X> create(){ return (shared_ptr<X>)(new X); }
///////////////////////////////////////////////////////////
int main()
{
	shared_ptr<Swap> sh_swap(create<Swap>());
	int num1 = 100, num2 = 200;

	sh_swap->swap(num1, num2);
	cout << "num1=" << num1 << " num2=" << num2 << endl;

	return 0;
}
