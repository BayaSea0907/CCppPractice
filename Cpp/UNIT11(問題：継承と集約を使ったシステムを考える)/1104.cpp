//問題１１－０４ BayaSea
#include <iostream>
#include <string>
using namespace std;

//会社クラス定義（基本クラス）
class Company {
    string name;			//会社名
public:
    Company(string cn = ""):name(cn){}		//（cn：会社名）
    string getName(){ return name; }		//会社取得

    //仮想メソッド
	virtual string getField() { return ""; }
	virtual int getConcert()  { return 0; }
};
//////////////////////////////////////////////////////////////////
//劇団クラス定義（派生クラス）
class Theatrical : public Company {
    string field;			//演劇分野
public:
    //（tn：劇団名、tf：演劇分野）
    Theatrical(string tn = "", string tf = ""):field(tf), Company(tn){}
    string getField(){ return field; }		//演劇分野取得
};
//////////////////////////////////////////////////////////////////
//音楽事務所クラス定義（派生クラス）
class Music : public Company {
    int concert;			//コンサート数
public:
    //（tn：音楽事務所名、tf：コンサート数）
    Music(string tn = "", int mc = 0):concert(mc), Company(tn){}
    int getConcert(){ return concert; }		//コンサート数取得
};
//////////////////////////////////////////////////////////////////
//能力クラス定義（基本クラス）
class Ability {
    string talent;			//能力
public:
    Ability(string at = ""):talent(at){}	//（at：俳優能力）
    string getTalent(){ return talent; }	//能力取得

    //仮想メソッド
	virtual string getName() { return ""; }
	virtual string getCompanyName() { return ""; }
	virtual string getCompanyTheatricalField() { return ""; }
    virtual int getCompanyMusicConcert(){ return 0; }
	virtual string getKind() { return ""; }

    //仮想デストラクタ
	virtual ~Ability(){}
};
//////////////////////////////////////////////////////////////////
//俳優クラス定義（派生クラス）
class Actor : public Ability {
    string name;		//俳優名
	Company* companyP;	//劇団用（会社）基本クラスポインタ
public:
    //（an：俳優名、at：俳優能力、st：会社名、stf：演劇分野）
    Actor(string an = "", string at = "", string st = "", string stf = "")
         :name(an), companyP(new Theatrical(st, stf)), Ability(at){}

    string getName(){ return name; }        //俳優名取得
//--------------------------------------------
    //会社クラスと継承関係にあるクラスのメソッド呼び出し用
    //会社名(劇団・音楽事務所）取得
    string getCompanyName(){ return companyP->getName(); }

    //劇団の演劇分野取得
    string getCompanyTheatricalField(){ return companyP->getField(); }

    //音楽事務所のコンサート数取得
    int getCompanyMusicConcert(){ return companyP->getConcert(); }
//--------------------------------------------
	~Actor() { delete companyP; }
};
//////////////////////////////////////////////////////////////////
//動物クラス定義（派生クラス）
class Animal : public Ability {
    string kind;					//動物種類
public:
    //（ak：動物種類、at：動物能力）
    Animal(string ak = "", string at = ""):kind(ak), Ability(at){}
    string getKind(){ return kind; }		//動物種類の取得
};
//////////////////////////////////////////////////////////////////
//舞台クラス定義
class Stage {
	Ability* abilityP;		//俳優用（能力）基本クラスポインタ
public:
	//（sn：俳優名、snt：俳優能力、stn：会社名、stf：演劇分野）
    Stage(string sn = "", string snt = "",
                                 string stn = "", string stf = "")
         :abilityP(new Actor(sn, snt, stn, stf)){}
//-----------------------------------------------
    //出演俳優・動物の能力取得
    string getAbility(){ return abilityP->getTalent(); }

    //出演俳優取得
    string getActorName(){ return abilityP->getName(); }

    //出演動物取得
    string getAnimalKind(){ return abilityP->getKind(); }
//-----------------------------------------------
    //会社名（劇団・音楽事務所）取得
    string getCompany(){ return abilityP->getCompanyName(); }

    //劇団の演劇分野取得
    string getTheatricalField()
	{
		return abilityP->getCompanyTheatricalField();
    }

    //音楽事務所のコンサート数取得
    int getMusicConcert(){ return abilityP->getCompanyMusicConcert(); }
//-----------------------------------------------
	~Stage() { delete abilityP; }
};
//////////////////////////////////////////////////////////////////
int main()
{
	Stage*	stageP(new Stage("Jenifer", "Dance", "MSG", "Musical"));

    cout << "俳優="  << stageP->getActorName()
         << " 能力=" << stageP->getAbility()	<< endl;
    cout << "劇団="  << stageP->getCompany()
         << " 分野=" << stageP->getTheatricalField() << endl;

    delete stageP;
	system("pause");
    return 0;
}
