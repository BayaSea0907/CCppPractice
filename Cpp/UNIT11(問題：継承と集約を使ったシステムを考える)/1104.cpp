//���P�P�|�O�S BayaSea
#include <iostream>
#include <string>
using namespace std;

//��ЃN���X��`�i��{�N���X�j
class Company {
    string name;			//��Ж�
public:
    Company(string cn = ""):name(cn){}		//�icn�F��Ж��j
    string getName(){ return name; }		//��Ў擾

    //���z���\�b�h
	virtual string getField() { return ""; }
	virtual int getConcert()  { return 0; }
};
//////////////////////////////////////////////////////////////////
//���c�N���X��`�i�h���N���X�j
class Theatrical : public Company {
    string field;			//��������
public:
    //�itn�F���c���Atf�F��������j
    Theatrical(string tn = "", string tf = ""):field(tf), Company(tn){}
    string getField(){ return field; }		//��������擾
};
//////////////////////////////////////////////////////////////////
//���y�������N���X��`�i�h���N���X�j
class Music : public Company {
    int concert;			//�R���T�[�g��
public:
    //�itn�F���y���������Atf�F�R���T�[�g���j
    Music(string tn = "", int mc = 0):concert(mc), Company(tn){}
    int getConcert(){ return concert; }		//�R���T�[�g���擾
};
//////////////////////////////////////////////////////////////////
//�\�̓N���X��`�i��{�N���X�j
class Ability {
    string talent;			//�\��
public:
    Ability(string at = ""):talent(at){}	//�iat�F�o�D�\�́j
    string getTalent(){ return talent; }	//�\�͎擾

    //���z���\�b�h
	virtual string getName() { return ""; }
	virtual string getCompanyName() { return ""; }
	virtual string getCompanyTheatricalField() { return ""; }
    virtual int getCompanyMusicConcert(){ return 0; }
	virtual string getKind() { return ""; }

    //���z�f�X�g���N�^
	virtual ~Ability(){}
};
//////////////////////////////////////////////////////////////////
//�o�D�N���X��`�i�h���N���X�j
class Actor : public Ability {
    string name;		//�o�D��
	Company* companyP;	//���c�p�i��Ёj��{�N���X�|�C���^
public:
    //�ian�F�o�D���Aat�F�o�D�\�́Ast�F��Ж��Astf�F��������j
    Actor(string an = "", string at = "", string st = "", string stf = "")
         :name(an), companyP(new Theatrical(st, stf)), Ability(at){}

    string getName(){ return name; }        //�o�D���擾
//--------------------------------------------
    //��ЃN���X�ƌp���֌W�ɂ���N���X�̃��\�b�h�Ăяo���p
    //��Ж�(���c�E���y�������j�擾
    string getCompanyName(){ return companyP->getName(); }

    //���c�̉�������擾
    string getCompanyTheatricalField(){ return companyP->getField(); }

    //���y�������̃R���T�[�g���擾
    int getCompanyMusicConcert(){ return companyP->getConcert(); }
//--------------------------------------------
	~Actor() { delete companyP; }
};
//////////////////////////////////////////////////////////////////
//�����N���X��`�i�h���N���X�j
class Animal : public Ability {
    string kind;					//�������
public:
    //�iak�F������ށAat�F�����\�́j
    Animal(string ak = "", string at = ""):kind(ak), Ability(at){}
    string getKind(){ return kind; }		//������ނ̎擾
};
//////////////////////////////////////////////////////////////////
//����N���X��`
class Stage {
	Ability* abilityP;		//�o�D�p�i�\�́j��{�N���X�|�C���^
public:
	//�isn�F�o�D���Asnt�F�o�D�\�́Astn�F��Ж��Astf�F��������j
    Stage(string sn = "", string snt = "",
                                 string stn = "", string stf = "")
         :abilityP(new Actor(sn, snt, stn, stf)){}
//-----------------------------------------------
    //�o���o�D�E�����̔\�͎擾
    string getAbility(){ return abilityP->getTalent(); }

    //�o���o�D�擾
    string getActorName(){ return abilityP->getName(); }

    //�o�������擾
    string getAnimalKind(){ return abilityP->getKind(); }
//-----------------------------------------------
    //��Ж��i���c�E���y�������j�擾
    string getCompany(){ return abilityP->getCompanyName(); }

    //���c�̉�������擾
    string getTheatricalField()
	{
		return abilityP->getCompanyTheatricalField();
    }

    //���y�������̃R���T�[�g���擾
    int getMusicConcert(){ return abilityP->getCompanyMusicConcert(); }
//-----------------------------------------------
	~Stage() { delete abilityP; }
};
//////////////////////////////////////////////////////////////////
int main()
{
	Stage*	stageP(new Stage("Jenifer", "Dance", "MSG", "Musical"));

    cout << "�o�D="  << stageP->getActorName()
         << " �\��=" << stageP->getAbility()	<< endl;
    cout << "���c="  << stageP->getCompany()
         << " ����=" << stageP->getTheatricalField() << endl;

    delete stageP;
	system("pause");
    return 0;
}
