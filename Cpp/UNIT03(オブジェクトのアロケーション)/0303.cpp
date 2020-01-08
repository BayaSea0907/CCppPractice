/*-----------------------------------------------------
|問題03-03		BayaSea
-------------------------------------------------------*/
#include <iostream>
using namespace std;

//Hero構造体定義
struct Hero {
	int hp;				//HP
};
////////////////////////////////////////////////////////////
int main(){
	Hero* heroP(new Hero);		//構造体変数領域へのポインタ宣言

	//heroP = new Hero;			//アロケーション

	heroP->hp = 100;			//HP設定
	cout << "HP=" << heroP->hp << endl;	//HP表示

	delete heroP;

	system("pause");
	return 0;
}