/*---------------------------------------------------------------
 問題15-02	2016.10.6

 BayaSea
-----------------------------------------------------------------*/
#include <iostream>
#include <memory>
using namespace std;

const double PAI = 3.141592653;

//円クラス定義
class Circle {
	int hankei = 10;		//半径（㎝）
public:
	//円弧計算
	double calcArc(const int& angle)
	{
		return hankei * (angle * PAI / 180);
	}
	int getHankei()const{ return hankei; }    //半径取得
};
///////////////////////////////////////////////////////////////////
//オブジェクトを生成するテンプレート外部関数
template<class X>
shared_ptr<X> create(){ return (shared_ptr<X>)(new X); }
///////////////////////////////////////////////////////////////////
int main()
{
	shared_ptr<Circle> sh_circle(create<Circle>());
	int angle;				//角度入力用

	cout << "角度の入力>> ";
	cin >> angle;

	cout << "角度=" << angle << " 円弧=" << sh_circle->calcArc(angle) << endl;

	return 0;
}
