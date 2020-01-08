/*---------------------------------------------------------
|問題11-02	 BayaSea
-----------------------------------------------------------*/

#include <iostream>
#include <string>
using namespace std;

//能力クラス定義（基本クラス）
class Ability {
protected:
    string talent;				//能力
public:
    Ability(string at = ""):talent(at){}	//（at：能力）
    string getTalent(){ return talent; }	//能力取得

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
    string getName(){ return name; }	//俳優名取得
};
////////////////////////////////////////////////////////////
//動物クラス定義（派生クラス）
class Animal : public Ability {
    string kind;			//動物種類
public:
    //（ak：動物種類、at：動物能力）
    Animal(string ak = "", string at = ""):kind(ak), Ability(at){}
    string getKind(){ return kind; }	//動物種類取得
};
////////////////////////////////////////////////////////////
//舞台クラス定義
class Stage {
	Ability* abilityActorP;		//俳優用（能力）基本クラスポインタ
	Ability* abilityAnimalP;	//動物用（能力）基本クラスポインタ
public:
    //オブジェクトの合成（sn：俳優名、st：俳優能力、sk：動物種類、skt：動物能力）
    Stage(string sn = "", string st = "", string sk = "", string skt = "")
        :abilityActorP(new Actor(sn, st)),	
         abilityAnimalP(new Animal(sk, skt)){}

    //出演俳優情報取得
    string getActorName()  { return abilityActorP->getName(); }		//俳優名
    string getActorTalent(){ return abilityActorP->getTalent(); }	//俳優能力

    //出演動物情報取得
    string getAnimalKind()  { return abilityAnimalP->getKind(); }	//動物
    string getAnimalTalent(){ return abilityAnimalP->getTalent(); }	//動物能力

    ~Stage()
    {
        delete abilityActorP;
        delete abilityAnimalP;
    }
};
////////////////////////////////////////////////////////////
int main()
{
    Stage* stageP(new Stage("Jenifer", "Dance", "Dog", "Shopping"));
 
    cout << "俳優="  << stageP->getActorName()
         << " 能力=" << stageP->getActorTalent()  << endl;
    cout << "動物="  << stageP->getAnimalKind()
         << " 能力=" << stageP->getAnimalTalent() << endl;

    delete stageP;
    return 0;
}
