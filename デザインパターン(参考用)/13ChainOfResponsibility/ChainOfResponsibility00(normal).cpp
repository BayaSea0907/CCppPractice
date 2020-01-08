//Chain of responsibility（normal）
//ある問題を解決できる複数のオブジェクトを登録しておき、問題発生時に登録した解決オブジェクトを
//順番に試みていくパターン
//場合によっては、登録されているどの解決オブジェクトも解決できないこともあり得る
//この場合、解決できないので問題を無視するか、デフォルト処理を振る舞わせる
//
//ChainOfResponsibility00(normal).cpp
//結果
//Event1では解決できない
//Event2で解決
//よかった無事解決された

#include <iostream>
#include <string>
#include <list>
using namespace std;

//イベントID
enum EventID {
	EVENT_1 = 1,
	EVENT_2,
	EVENT_3
};

//Chain of responsibility-----------------------------------------------
//////////////////////////////////////////////////////////////////
//イベント解決処理interfaceクラス定義（抽象クラス定義）
class IEventHandler {
public:
	virtual bool Proc(EventID id) = 0;	//イベントを処理
};

//////////////////////////////////////////////////////////////////
//イベント解決処理クラス定義
class EventHandler1 : public IEventHandler {
public:
	bool Proc(EventID id)
	{
		if(id == EVENT_1)
		{
			cout << "Event1で解決" << endl;
			return true;					//解決できた
		}

		cout << "Event1では解決できない" << endl;
		return false;						//解決できなかった
	}
};
//-------------------------------------------------------------
class EventHandler2 : public IEventHandler {
public:
	bool Proc(EventID id)
	{
		if(id == EVENT_2)
		{
			cout << "Event2で解決" << endl;
			return true;					//解決できた
		}

		cout << "Event2では解決できない" << endl;
		return false;						//解決できなかった
	}
};
//----------------------------------------------------------------------

//イベント解決処理オブジェクト管理＆処理--------------------------------
/////////////////////////////////////////////////////////////////////
//イベント通知クラス
class EventSender {
	list<IEventHandler*> mHandlerList;		//イベント解決処理オブジェクト管理リスト
public:
	EventSender(){}
	
	//イベント解決処理オブジェクトの登録
	void AddHandler(IEventHandler* ahandlerP){ mHandlerList.push_back(ahandlerP); }
	
	//イベント解決処理オブジェクトの削除
	void RemoveHandler(IEventHandler* rhandlerP){ mHandlerList.remove(rhandlerP); }

	//イベントを通知する
	void SendEvent(EventID id)
	{
		list<IEventHandler*>::iterator start_itr = mHandlerList.begin();
		list<IEventHandler*>::iterator End_itr = mHandlerList.end();

		//登録済解決オブジェクトを順番に実施
		while(start_itr != End_itr)
		{
			//それぞれの解決オブジェクトを順番に処理
			//trueが返ってきたら、イベントは解決処理されたことを表す
			if((*start_itr)->Proc(id))
			{
				cout << "よかった無事解決された" << endl;
				return;
			}
			++start_itr;		//解決できなかった場合、次の解決オブジェクトを指定
		}

		//すべての登録済解決オブジェクトを実施したものの解決できなかった場合
		//必要があれば、デフォルトを振る舞わせる
		cout << "この問題を解決るには、他の方法が必要だあ" << endl;
	}

	~EventSender(){}
};
//----------------------------------------------------------------------

///////////////////////////////////////////////////////////////////
int main()
{
	//イベント解決処理オブジェクト生成
	IEventHandler* event1P = new EventHandler1;
	IEventHandler* event2P = new EventHandler2;

	EventSender* senderP = new EventSender;		//イベント通知オブジェクト生成

	//イベント解決オブジェクトの登録
	senderP->AddHandler(event1P);
	senderP->AddHandler(event2P);

	EventID eventid = EVENT_2;		//問題イベント

	senderP->SendEvent(eventid);	//問題イベントを通知オブジェクトへ通知

	delete event1P;
	delete event2P;
	delete senderP;

	return 0;
}