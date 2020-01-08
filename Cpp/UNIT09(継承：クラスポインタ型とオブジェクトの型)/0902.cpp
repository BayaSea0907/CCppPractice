/*-----------------------------------------------------------
|問題09-02	 BayaSea
-------------------------------------------------------------*/

#include <iostream>
#include <string>			//文字列操作用クラス
using namespace std;

//飛行機クラス定義（基本クラス）
class AirPlane {
	string engine = "プロペラ";	//動力
public:
	string getEngine() { return engine; }
};
/////////////////////////////////////////////////////////////
//旅客機クラス定義（派生クラス）
class PassengerPlane : public AirPlane {
	int passenger = 180;		//乗客数
public:
	int getPassenger() { return passenger; }
};
/////////////////////////////////////////////////////////////
int main()
{
	PassengerPlane* passPlaneP(new PassengerPlane);

	cout << "旅客機エンジン=" << passPlaneP->getEngine()
		 << " 乗客数=" << passPlaneP->getPassenger() << endl;

	delete passPlaneP;
	return 0;
}
