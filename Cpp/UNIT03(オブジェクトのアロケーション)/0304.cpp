//--------------------------------------------------
//問題03-04		BayaSea
//	Q.それぞれメモリに作られる領域名を述べなさい。
//
//	A.GNUM = 静的領域
//	  num  = スタック領域
//    p    = スタック領域
//    pの値(new int) = ヒープ領域
//--------------------------------------------------
#include <iostream>
using namespace std;

int GNUM = 100;		//外部変数

int main()
{
	int num = 200;	//自動変数
	int* p;			//ポインタ宣言（これも自動変数）

	cout << "GNUMアドレス=" << hex << &GNUM << " 値=" << GNUM << endl;
	cout << "numアドレス=" << hex << &num << " 値=" << num << endl << endl;

	p = new int;	//メモリアロケーション
	*p = 300;		//アロケーション領域に値を格納

	cout << "アロケーション領域アドレス=" << hex <<	p << " 値=" <<	*p << endl;
	cout << "ポインタアドレス=" << hex << &p << " 値=" << p << endl;

	delete p;
	system("pause");
    return 0;
}

