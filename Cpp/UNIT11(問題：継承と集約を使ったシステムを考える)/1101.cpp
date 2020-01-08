/*---------------------------------------------------------
|問題11-01	 BayaSea
-----------------------------------------------------------*/
#include <iostream>
#include <string>

using namespace std;

//俳優クラス定義
class Actor {
    string name;			//俳優名
public:
    Actor(string an = ""):name(an){}	//（an：俳優名）
    string getName(){ return name; }	//俳優名取得
};
////////////////////////////////////////////////////////////
//動物クラス定義
class Animal {
    string kind;			//動物種類
public:
    Animal(string ak = ""):kind(ak){}	//（ak：動物種類）
    string getKind(){ return kind; }	//動物種類取得
};
////////////////////////////////////////////////////////////
//舞台クラス定義
class Stage {
	Actor*  actorP;			//俳優用クラスポインタ
	Animal* animalP;		//動物用クラスポインタ
public:
    //（sn：俳優名、sk：動物種類）
	Stage(string sn = "", string sk = "") : actorP(new Actor(sn)), animalP(new Animal(sk)){}
 
    string getActorName() { return actorP->getName();  }	//出演俳優取得
    string getAnimalKind(){ return animalP->getKind(); }	//出演動物取得

    ~Stage()
    {
		delete actorP;
		delete animalP;
    }
};
////////////////////////////////////////////////////////////
int main()
{
    Stage* stageP(new Stage("Jenifer", "Dog"));
	 
    cout << "俳優="  << stageP->getActorName()
         << " 動物=" << stageP->getAnimalKind() << endl;

    delete stageP;
    return 0;
}
