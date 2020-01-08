/*---------------------------------------------------------
|���11-03	 BayaSea
-----------------------------------------------------------*/

#include <iostream>
#include <string>
using namespace std;

//�\�̓N���X��`�i��{�N���X�j
class Ability {
    string talent;			//�\��
public:
	//�iat�F�o�D�\�́j
    Ability(string at = ""):talent(at){}	
    string getTalent(){ return talent; }

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
    string getName(){ return name; }
};
////////////////////////////////////////////////////////////
//�����N���X��`�i�h���N���X�j
class Animal : public Ability {
    string kind;	//�������
public:
    //�iak�F������ށAat�F�����\�́j
    Animal(string ak = "", string at = ""):kind(ak), Ability(at){}
    string getKind(){ return kind; }
};
//***********************************************************
//��ЃN���X��`�i��{�N���X�j
class Company {
    string name;			//��Ж�
public:
    Company(string cn = ""):name(cn){}		//�icn�F��Ж��j
    string getName(){ return name; }		//�\�͎擾

    //���z���\�b�h
	virtual string getField()	{ return ""; }
	virtual int getConcert() { return 0; }
};

////////////////////////////////////////////////////////////
//���c�N���X��`�i�h���N���X�j
class Theatrical : public Company
{
    string field;			//��������
public:
    //�itn�F���c���Atf�F��������j
    Theatrical(string tn = "", string tf = ""):field(tf), Company(tn){}
    string getField(){ return field; }	
};
/////////////////////////////////////////////////////////////
//���y�������N���X��`�i�h���N���X�j
class Music : public Company {
    int concert;			//�R���T�[�g��
public:
    //�itn�F���y���������Atf�F�R���T�[�g���j
    Music(string tn = "", int mc = 0):concert(mc), Company(tn){}
    int getConcert(){ return concert; }	
};
/*************************************************************/
//����N���X��`
class Stage{
	Ability* abilityP;	//�o�D�p�i�\�́j��{�N���X�|�C���^
	Company* companyP;	//���c�p�i��Ёj��{�N���X�|�C���^
public:
   //�I�u�W�F�N�g�̍����isn�F�o�D���Ast�F�o�D�\�́Astn�F��Ж��Astf�F��������j
    Stage(string sn = "", string st = "", string stn = "", string stf = "")
           : abilityP(new Actor(sn, st)),
			 companyP(new Theatrical(stn, stf)){}
//-------------------------------------------
    //�o���i�o�D�E�����j�\�͎擾
    string getAbilityTalent(){ return abilityP->getTalent(); }

    //�o���o�D�擾
    string getActorName(){ return abilityP->getName(); }

    //�o�������擾
    //string getAnimalKind(){ return abilityP->getKind(); }
//-----------------------------------------------
    //��Ж��i���c�E���y�������j�擾
    string getCompanyName(){ return companyP->getName(); }

    //���c��������擾
	string getTheatricalField() { return companyP->getField(); }

    //���y�������R���T�[�g���擾
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
    cout << "�o�D="  << stageP->getActorName()
         << " �\��=" << stageP->getAbilityTalent()   << endl;
    cout << "���c="  << stageP->getCompanyName()
         << " ����=" << stageP->getTheatricalField() << endl;

    delete stageP;
    return 0;
}

