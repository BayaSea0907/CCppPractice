//Chain of responsibility�inormal-operator�g�p�j
//����������������ł���\���̂��镡���̃I�u�W�F�N�g��o�^���A���Ԃɉ������������݂Ă���
//�����ł���I�u�W�F�N�g�ɍs�������܂Ői�߂Ă���
//�o�^����Ă���ǂ̃I�u�W�F�N�g�������ł��Ȃ��ꍇ�����蓾��
//���̏ꍇ�ɂ͖��C�x���g�𖳎����邩�A�f�t�H���g�̏�����U�镑��
//
//�Ⴆ�΁A�w������̎���i�C�x���g���j���w�����g�������ł�����̂Ȃ̂��A�S�C���x���ŉ����ł�����̂Ȃ̂��A
//��C���x���ŉ����ł�����̂Ȃ̂���\��
//�C�x���g���������邽�߂�interface�N���X���`���A���ꂼ��̉����N���X���p����`����
//�����āA�C�x���g�����I�u�W�F�N�g�����X�g�\���ŊǗ����A�����������C�x���g�������ꂼ��̃C�x���g�����I�u�W�F�N�g��
//���������ĉ���������
//�����A�����ł��Ȃ���΁A���̃C�x���g�����I�u�W�F�N�g�ɈϔC����`�ŉ��������݂�
//
//�C�x���g�����I�u�W�F�N�g�������ł��邩�ǂ����́A�����C�x���g���̓�Փx�ƁA���ꂼ��̃C�x���g�����I�u�W�F�N�g������
//�����\�̓��x���Ƃ��r���Ĕ��f����
//
//ChainOfResponsibility01(normal-operator).cpp
//����
//����͂�����܂ŁHLv= 1
//�w���������ł���
//�悩���������������ꂽ

//�g�ѓd�b�����čs���Ă悢�HLv= 3
//�w���ł͉����ł��Ȃ�
//�S�C�ł͉����ł��Ȃ�
//��C�������ł���
//�悩���������������ꂽ


#include <iostream>
#include <string>
#include <list>
using namespace std;

////////////////////////////////////////////////////////////////////
//��Փx�N���X��`
class Level {
	int degree;		//��Փx
public:
	Level(int ldegree):degree(ldegree){}
	int getDiffLevel()const{ return degree; }
};

////////////////////////////////////////////////////////////////////
//����N���X��`
class Question {
	string quesText;		//������e
	Level quesLevel;		//�����Փx�I�u�W�F�N�g
public:
	Question(string squesText, int squesLevel):quesText(squesText), quesLevel(squesLevel){}
	string getQuesText()const{ return quesText; }
	Level getQuesLevel()const{ return quesLevel; }
};
//----------------------------------------------------------------------

//Chain of responsibility-----------------------------------------------
//////////////////////////////////////////////////////////////////
//�C�x���g������interface�N���X��`�i���ۃN���X��`�j
class SolvePerson {
public:
	virtual bool operator>=(Question* questionP) = 0;	//�C�x���g������
};

//////////////////////////////////////////////////////////////////
//�C�x���g�����ҁi�w���j�N���X��`
class Student : public SolvePerson {
	string position;			//����i�E�ʁj
	Level abilityLevel;			//�����̓I�u�W�F�N�g
public:
	Student(string sposition):position(sposition), abilityLevel(1){}

	//�C�x���g������
	bool operator>=(Question* questionP)
	{
		//�����̓��x���Ǝ����Փx�Ƃ̔�r
		if(abilityLevel.getDiffLevel() >= questionP->getQuesLevel().getDiffLevel())
		{
			cout << "�w���������ł���" << endl;
			return true;		//���ȉ����ł���
		}

		cout << "�w���ł͉����ł��Ȃ�" << endl;
		return false;			//�����ł��Ȃ�
	}
};
//----------------------------------------------------------------
//�C�x���g�����ҁi�S�C�j�N���X��`
class ClassTeacher : public SolvePerson {
	string position;			//����i�E�ʁj
	Level abilityLevel;			//�����̓I�u�W�F�N�g
public:
	ClassTeacher(string sposition):position(sposition), abilityLevel(2){}

