//Strategy�ishared�j
//���鏈���̃A���S���Y�������̐헪�P�ʃI�u�W�F�N�g�Ƃ��čl���A�K�v�ɉ����Đ헪�P�ʂŌ�������
//�A���S���Y����if���Ȃǂŕ��򂳂������ɁA�헪�P�ʃI�u�W�F�N�g�Ō�������̂�
//�����⑼�̐헪�̒ǉ����ȒP�ɍs����

//�y�v���O�����z�N���r�헪�A�g����r�헪�̂����ꂩ��헪�I�u�W�F�N�g�Ƃ��đI������
//���ʐ헪interface���`���A�h���N���X�Ƃ��Ă��ꂼ��̐헪�N���X���`����
//���̂ق��ɁA�I�������헪�I�u�W�F�N�g���Ǘ�����N���X�iCompOperation�j���`����
//�����āA����CompOperation�I�u�W�F�N�g�ŊǗ����Ă���I��헪�I�u�W�F�N�g�̔�r�������s��
//�헪�I�u�W�F�N�g�P�ʂŃA���S���Y����؂�ւ�����̂ŁA�_��Ń����e�i���X���₷���݌v�ƂȂ�
//
//�I�u�W�F�N�g�����e���v���[�g�֐��̈����������Ȃ肷���Ȃ��悤�ɁA�C���X�^���X�ϐ��ւ̏�������
//���\�b�h�ōs���悤�ɂ��Ă���

//Strategy02(shared).cpp
//����
//RYO��KEN�͓��N
//RYO������

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
//�l�N���X��`
class Human {
	string name;	//���O
	int height;		//�g��
	int weight;		//�̏d
	int age;		//�N��
public:
	Human(string hname = "", int hheight = 0, int hweight = 0, int hage = 0)
			:name(hname), height(hheight), weight(hweight), age(hage){}

	string getName()const{ return name; }
	int getHeight()const{ return height; }
	int getWeight()const{ return weight; }
	int getAge()const{ return age; }

	void setName(string sname){ name = sname; }
	void setHeight(int sheight){ height = sheight; }
	void setWeight(int sweight){ weight = sweight; }
	void setAge(int sage){ age = sage; }
};

//Strategy��`----------------------------------------------------------
//////////////////////////////////////////////////////////////////
//��r�헪interface�N���X��`�i���ۃN���X��`�j
class Comparator {
public:
	virtual int compare(shared_ptr<Human> sh_h1, shared_ptr<Human> sh_h2) = 0;
};

///////////////////////////////////////////////////////////////////
//�N���r�N���X��`
class AgeComparator : public Comparator {
public:
	int compare(shared_ptr<Human> sh_h1, shared_ptr<Human> sh_h2)
	{
		if(sh_h1->getAge() > sh_h2->getAge())			return 1;
		else if(sh_h1->getAge() == sh_h2->getAge())		return 0;
		else											return -1;
	}
};
//----------------------------------------------------------------
//�g����r�N���X��`
class HeightComparator : public Comparator {
public:
	int compare(shared_ptr<Human> sh_h1, shared_ptr<Human> sh_h2)
	{
		if(sh_h1->getHeight() > sh_h2->getHeight())			return 1;
		else if(sh_h1->getHeight() == sh_h2->getHeight())	return 0;
		else												return -1;
	}
};
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//��r����N���X��`
class CompOperation {
	shared_ptr<Comparator> sh_comparator;	//�I�����s�����r�헪�I�u�W�F�N�g�Ǘ�
public:
	CompOperation(shared_ptr<Comparator> mcomparator):sh_comparator(mcomparator){}

	int compare(shared_ptr<Human> sh_h1, shared_ptr<Human> sh_h2)
	{
		return sh_comparator->compare(sh_h1, sh_h2);
	}
	~CompOperation(){}
};
//----------------------------------------------------------------------

///////////////////////////////////////////////////////////////////
int main()
{
	shared_ptr<Human> sh_human1(createObject<Human>());
	sh_human1->setName("RYO");
	sh_human1->setHeight(190);
	sh_human1->setWeight(80);
	sh_human1->setAge(25);

	shared_ptr<Human> sh_human2(createObject<Human>());
	sh_human2->setName("KEN");
	sh_human2->setHeight(180);
	sh_human2->setWeight(75);
	sh_human2->setAge(25);

	//�N���r
	shared_ptr<Comparator> sh_comparator(createObject<AgeComparator>());
	shared_ptr<CompOperation> sh_comp(createObject<CompOperation>(sh_comparator));

	switch(sh_comp->compare(sh_human1, sh_human2))
	{
		case 1: cout << sh_human1->getName() << "���N��" << endl;  break;
		case 0: cout << sh_human1->getName() << "��" 
					 << sh_human2->getName() << "�͓��N" << endl;  break;
		default: cout << sh_human2->getName() << "���N��" << endl;  break;
	}

	sh_comparator.reset();
	sh_comp.reset();

	//�g����r
	sh_comparator = createObject<HeightComparator>();
	sh_comp = createObject<CompOperation>(sh_comparator);

	switch(sh_comp->compare(sh_human1, sh_human2))
	{
		case 1: cout << sh_human1->getName() << "������" << endl;  break;
		case 0: cout << sh_human1->getName() << "��" 
					 << sh_human2->getName() << "�͓�������" << endl;  break;
		default: cout << sh_human2->getName() << "������" << endl;  break;
	}

	return 0;
}
