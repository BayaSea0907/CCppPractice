//Chain of responsibility�ishared-operator�g�p�j
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
//ChainOfResponsibility02(shared-operator).cpp
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
#include <memory>
using namespace std::tr1;
using namespace std;

//�I�u�W�F�N�g�����e���v���[�g�֐�-----------------------------------
///////////////////////////////////////////////////////////////////
template<class X>
shared_ptr<X> createObject()
{
	return (shared_ptr<X>)(new X);
}
//---------------------------------------------------------------
template<class X, class Y>
shared_ptr<X> createObject(Y n)
{
	return (shared_ptr<X>)(new X(n));
}
//---------------------------------------------------------------
template<class X, class Y, class Z>
shared_ptr<X> createObject(Y n, Z m)
{
	return (shared_ptr<X>)(new X(n, m));
}
//--------------------------------------------------------------------

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
	virtual bool operator>=(shared_ptr<Question> sh_question) = 0;	//�C�x���g������
};

//////////////////////////////////////////////////////////////////
//�C�x���g�����ҁi�w���j�N���X��`
class Student : public SolvePerson {
	string position;			//����i�E�ʁj
	Level abilityLevel;			//�����̓I�u�W�F�N�g
public:
	Student(string sposition):position(sposition), abilityLevel(1){}

	//�C�x���g������
	bool operator>=(shared_ptr<Question> sh_question)
	{
		//�����̓��x���Ǝ����Փx�Ƃ̔�r
		if(abilityLevel.getDiffLevel() >= sh_question->getQuesLevel().getDiffLevel())
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
	bool operator>=(shared_ptr<Question> sh_question)
	{
		//�����̓��x���Ǝ����Փx�Ƃ̔�r
		if(abilityLevel.getDiffLevel() >= sh_question->getQuesLevel().getDiffLevel())
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
	bool operator>=(shared_ptr<Question> sh_question)
	{
		//�����̓��x���Ǝ����Փx�Ƃ̔�r
		if(abilityLevel.getDiffLevel() >= sh_question->getQuesLevel().getDiffLevel())
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
	list<shared_ptr<SolvePerson>> sh_lstPerson;		//�C�x���g�����҃I�u�W�F�N�g�Ǘ����X�g
public:
	EventSender(){}
	
	//�C�x���g�����҃I�u�W�F�N�g�̓o�^
	void addLstPerson(shared_ptr<SolvePerson> aperson){ sh_lstPerson.push_back(aperson); }
	
	//�C�x���g�����҃I�u�W�F�N�g�̍폜
	void RemoveLstPerson(shared_ptr<SolvePerson> rperson){ sh_lstPerson.remove(rperson); }

	//�����������C�x���g�i���j���󂯕t����
	void sendEvent(shared_ptr<Question> sh_question)
	{
		showEvent(sh_question);

		list<shared_ptr<SolvePerson>>::iterator start_itr = sh_lstPerson.begin();
		list<shared_ptr<SolvePerson>>::iterator End_itr = sh_lstPerson.end();

		//���ԂɁAlist�o�^�ω����҃I�u�W�F�N�g�ɃC�x���g������������
		while(start_itr != End_itr)
		{
			//�����҃I�u�W�F�N�g�̉����͂ƃC�x���g���̓�Փx�Ƃ��r����
			//�����ł����ꍇ�́Atrue���Ԃ�
			if((**start_itr) >= sh_question)
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
	void showEvent(shared_ptr<Question> sh_question)
	{
		cout << sh_question->getQuesText() << "Lv= "
			 << sh_question->getQuesLevel().getDiffLevel() << endl;
	}

	~EventSender(){}
};
//----------------------------------------------------------------------

////////////////////////////////////////////////////////////////////
int main()
{
	//�����҃I�u�W�F�N�g����
	shared_ptr<SolvePerson> sh_student(createObject<Student, string>("�w��"));
	shared_ptr<SolvePerson> sh_rookie(createObject<ClassTeacher, string>("�S�C"));
	shared_ptr<SolvePerson> sh_veteran(createObject<ChiefTeacher, string>("��C"));

	//�C�x���g�ʒm�I�u�W�F�N�g����
	shared_ptr<EventSender> sh_sender(createObject<EventSender>());

	//�����҃I�u�W�F�N�g�̓o�^
	sh_sender->addLstPerson(sh_student);
	sh_sender->addLstPerson(sh_rookie);
	sh_sender->addLstPerson(sh_veteran);

	//���C�x���g
	shared_ptr<Question> sh_question1(createObject<Question, string, int>("����͂�����܂ŁH", 1));
	shared_ptr<Question> sh_question2(createObject<Question, string, int>("�g�ѓd�b�����čs���Ă悢�H", 3));

	//���C�x���g��ʒm�I�u�W�F�N�g�֒ʒm���ĉ������Ă��炤
	sh_sender->sendEvent(sh_question1);
	cout << endl;
	sh_sender->sendEvent(sh_question2);

	return 0;
}

