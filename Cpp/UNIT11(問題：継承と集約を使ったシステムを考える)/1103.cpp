/*---------------------------------------------------------
|問題11-03	 BayaSea
-----------------------------------------------------------*/

#include <iostream>
#include <string>
using namespace std;

//能力クラス定義（基本クラス）
class Ability {
    string talent;			//能力
public:
	//（at：俳優能力）
    Ability(string at = ""):talent(at){}	
    string getTalent(){ return talent; }

    //仮想メソッド
	virtual string getName() { return ""; }
	virtual string getKind() { return ""; }
};
////////////////////////////////////////////////////////////
//俳優クラス定義（派生クラス）
class Actor : public Ability {
    string name;	//俳優名
public:
    //（an：俳優名、at：俳優能力）
    Actor(string an = "", string at = ""):name(an), Ability(at){}
    string getName(){ return name; }
};
////////////////////////////////////////////////////////////
//動物クラス定義（派生クラス）
class Animal : public Ability {
    string kind;	//動物種類
public:
    //（ak：動物種類、at：動物能力）
    Animal(string ak = "", string at = ""):kind(ak), Ability(at){}
    string getKind(){ return kind; }
};
//***********************************************************
//会社クラス定義（基本クラス）
class Company {
    string name;			//会社名
public:
    Company(string cn = ""):name(cn){}		//（cn：会社名）
    string getName(){ return name; }		//能力取得

    //仮想メソッド
	virtual string getField()	{ return ""; }
	virtual int getConcert() { return 0; }
};

////////////////////////////////////////////////////////////
//劇団クラス定義（派生クラス）
class Theatrical : public Company
{
    string field;			//演劇分野
public:
    //（tn：劇団名、tf：演劇分野）
    Theatrical(string tn = "", string tf = ""):field(tf), Company(tn){}
    string getField(){ return field; }	
};
/////////////////////////////////////////////////////////////
//音楽事務所クラス定義（派生クラス）
class Music : public Company {
    int concert;			//コンサート数
public:
    //（tn：音楽事務所名、tf：コンサート数）
    Music(string tn = "", int mc = 0):concert(mc), Company(tn){}
    int getConcert(){ return concert; }	
};
/*************************************************************/
//舞台クラス定義
class Stage{
	Ability* abilityP;	//俳優用（能力）基本クラスポインタ
	Company* companyP;	//劇団用（会社）基本クラスポインタ
public:
   //オブジェクトの合成（sn：俳優名、st：俳優能力、stn：会社名、stf：演劇分野）
    Stage(string sn = "", string st = "", string stn = "", string stf = "")
           : abilityP(new Actor(sn, st)),
			 companyP(new Theatrical(stn, stf)){}
//-------------------------------------------
    //出演（俳優・動物）能力取得
    string getAbilityTalent(){ return abilityP->getTalent(); }

    //出演俳優取得
    string getActorName(){ return abilityP->getName(); }

    //出演動物取得
    //string getAnimalKind(){ return abilityP->getKind(); }
//-----------------------------------------------
    //会社名（劇団・音楽事務所）取得
    string getCompanyName(){ return companyP->getName(); }

    //劇団演劇分野取得
	string getTheatricalField() { return companyP->getField(); }

    //音楽事務所コンサート数取得
    //int getMusicConcert(){ return companyP->getConcert(); }
//-----------------------------------------------
    ~Stage()
    {
        delete abilityP;
        delete companyP;
    }
};
/////////////////////////////////////////////////////////////
int main()
{
   	Stage* stageP(new Stage("Jenifer", "Dance", "MSG", "Musical"));
    cout << "俳優="  << stageP->getActorName()
         << " 能力=" << stageP->getAbilityTalent()   << endl;
    cout << "劇団="  << stageP->getCompanyName()
         << " 分野=" << stageP->getTheatricalField() << endl;

    delete stageP;
    return 0;
}

