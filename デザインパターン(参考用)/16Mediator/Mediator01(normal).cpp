//Mediator�inormal�j
//Mediator�́A�����̃I�u�W�F�N�g�Ԃ̒��������邽�߂ɁA�e�I�u�W�F�N�g����̖₢���킹���󂯁A
//�K�X���f���s���Ďw�����o���u����ҁv�̖������ʂ����N���X�𗘗p����p�^�[��
//Mediator�ł́A����҂̖������ʂ���Mediator�C���^�t�F�[�X�A���k�����鑤�i�����j��\��Collegue�C���^�t�F�[�X��
//��`���āA���ꂼ�����������`�ŁA���ۂ̒������⑊�k�҂�\���N���X���쐬����

//Mediator�ł́A�e�I�u�W�F�N�g�́A�����̏�Ԃ��ς�����Ƃ���Mediator�ɘA�����āA
//Mediator�́A�ΏۂƂȂ�I�u�W�F�N�g�̏�Ԃ𔻒f���A�A�����Ă����I�u�W�F�N�g�ɁA
//�A���ɑ΂���Ԏ����s��

//��ł́A���������铯���ɗ������̂ŁA����҂ɑ���̓����ɍ����l�����邩�ǂ��������Ă������
//���̌��ʂ������Ă��炤���Ƃɂ��Ă��܂�
//����҂́A���ׂĂ̓�����map�i���O�Ɛ����I�u�W�F�N�g�̃|�C���^���y�A�j�ŊǗ����Ă���

//�����interface�N���X���p�������N���X��`�́A�����interface�Ɠ���interface�̃N���X��`�ȍ~��
//��`���Ȃ��ƃR���p�C���G���[�ƂȂ�

//Mediator01(normal).cpp
//����
//YASU��MAI�ɗ�����
//������`�@�f�[�g�ɗU����
//
//MAI��SEKI�ɗ�����
//�Ȃ񂾂��āI�@�ށi�ޏ��j�m��Ȃ��̂��H
//
//YASU��KAORI��������
//�����`��I�@�c�O���`

#include <iostream>
#include <string>
#include <map>
using namespace std;

class Colleague;

//Mediator��Colleague��inteface�N���X��`++++++++++++++++++++++++++++++++++
//Mediator-------------------------------------------------------------
//////////////////////////////////////////////////////////////////
//�����interface�N���X��`�i���ۃN���X�j
class Mediator {
public:
	virtual void addColleague(Colleague* colleagueP) = 0;	//����map�ɓo�^

	//���l�̗L���ɂ��Ă̖⍇���ɉ�����
	virtual int inquire(Colleague* colleagueInLoveP, string name) = 0;
};
//---------------------------------------------------------------------

//Colleague------------------------------------------------------------
/////////////////////////////////////////////////////////////////
//�����N���Xinterafece�N���X��`�i���ۃN���X�j
class Colleague {
public:
	virtual string getName()const = 0;
	virtual void setCompanion(string name) = 0;		//���ɗ���������
	virtual void fallInLove() = 0;					//���ɗ������imediator�֒ʒm�j
	virtual int getLoverCheck() = 0;				//���l�L���擾
};
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//����҂Ɠ����̃N���X��`+++++++++++++++++++++++++++++++++++++++++++++++++
//////////////////////////////////////////////////////////////////
//����҃N���X��`
class ZweiPerson : public Mediator {
	map<string, Colleague*> mapColleague;					//�����I�u�W�F�N�g�Ǘ�map
	map<string, Colleague*>::iterator mapColleague_itr;
public:
	//map�ɓ����I�u�W�F�N�g��o�^�i���O�ƃI�u�W�F�N�g�̃|�C���^�j
	void addColleague(Colleague* acolleagueP)
	{
		mapColleague.insert(pair<string, Colleague*>(acolleagueP->getName(), acolleagueP));
	}

	//���l�̗L���ɂ��Ă̖⍇���ɉ�����
	int inquire(Colleague* colleagueInLoveP, string name)
	{
		int possibility = 0;	//�O�F����map�ɖ��o�^�A�P�F�t��������A�Q�F�t�������Ȃ�

		mapColleague_itr = mapColleague.begin();

		//�t�����������l������map�ɓo�^����Ă邩����
		if((mapColleague_itr = mapColleague.find(name)) != mapColleague.end())
		{
			//����map�ɓo�^����Ă�΁A�t��������������ɍ����l�����邩�ǂ����₢���킹��
			if(mapColleague_itr->second->getLoverCheck() == 0)
			{
				possibility = 1;	//�����l�����Ȃ���΁A�Ԏ���t��������ɐݒ�
			}
			else
			{
				possibility = 2;	//���l������΁A�t�������Ȃ��ɐݒ�
			}
		}
		return possibility;			//�t�������邩�ǂ�����Ԏ�����
	}
};
//----------------------------------------------------------------------
////////////////////////////////////////////////////////////////
//�����N���X��`
class Member : public Colleague {
	string name;					//����
	int loverCheck;					//���l�L���i�O�����A�P�L��j
	string companion;				//���ɗ���������
	Mediator* mediatorP;			//����ҊǗ��|�C���^
public:
	Member(string sname, int sLoverCheck, Mediator* lmediatorP)
					:name(sname), loverCheck(sLoverCheck), mediatorP(lmediatorP){}

	void setCompanion(string name){ companion = name; }		//���ɗ���������o�^
	string getName()const{ return name; }

	//���ɗ�����
	void fallInLove()
	{
		//���ɗ���������ɗ��l�����邩�ǂ����𒲒�҂ɐq�˂�
		switch(mediatorP->inquire(this, companion))
		{
			//����҂���̕Ԏ��Ŕ�������
			case 1: cout << "������`�@�f�[�g�ɗU����" << endl; break;
			case 2: cout << "�����`��I�@�c�O���`" << endl; break;
			default: cout << "�Ȃ񂾂��āI�@�ށi�ޏ��j��m��Ȃ��̂��H" << endl;
		}
	}

	int getLoverCheck(){ return loverCheck; }	//����҂���̖₢���킹��t
};
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

////////////////////////////////////////////////////////////////
int main()
{
	Mediator* mediatorP = new ZweiPerson;	//����Ґ���

	//�����ɒ���҂�o�^
	Colleague* colleagueP1 = new Member("YASU", 0, mediatorP);
	Colleague* colleagueP2 = new Member("MAI", 0, mediatorP);
	Colleague* colleagueP3 = new Member("KAORI", 1, mediatorP);

	//����҂ɂ��ׂĂ̓�����o�^
	mediatorP->addColleague(colleagueP1);
	mediatorP->addColleague(colleagueP2);
	mediatorP->addColleague(colleagueP3);

	cout << "YASU��MAI�ɗ�����" << endl;
	colleagueP1->setCompanion("MAI");		//YASU��MAI�ɗ�����
	colleagueP1->fallInLove();				//���ɗ�����
	cout << endl;

	cout << "MAI��SEKI�ɗ�����" << endl;
	colleagueP2->setCompanion("SEKI");		//MAI��SEKI�ɗ�����
	colleagueP2->fallInLove();				//���ɗ�����
	cout << endl;

	cout << "YASU��KAORI��������" << endl;
	colleagueP1->setCompanion("KAORI");		//YASU��KAORI��������
	colleagueP1->fallInLove();				//���ɗ�����

	delete mediatorP;
	delete colleagueP1;
	delete colleagueP2;
	delete colleagueP3;

	return 0;
}
