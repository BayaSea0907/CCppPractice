/*--------------------------------------------------------------
| 問題05-07	  BayaSea
----------------------------------------------------------------*/
#include <iostream>
using namespace std;

//居間構造体
struct Living {
	int room;		//部屋数
};
/////////////////////////////////////////////////////////////////
//家クラス
class House{
	Living* livingP;
public:
	//コンストラクタ
	House() : livingP(new Living){}

	//デストラクタ
	~House() { delete livingP; }

	void setRoom(int sr = 0) { livingP->room = sr; }
	int getRoom() { return livingP->room; }
};
/////////////////////////////////////////////////////////////////
int main()
{
	House* houseP(new House);

	houseP->setRoom(10);
	cout << "部屋=" << houseP->getRoom() << endl;

	delete houseP;

	system("pause");
	return 0;
}
