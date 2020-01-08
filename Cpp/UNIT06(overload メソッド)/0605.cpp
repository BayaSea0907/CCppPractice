//問題０６－０５ BayaSea
#include <stdlib.h>
#include <time.h>
#include <iostream>
using namespace std;

//数当てゲームクラス
class Game
{
	int PC;			//数当てナンバー
public:
	//コンストラクタ
	Game()
	{
		srand((unsigned)time(NULL));
		PC = rand() % 10;
	}
	/*
	//数当て（PC対戦用）
	void hit()
	{
		if(PC == (rand() % 10))		cout << "あたり" << endl;
		else						cout << "はずれ" << endl;
	}
	//数当て（プレイヤー対戦用）
	void hit(int play)
	{
		if(play == PC)				cout << "あたり" << endl;
		else						cout << "はずれ" << endl;
	}
	*/
	//---------------------------------------------------------------
	//チャレンジ問題：数当て（play:0～9　プレイヤー対戦、0～9以外　PC対戦用乱数）
	void hit(int play = (rand() % 10))
	{
		//PC対戦、プレーヤー対戦共通
		if(play == PC)				cout << "あたり" << endl;
		else						cout << "はずれ" << endl;
	}
	//---------------------------------------------------------------
};
int main()
{
	Game* gameP(new Game);
	int select;          //対戦ケース選択用（１：対PC、１以外：対プレイヤー）
	int play;            //プレイヤー入力値用

	cout << "PC対戦(1)　or　PC対プレイヤー対戦(2)>> ";
	cin >> select;

	switch (select)
	{
	case 1:
		gameP->hit();
		break;
	default:
		do
		{
			cout << "プレイヤー値の入力（０～９）>> ";
			cin >> play;

			if (play >= 0 && play <= 9)    break;

			cout << "範囲外です　再入力して下さい" << endl;
		} while (1);

		gameP->hit(play);
		break;
	}

	delete gameP;
	return 0;
}
