//Chain of responsibility（normal）
//ある問題を解決処理できる可能性のある複数のオブジェクトを登録し、順番に解決処理を試みていく
//解決できるオブジェクトに行き着くまで進めていく
//登録されているどのオブジェクトも処理できない場合もあり得る
//この場合には問題イベントを無視するか、デフォルトの処理を振る舞う
//
//例えば、学生からの質問（イベント問題）を学生自身が解決できるものなのか、担任レベルで解決できるものなのか、
//主任レベルで解決できるものなのかを表す
//イベントを解決するためのinterfaceクラスを定義し、それぞれの解決クラスを継承定義する
//そして、イベント解決オブジェクトをリスト構造で管理し、解決したいイベント問題をそれぞれのイベント解決オブジェクトに
//投げかけて解決させる
//もし、解決できなければ、次のイベント解決オブジェクトに委任する形で解決を試みる
//
//イベント解決オブジェクトが解決できるかどうかは、解決イベント問題の難易度と、それぞれのイベント解決オブジェクトがもつ
//解決能力レベルとを比較して判断する
//
//ChainOfResponsibility01(normal).cpp
//結果
//おやつはいくらまで？Lv= 1
//学生が解決できた
//よかった無事解決された

//携帯電話持って行ってよい？Lv= 3
//学生では解決できない
//担任では解決できない
//主任が解決できた
//よかった無事解決された


#include <iostream>
#include <string>
#include <list>
using namespace std;

////////////////////////////////////////////////////////////////////
//難易度クラス定義
class Level {
	int degree;		//難易度
public:
	Level(int ldegree):degree(ldegree){}
	int getDiffLevel()const{ return degree; }

	//難易度比較
	bool moreThan(Level another)
	{
		if(degree >= another.degree)	return true;		//自己が難
		else							return false;		//相手が難
	}
};

////////////////////////////////////////////////////////////////////
//質問クラス定義
class Question {
	string quesText;		//質問内容
	Level quesLevel;		//質問難易度オブジェクト
public:
	Question(string squesText, int squesLevel):quesText(squesText), quesLevel(squesLevel){}
	string getQuesText()const{ return quesText; }
	Level getQuesLevel()const{ return quesLevel; }
};
//----------------------------------------------------------------------

//Chain of responsibility-----------------------------------------------
//////////////////////////////////////////////////////////////////
//イベント解決者interfaceクラス定義（抽象クラス定義）
class SolvePerson {
public:
	virtual bool solveQuestion(Question* questionP) = 0;	//イベント問題解決
};

//////////////////////////////////////////////////////////////////
//イベント解決者（学生）クラス定義
class Student : public SolvePerson {
	string position;			//立場（職位）
	Level abilityLevel;			//解決力オブジェクト
public:
	Student(string sposition):position(sposition), abilityLevel(1){}

	//イベント問題解決
	bool solveQuestion(Question* questionP)
	{
		//解決力レベルと質問難易度との比較
		if(abilityLevel.moreThan(questionP->getQuesLevel()))
		{
			cout << "学生が解決できた" << endl;
			return true;		//自己解決できた
		}

		cout << "学生では解決できない" << endl;
		return false;			//解決できない
	}
};
//----------------------------------------------------------------
//イベント解決者（担任）クラス定義
class ClassTeacher : public SolvePerson {
	string position;			//立場（職位）
	Level abilityLevel;			//解決力オブジェクト
public:
	ClassTeacher(string sposition):position(sposition), abilityLevel(2){}

	//イベント問題解決
	bool solveQuestion(Question* questionP)
	{
		//解決力レベルと質問難易度との比較
		if(abilityLevel.moreThan(questionP->getQuesLevel()))
		{
			cout << "担任が解決できた" << endl;
			return true;		//自己解決できた
		}

		cout << "担任では解決できない" << endl;
		return false;			//解決できない
	}
};
//----------------------------------------------------------------
//イベント解決者（主任）クラス定義
class ChiefTeacher : public SolvePerson {
	string position;			//立場（職位）
	Level abilityLevel;			//解決力オブジェクト
public:
	ChiefTeacher(string sposition):position(sposition), abilityLevel(3){}

	//イベント問題解決
	bool solveQuestion(Question* questionP)
	{
		//解決力レベルと質問難易度との比較
		if(abilityLevel.moreThan(questionP->getQuesLevel()))
		{
			cout << "主任が解決できた" << endl;
			return true;		//自己解決できた
		}

		cout << "主任では解決できない" << endl;
		return false;			//解決できない
	}
};
//----------------------------------------------------------------------

//イベント解決処理オブジェクト管理＆処理--------------------------------
/////////////////////////////////////////////////////////////////////
//イベント通知クラス
class EventSender {
	list<SolvePerson*> lstPerson;		//イベント解決者オブジェクト管理リスト
public:
	EventSender(){}
	
	//イベント解決者オブジェクトの登録
	void addLstPerson(SolvePerson* apersonP){ lstPerson.push_back(apersonP); }
	
	//イベント解決者オブジェクトの削除
	void RemoveLstPerson(SolvePerson* rpersonP){ lstPerson.remove(rpersonP); }

	//解決したいイベント（問題）を受け付ける
	void sendEvent(Question* questionP)
	{
		showEvent(questionP);

		list<SolvePerson*>::iterator start_itr = lstPerson.begin();
		list<SolvePerson*>::iterator End_itr = lstPerson.end();

		//順番に、list登録済解決者オブジェクトにイベントを解決させる
		while(start_itr != End_itr)
		{
			//解決者オブジェクトにイベントを送って解決する
			//解決できた場合は、trueが返る
			if((*start_itr)->solveQuestion(questionP))
			{
				cout << "よかった無事解決された" << endl;
				return;
			}

			//解決できなかった場合、次の解決者オブジェクトを指定
			++start_itr;
		}

		//すべての解決者オブジェクトで解決できなかった場合
		cout << "誰にも解決できませんでした。やってみなさい。" << endl;
	}

	//受け付けたイベント（問題）表示
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
	//解決者オブジェクト生成
	SolvePerson* studentP = new Student("学生");
	SolvePerson* rookieP = new ClassTeacher("担任");
	SolvePerson* veteranP = new ChiefTeacher("主任");

	EventSender* senderP = new EventSender;		//イベント通知オブジェクト生成

	//解決者オブジェクトの登録
	senderP->addLstPerson(studentP);
	senderP->addLstPerson(rookieP);
	senderP->addLstPerson(veteranP);

	//問題イベント
	Question* questionP1 = new Question("おやつはいくらまで？", 1);
	Question* questionP2 = new Question("携帯電話持って行ってよい？", 3);

	//問題イベントを通知オブジェクトへ通知して解決してもらう
	senderP->sendEvent(questionP1);
	cout << endl;
	senderP->sendEvent(questionP2);

	delete studentP;
	delete rookieP;
	delete veteranP;
	delete senderP;

	return 0;
}

