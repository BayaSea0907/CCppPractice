//Chain of responsibility�inormal�j
//������������ł��镡���̃I�u�W�F�N�g��o�^���Ă����A��蔭�����ɓo�^���������I�u�W�F�N�g��
//���ԂɎ��݂Ă����p�^�[��
//�ꍇ�ɂ���ẮA�o�^����Ă���ǂ̉����I�u�W�F�N�g�������ł��Ȃ����Ƃ����蓾��
//���̏ꍇ�A�����ł��Ȃ��̂Ŗ��𖳎����邩�A�f�t�H���g������U�镑�킹��
//
//ChainOfResponsibility00(normal).cpp
//����
//Event1�ł͉����ł��Ȃ�
//Event2�ŉ���
//�悩���������������ꂽ

#include <iostream>
#include <string>
#include <list>
using namespace std;

//�C�x���gID
enum EventID {
	EVENT_1 = 1,
	EVENT_2,
	EVENT_3
};

//Chain of responsibility-----------------------------------------------
//////////////////////////////////////////////////////////////////
//�C�x���g��������interface�N���X��`�i���ۃN���X��`�j
class IEventHandler {
public:
	virtual bool Proc(EventID id) = 0;	//�C�x���g������
};

//////////////////////////////////////////////////////////////////
//�C�x���g���������N���X��`
class EventHandler1 : public IEventHandler {
public:
	bool Proc(EventID id)
	{
		if(id == EVENT_1)
		{
			cout << "Event1�ŉ���" << endl;
			return true;					//�����ł���
		}

		cout << "Event1�ł͉����ł��Ȃ�" << endl;
		return false;						//�����ł��Ȃ�����
	}
};
//-------------------------------------------------------------
class EventHandler2 : public IEventHandler {
public:
	bool Proc(EventID id)
	{
		if(id == EVENT_2)
		{
			cout << "Event2�ŉ���" << endl;
			return true;					//�����ł���
		}

		cout << "Event2�ł͉����ł��Ȃ�" << endl;
		return false;						//�����ł��Ȃ�����
	}
};
//----------------------------------------------------------------------

//�C�x���g���������I�u�W�F�N�g�Ǘ�������--------------------------------
/////////////////////////////////////////////////////////////////////
//�C�x���g�ʒm�N���X
class EventSender {
	list<IEventHandler*> mHandlerList;		//�C�x���g���������I�u�W�F�N�g�Ǘ����X�g
public:
	EventSender(){}
	
	//�C�x���g���������I�u�W�F�N�g�̓o�^
	void AddHandler(IEventHandler* ahandlerP){ mHandlerList.push_back(ahandlerP); }
	
	//�C�x���g���������I�u�W�F�N�g�̍폜
	void RemoveHandler(IEventHandler* rhandlerP){ mHandlerList.remove(rhandlerP); }

	//�C�x���g��ʒm����
	void SendEvent(EventID id)
	{
		list<IEventHandler*>::iterator start_itr = mHandlerList.begin();
		list<IEventHandler*>::iterator End_itr = mHandlerList.end();

		//�o�^�ω����I�u�W�F�N�g�����ԂɎ��{
		while(start_itr != End_itr)
		{
			//���ꂼ��̉����I�u�W�F�N�g�����Ԃɏ���
			//true���Ԃ��Ă�����A�C�x���g�͉����������ꂽ���Ƃ�\��
			if((*start_itr)->Proc(id))
			{
				cout << "�悩���������������ꂽ" << endl;
				return;
			}
			++start_itr;		//�����ł��Ȃ������ꍇ�A���̉����I�u�W�F�N�g���w��
		}

		//���ׂĂ̓o�^�ω����I�u�W�F�N�g�����{�������̂̉����ł��Ȃ������ꍇ
		//�K�v������΁A�f�t�H���g��U�镑�킹��
		cout << "���̖���������ɂ́A���̕��@���K�v����" << endl;
	}

	~EventSender(){}
};
//----------------------------------------------------------------------

///////////////////////////////////////////////////////////////////
int main()
{
	//�C�x���g���������I�u�W�F�N�g����
	IEventHandler* event1P = new EventHandler1;
	IEventHandler* event2P = new EventHandler2;

	EventSender* senderP = new EventSender;		//�C�x���g�ʒm�I�u�W�F�N�g����

	//�C�x���g�����I�u�W�F�N�g�̓o�^
	senderP->AddHandler(event1P);
	senderP->AddHandler(event2P);

	EventID eventid = EVENT_2;		//���C�x���g

	senderP->SendEvent(eventid);	//���C�x���g��ʒm�I�u�W�F�N�g�֒ʒm

	delete event1P;
	delete event2P;
	delete senderP;

	return 0;
}