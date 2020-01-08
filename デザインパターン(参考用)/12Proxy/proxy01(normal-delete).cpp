//proxy�i�����̈�̉���^�C�~���O�������@�j
//��ʂ̃|�C���^���g���Ă���ꍇ�Adelete����̃^�C�~���O�����ɂȂ�
//shared�|�C���^���g���v���O�����ł͕s�v�ł���
//�I�u�W�F�N�g�����֐����g���āA�I�u�W�F�N�g�𐶐������ꍇ�A�����I�u�W�F�N�g���������^�C�~���O�����ɂȂ�
//�����Ɖ���́A�ł��邾���������邢�͋߂��ꏊ�ōs���ق����킩��Ղ�
//�Ⴆ�΁AsimpleFactory��factoryMethod�p�^�[���̂悤�ȏꍇ�Amain�֐��ŉ�����Ă��邪�A
//����������Ȃ���΂Ȃ�Ȃ��̂��A����ɁA������Y��̉\�����傫���Ȃ�ȂǁA�v���O���}�[�ɉߓx�̕��ׂ�
//�����Ă��܂�
//
/*
/////////////////////////////////////////////////////////////////
//�I�u�W�F�N�g�����֐�
//�����ŁA�h���N���X�I�u�W�F�N�g�𐶐����Ă���i�߂�l�́A��{�N���X�|�C���^�j
IProduct* createFactory(int id)
{
    switch(id)
    {
        case 1: return new Car("Audi");
        case 2: return new Foods(800);
       default: return NULL;
    }
}
/////////////////////////////////////////////////////////////////
int main()
{
	IProduct* carP;
	IProduct* foodsP;

	carP = createFactory(1);
	foodsP = createFactory(2);

	//���_�@�����h���I�u�W�F�N�g�𗘗p���Ă���ꏊ�ŉ�������Ă���
	delete carP;
	delete foodsP;

	return 0;
}
*/
//�y�d�v�|�C���g�z
//�㗝�N���X�Ő����h���I�u�W�F�N�g�Ƃ��Ǘ������A�㗝�I�u�W�F�N�g�����ł��鎞�_��
//�����I�ɐ����h���I�u�W�F�N�g�����������̂ŁA������ӎ������Ȃ����Ă���
//�㗝�I�u�W�F�N�g�́A�錾�ŗ̈���m�ۂ���
//�錾�ɂ��A�㗝�I�u�W�F�N�g���X�R�[�v�𔲂������ɁA�����I�ɐ����h���I�u�W�F�N�g��
//��������_�����_�ł���
//proxy01(normal-delete).cpp
//����
//Audi
//COKE

#include <iostream>
#include <string>
using namespace std;

//�N���X��`�Ɣh���I�u�W�F�N�g�����֐�-------------------------------
/////////////////////////////////////////////////////////////////
//���iinterface�N���X��`
class IProduct {
public:
	virtual ~IProduct(){}
	virtual string getName()const{ return ""; }
	virtual int getKosu()const{ return 0; }
};

/////////////////////////////////////////////////////////////////
//�����ԃN���X��`
class Car : public IProduct {
	string name;			//�Ԏ햼
public:
	Car(string cname):name(cname){}
	~Car(){}
	string getName()const{ return name; }
};

/////////////////////////////////////////////////////////////////
//�H�i�N���X��`
class Foods : public IProduct {
	int kosu;				//��
public:
	Foods(int fkosu):kosu(fkosu){}
	~Foods(){}
	int getKosu()const{ return kosu; }
};

/////////////////////////////////////////////////////////////////
//�I�u�W�F�N�g�����H��֐�
//�����ŁA�I�u�W�F�N�g�𐶐����Ă���i�߂�l�́A��{�N���X�|�C���^�j
IProduct* createFactory(int id)
{
    switch(id)
    {
        case 1: return new Car("Audi");
        case 2: return new Foods(800);
       default: return NULL;
    }
}
//-------------------------------------------------------------------

/////////////////////////////////////////////////////////////////
//Proxy�N���X��`�i�{���̃N���X�̑㗝�N���X�j
//���������I�u�W�F�N�g���f�X�g���N�^�ŉ������
class Proxy : public IProduct
{
	IProduct* realClassP;	//�����I�u�W�F�N�g�Ǘ��p�|�C���^
public:
	Proxy(IProduct* productP = NULL):realClassP(productP){}

	//�����I�u�W�F�N�g���Ǘ�����
	void setRealClassP(IProduct* productP){ realClassP = productP; }
	void operator=(IProduct* productP)
{
if(realClassP != NULL)	delete realClassP;
realClassP = productP;
}

	//�����I�u�W�F�N�g�̃��\�b�h���Ăяo��
	string getName()const{ return realClassP->getName(); }
	int getKosu()const{ return realClassP->getKosu(); }

	//�����I�u�W�F�N�g�����
	~Proxy(){ delete realClassP; }
};

/////////////////////////////////////////////////////////////////
int main()
{
	Proxy proxy;		//�i�d�v�j�㗝�N���X�̃I�u�W�F�N�g�錾

	//�㗝�N���X�Ő����I�u�W�F�N�g���Ǘ�����
//	proxy.setRealClassP(createFactory(1));		//���\�b�h�g�p
	proxy = createFactory(1);				//���Z�qoverload�g�p

	cout << proxy.getName() << endl;

	proxy = createFactory(2);				//���Z�qoverload�g�p
	cout << proxy.getKosu() << endl;

	return 0;
}
