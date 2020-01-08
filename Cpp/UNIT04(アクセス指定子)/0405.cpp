/*-----------------------------------------------------------
| 問題04-05	 BayaSea
-------------------------------------------------------------*/
#include <iostream>
using namespace std;

class CU{
	int total;		//総数（人）
	int male;		//男性（人）
	int female;		//女性（人）
public:
	//男女人数設定
	void setMale  (int sm) { male = sm; }
	void setFamele(int sf) { female = sf; }

	//人数取得
	int getMale()	{ return male; }
	int getFemale() { return female; }
	int getCalcTotal() { return total = male + female; }	//総数

	//構成比率取得
	double getCalcMaleRatio()	{ return ((double)male   / (double)total) * 100.0; }	//男性
	double getCalcFemaleRatio()	{ return ((double)female / (double)total) * 100.0; }	//女性
};
////////////////////////////////////////////////////////////
int main()
{
	CU* cuP(new CU);

	cuP->setMale(23);
	cuP->setFamele(5);

	cout << "クラス人数=" << cuP->getCalcTotal() << endl;
	cout << "男性="	<< cuP->getMale()   << " 構成比%=" << cuP->getCalcMaleRatio()   << endl;
	cout << "女性=" << cuP->getFemale() << " 構成比%=" << cuP->getCalcFemaleRatio() << endl;

	delete cuP;
	system("pause");
	return 0;
}
