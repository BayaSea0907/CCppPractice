//Decorator�inormal�j
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
//Decorator01(normal).cpp
//����
//�J�V���[�i�b�ctopping�o�j���A�C�X�N���[���̓o�j����
//�J�V���[�i�b�ctopping�����A�C�X�N���[���͖�����
//�X���C�X�A�[�����htopping�J�V���[�i�b�ctopping�o�j���A�C�X�N���[���̓o�j����

#include <iostream>
#include <string>
using namespace std;

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
	Icecream* orgIceP;				//�g�b�s���O����A�C�X�N���[���Ǘ��p�|�C���^
public:
	CashewNutsToppingIcecream(Icecream* iceP){ orgIceP = iceP; }

	string getName()
	{
		string name = "�J�V���[�i�b�ctopping";
		name += orgIceP->getName();
		return name;
	}

	string howSweet(){ return orgIceP->howSweet(); }
};
//------------------------------------------------------------
//�J�V���[�i�b�c�g�b�s���O�N���X��`
class SliceAlmondToppingIcecream : public Icecream {
	Icecream* orgIceP;				//�g�b�s���O����A�C�X�N���[���Ǘ��p�|�C���^
public:
	SliceAlmondToppingIcecream(Icecream* iceP){ orgIceP = iceP; }

	string getName()
	{
		string name = "�X���C�X�A�[�����htopping";
		name += orgIceP->getName();
		return name;
	}

	string howSweet(){ return orgIceP->howSweet(); }
};
//-----------------------------------------------------------------------

///////////////////////////////////////////////////////////////////
int main()
{
	Icecream* iceP1 = new CashewNutsToppingIcecream(new VanillaIcecream());
	Icecream* iceP2 = new CashewNutsToppingIcecream(new GreenTeaIcecream());
	Icecream* iceP3 = new SliceAlmondToppingIcecream(
						new CashewNutsToppingIcecream(new VanillaIcecream()));

	cout << iceP1->getName() << "��" << iceP1->howSweet() << endl;
	cout << iceP2->getName() << "��" << iceP2->howSweet() << endl;
	cout << iceP3->getName() << "��" << iceP3->howSweet() << endl;

	delete iceP1;
	delete iceP2;
	delete iceP3;

	return 0;
}
