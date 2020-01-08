//Bridge（追加が大変）
//【Bridge01.cpp問題点】
//Windowクラスの機能を追加した新しいWindowクラスを定義するには、Windowクラスを階層継承することになる
//また、描画Ｂのように描画クラスを追加したい場合、interfaceクラスを階層継承すればよいが、
//描画するWindowクラスでは、使用する描画クラスを描画Ａクラス固定にしているので描画Ｂに差替えられない
/*
//ウィンドウ
class CWindow {
	shared_ptr<CDrawUseLibA> sh_mDrawer;		//描画Ａのみしか使えない
public:
	CWindow():sh_mDrawer(createObject<CDrawUseLibA>()){}
	void draw(){ sh_mDrawer->draw(); }
};
*/
//
//そこで、追加した描画Ｂクラスでも使えるように、使用する描画クラスを受け取るように
//Windowクラスを変更する
/*
//ウィンドウ
class CWindow {
//	shared_ptr<CDrawUseLibA> sh_mDrawer;		//①描画Ａのみしか使えない
	shared_ptr<IDrawer> sh_mDrawer;				//②描画Ｂも使えるようにinterfaceクラス型にする
public:
	//②interfaceクラスにしても、描画Ａもしくは描画Ｂの固定になってしまう
//	CWindow():sh_mDrawer(createObject<CDrawUseLibA>()){}
//	CWindow():sh_mDrawer(createObject<CDrawUseLibB>()){}

	//③使用する描画クラス（Ａ、Ｂ）を受け取ることで、汎用性をもたせる
	CWindow(IDrawer* drawerP):sh_mDrawer(drawerP){}
	void draw(){ sh_mDrawer->draw(); }
};
*/
//
//この場合、オブジェクト生成テンプレート関数を追加する
/*
//---------------------------------------------------------------
template<class X, class Y>
shared_ptr<X> createObject()
{
	return (shared_ptr<X>)(new X(new Y));
}
*/
//さらに、main関数では、どの描画クラスを使うのか指定してwindowを生成する
//	shared_ptr<CWindow> sh_window1(createObject<CWindow, CDrawUseLibA>());
//	shared_ptr<CWindow> sh_window2(createObject<CWindow, CDrawUseLibB>());

//【問題点】
//しかしながら、Windowクラスの機能拡張を考えた場合、Windowクラス以降の継承クラスを
//幾層にも機能継承することになり不具合が生じる（Bridge03.cpp）

//
//Bridge02(shared).cpp
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
//--------------------------------------------------------------------

//////////////////////////////////////////////////////////////////
//ウィンドウ
class CWindow {
	shared_ptr<IDrawer> sh_mDrawer;				//②描画Ｂも使えるようにinterfaceクラス型にする
public:
	//③使用する描画クラス（Ａ、Ｂ）を受け取ることで、汎用性をもたせる
	CWindow(IDrawer* drawerP):sh_mDrawer(drawerP){}
	void draw(){ sh_mDrawer->draw(); }
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
	//Windowクラスに使用する描画クラスを渡すことで、描画クラスが増えても対応できる
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
