//Adapter パターン
//あなたのクラスはみんなばらばらで、まったくまとまりがありません。
//あなたは、学級代表を決める必要があると感じ、太郎君に学級代表を任せようと思いました。
//【コンパイルエラーになる】
//Chairperson インタフェースを実装していない Taro クラスを
//Chairperson オブジェクトとして利用しようとしてもできない
//adapter0.cpp

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
//担任クラス定義
class Teacher {
	Chairperson* chairpersonP;		//抽象クラスポインタ（interface）
public:
	Teacher()
	{
		chairpersonP = new Taro;		//太郎生成（エラー）
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
