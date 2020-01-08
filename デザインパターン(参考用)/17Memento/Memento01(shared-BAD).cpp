//Memento（shared）
//Mementoオブジェクトもsharedポインタで管理させて、どこでも生成できるようにしてある
//（Mementoクラスのコンストラクタをpublic扱いにしている）
//この場合、コンストラクタをprivateにするとオブジェクト生成テンプレート関数で生成できない点が問題となる
//Singletonパターンにすることも考えられるが、MementoオブジェクトはGameManagerクラスでしか生成しないことを
//考えれば、コンストラクタをprivateにして、通常のポインタで管理するだけでよい（Memento02(shared).cpp）

//Memento01(shared-BAD).cpp
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
//---------------------------------------------------------------
template<class X, class Y>
shared_ptr<X> createObject(Y n)
{
	return (shared_ptr<X>)(new X(n));
}
//---------------------------------------------------------------
template<class X, class Y>
shared_ptr<X> createObject(Y n, Y m)
{
	return (shared_ptr<X>)(new X(n, m));
}
//--------------------------------------------------------------------

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

	friend class GameManager;	//GameManagerだけがprivateなメンバをアクセスできる
public:
	Memento(){}			//コンストラクタ（どこでもMementoオブジェクトを生成できてしまう問題あり）
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
	shared_ptr<Memento> createMemento()
	{
		//Momento記録オブジェクトの生成
		shared_ptr<Memento> sh_memento(createObject<Memento>());

		sh_memento->setScore(score);
		sh_memento->setHighScore(highScore);
		cout << "保存：スコア=" << sh_memento->getScore() 
			 << " ハイスコア=" << sh_memento->getHighScore() << endl;
		return sh_memento;
	}
	
	//状態の復元
	void setMemento(shared_ptr<const Memento> sh_memento)
	{
		score = sh_memento->getScore();
		highScore = sh_memento->getHighScore();
		cout << "復元：スコア=" << sh_memento->getScore() 
			 << " ハイスコア=" << sh_memento->getHighScore() << endl << endl;
	}
	~GameManager(){}
};
//-------------------------------------------------------------------

//////////////////////////////////////////////////////////////////
int main()
{
	shared_ptr<GameManager> sh_game(createObject<GameManager>());	//ゲーム管理オブジェクト
	shared_ptr<Memento> sh_memento = NULL;							//Mementoオブジェクト

	srand((unsigned int)time(NULL));

	while(1)
	{
		sh_game->continueGame();		//ゲーム進行

		//未保存中で適当なタイミングで、状態を保存
		if(sh_memento == NULL && rand() % 40 == 0)
		{
			sh_memento = sh_game->createMemento();		//保存中
		}

		//保存中で適当なタイミングで、状態を復元
		if(sh_memento != NULL && rand() % 70 == 1)
		{
			sh_game->setMemento(sh_memento);	//状態を復元
			sh_memento = NULL;					//未保存中
		}

		//終了
		if(sh_memento == NULL && rand() % 100 == 0)	break;
	}

	return 0;
}
