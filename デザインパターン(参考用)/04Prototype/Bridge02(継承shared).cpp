//Bridge�i�ǉ�����ρj
//�yBridge01.cpp���_�z
//Window�N���X�̋@�\��ǉ������V����Window�N���X���`����ɂ́AWindow�N���X���K�w�p�����邱�ƂɂȂ�
//�܂��A�`��a�̂悤�ɕ`��N���X��ǉ��������ꍇ�Ainterface�N���X���K�w�p������΂悢���A
//�`�悷��Window�N���X�ł́A�g�p����`��N���X��`��`�N���X�Œ�ɂ��Ă���̂ŕ`��a�ɍ��ւ����Ȃ�
/*
//�E�B���h�E
class CWindow {
	shared_ptr<CDrawUseLibA> sh_mDrawer;		//�`��`�݂̂����g���Ȃ�
public:
	CWindow():sh_mDrawer(createObject<CDrawUseLibA>()){}
	void draw(){ sh_mDrawer->draw(); }
};
*/
//
//�����ŁA�ǉ������`��a�N���X�ł��g����悤�ɁA�g�p����`��N���X���󂯎��悤��
//Window�N���X��ύX����
/*
//�E�B���h�E
class CWindow {
//	shared_ptr<CDrawUseLibA> sh_mDrawer;		//�@�`��`�݂̂����g���Ȃ�
	shared_ptr<IDrawer> sh_mDrawer;				//�A�`��a���g����悤��interface�N���X�^�ɂ���
public:
	//�Ainterface�N���X�ɂ��Ă��A�`��`�������͕`��a�̌Œ�ɂȂ��Ă��܂�
//	CWindow():sh_mDrawer(createObject<CDrawUseLibA>()){}
//	CWindow():sh_mDrawer(createObject<CDrawUseLibB>()){}

	//�B�g�p����`��N���X�i�`�A�a�j���󂯎�邱�ƂŁA�ėp������������
	CWindow(IDrawer* drawerP):sh_mDrawer(drawerP){}
	void draw(){ sh_mDrawer->draw(); }
};
*/
//
//���̏ꍇ�A�I�u�W�F�N�g�����e���v���[�g�֐���ǉ�����
/*
//---------------------------------------------------------------
template<class X, class Y>
shared_ptr<X> createObject()
{
	return (shared_ptr<X>)(new X(new Y));
}
*/
//����ɁAmain�֐��ł́A�ǂ̕`��N���X���g���̂��w�肵��window�𐶐�����
//	shared_ptr<CWindow> sh_window1(createObject<CWindow, CDrawUseLibA>());
//	shared_ptr<CWindow> sh_window2(createObject<CWindow, CDrawUseLibB>());

//�y���_�z
//�������Ȃ���AWindow�N���X�̋@�\�g�����l�����ꍇ�AWindow�N���X�ȍ~�̌p���N���X��
//���w�ɂ��@�\�p�����邱�ƂɂȂ�s���������iBridge03.cpp�j

//
//Bridge02(shared).cpp
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
//--------------------------------------------------------------------

//////////////////////////////////////////////////////////////////
//�E�B���h�E
class CWindow {
	shared_ptr<IDrawer> sh_mDrawer;				//�A�`��a���g����悤��interface�N���X�^�ɂ���
public:
	//�B�g�p����`��N���X�i�`�A�a�j���󂯎�邱�ƂŁA�ėp������������
	CWindow(IDrawer* drawerP):sh_mDrawer(drawerP){}
	void draw(){ sh_mDrawer->draw(); }
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
	//Window�N���X�Ɏg�p����`��N���X��n�����ƂŁA�`��N���X�������Ă��Ή��ł���
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
