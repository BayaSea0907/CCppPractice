//Bridge（sharedポインタ使用）
//クラスを継承するとき、その目的には大きく分けて２種類ある。
//【Bridge02.cpp問題点】
//しかしながら、Windowクラスの機能拡張を考えた場合、Windowクラス以降の継承クラスを
//幾層にも機能継承することになり不具合が生じる（Bridge03.cpp）
/*
//////////////////////////////////////////////////////////////////
//Bridgeクラス定義
class CWindowBase {
	shared_ptr<IDrawer> sh_mDrawer;				//どの描画クラスでも使えるinterfaceクラス型
public:
	CWindowBase(IDrawer* drawer):sh_mDrawer(drawer){}
	void draw(){ sh_mDrawer->draw(); }
	virtual ~CWindowBase(){}
};

//////////////////////////////////////////////////////////////////
//ウィンドウ
class CWindow : public CWindowBase {
public:
	CWindow(IDrawer* drawer):CWindowBase(drawer){}
	~CWindow(){}
};
//--------------------------------------------------------------------
*/
//Bridgeパターンを使うと、２つの機能階層とinterface階層構造を明確に分離することができる。
//【どの描画機能を使うかは、CWindowBaseクラスのコンストラクタに、
//何を渡したかで決定します。

	//描画クラスは自由に変更できる。
	//かつ、Windowクラスの機能拡張があっても機能継承が容易（深い継承階層にならない）
/*
	shared_ptr<CWindow> sh_window1(createObject<CWindow, CDrawUseLibB>());
	shared_ptr<CWindow> sh_window2(createObject<CWindow, CDrawUseLibB>());
*/

//オブジェクト生成テンプレート関数-----------------------------------
/*
///////////////////////////////////////////////////////////////////
template<class X>
shared_ptr<X> createObject()
{
	return (shared_ptr<X>)(new X);
}
//---------------------------------------------------------------
template<class X, class Y>
shared_ptr<X> createObject()
{
	return (shared_ptr<X>)(new X(new Y));
}
//--------------------------------------------------------------------
*/
//
//Bridge03(shared).cpp
//結果
//描画Ａ
//描画Ｂ

#include <iostream>
#include <string>
#include <memory>
using namespace std::tr1;
using namespace std;

//描画クラス----------------------------------------------------------
//////////////////////////////////////////////////////////////////
//描画interfaceクラス定義（抽象interfaceクラス）
class IDrawer {
public:
	virtual void draw() = 0;
};
//----------------------------------------------------------------
//描画Ａクラス定義
//描画Ａクラス定義
class CDrawUseLibA : public IDrawer {
public:
    void draw(){ cout << "描画Ａ" << endl; }
};
//----------------------------------------------------------------
//描画Ｂクラス定義
class CDrawUseLibB : public IDrawer {
public:
    void draw(){ cout << "描画Ｂ" << endl; }
};
//------------------------------------------------------------------

//////////////////////////////////////////////////////////////////
//Bridgeクラス定義
class CWindowBase {
	shared_ptr<IDrawer> sh_mDrawer;				//どの描画クラスでも使えるinterfaceクラス型
public:
	CWindowBase(IDrawer* drawer):sh_mDrawer(drawer){}
	void draw(){ sh_mDrawer->draw(); }
	virtual ~CWindowBase(){}
};

//////////////////////////////////////////////////////////////////
//ウィンドウ
class CWindow : public CWindowBase {
public:
	CWindow(IDrawer* drawer):CWindowBase(drawer){}
	~CWindow(){}
};
//--------------------------------------------------------------------

//オブジェクト生成テンプレート関数-----------------------------------
///////////////////////////////////////////////////////////////////
template<class X>
shared_ptr<X> createObject()
{
	return (shared_ptr<X>)(new X);
}
//---------------------------------------------------------------
template<class X, class Y>
shared_ptr<X> createObject()
{
	return (shared_ptr<X>)(new X(new Y));
}
//--------------------------------------------------------------------

///////////////////////////////////////////////////////////////////
int main()
{
	//描画クラスは自由に変更できる。
	//かつ、Windowクラスの機能拡張があっても機能継承が容易（深い継承階層にならない）
	shared_ptr<CWindow> sh_window1(createObject<CWindow, CDrawUseLibA>());
	shared_ptr<CWindow> sh_window2(createObject<CWindow, CDrawUseLibB>());

	sh_window1->draw();
	sh_window2->draw();


/*
   	CWindow* windowP = new CWindow(new CDrawUseLibB);
    delete windowP;
*/
	return 0;
}
