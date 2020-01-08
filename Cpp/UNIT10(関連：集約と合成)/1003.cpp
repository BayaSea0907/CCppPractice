/*----------------------------------------------------------
|問題10-03	 BayaSea
------------------------------------------------------------*/
#include <iostream>
#include <string>			//文字列操作用
using namespace std;

//店長クラス定義（合成オブジェクトのクラス）
class Manager {
	string name;			//店長名
public:
	//（mn：店長名）
	Manager(string mn = "") :name(mn){}
	string getName(){ return name; }		//店長名取得
	~Manager(){ cout << "合成オブジェクト消滅" << endl; }
};
///////////////////////////////////////////////////////////
//店舗クラス定義
class Shop {
	Manager* manaP;		//店長オブジェクトを参照するポインタ
public:
    //実引数のないコンストラクタ
	Shop() : manaP(NULL) {}

	//合成した店長オブジェクトの店長名取得
	string getManagerName()
	{ 
		if (manaP != NULL)	return manaP->getName();
		else				return "店長は行方不明です。";
	}

    //追加（店長の任命　ここで店長オブジェクトを初めて生成する）
	void  appoManager(string mn)
	{
		if(manaP == NULL) manaP = new Manager(mn);
	}


    //追加（店長の解任　店長オブジェクトを解放する）
	void removeManager()
	{
		if(manaP != NULL)	delete manaP;
		manaP = NULL;
	}

    //デストラクタ
    ~Shop()
    {
        //合成した店長オブジェクトの解放
		if (manaP != NULL)	delete manaP;

        cout << "オブジェクトが消滅しました" << endl;
    }
};
///////////////////////////////////////////////////////////
int main()
{
	Shop* shopP(new Shop);

	shopP->appoManager("ANRI");

	cout << "店長=" << shopP->getManagerName() << endl;

	delete shopP;
	return 0;
}

