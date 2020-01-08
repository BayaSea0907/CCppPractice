//Flyweight（normal）
//Flyweightパターンは、無駄なインスタンスを生成を防ぎ、共有することでリソースを無駄なく使う
//共有できるものは共有する（オブジェクトのメモリ使用量を小さくする）
//Flyweightパターンを利用することで、どのインスタンスを持っているのかなどを、
//利用者(呼び出し側)で把握しておく必要がなくなる
//複数の呼び出し先からの要求にも無駄なく応えることが可能となる
//Flyweightパターンは、ひとつのインスタンスを各所で共有できるので、
//共有されるインスタンスが本質的(intrinsic)な情報のみを持つ場合にのみ利用するべき
//非本質的(extrinsic)な情報は、どこかの誰かが変更する可能性のあるものであり、
//共有するインスタンスを勝手に誰かが変更することで、そこかしこに影響を与えることになりかねない

//例）アルファベット52（大小26）文字から構成される英文では、文章量が多くても、
//生成するオブジェクトの個数は52個で済むはず

//生成文字オブジェクト用に文字クラスを定義する
//文字に応じた文字オブジェクトを生成し、既に生成されていれば、その文字オブジェクトを
//返す文字オブジェクト生成クラスCharacterFactoryをFlyweightパターンとして定義する

//CharacterFactoryクラス経由で、文字オブジェクトを取得するので、CharacterFactoryクラスは
//グローバルな場所に存在させるべき
//そこで、FlyweightとしてはCharacterFactoryクラスをSingletonにしてしまうのが一般的
//
//Flyweight00(normal).cpp
//結果
//新規生成 文字オブジェクト
//X
//新規生成 文字オブジェクト
//G
//既生成済 文字オブジェクト
//X
//新規生成 文字オブジェクト
//a

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

//オブジェクト生成文字------------------------------------------------
//////////////////////////////////////////////////////////////////
//文字クラス
class Character {
	char mozi;		//文字
public:
	Character(char cmozi):mozi(cmozi){}
	char getMozi()const{ return mozi; }

	//関数オブジェクトから呼び出される（必要）
	bool operator==(char target){ return mozi == target; }
};
//-----------------------------------------------------------------
////////////////////////////////////////////////////////////////////
//関数オブジェクト用クラス定義（探索値と同値要素判別）
//引数はポインタ対応
template<class X>
class EqTargetIf
{
	char target;	//探索値
public:
	EqTargetIf(char ftarget):target(ftarget){}
	bool operator()(X ptr){ return *ptr == target; }
};
//--------------------------------------------------------------------

//Flyweight-----------------------------------------------------------
//////////////////////////////////////////////////////////////////
//文字オブジェクト生成ファクトリ（Singletonパターン）
class CharacterFactory {
	vector<Character*> vCharacter;		//文字オブジェクト
	//コピー禁止
	CharacterFactory(){}
	CharacterFactory(const CharacterFactory& rhs){}
	CharacterFactory& operator=(const CharacterFactory& rhs){}
public:
	//唯一のアクセス経路
	static CharacterFactory* GetInstance()
	{
		static CharacterFactory instance;
		return &instance;
	}

	//生成文字オブジェクト取得
	Character* GetCharacter(char mozi)
	{
		vector<Character*>::iterator result_itr;	//vectorの検索位置iterator宣言

		//文字オブジェクトが既に生成されてるかどうかをvector探索
		result_itr = find_if(vCharacter.begin(), vCharacter.end(), EqTargetIf<Character*>(mozi));

		int index;		//文字オブジェクトのvector登録位置取得用

		//まだ生成されていなければ文字オブジェクトを作る
		if(result_itr == vCharacter.end())
		{
			cout << "新規生成 文字オブジェクト" << endl;
			vCharacter.push_back(new Character(mozi));		//文字オブジェクト生成追加登録

			//追加登録位置取得（vectorの最後に追加しているので）
			index = (int)(vCharacter.end() - vCharacter.begin());
			index--;
		}
		else
		{
			cout << "既生成済 文字オブジェクト" << endl;
			index = (int)(result_itr - vCharacter.begin());		//登録済vector要素位置取得
		}
		return vCharacter[index];		//文字オブジェクトの登録位置を戻す
	}

	~CharacterFactory()
	{
		//vectorに登録した文字オブジェクトの解放
		for(int i = 0; i < (int)vCharacter.size(); i++)	delete vCharacter[i];
	}
};
//--------------------------------------------------------------------

///////////////////////////////////////////////////////////////////
int main()
{
	CharacterFactory* sP1 = CharacterFactory::GetInstance();	//Singletonオブジェクト生成

	//文字オブジェクト生成
	cout << sP1->GetCharacter('X')->getMozi() << endl;
	cout << sP1->GetCharacter('G')->getMozi() << endl;
	cout << sP1->GetCharacter('X')->getMozi() << endl;
	cout << sP1->GetCharacter('a')->getMozi() << endl;

	return 0;
}
