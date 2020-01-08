//Memento（normal）
//Memento とは、英語で「記念品」「形見」を意味する単語
//Memento パターンとは、 インスタンスのあるときの状態をスナップショットとして保存しておくことで、
//その時のインスタンスの状態を復元することを可能にするもの
//インスタンスの状態が、プログラム実行中にどんどん変化することが考えられます。
//一度変化してしまったインスタンスを、「少し前の状態に戻したい」「ある時点の状態に戻したい」などの要求は
//時に発生するものです。 このような要求にスマートに応えることができるのが、Memento パターンです。
//Memento パターンを使うと、インスタンスのある時の状態を、簡単にスナップショットとして残すことができ、
//さらに、そこからの復元も可能になります。
//インスタンス全ての状態を覚えておくために、 clone を作成することもありますが、
//Memento パターンでは、必要な情報のみを保持しておき、必要なデータのみを復元できる


//例えば、ゲームを中断して再開した時、中断時の得点状態から継続するとする
//得点記録クラスとしてMementoクラスを定義し、このMementoクラスにはゲーム管理オブジェクトからしか
//アクセスできないようにする（アクセスできる権限は、friendであるGameManagerクラスのみ）
//そしてMementoクラスでは、インスタンス変数（得点）をアクセスするメソッドやコンストラクタも
//privateにしておき、メソッドはGameManagerクラスだけがアクセスできるようにする
//プログラムでは、乱数を発生させて保存、復元を行い、確認のため保存復元タイミングで得点を表示している

//Memento00(normal).cpp
//結果
//保存：スコア=280 ハイスコア=4060
//復元：スコア=280 ハイスコア=4060
//
//保存：スコア=450 ハイスコア=10350
//復元：スコア=450 ハイスコア=10350
//
//保存：スコア=630 ハイスコア=20160
//復元：スコア=630 ハイスコア=20160
//
//保存：スコア=1200 ハイスコア=72600
//復元：スコア=1200 ハイスコア=72600
//
//保存：スコア=1610 ハイスコア=130410
//復元：スコア=1610 ハイスコア=130410

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

//Memento----------------------------------------------------------------
//////////////////////////////////////////////////////////////////
//現状の記録クラス定義
class Memento {
	int score;				//現在のスコア
	int highScore;			//ハイスコア

	void setScore(int sscore){ score = sscore; }
	int  getScore()const{ return score; }
	void setHighScore(int shighScore){ highScore = shighScore; }
	int  getHighScore()const{ return highScore; }

	Memento(){}					//コンストラクタ
	friend class GameManager;	//GameManagerだけがprivateなメンバをアクセスできる
public:
	~Memento(){}
};

//Mementoクラスを使って状態を記録したいクラス定義--------------------
//////////////////////////////////////////////////////////////////
//ゲーム管理クラス定義
class GameManager {
	int score;				//現在のスコア
	int highScore;			//ハイスコア
public:
	GameManager():score(0), highScore(0){}

	//ゲーム進行（得点加算）
	void continueGame()
	{
		score += 10;
		highScore += score;
	}
	
	//状態の保存
	Memento* createMemento()
	{
		Memento* memP = new Memento();		//Momento記録オブジェクトの生成

		memP->setScore(score);
		memP->setHighScore(highScore);
		cout << "保存：スコア=" << memP->getScore() 
			 << " ハイスコア=" << memP->getHighScore() << endl;
		return memP;
	}
	
	//状態の復元
	void setMemento(const Memento* memP)
	{
		score = memP->getScore();
		highScore = memP->getHighScore();
		cout << "復元：スコア=" << memP->getScore() 
			 << " ハイスコア=" << memP->getHighScore() << endl << endl;
	}
	~GameManager(){}
};
//-------------------------------------------------------------------

//////////////////////////////////////////////////////////////////
int main()
{
	GameManager* gameP = new GameManager;	//ゲーム管理オブジェクト管理ポインタ
	Memento* memP = NULL;					//Mementoオブジェクト管理ポインタ

	srand((unsigned int)time(NULL));

	while(1)
	{
		gameP->continueGame();		//ゲーム進行

		//未保存中で適当なタイミングで、状態を保存
		if(memP == NULL && rand() % 40 == 0)
		{
			memP = gameP->createMemento();		//保存中
		}

		//保存中で適当なタイミングで、状態を復元
		if(memP != NULL && rand() % 70 == 0)
		{
			gameP->setMemento(memP);	//状態を復元
			delete memP;				//状態を復元したら生成Mementoオブジェクトを解放
			memP = NULL;				//未保存中
		}

		//終了
		if(memP == NULL && rand() % 100 == 0)	break;
	}

	delete gameP;

	return 0;
}
