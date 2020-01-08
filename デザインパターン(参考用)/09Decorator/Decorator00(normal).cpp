//Decorator（normal）
//既存のクラスに対する追加機能を、そのクラス自身に追加せずに、
//飾り付ける（Decorateする）感覚（コアとなるものにかぶせていくイメージ）で実装する。
//例）既存の処理の前後に新たな処理を付け加えることができる

//一番上位に、飾りとなるクラスと、飾られる側のクラスの共通interfaceクラスを定義する
//飾りクラスに今、飾っている対象（飾られる側のオブジェクト）を記憶させる
//
//【プログラム内容】
//文字列に＋記号の飾りをつける
//飾りをつける文字列StrDisplayクラスと飾り枠Borderクラスとの共通interface　Displayクラスを定義する
//飾り枠Borderクラスを継承した＋記号飾りPlusBorderクラスを定義する
//飾りをつける表示文字列は飾り枠interfaceクラスで制御しながら、表示飾り枠クラスのメソッドで
//編集する
//
//Decorator00(normal).cpp
//結果
//+++ game Playing +++

#include <iostream>
#include <string>
using namespace std;

//////////////////////////////////////////////////////////////////
//文字列表示操作interfaceクラス定義（抽象クラス定義）
class Display {
public:
	Display(){}

	virtual int getRowCount()const = 0;			//表示行数取得
	virtual string getText(int row)const = 0;	//表示文字列取得

	//文字列表示
	void Print()
	{
		for(int i = 0; i < getRowCount(); i++)
			cout << getText(i) << endl;
	}

	virtual ~Display(){}
};

//Decorator定義----------------------------------------------------------
//////////////////////////////////////////////////////////////////
//飾り枠interfaceクラス定義
class Border : public Display {
	Display* displayP;				//飾り枠をつける文字列管理用ポインタ
protected:
	Border(Display* bdisplayP):displayP(bdisplayP){}
	const Display* getDisplay()const{ return displayP; }
	virtual ~Border(){ delete displayP; }
};
//----------------------------------------------------------------
//+記号飾り枠クラス定義
class PlusBorder : public Border {
public:
	PlusBorder(Display* displayP):Border(displayP){}

	//行数取得
	virtual int getRowCount()const
	{
		return getDisplay()->getRowCount();
	}

	//+記号飾り枠を付けた文字列取得
	virtual string getText(int row)const
	{
		string text("+++ " + getDisplay()->getText(row) + " +++");
		return text;
	}
	virtual ~PlusBorder(){}
};
//----------------------------------------------------------------------

///////////////////////////////////////////////////////////////////
//表示文字列クラス定義
class StrDisplay : public Display {
	string dispStr;						//表示文字列
public:
	StrDisplay(const string& sstr):dispStr(sstr){}

	virtual int getRowCount()const{ return 1; }				//表示行数（１行固定）取得
	virtual string getText(int row)const{ return dispStr; }	//表示文字列取得

	virtual ~StrDisplay(){}
};

///////////////////////////////////////////////////////////////////
int main()
{
	//飾り枠付きの文字列表示
	Display* displayP = new PlusBorder(new StrDisplay("game Playing"));

	displayP->Print();

	delete displayP;

	return 0;
}
