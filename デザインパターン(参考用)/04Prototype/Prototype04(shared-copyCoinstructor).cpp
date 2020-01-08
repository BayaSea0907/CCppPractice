//Prototype（shared：コピーコンストラクタ代用）
//事前にクラスのインスタンス（オブジェクト）を用意しておき、
//そのコピー（クローン）を作りだすことで、以降のインスタンス生成を簡単にする
//Cloneメソッドを使わずに、コピーコンストラクタを使って、C++らしいCloneを作っている
//

//Prototype04(shared-copyConstructor).cpp
//結果
//original name = MICKY
//clone name = MICKY

#include <iostream>
#include <string>
#include <memory>
using namespace std::tr1;
using namespace std;

//////////////////////////////////////////////////////////////////
//Clone interfaceクラス定義（抽象intrerfaceクラス）
class IClone {
public:
	virtual string getName()const = 0;
	virtual ~IClone(){}
};

//////////////////////////////////////////////////////////////////
//クローンマウスクラス定義
//class Mouse {
class Mouse : public IClone {
	string name;
public:
	Mouse(string mname = ""):name(mname){}

	//自身のクローンを作るコピーコンストラクタ
	Mouse(const IClone& mob)
	{
		name = mob.getName();
	}
	
	string getName()const{ return name; }
	~Mouse(){}
};

//オブジェクト生成テンプレート関数（sharedポインタの場合ここに定義）-----
///////////////////////////////////////////////////////////////////
template<class X>
shared_ptr<X> createObject(string n)
{
	return (shared_ptr<X>)(new X(n));
}
//sharedポインタ用--------------------------------------------------
template<class X>
shared_ptr<X> createObject(shared_ptr<IClone> n)
{
	return (shared_ptr<X>)(new X(*n));
}
//------------------------------------------------------------------------

///////////////////////////////////////////////////////////////////
int main()
{
/*
	Mouse original("MICKY");
	Mouse clone = original;		//clone作成

	cout << "original name = " << original.getName() << endl;
	cout << "clone name = " << clone.getName() << endl;
*/
/*
	Mouse* originalP = new Mouse("MICKY");
	Mouse* cloneP = new Mouse(*originalP);		//clone作成

	cout << "original name = " << originalP->getName() << endl;
	cout << "clone name = " << cloneP->getName() << endl;

	delete originalP;
	delete cloneP:
*/
/*
	IClone* original = new Mouse("MICKY");
	IClone* clone = new Mouse(*original);		//clone作成

	cout << "original name = " << original->getName() << endl;
	cout << "clone name = " << clone->getName() << endl;

	delete originalP;
	delete cloneP:
*/

	shared_ptr<IClone> original(createObject<Mouse>("MICKY"));
	shared_ptr<IClone> clone(createObject<Mouse>(original));		//clone作成

	cout << "original name = " << original->getName() << endl;
	cout << "clone name = " << clone->getName() << endl;

	return 0;
}
