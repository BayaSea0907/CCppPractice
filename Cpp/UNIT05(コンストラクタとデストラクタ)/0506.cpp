/*----------------------------------------------------------
|問題05-06   BayaSea
------------------------------------------------------------*/
#include <string>
#include <iostream>
#define DATELENGTH 3
using namespace std;

//名簿クラス定義
class Meibo {
	string* nameP[DATELENGTH];		//名前格納用ポインタ配列
public:
	//コンストラクタ
	Meibo() {
		nameP[0] = new string("MIZU");
		nameP[1] = new string("GORO");
		nameP[2] = new string("TOWA");
	}

	//デストラクタ
	~Meibo(){
		for (int i = 0; i < DATELENGTH; i++) {
			delete nameP[i];
		}
	}

	//名簿表示
	void show() {
		for (int i = 0; i < DATELENGTH; i++) {
			cout << *nameP[i] << endl;				// **(nameP + i)
		}
	}
};
///////////////////////////////////////////////////////////////
int main()
{
	Meibo* meiboP(new Meibo);

	//表示
	meiboP->show();	

	delete meiboP;

	system("pause");
	return 0;
}
