//Bridge�ishared�|�C���^�g�p�j
//�N���X���p������Ƃ��A���̖ړI�ɂ͑傫�������ĂQ��ނ���B
//�yBridge02.cpp���_�z
//�������Ȃ���AWindow�N���X�̋@�\�g�����l�����ꍇ�AWindow�N���X�ȍ~�̌p���N���X��
//���w�ɂ��@�\�p�����邱�ƂɂȂ�s���������iBridge03.cpp�j
/*
//////////////////////////////////////////////////////////////////
//Bridge�N���X��`
class CWindowBase {
	shared_ptr<IDrawer> sh_mDrawer;				//�ǂ̕`��N���X�ł��g����interface�N���X�^
public:
	CWindowBase(IDrawer* drawer):sh_mDrawer(drawer){}
	void draw(){ sh_mDrawer->draw(); }
	virtual ~CWindowBase(){}
};

//////////////////////////////////////////////////////////////////
//�E�B���h�E
class CWindow : public CWindowBase {
public:
	CWindow(IDrawer* drawer):CWindowBase(drawer){}
	~CWindow(){}
};
//--------------------------------------------------------------------
*/
//Bridge�p�^�[�����g���ƁA�Q�̋@�\�K�w��interface�K�w�\���𖾊m�ɕ������邱�Ƃ��ł���B
//�y�ǂ̕`��@�\���g�����́ACWindowBase�N���X�̃R���X�g���N�^�ɁA
//����n�������Ō��肵�܂��B

	//�`��N���X�͎��R�ɕύX�ł���B
	//���AWindow�N���X�̋@�\�g���������Ă��@�\�p�����e�Ձi�[���p���K�w�ɂȂ�Ȃ��j
/*
	shared_ptr<CWindow> sh_window1(createObject<CWindow, CDrawUseLibB>());
	shared_ptr<CWindow> sh_window2(createObject<CWindow, CDrawUseLibB>());
*/

//�I�u�W�F�N�g�����e���v���[�g�֐�-----------------------------------
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
//����
//�`��`
//�`��a

#include <iostream>
#include <string>
#include <memory>
using namespace std::tr1;
using namespace std;

//�`��N���X----------------------------------------------------------
//////////////////////////////////////////////////////////////////
//�`��interface�N���X��`�i����interface�N���X�j
class IDrawer {
public:
	virtual void draw() = 0;
};
//----------------------------------------------------------------
//�`��`�N���X��`
//�`��`�N���X��`
class CDrawUseLibA : public IDrawer {
public:
    void draw(){ cout << "�`��`" << endl; }
};
//----------------------------------------------------------------
//�`��a�N���X��`
class CDrawUseLibB : public IDrawer {
public:
    void draw(){ cout << "�`��a" << endl; }
};
//------------------------------------------------------------------

//////////////////////////////////////////////////////////////////
//Bridge�N���X��`
class CWindowBase {
	shared_ptr<IDrawer> sh_mDrawer;				//�ǂ̕`��N���X�ł��g����interface�N���X�^
public:
	CWindowBase(IDrawer* drawer):sh_mDrawer(drawer){}
	void draw(){ sh_mDrawer->draw(); }
	virtual ~CWindowBase(){}
};

//////////////////////////////////////////////////////////////////
//�E�B���h�E
class CWindow : public CWindowBase {
public:
	CWindow(IDrawer* drawer):CWindowBase(drawer){}
	~CWindow(){}
};
//--------------------------------------------------------------------

//�I�u�W�F�N�g�����e���v���[�g�֐�-----------------------------------
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
	//�`��N���X�͎��R�ɕύX�ł���B
	//���AWindow�N���X�̋@�\�g���������Ă��@�\�p�����e�Ձi�[���p���K�w�ɂȂ�Ȃ��j
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
