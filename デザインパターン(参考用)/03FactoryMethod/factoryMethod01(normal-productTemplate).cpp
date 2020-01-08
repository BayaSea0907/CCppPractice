//factoryMethod�i���i�N���X��template�ɕύX�j
//factoryMethod00(normal).cpp�̕ύX
//���i�N���XProduct�̃C���X�^���X�ϐ��̌^���e���v���[�g�ɕύX
//���̌��ʁA���iinterface�N���XIProduct���e���v���[�g�ɕύX
//����ɁA�I�u�W�F�N�g�����H��N���X��IFactory�ACFactory���e���v���[�g�֕ύX
//
//���iinterface�N���XIProduct�A�H��interface�N���XIFactory�́A
//���ۃN���X�Œ�`

//factoryMethod�̍l�����͓���
//�y�d�v�|�C���g�z
//���i�I�u�W�F�N�g�����́A�H��interface�N���X��CreateInstance���\�b�h��
//�Ăяo���Ȃ����萶���ł��Ȃ����Ƃ��|�C���g
//
//factoryMethod01(normal-productTemplate).cpp
//����
//Audi
//CAKE

#include <iostream>
#include <string>
using namespace std;

//���i�I�u�W�F�N�g�����N���X--------------------------------
//////////////////////////////////////////////////////////
//���iinterface�N���X��`�i�e���v���[�ginterface���ۃN���X�j
template<class X>
class IProduct {
public:
	virtual X getInst()const = 0;
	virtual ~IProduct(){}
};
//////////////////////////////////////////////////////////
//���i�N���X��`�i�e���v���[�g���ۃN���X�j
template<class X>
class Product : public IProduct<X> {
	X inst;
public:
	Product(X pinst):inst(pinst){}
	X getInst()const{ return inst; }
	~Product(){}
};
//----------------------------------------------------------

//�I�u�W�F�N�g�����N���X------------------------------------
//////////////////////////////////////////////////////////
//�H��interface�N���X��`�i�e���v���[�g���ۃN���X�j
template<class X>
class IFactory
{
	//�A���̏������z���\�b�h���B�̔h���N���X�̃��\�b�h�ŏ㏑������
	virtual IProduct<X>* create(X cinst) = 0;
public:
	//�@�������Ăяo���āA���i�I�u�W�F�N�g�𐶐�����
	IProduct<X>* CreateInstance(X cinst)
	{
		return create(cinst);	//�A���Ăяo��
	}

	virtual ~IFactory(){}
};
//////////////////////////////////////////////////////////
//���i�𐶐�����H��N���X��`�i�e���v���[�g�H��N���X�j
//�����Ő��i�h���N���X�I�u�W�F�N�g�𐶐�����i�߂�l�́A��{�N���X�|�C���^�j
template<class X>
class CFactory : public IFactory<X>
{
protected:
	//�B�����ŁA���ۂɐ��i�I�u�W�F�N�g�𐶐�
	IProduct<X>* create(X cinst){ return new Product<X>(cinst); }
public:
	~CFactory(){}
};
//--------------------------------------------------------------------

//////////////////////////////////////////////////////////
int main()
{
	CFactory<string>* cFactoryP1 = new CFactory<string>();		//�I�u�W�F�N�g�����H�ꐶ��
	IProduct<string>* carP;

	CFactory<int>* cFactoryP2 = new CFactory<int>();		//�I�u�W�F�N�g�����H�ꐶ��
	IProduct<int>* foodsP;

	//�H��I�u�W�F�N�g�Ő��i�I�u�W�F�N�g�𐶐�
	carP = cFactoryP1->CreateInstance("Audi");		//�����ԃI�u�W�F�N�g����
	cout << carP->getInst() << endl;

	foodsP = cFactoryP2->CreateInstance(800);		//�H�i�I�u�W�F�N�g����
	cout << foodsP->getInst() << endl;

	delete carP;
	delete foodsP;
	delete cFactoryP1;
	delete cFactoryP2;

	return 0;
}
