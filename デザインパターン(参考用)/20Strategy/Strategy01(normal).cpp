//Strategy�inormal�j
//���鏈���̃A���S���Y�������̐헪�P�ʃI�u�W�F�N�g�Ƃ��čl���A�K�v�ɉ����Đ헪�P�ʂŌ�������
//�A���S���Y����if���Ȃǂŕ��򂳂������ɁA�헪�P�ʃI�u�W�F�N�g�Ō�������̂�
//�����⑼�̐헪�̒ǉ����ȒP�ɍs����

//�y�v���O�����z�N���r�헪�A�g����r�헪�̂����ꂩ��헪�I�u�W�F�N�g�Ƃ��đI������
//���ʐ헪interface���`���A�h���N���X�Ƃ��Ă��ꂼ��̐헪�N���X���`����
//���̂ق��ɁA�I�������헪�I�u�W�F�N�g���Ǘ�����N���X�iCompOperation�j���`����
//�����āA����CompOperation�I�u�W�F�N�g�ŊǗ����Ă���I��헪�I�u�W�F�N�g�̔�r�������s��
//�헪�I�u�W�F�N�g�P�ʂŃA���S���Y����؂�ւ�����̂ŁA�_��Ń����e�i���X���₷���݌v�ƂȂ�
//
//Strategy01(normal).cpp
//����
//RYO��KEN�͓��N
//RYO������

#include <iostream>
#include <string>
using namespace std;

//////////////////////////////////////////////////////////////////
//�l�N���X��`
class Human {
	string name;	//���O
	int height;		//�g��
	int weight;		//�̏d
	int age;		//�N��
public:
	Human(string hname, int hheight, int hweight, int hage)
			:name(hname), height(hheight), weight(hweight), age(hage){}

	string getName()const{ return name; }
	int getHeight()const{ return height; }
	int getWeight()const{ return weight; }
	int getAge()const{ return age; }
};

//Strategy��`----------------------------------------------------------
//////////////////////////////////////////////////////////////////
//��r�헪interface�N���X��`�i���ۃN���X��`�j
class Comparator {
public:
	virtual int compare(Human* h1P,Human* h2P) = 0;
};

///////////////////////////////////////////////////////////////////
//�N���r�N���X��`
class AgeComparator : public Comparator {
public:
	int compare(Human* h1P, Human* h2P)
	{
		if(h1P->getAge() > h2P->getAge())			return 1;
		else if(h1P->getAge() == h2P->getAge())		return 0;
		else										return -1;
	}
};
//----------------------------------------------------------------
//�g����r�N���X��`
class HeightComparator : public Comparator {
public:
	int compare(Human* h1P, Human* h2P)
	{
		if(h1P->getHeight() > h2P->getHeight())			return 1;
		else if(h1P->getHeight() == h2P->getHeight())	return 0;
		else											return -1;
	}
};
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//��r����N���X��`
class CompOperation {
	Comparator* comparatorP;	//�I�����s�����r�헪�I�u�W�F�N�g�Ǘ��|�C���^
public:
	CompOperation(Comparator* mcomparatorP):comparatorP(mcomparatorP){}

	int compare(Human* h1P, Human* h2P)
	{
		return comparatorP->compare(h1P, h2P);
	}
	~CompOperation(){ delete comparatorP; }		//��r�헪�I�u�W�F�N�g�̉��
};
//----------------------------------------------------------------------

///////////////////////////////////////////////////////////////////
int main()
{
	Human* human1P = new Human("RYO", 190, 80, 25);
	Human* human2P = new Human("KEN", 180, 75, 25);

	//�N���r
	CompOperation* comp1P = new CompOperation(new AgeComparator());

	switch(comp1P->compare(human1P, human2P))
	{
		case 1: cout << human1P->getName() << "���N��" << endl;  break;
		case 0: cout << human1P->getName() << "��" 
					 << human2P->getName() << "�͓��N" << endl;  break;
		default: cout << human2P->getName() << "���N��" << endl;  break;
	}
	delete comp1P;

	//�g����r
	comp1P = new CompOperation(new HeightComparator());

	switch(comp1P->compare(human1P, human2P))
	{
		case 1: cout << human1P->getName() << "������" << endl;  break;
		case 0: cout << human1P->getName() << "��" 
					 << human2P->getName() << "�͓�������" << endl;  break;
		default: cout << human2P->getName() << "������" << endl;  break;
	}

	delete comp1P;
	delete human1P;
	delete human2P;

	return 0;
}
