//adapter1.cpp
//Taro クラスと Chairperson インタフェースのインタフェースの違いを埋めるように
//NewTaro クラスを実装する。

#include <iostream>
using namespace std;

//////////////////////////////////////////////////////
//太郎能力クラス定義
class Taro{
public:
	void enjoyWithAllClassmate()
	{
		cout << "みんなで楽しむ" << endl;
	}
};

//////////////////////////////////////////////////////
//学級代表クラス定義（抽象クラス：interface）
class Chairperson{
public:
	virtual void organizeClass() = 0;
};

//////////////////////////////////////////////////////
//new太郎能力クラス定義（interfaceの実装クラス）
class NewTaro : public Taro, public Chairperson {
public:
	void organizeClass()
	{
		enjoyWithAllClassmate();
	}
};

//////////////////////////////////////////////////////
//担任クラス定義
class Teacher {
	Chairperson* chairpersonP;		//抽象クラスポインタ（interface）
public:
	Teacher()
	{
		chairpersonP = new NewTaro;		//new太郎生成
		chairpersonP->organizeClass();
	}
	~Teacher(){ delete chairpersonP; }
};

//////////////////////////////////////////////////////
int main()
{
	Teacher* teacherP(new Teacher);

	delete teacherP;

	return 0;
}
