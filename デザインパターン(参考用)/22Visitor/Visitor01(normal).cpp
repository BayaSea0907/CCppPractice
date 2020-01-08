//Visitor�inormal�j
//Visitor�ł́A�u�����v��K��҂ł���Visitor�I�u�W�F�N�g�ɋL�q���邱�ƂŁA�����̒ǉ����ȒP����
//�����Ώۂ�acceptor�I�u�W�F�N�g�́AVisitor�I�u�W�F�N�g���󂯓����accept���\�b�h����������

//�K���ɖK��҂��K���|���K���|���K��ҁi�K��ړI�̏����j�|���K���@�Ƃ�������ŏ������s���

//�Ⴆ�΁A�K���Visitor���p������K�₵�ăp���𔃂����̂Ƃ���
//Visitor�p�^�[���̏����̗���͎��̂悤�ɂȂ�
//�@�p�������K��҂�������
//	main()��	sh_shop1->accept(sh_visitor);
//�A����ƁA�K����󂯂��p�����͖K��҂̖K��ړI��������
//	�p������aaceptor��`
//	void Bakery::accept(shared_ptr<Visitor> sh_visitor){ sh_visitor->visitBakery(this); }
//�B���ɖK��҂��K��ړI�ł���i�p���𔃂��j�s�ׂ��s��
//	Visitor�N���X�̃p�����K��i�p���𔃂��j��`
//	void visitBakery(Bakery* bakeryP){ bakeryP->sellBread(); }
//�C�Ō�ɁA�K���̃p�������K��҂̍s�ׂɑ΂��Ĕ�������
//	�p�����N���X
//	void sellBread(){ cout << "Bekery�w���x����[�x" << endl; }

//Visitor01(normal).cpp
//����
//�p������K��
//Bekery�w���x����[�x
//
//�X�֋ǂ�K��
//Postoffice�w�莆����܂����x

#include <iostream>
#include <string>
using namespace std;

class Visitor;

//acceptor--------------------------------------------------------------
////////////////////////////////////////////////////////////////////
//�K���N���Xinterface�N���X��`�i���ۃN���X�j
class Shop {
public:
	virtual void accept(Visitor* visitorP) = 0;		//�K��Ҏ��
	virtual ~Shop(){}
};

//���ۂ̖K���N���X��`---------------------------------------------
/////////////////////////////////////////////////////////////////////
//�p����
class Bakery : public Shop {
public:
	void accept(Visitor* visitorP);
	void sellBread(){ cout << "Bekery�w���x����[�x" << endl; }
};
//-------------------------------------------------------------------
//�X�֋�
class PostOffice : public Shop {
public:
	void accept(Visitor* visitorP);
	void postLetter(){ cout << "Postoffice�w�莆����܂����x" << endl; }
};
//-----------------------------------------------------------------------

//Visitor----------------------------------------------------------------
////////////////////////////////////////////////////////////////////
//�K��҃N���X��`
class Visitor {
public:
	//�p�����K��i�p���𔃂��j
	void visitBakery(Bakery* bakeryP){ bakeryP->sellBread(); }

	//�X�֋ǖK��i�莆���o���j
	void visitPostOffice(PostOffice* postOfficeP){ postOfficeP->postLetter(); }
};
//-----------------------------------------------------------------------

//�K���N���X��acceptor��`---------------------------------------------
//�����̈ʒu�ɒ�`���Ȃ���compaileError
/////////////////////////////////////////////////////////////////////
//�p����
void Bakery::accept(Visitor* visitorP){ visitorP->visitBakery(this); }

//�X�֋�
void PostOffice::accept(Visitor* visitorP){ visitorP->visitPostOffice(this); }
//-----------------------------------------------------------------------

/////////////////////////////////////////////////////////////////////
int main()
{
	Shop* shopP1 = new Bakery;			//�K���p�����I�u�W�F�N�g����
	Shop* shopP2 = new PostOffice;		//�K���X�֋ǃI�u�W�F�N�g����
	Visitor* visitorP = new Visitor;	//�K��҃I�u�W�F�N�g����

	cout << "�p������K��" << endl;
	shopP1->accept(visitorP);			//�p������K��

	cout << endl;
	cout << "�X�֋ǂ�K��" << endl;
	shopP2->accept(visitorP);			//�X�֋ǂ�K��

	delete shopP1;
	delete shopP2;
	delete visitorP;

	return 0;
}