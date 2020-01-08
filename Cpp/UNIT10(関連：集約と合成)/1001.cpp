/*---------------------------------------------------------
|問題10-01	 BayaSea
-----------------------------------------------------------*/
#include <iostream>
#include <string>			//文字列操作用
using namespace std;

//プロジェクタークラス定義
class Projector {
	string maker;			//メーカー
public:
	Projector(string pm = "") :maker(pm){}
	string getMaker(){ return maker; }
};
///////////////////////////////////////////////////////////
//教室クラス定義
class Room {
	Projector* projecP = NULL;
public:
	//プロジェクター設置
	void setProjector(string sm)
	{
		//ifの比較がないと、連続で呼び出した際にメモリリークを起こしてしまう。
		if (projecP == NULL) projecP = new Projector(sm);	
	}

	//プロジェクターをはずす
	void removeProjector()
	{
		if (projecP != NULL) delete projecP;
		projecP = NULL;
	}

	//プロジェクターのメーカー取得
	string getProjectorMaker()
	{
		if (projecP != NULL)	return projecP->getMaker();
		else					return "はない";
	}

	~Room()
	{
		if (projecP != NULL) delete projecP;
	}
};
///////////////////////////////////////////////////////////
int main()
{
	Room* roomP(new Room);

	roomP->setProjector("HITEC");
	cout << "プロジェクター=" << roomP->getProjectorMaker() << endl;

	roomP->removeProjector();

	delete roomP;
	return 0;
}