	//�C�x���g������
	bool operator>=(Question* questionP)
	{
		//�����̓��x���Ǝ����Փx�Ƃ̔�r
		if(abilityLevel.getDiffLevel() >= questionP->getQuesLevel().getDiffLevel())
		{
			cout << "�S�C�������ł���" << endl;
			return true;		//���ȉ����ł���
		}

		cout << "�S�C�ł͉����ł��Ȃ�" << endl;
		return false;			//�����ł��Ȃ�
	}
};
//----------------------------------------------------------------
//�C�x���g�����ҁi��C�j�N���X��`
class ChiefTeacher : public SolvePerson {
	string position;			//����i�E�ʁj
	Level abilityLevel;			//�����̓I�u�W�F�N�g
public:
	ChiefTeacher(string sposition):position(sposition), abilityLevel(3){}

	//�C�x���g������
	bool operator>=(Question* questionP)
	{
		//�����̓��x���Ǝ����Փx�Ƃ̔�r
		if(abilityLevel.getDiffLevel() >= questionP->getQuesLevel().getDiffLevel())
		{
			cout << "��C�������ł���" << endl;
			return true;		//���ȉ����ł���
		}

		cout << "��C�ł͉����ł��Ȃ�" << endl;
		return false;			//�����ł��Ȃ�
	}
};
//----------------------------------------------------------------------

//�C�x���g���������I�u�W�F�N�g�Ǘ�������--------------------------------
/////////////////////////////////////////////////////////////////////
//�C�x���g�ʒm�N���X
class EventSender {
	list<SolvePerson*> lstPerson;		//�C�x���g�����҃I�u�W�F�N�g�Ǘ����X�g
public:
	EventSender(){}
	
	//�C�x���g�����҃I�u�W�F�N�g�̓o�^
	void addLstPerson(SolvePerson* apersonP){ lstPerson.push_back(apersonP); }
	
	//�C�x���g�����҃I�u�W�F�N�g�̍폜
	void RemoveLstPerson(SolvePerson* rpersonP){ lstPerson.remove(rpersonP); }

	//�����������C�x���g�i���j���󂯕t����
	void sendEvent(Question* questionP)
	{
		showEvent(questionP);

		list<SolvePerson*>::iterator start_itr = lstPerson.begin();
		list<SolvePerson*>::iterator End_itr = lstPerson.end();

		//���ԂɁAlist�o�^�ω����҃I�u�W�F�N�g�ɃC�x���g������������
		while(start_itr != End_itr)
		{
			//�����҃I�u�W�F�N�g�̉����͂ƃC�x���g���̓�Փx�Ƃ��r����
			//�����ł����ꍇ�́Atrue���Ԃ�
			if((**start_itr) >= questionP)
			{
				cout << "�悩���������������ꂽ" << endl;
				return;
			}

			//�����ł��Ȃ������ꍇ�A���̉����҃I�u�W�F�N�g���w��
			++start_itr;
		}

		//���ׂẲ����҃I�u�W�F�N�g�ŉ����ł��Ȃ������ꍇ
		cout << "�N�ɂ������ł��܂���ł����B����Ă݂Ȃ����B" << endl;
	}

	//�󂯕t�����C�x���g�i���j�\��
	void showEvent(Question* questionP)
	{
		cout << questionP->getQuesText() << "Lv= "
			 << questionP->getQuesLevel().getDiffLevel() << endl;
	}

	~EventSender(){}
};
//----------------------------------------------------------------------

////////////////////////////////////////////////////////////////////
int main()
{
	//�����҃I�u�W�F�N�g����
	SolvePerson* studentP = new Student("�w��");
	SolvePerson* rookieP = new ClassTeacher("�S�C");
	SolvePerson* veteranP = new ChiefTeacher("��C");

	EventSender* senderP = new EventSender;		//�C�x���g�ʒm�I�u�W�F�N�g����

	//�����҃I�u�W�F�N�g�̓o�^
	senderP->addLstPerson(studentP);
	senderP->addLstPerson(rookieP);
	senderP->addLstPerson(veteranP);

	//���C�x���g
	Question* questionP1 = new Question("����͂�����܂ŁH", 1);
	Question* questionP2 = new Question("�g�ѓd�b�����čs���Ă悢�H", 3);

	//���C�x���g��ʒm�I�u�W�F�N�g�֒ʒm���ĉ������Ă��炤
	senderP->sendEvent(questionP1);
	cout << endl;
	senderP->sendEvent(questionP2);

	delete studentP;
	delete rookieP;
	delete veteranP;
	delete senderP;

	return 0;
}

