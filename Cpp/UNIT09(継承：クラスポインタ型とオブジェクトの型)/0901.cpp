/*-----------------------------------------------------------
|問題09-01	 BayaSea
-------------------------------------------------------------*/

#include <iostream>
#include <string>			//文字列操作用クラス
using namespace std;

//飛行機クラス定義（基本クラス）
class AirPlane {
	string engine = "プロペラ";	//動力
public:
	string getEngine() { return engine; }
	virtual int getPassenger() { return 0; }
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
	AirPlane* airP(new PassengerPlane);

	cout << "旅客機エンジン=" << airP->getEngine()
		 << " 乗客数=" << airP->getPassenger() << endl;

	delete airP;
	return 0;
}

