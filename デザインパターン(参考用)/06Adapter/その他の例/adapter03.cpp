//Adapter パターン（委譲を利用）
//太郎君がどうしても Chairperson インタフェースを実装したくないと言い張った場合
//のことを考えましょう。あなたは、太郎君と仲の良い花子さんに学級代表になってもら
//うことにしました。
//先生の狙いは、花子さんが、 Taro クラスの enjoyWithClassmate メソッドをうまく
//呼び出すことでクラスをまとめていくというものです。
//この際、学級代表は花子さんなので、花子さんが Chairperson インタフェースを実装する
//ことになります。
//adapter2.cpp

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
//花子能力クラス定義（interfaceの実装クラス）
class Hanako : public Chairperson {
	Taro* taroP;
public:
	Hanako():taroP(new Taro){}
	void organizeClass()
	{
		taroP->enjoyWithAllClassmate();
	}
	~Hanako(){ delete taroP; }
};

//////////////////////////////////////////////////////
//担任クラス定義
class Teacher {
	Chairperson* chairpersonP;		//抽象クラスポインタ（interface）
public:
	Teacher()
	{
		chairpersonP = new Hanako;		//花子生成
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
