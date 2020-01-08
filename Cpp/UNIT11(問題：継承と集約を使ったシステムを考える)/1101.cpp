/*---------------------------------------------------------
|���11-01	 BayaSea
-----------------------------------------------------------*/
#include <iostream>
#include <string>

using namespace std;

//�o�D�N���X��`
class Actor {
    string name;			//�o�D��
public:
    Actor(string an = ""):name(an){}	//�ian�F�o�D���j
    string getName(){ return name; }	//�o�D���擾
};
////////////////////////////////////////////////////////////
//�����N���X��`
class Animal {
    string kind;			//�������
public:
    Animal(string ak = ""):kind(ak){}	//�iak�F������ށj
    string getKind(){ return kind; }	//������ގ擾
};
////////////////////////////////////////////////////////////
//����N���X��`
class Stage {
	Actor*  actorP;			//�o�D�p�N���X�|�C���^
	Animal* animalP;		//�����p�N���X�|�C���^
public:
    //�isn�F�o�D���Ask�F������ށj
	Stage(string sn = "", string sk = "") : actorP(new Actor(sn)), animalP(new Animal(sk)){}
 
    string getActorName() { return actorP->getName();  }	//�o���o�D�擾
    string getAnimalKind(){ return animalP->getKind(); }	//�o�������擾

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
	 
    cout << "�o�D="  << stageP->getActorName()
         << " ����=" << stageP->getAnimalKind() << endl;

    delete stageP;
    return 0;
}
