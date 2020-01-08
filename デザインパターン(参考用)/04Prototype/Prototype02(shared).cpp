//Prototype（shared）
//事前にクラスのインスタンス（オブジェクト）を用意しておき、
//そのコピー（クローン）を作りだすことで、以降のインスタンス生成を簡単にする
//
//Prototype02(shared).cpp
//結果
//real name = MICKY
//clone name = MICKY

#include <iostream>
#include <string>
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
//--------------------------------------------------------------------

//////////////////////////////////////////////////////////////////
//Clone interfaceクラス定義（抽象intrerfaceクラス）
class IClone {
public:
	virtual shared_ptr<IClone> Clone() = 0;
	virtual void setName(string) = 0;
	virtual string getName()const = 0;
	virtual ~IClone(){}
};

//////////////////////////////////////////////////////////////////
//クローンマウスクラス定義
class Mouse : public IClone {
	string name;
public:
	Mouse(string mname = ""):name(mname){}
	
	//自身のクローンを作る
	shared_ptr<IClone> Clone()
	{
		shared_ptr<IClone> clone(createObject<Mouse>());
		
		clone->setName(name);
		return (shared_ptr<IClone>)clone;
	}

	void setName(string sname){ name = sname; }
	string getName()const{ return name; }

	~Mouse(){}
};

///////////////////////////////////////////////////////////////////
int main()
{
	shared_ptr<IClone> real(createObject<Mouse>("MICKY"));
	shared_ptr<IClone> clone = real->Clone();

	cout << "real name = " << real->getName() << endl;
	cout << "clone name = " << clone->getName() << endl;

	return 0;
}
