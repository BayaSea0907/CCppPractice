//factoryMethod�i���i�I�u�W�F�N�g�̊ȗ����j
//factoryMethod00�̐��i�N���X���P�i�C���X�^���X�ϐ�string�̂݁j�ɂ���
//
//factoryMethod�̓����͓���
//�y�d�v�|�C���g�z
//���i�I�u�W�F�N�g�����́A�H��interface�N���X��CreateInstance���\�b�h��
//�Ăяo���Ȃ����萶���ł��Ȃ����Ƃ��|�C���g
//
//factoryMethod02(normal-easy).cpp
//����
//Audi
//CAKE

#include <iostream>
#include <string>
using namespace std;

//���i�I�u�W�F�N�g����-------------------------------------
//////////////////////////////////////////////////////////
//���iinterface�N���X��`
class IProduct {
public:
	virtual string getName()const{ return ""; }
	virtual ~IProduct(){}
};

//////////////////////////////////////////////////////////
//���i�N���X��`
class Product : public IProduct {
	string name;		//���i��
public:
	Product(string pname):name(pname){}
	string getName()const{ return name; }
	~Product(){}
};
//----------------------------------------------------------

//�I�u�W�F�N�g�����N���X------------------------------------
//////////////////////////////////////////////////////////
//�H��interface�N���X��`
class IFactory
{
	//�A�h���N���X�̃��\�b�h�B�ŏ㏑������
	virtual IProduct* create(string cname) = 0;
public:
	//�@�������Ăяo���Ďn�܂�
	//�������z���\�b�h����āA�h���N���XCFactory�Ŏ��ۂɐ�������
	IProduct* CreateInstance(string cname){ return create(cname); }

	virtual ~IFactory(){}
};
//////////////////////////////////////////////////////////
//���i�𐶐�����H��N���X��`
//�����Ő��i�h���N���X�I�u�W�F�N�g�𐶐�����i�߂�l�́A��{�N���X�|�C���^�j
class CFactory : public IFactory
{
protected:
	//�B�����ŁA���ۂɐ��i�I�u�W�F�N�g�𐶐�����
	IProduct* create(string cname){ return new Product(cname); }
public:
	~CFactory(){}
};
//--------------------------------------------------------------------

//////////////////////////////////////////////////////////
int main()
{
	CFactory* cFactoryP = new CFactory();		//�I�u�W�F�N�g�����H�ꐶ��
	IProduct* carP;
	IProduct* foodsP;

	//�H��I�u�W�F�N�g�Ő��i�I�u�W�F�N�g�𐶐�
	carP = cFactoryP->CreateInstance("Audi");		//�����ԃI�u�W�F�N�g����
	cout << carP->getName() << endl;

	foodsP = cFactoryP->CreateInstance("CAKE");		//�H�i�I�u�W�F�N�g����
	cout << foodsP->getName() << endl;

	delete carP;
	delete foodsP;
	delete cFactoryP;

	return 0;
}
