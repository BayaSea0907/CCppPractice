//問題０２－０３		BayaSea
#include <iostream>
using namespace std;

//弁当クラス定義
class Bento {
	int kosu = 10;       //個数（10）
public:
	int getKosu(){ return kosu; }
	int calc(int un){ return kosu * un; }
};
///////////////////////////////////////////////////////////////////
int main()
{
	Bento bento; 		//オブジェクト宣言

	cout << "Enterキーを押して下さい" << endl;
	cin.ignore();

	cout << "kosu=" << bento.getKosu() << endl;

	cout << "Enterキーを2回押して下さい" << endl;
	cin.ignore(2);

	cout << "合計=" << bento.calc(500) << endl;

	system("pause");
	return 0;
}