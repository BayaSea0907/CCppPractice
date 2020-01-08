//Memento（shared）
//オブジェクトのあるときの状態をスナップショットとして保存しておくことで、
//その時の状態を復元することを可能にするもの
//オブジェクトの状態が、プログラム実行中にどんどん変化している場合、
//オブジェクトを「少し前の状態に戻したい」「ある時点の状態に戻したい」などに対応する
//cloneパターン、オブジェクトの全ての状態を覚えておいてもよいが、必要な情報のみを保持して、
//必要なデータのみを復元するのにMementoパターンを使える

//例えば、ゲームを中断して再開した時、中断時の得点状態から継続する場合に、Mementopターンを使える
//この場合、得点記録クラスとしてMementoクラスを定義して、このMementoクラスにはゲーム管理オブジェクトから
//しかアクセスできないようにしておく（アクセスできる権限は、friendであるGameManagerクラスのみ）
//そしてMementoクラスでは、インスタンス変数（得点）をアクセスするメソッドやコンストラクタも
//privateにしておき、メソッドはGameManagerクラスだけがアクセスできるようにする
//このプログラムでは、乱数を発生させて保存、復元を行い、確認のため保存復元タイミングで得点を表示している

//Mementoオブジェクトは、GameManagerクラスのみで生成するので、通常のポインタで管理している
//Mementoオブジェクトもsharedポインタで管理させてもよいが、この場合、コンストラクタをprivateにすると
//オブジェクト生成テンプレート関数で生成できない
//Singletonパターンにすることも考えられるが、MementoオブジェクトはGameManagerクラスでしか生成しないことを
//考えれば、コンストラクタをprivateにして、通常のポインタで管理するだけでよい

//Memento02(shared).cpp
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
#include <memory>
using namespace std::tr1;
using namespace std;

//オブジェクト生成テンプレート関数-----------------------------------
///////////////////////////////////////////////////////////////////
template<class X>
shared_ptr<X> createObject()
{
	return (shared_ptr<X>)(new X);
}
//--------------------------------------------------------------------

//Memento----------------------------------------------------------------
//////////////////////////////////////////////////////////////////
//現状の記録クラス定義
class Memento {
	int score;				//現在のスコア
	int highScore;			//ハイスコア

	void setScore(int sscore){ score = sscore; }
	int getScore()const{ return score; }
	void setHighScore(int shighScore){ highScore = shighScore; }
	int getHighScore()const{ return highScore; }

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
		//Momento記録オブジェクトの生成
		Memento* mementoP = new Memento;

		mementoP->setScore(score);
		mementoP->setHighScore(highScore);
		cout << "保存：スコア=" << mementoP->getScore() 
			 << " ハイスコア=" << mementoP->getHighScore() << endl;
		return mementoP;
	}
	
	//状態の復元
	void setMemento(const Memento* mementoP)
	{
		score = mementoP->getScore();
		highScore = mementoP->getHighScore();
		cout << "復元：スコア=" << mementoP->getScore() 
			 << " ハイスコア=" << mementoP->getHighScore() << endl << endl;
	}
	~GameManager(){}
};
//-------------------------------------------------------------------

//////////////////////////////////////////////////////////////////
int main()
{
	shared_ptr<GameManager> sh_game(createObject<GameManager>());	//ゲーム管理オブジェクト
	Memento* mementoP = NULL;										//Mementoオブジェクト管理ポインタ

	srand((unsigned int)time(NULL));

	while(1)
	{
		sh_game->continueGame();		//ゲーム進行

		//未保存中で適当なタイミングで、状態を保存
		if(mementoP == NULL && rand() % 40 == 0)
		{
			mementoP = sh_game->createMemento();		//保存中
		}

		//保存中で適当なタイミングで、状態を復元
		if(mementoP != NULL && rand() % 70 == 0)
		{
			sh_game->setMemento(mementoP);	//状態を復元
			delete mementoP;				//状態を復元したら生成Mementoオブジェクトを解放
			mementoP = NULL;				//未保存中
		}

		//終了
		if(mementoP == NULL && rand() % 100 == 0)	break;
	}

	return 0;
}
