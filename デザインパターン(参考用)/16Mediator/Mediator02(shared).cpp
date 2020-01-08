//Mediator（shared）
//Mediatorは、複数のオブジェクト間の調整をするために、各オブジェクトからの問い合わせを受け、
//適宜判断を行って指示を出す「調停者」の役割を果たすクラスを利用するパターン
//Mediatorでは、調停者の役割を果たすMediatorインタフェース、相談をする側（同僚）を表すCollegueインタフェースを
//定義して、それぞれを実装する形で、実際の調整役や相談者を表すクラスを作成する

//Mediatorでは、各オブジェクトは、自分の状態が変わったときにMediatorに連絡して、
//Mediatorは、対象となるオブジェクトの状態を判断し、連絡してきたオブジェクトに、
//連絡に対する返事を行う

//例では、同僚がある同僚に恋したので、調停者に相手の同僚に今恋人がいるかどうか聞いてもらって
//その結果を教えてもらうことにしています
//調停者は、すべての同僚をmap（名前と生成オブジェクトのポインタをペア）で管理している

//調停者interfaceクラスを継承したクラス定義は、調停者interfaceと同僚interfaceのクラス定義以降に
//定義しないとコンパイルエラーとなる

//Mediator01(shared).cpp
//結果
//YASUはMAIに恋した
//やった～　デートに誘おう
//
//MAIはSEKIに恋した
//なんだって！　彼（彼女）知らないのか？
//
//YASUはKAORIも恋した
//うぇ～ん！　残念だ～

#include <iostream>
#include <string>
#include <map>
#include <memory>
using namespace std::tr1;
using namespace std;

class Colleague;

//オブジェクト生成テンプレート関数-----------------------------------
///////////////////////////////////////////////////////////////////
template<class X>
shared_ptr<X> createObject()
{
	return (shared_ptr<X>)(new X);
}
//--------------------------------------------------------------------
template<class X, class Y, class Z, class T>
shared_ptr<X> createObject(Y n, Z m, T t)
{
	return (shared_ptr<X>)(new X(n, m, t));
}
//--------------------------------------------------------------------

//MediatorとColleagueのintefaceクラス定義++++++++++++++++++++++++++++++++++
//Mediator-------------------------------------------------------------
//////////////////////////////////////////////////////////////////
//調停者interfaceクラス定義（抽象クラス）
class Mediator {
public:
	virtual void addColleague(shared_ptr<Colleague> sh_colleague) = 0;	//同僚mapに登録

	//恋人の有無についての問合せに応える
	virtual int inquire(Colleague* colleagueInLoveP, string name) = 0;
};
//---------------------------------------------------------------------

//Colleague------------------------------------------------------------
/////////////////////////////////////////////////////////////////
//同僚クラスinterafeceクラス定義（抽象クラス）
class Colleague {
public:
	virtual string getName()const = 0;
	virtual void setCompanion(string name) = 0;		//恋に落ちた相手
	virtual void fallInLove() = 0;					//恋に落ちた（mediatorへ通知）
	virtual int getLoverCheck() = 0;				//恋人有無取得
};
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//調停者と同僚のクラス定義+++++++++++++++++++++++++++++++++++++++++++++++++
//////////////////////////////////////////////////////////////////
//調停者クラス定義
class ZweiPerson : public Mediator {
	map<string, shared_ptr<Colleague>> mapColleague;					//同僚オブジェクト管理map
	map<string, shared_ptr<Colleague>>::iterator mapColleague_itr;
public:
	//mapに同僚オブジェクトを登録（名前とオブジェクトのポインタ）
	void addColleague(shared_ptr<Colleague> sh_acolleague)
	{
		mapColleague.insert(pair<string, shared_ptr<Colleague>>(sh_acolleague->getName(), sh_acolleague));
	}

	//恋人の有無についての問合せに応える
	int inquire(Colleague* colleagueInLoveP, string name)
	{
		int possibility = 0;	//０：同僚mapに未登録、１：付き合える、２：付き合えない

		mapColleague_itr = mapColleague.begin();

		//付き合いたい人が同僚mapに登録されてるか検索
		if((mapColleague_itr = mapColleague.find(name)) != mapColleague.end())
		{
			//同僚mapに登録されてれば、付き合いたい相手に今恋人がいるかどうか問い合わせる
			if(mapColleague_itr->second->getLoverCheck() == 0)
			{
				possibility = 1;	//今恋人がいなければ、返事を付き合えるに設定
			}
			else
			{
				possibility = 2;	//恋人がいれば、付き合えないに設定
			}
		}
		return possibility;			//付き合えるかどうかを返事する
	}
};
//----------------------------------------------------------------------
////////////////////////////////////////////////////////////////
//同僚クラス定義
class Member : public Colleague {
	string name;						//氏名
	int loverCheck;						//恋人有無（０無し、１有り）
	string companion;					//恋に落ちた相手
	shared_ptr<Mediator> sh_mediator;	//調停者管理ポインタ
public:
	Member(string sname, int sLoverCheck, shared_ptr<Mediator> sh_lmediator)
					:name(sname), loverCheck(sLoverCheck), sh_mediator(sh_lmediator){}

	void setCompanion(string name){ companion = name; }		//恋に落ちた相手登録
	string getName()const{ return name; }

	//恋に落ちた
	void fallInLove()
	{
		//恋に落ちた相手に恋人がいるかどうかを調停者に尋ねる
		switch(sh_mediator->inquire(this, companion))
		{
			//調停者からの返事で反応する
			case 1: cout << "やった～　デートに誘おう" << endl; break;
			case 2: cout << "うぇ～ん！　残念だ～" << endl; break;
			default: cout << "なんだって！　彼（彼女）を知らないのか？" << endl;
		}
	}

	int getLoverCheck(){ return loverCheck; }	//調停者からの問い合わせ受付
};
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

////////////////////////////////////////////////////////////////
int main()
{
	//調停者生成
	shared_ptr<Mediator> sh_mediator(createObject<ZweiPerson>());

	//同僚に調停者を登録
	shared_ptr<Colleague> sh_colleague1(createObject<Member, string, int, shared_ptr<Mediator>>("YASU", 0, sh_mediator));
	shared_ptr<Colleague> sh_colleague2(createObject<Member, string, int, shared_ptr<Mediator>>("MAI", 0, sh_mediator));
	shared_ptr<Colleague> sh_colleague3(createObject<Member, string, int, shared_ptr<Mediator>>("KAORI", 1, sh_mediator));

	//調停者にすべての同僚を登録
	sh_mediator->addColleague(sh_colleague1);
	sh_mediator->addColleague(sh_colleague2);
	sh_mediator->addColleague(sh_colleague3);

	cout << "YASUはMAIに恋した" << endl;
	sh_colleague1->setCompanion("MAI");		//YASUはMAIに恋した
	sh_colleague1->fallInLove();			//恋に落ちた
	cout << endl;

	cout << "MAIはSEKIに恋した" << endl;
	sh_colleague2->setCompanion("SEKI");	//MAIはSEKIに恋した
	sh_colleague2->fallInLove();			//恋に落ちた
	cout << endl;

	cout << "YASUはKAORIも恋した" << endl;
	sh_colleague1->setCompanion("KAORI");	//YASUはKAORIも恋した
	sh_colleague1->fallInLove();			//恋に落ちた

	return 0;
}
