/*--------------------------------------------------
|問題03-05		BayaSea
----------------------------------------------------*/
#include <iostream>
using namespace std;

//都道府県クラス定義
class Tokyo{
	int population = 13228912;
	double area = 2188.67;
public:
	//人口密度計算取得
	int getCalcPopulationDensity() {
		return (int)((double) population / area);
	}
};
////////////////////////////////////////////////////////////
int main()
{
	Tokyo* tokyoP(new Tokyo);

	cout << "人口密度="
	     << tokyoP->getCalcPopulationDensity() << endl;

	delete tokyoP;

	system("pause");
	return 0;
}
