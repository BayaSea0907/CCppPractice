/*---------------------------------------------------------
|���11-02	 BayaSea
-----------------------------------------------------------*/

#include <iostream>
#include <string>
using namespace std;

//�\�̓N���X��`�i��{�N���X�j
class Ability {
protected:
    string talent;				//�\��
public:
    Ability(string at = ""):talent(at){}	//�iat�F�\�́j
    string getTalent(){ return talent; }	//�\�͎擾

    //���z���\�b�h
	virtual string getName() { return ""; }
	virtual string getKind() { return ""; }
};
////////////////////////////////////////////////////////////
//�o�D�N���X��`�i�h���N���X�j
class Actor : public Ability {
    string name;	//�o�D��
public:
    //�ian�F�o�D���Aat�F�o�D�\�́j
    Actor(string an = "", string at = ""):name(an), Ability(at){}
    string getName(){ return name; }	//�o�D���擾
};
////////////////////////////////////////////////////////////
//�����N���X��`�i�h���N���X�j
class Animal : public Ability {
    string kind;			//�������
public:
    //�iak�F������ށAat�F�����\�́j
    Animal(string ak = "", string at = ""):kind(ak), Ability(at){}
    string getKind(){ return kind; }	//������ގ擾
};
////////////////////////////////////////////////////////////
//����N���X��`
class Stage {
	Ability* abilityActorP;		//�o�D�p�i�\�́j��{�N���X�|�C���^
	Ability* abilityAnimalP;	//�����p�i�\�́j��{�N���X�|�C���^
public:
    //�I�u�W�F�N�g�̍����isn�F�o�D���Ast�F�o�D�\�́Ask�F������ށAskt�F�����\�́j
    Stage(string sn = "", string st = "", string sk = "", string skt = "")
        :abilityActorP(new Actor(sn, st)),	
         abilityAnimalP(new Animal(sk, skt)){}

    //�o���o�D���擾
    string getActorName()  { return abilityActorP->getName(); }		//�o�D��
    string getActorTalent(){ return abilityActorP->getTalent(); }	//�o�D�\��

    //�o���������擾
    string getAnimalKind()  { return abilityAnimalP->getKind(); }	//����
    string getAnimalTalent(){ return abilityAnimalP->getTalent(); }	//�����\��

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
 
    cout << "�o�D="  << stageP->getActorName()
         << " �\��=" << stageP->getActorTalent()  << endl;
    cout << "����="  << stageP->getAnimalKind()
         << " �\��=" << stageP->getAnimalTalent() << endl;

    delete stageP;
    return 0;
}
