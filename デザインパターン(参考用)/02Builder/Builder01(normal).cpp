//Builder（normal）
//「作成過程」を決定するDirectorと呼ばれるものと「表現形式」を決定するBuilderと呼ばれるものを組み合わて、
//オブジェクトの生成をより柔軟にし、そのオブジェクトの「作成過程」をもコントロールすることができるようにする
//
//Builder01(normal).cpp
//結果
//作成した塩水の塩は35g 水は150g

#include <iostream>
#include <string>
using namespace std;

//////////////////////////////////////////////////////////////////
//塩水クラス定義
class SaltWater {
	double salt;	//塩（g)
	double water;	//水（g）
public:
	SaltWater():salt(0.0), water(0.0){}

	void addSalt(double asalt){ salt += asalt; }		//塩追加
	void addWater(double awater){ water += awater; }	//水追加

	double getSalt()const{ return salt; }				//塩取得
	double getWater()const{ return water; }				//水取得
};

//表現形式------------------------------------------------------------
//////////////////////////////////////////////////////////////////
//Builder（表現形式）interfaceクラス定義（抽象クラス）
class Builder {
public:
	virtual void addSolute(double asalt) = 0;
	virtual void addSolvent(double awater) = 0;
	virtual void abandonSolution(double asaltwater) = 0;
	virtual SaltWater* getResult()const = 0;
	virtual ~Builder(){}
};

//////////////////////////////////////////////////////////////////
//塩水Builderクラス定義
class SaltWaterBuilder : public Builder {
	SaltWater* saltWaterP;					//生成塩水オブジェクト管理ポインタ
public:
	SaltWaterBuilder():saltWaterP(new SaltWater){}					//塩水オブジェクト生成
	void addSolute(double asalt){ saltWaterP->addSalt(asalt); }		//塩追加
	void addSolvent(double awater){ saltWaterP->addWater(awater); }	//水追加

	//塩水廃棄
	void abandonSolution(double asaltwater)
	{
		double abandonsalt = asaltwater * (saltWaterP->getSalt() /
												(saltWaterP->getSalt() + saltWaterP->getWater()));
		double abandonwater = asaltwater * (saltWaterP->getWater() /
												(saltWaterP->getSalt() + saltWaterP->getWater()));

		saltWaterP->addSalt(-abandonsalt);		//塩減少分を追加
		saltWaterP->addWater(-abandonwater);	//水減少分を追加
	}

	SaltWater* getResult()const{ return saltWaterP; }	//現在の塩水取得
	~SaltWaterBuilder(){ delete saltWaterP; }
};
//--------------------------------------------------------------------

//作成過程------------------------------------------------------------
//////////////////////////////////////////////////////////////////
//Builderオブジェクトの（作成過程）クラス定義
class Director {
	Builder* builderP;				//実際に操作する生成Builderオブジェクトを管理するポインタ
public:
	Director(Builder* dbuilderP):builderP(dbuilderP){}

	//生成Builderオブジェクトの作成過程を書きならべたメソッド
	void constract()
	{
		builderP->addSolvent(100);		//水追加
		builderP->addSolute(40);		//塩追加
		builderP->abandonSolution(70);	//塩水を70％廃棄
		builderP->addSolvent(100);		//水追加
		builderP->addSolute(15);		//塩追加
	}
};
//--------------------------------------------------------------------

///////////////////////////////////////////////////////////////////
int main()
{
	//塩水Builderオブジェクト生成
	Builder* builderP = new SaltWaterBuilder;

	//塩水Builderオブジェクトの作成過程オブジェクト生成
	Director* directP = new Director(builderP);

	directP->constract();							//塩水を作る

	SaltWater* saltWaterP = (SaltWater*)builderP->getResult();		//作った塩水を取得

	cout << "作成した塩水の塩は" << saltWaterP->getSalt() << "g"
		 << " 水は" << saltWaterP->getWater() << "g" << endl;

	delete builderP;
	delete directP;

	return 0;
}
