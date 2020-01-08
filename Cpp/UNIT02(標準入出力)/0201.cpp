//問題０２－０１		BayaSea
#include <iostream>
using namespace std;

//図形クラス定義
class Fig {
	int high;		//高さ（cm）
	int bottom;		//底辺（cm）
public:
	void setHigh(int sh){ high = sh; }					//高さ設定
	void setBottom(int sb){ bottom = sb; }    			//底辺設定
	double getArea(){ return (double)(bottom * high) / 2.0; }	//面積取得
};
//////////////////////////////////////////////////////////////
int main()
{
	Fig fig;		//オブジェクト宣言
	int high;		//高さ入力用
	int bottom;		//底辺入力用

	cout << "高さと底辺の入力>> ";
	cin >> high >> bottom;

	fig.setHigh(high); 		//高さ設定メソッド呼び出し
	fig.setBottom(bottom); 	//底辺設定メソッド呼び出し

	cout << "三角形の面積=" << fig.getArea() << endl;

	system("pause");
	return 0;
}
