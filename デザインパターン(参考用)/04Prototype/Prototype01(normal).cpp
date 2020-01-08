//Prototype（normal）
//事前にクラスのインスタンス（オブジェクト）を用意しておき、
//そのコピー（クローン）を作りだすことで、以降のインスタンス生成を簡単にする
//
//Prototype01(normal).cpp
//結果
//real name = MICKY
//clone name = MICKY

#include <iostream>
#include <string>
using namespace std;

//////////////////////////////////////////////////////////////////
//Clone interfaceクラス定義（抽象intrerfaceクラス）
class IClone {
public:
	virtual IClone* Clone() = 0;
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
	IClone* Clone()
	{
		IClone* cloneP = new Mouse();
		
		cloneP->setName(name);
		return cloneP;
	}

	void setName(string sname){ name = sname; }
	string getName()const{ return name; }

	~Mouse(){}
};

///////////////////////////////////////////////////////////////////
int main()
{
	IClone* realP(new Mouse("MICKY"));

	IClone* cloneP = realP->Clone();

	cout << "real name = " << realP->getName() << endl;
	cout << "clone name = " << cloneP->getName() << endl;

	delete realP;
	delete cloneP;

	return 0;
}
