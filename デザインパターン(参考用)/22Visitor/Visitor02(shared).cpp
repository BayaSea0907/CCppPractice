//Visitor�ishared�j
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

//Visitor02(shared).cpp
//����
//�p������K��
//Bekery�w���x����[�x
//
//�X�֋ǂ�K��
//Postoffice�w�莆����܂����x

#include <iostream>
#include <string>
#include <memory>
using namespace std::tr1;
using namespace std;

class Visitor;

//�I�u�W�F�N�g�����e���v���[�g�֐�-----------------------------------
///////////////////////////////////////////////////////////////////
template<class X>
shared_ptr<X> createObject()
{
	return (shared_ptr<X>)(new X);
}
//--------------------------------------------------------------------

//acceptor--------------------------------------------------------------
////////////////////////////////////////////////////////////////////
//�K���N���Xinterface�N���X��`�i���ۃN���X�j
class Shop {
public:
	virtual void accept(shared_ptr<Visitor> sh_visitor) = 0;		//�K��Ҏ��
	virtual ~Shop(){}
};

//���ۂ̖K���N���X��`---------------------------------------------
/////////////////////////////////////////////////////////////////////
//�p����
class Bakery : public Shop {
public:
	void accept(shared_ptr<Visitor> sh_visitor);
	void sellBread(){ cout << "Bekery�w���x����[�x" << endl; }
};
//-------------------------------------------------------------------
//�X�֋�
class PostOffice : public Shop {
public:
	void accept(shared_ptr<Visitor> sh_visitor);
	void postLetter(){ cout << "Postoffice�w�莆����܂����x" << endl; }
};
//-----------------------------------------------------------------------

//Visitor----------------------------------------------------------------
////////////////////////////////////////////////////////////////////
//�K��҃N���X��`
//acceptor����K���̃A�h���X��this�œn���Ă���̂ŁA������normal�ȃ|�C���^�Ŏ󂯂�ishared�ł͎󂯎��Ȃ��j
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
void Bakery::accept(shared_ptr<Visitor> sh_visitor){ sh_visitor->visitBakery(this); }

//�X�֋�
void PostOffice::accept(shared_ptr<Visitor> sh_visitor){ sh_visitor->visitPostOffice(this); }
//-----------------------------------------------------------------------

/////////////////////////////////////////////////////////////////////
int main()
{
	shared_ptr<Shop> sh_shop1(createObject<Bakery>());			//�K���p�����I�u�W�F�N�g����
	shared_ptr<Shop> sh_shop2(createObject<PostOffice>());		//�K���X�֋ǃI�u�W�F�N�g����
	shared_ptr<Visitor> sh_visitor(createObject<Visitor>());	//�K��҃I�u�W�F�N�g����

	cout << "�p������K��" << endl;
	sh_shop1->accept(sh_visitor);		//�p������K��

	cout << endl;
	cout << "�X�֋ǂ�K��" << endl;
	sh_shop2->accept(sh_visitor);		//�X�֋ǂ�K��

	return 0;
}