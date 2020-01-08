//Prototype（declare：コピーコンストラクタ代用）
//事前にクラスのインスタンス（オブジェクト）を用意しておき、
//そのコピー（クローン）を作りだすことで、以降のインスタンス生成を簡単にする
//Cloneメソッドを使わずに、コピーコンストラクタを使って、C++らしいCloneを作っている
//

//Prototype03(declare-copyConstructor).cpp
//結果
//original name = MICKY
//clone name = MICKY

#include <iostream>
#include <string>
using namespace std;

//クローンマウスクラス定義
class Mouse {
	string name;
public:
	Mouse(string mname = ""):name(mname){}

	//自身のクローンを作るコピーコンストラクタ
	Mouse(const Mouse& mob)
	{
		name = mob.getName();
	}
	
	string getName()const{ return name; }
	~Mouse(){}
};

///////////////////////////////////////////////////////////////////
int main()
{
	Mouse original("MICKY");
	Mouse clone = original;		//clone作成

	cout << "original name = " << original.getName() << endl;
	cout << "clone name = " << clone.getName() << endl;

	return 0;
}
