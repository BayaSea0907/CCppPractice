/*----------------------------------------------------------
|問題09-08	 BayaSea
------------------------------------------------------------*/
#include <iostream>
#include <string>
using namespace std;

//BOSS（親キャラ）クラス
class BOSS
{
    string bossName;	//親キャラ名
    int defPower;		//防御能力
public:
	BOSS(string bn = "") :bossName(bn) {};

	void setDefPower(int sd) { defPower = sd; }		//防御能力設定

	string getBossName() { return bossName; }		//親キャラ名取得
	int	   getDefPower() { return defPower; }		//防御能力取得

	//子キャラ用
	virtual void setWeapon(string) {};
	virtual string getFollName() { return ""; }
	virtual string getWeapon()	 { return ""; }
};
////////////////////////////////////////////////////////////
//Follower（子キャラ）クラス
class Follower : public BOSS
{
    string follName;   //子キャラ名
    string weapon;     //武器名
public:
	//子キャラ名、親キャラ名初期化
	Follower(string fn = "", string bn = "") : follName(fn), BOSS(bn) {};

	void setWeapon(string sw) { weapon = sw; }		//武器名設定

	string getFollName() { return follName; }		//子キャラ名取得
	string getWeapon()	 { return weapon;	}		//武器名取得
};
////////////////////////////////////////////////////////////
int main()
{
	BOSS* bossP(new Follower("石松", "次郎長"));

	bossP->setDefPower(100);
	bossP->setWeapon("槍イカ");

	cout << "子キャラ="			<< bossP->getFollName() << endl;
	cout << "子キャラの親キャラ=" << bossP->getBossName() << endl;
    cout << "子キャラの防御能力=" << bossP->getDefPower()	<< endl;
    cout << "子キャラの武器="		<< bossP->getWeapon()	<< endl;

	delete bossP;

	system("pause");
	return 0;
}
