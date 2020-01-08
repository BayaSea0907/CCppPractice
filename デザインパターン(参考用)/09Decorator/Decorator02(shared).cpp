//Decorator�ishared�j
//�����̃N���X�ɑ΂���ǉ��@�\���A���̃N���X���g�ɒǉ������ɁA
//����t����iDecorate����j���o�i�R�A�ƂȂ���̂ɂ��Ԃ��Ă����C���[�W�j�Ŏ�������B
//��j�����̏����̑O��ɐV���ȏ�����t�������邱�Ƃ��ł���

//��ԏ�ʂɁA����ƂȂ�N���X�ƁA�����鑤�̃N���X�̋���interface�N���X���`����
//����N���X�ɍ��A�����Ă���Ώہi�����鑤�̃I�u�W�F�N�g�j���L��������
//
//�y�v���O�������e�z
//�f�t�H���g�A�C�X�N���[���Ƀg�b�s���O������
//�f�t�H���g�A�C�X�N���[���́A�o�j���A�����A�J�V���[�i�b�c�t�o�j��
//�g�b�s���O�́A�J�V���[�i�b�c�A�X���C�X�A�[�����h
//�f�t�H���g�A�C�X�N���[���ƃg�b�s���O�N���X�̋���interface�N���X�́AIcecream�N���X
//
//Decorator02(shared).cpp
//����
//�J�V���[�i�b�ctopping�o�j���A�C�X�N���[���̓o�j����
//�J�V���[�i�b�ctopping�����A�C�X�N���[���͖�����
//�X���C�X�A�[�����htopping�J�V���[�i�b�ctopping�o�j���A�C�X�N���[���̓o�j����

#include <iostream>
#include <string>
#include <memory>
using namespace std::tr1;
using namespace std;

//�I�u�W�F�N�g�����e���v���[�g�֐�-----------------------------------
///////////////////////////////////////////////////////////////////
template<class X>
shared_ptr<X> createObject()
{
	return (shared_ptr<X>)(new X);
}
//---------------------------------------------------------------
template<class X, class Y>
shared_ptr<X> createObject(Y n)
{
	return (shared_ptr<X>)(new X(n));
}
//--------------------------------------------------------------------

//////////////////////////////////////////////////////////////////
//�A�C�X�N���[��interface�N���X��`
class Icecream {
public:
	virtual string getName() = 0;
	virtual string howSweet() = 0;
};

//Decorator��`----------------------------------------------------------
//��{�A�C�X�N���[��
//////////////////////////////////////////////////////////////////
//�o�j���A�C�X�N���[���N���X��`
class VanillaIcecream : public Icecream {
public:
	string getName(){ return "�o�j���A�C�X�N���[��"; }
	string howSweet(){ return "�o�j����"; }
};
//------------------------------------------------------------
//�����A�C�X�N���[���N���X��`
class GreenTeaIcecream : public Icecream {
public:
	string getName(){ return "�����A�C�X�N���[��"; }
	string howSweet(){ return "������"; }
};
//------------------------------------------------------------
//�J�V���[�i�b�c�t���o�j���A�C�X�N���[����`
class CashewNutsVanillaIcecream : public VanillaIcecream {
public:
	string getName(){ return "�J�V���[�i�b�c�o�j���A�C�X�N���[��"; }
};
//------------------------------------------------------------

//�g�b�s���O��`----------------------------------------------
//�J�V���[�i�b�c�g�b�s���O�N���X��`
class CashewNutsToppingIcecream : public Icecream {
	shared_ptr<Icecream> sh_orgIce;			//�g�b�s���O����A�C�X�N���[��
public:
	CashewNutsToppingIcecream(shared_ptr<Icecream> sh_ice){ sh_orgIce = sh_ice; }

	string getName()
	{
		string name = "�J�V���[�i�b�ctopping";
		name += sh_orgIce->getName();
		return name;
	}

	string howSweet(){ return sh_orgIce->howSweet(); }
};
//------------------------------------------------------------
//�J�V���[�i�b�c�g�b�s���O�N���X��`
class SliceAlmondToppingIcecream : public Icecream {
	shared_ptr<Icecream> sh_orgIce;			//�g�b�s���O����A�C�X�N���[��
public:
	SliceAlmondToppingIcecream(shared_ptr<Icecream> sh_ice){ sh_orgIce = sh_ice; }

	string getName()
	{
		string name = "�X���C�X�A�[�����htopping";
		name += sh_orgIce->getName();
		return name;
	}

	string howSweet(){ return sh_orgIce->howSweet(); }
};
//-----------------------------------------------------------------------

///////////////////////////////////////////////////////////////////
int main()
{
	shared_ptr<Icecream> sh_baseIce1(createObject<VanillaIcecream>());
	shared_ptr<Icecream> sh_ice1;
	sh_ice1 = createObject<CashewNutsToppingIcecream, shared_ptr<Icecream>>(sh_baseIce1);

	shared_ptr<Icecream> sh_baseIce2(createObject<GreenTeaIcecream>());
	shared_ptr<Icecream> sh_ice2;
	sh_ice2 = createObject<CashewNutsToppingIcecream, shared_ptr<Icecream>>(sh_baseIce2);

	shared_ptr<Icecream> sh_ice3(createObject<SliceAlmondToppingIcecream, shared_ptr<Icecream>>(sh_ice1));

	cout << sh_ice1->getName() << "��" << sh_ice1->howSweet() << endl;
	cout << sh_ice2->getName() << "��" << sh_ice2->howSweet() << endl;
	cout << sh_ice3->getName() << "��" << sh_ice3->howSweet() << endl;

	return 0;
}
