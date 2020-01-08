//Builder�inormal�j
//�u�쐬�ߒ��v�����肷��Director�ƌĂ΂����̂Ɓu�\���`���v�����肷��Builder�ƌĂ΂����̂�g�ݍ���āA
//�I�u�W�F�N�g�̐��������_��ɂ��A���̃I�u�W�F�N�g�́u�쐬�ߒ��v�����R���g���[�����邱�Ƃ��ł���悤�ɂ���
//
//Builder01(normal).cpp
//����
//�쐬���������̉���35g ����150g

#include <iostream>
#include <string>
using namespace std;

//////////////////////////////////////////////////////////////////
//�����N���X��`
class SaltWater {
	double salt;	//���ig)
	double water;	//���ig�j
public:
	SaltWater():salt(0.0), water(0.0){}

	void addSalt(double asalt){ salt += asalt; }		//���ǉ�
	void addWater(double awater){ water += awater; }	//���ǉ�

	double getSalt()const{ return salt; }				//���擾
	double getWater()const{ return water; }				//���擾
};

//�\���`��------------------------------------------------------------
//////////////////////////////////////////////////////////////////
//Builder�i�\���`���jinterface�N���X��`�i���ۃN���X�j
class Builder {
public:
	virtual void addSolute(double asalt) = 0;
	virtual void addSolvent(double awater) = 0;
	virtual void abandonSolution(double asaltwater) = 0;
	virtual SaltWater* getResult()const = 0;
	virtual ~Builder(){}
};

//////////////////////////////////////////////////////////////////
//����Builder�N���X��`
class SaltWaterBuilder : public Builder {
	SaltWater* saltWaterP;					//���������I�u�W�F�N�g�Ǘ��|�C���^
public:
	SaltWaterBuilder():saltWaterP(new SaltWater){}					//�����I�u�W�F�N�g����
	void addSolute(double asalt){ saltWaterP->addSalt(asalt); }		//���ǉ�
	void addSolvent(double awater){ saltWaterP->addWater(awater); }	//���ǉ�

	//�����p��
	void abandonSolution(double asaltwater)
	{
		double abandonsalt = asaltwater * (saltWaterP->getSalt() /
												(saltWaterP->getSalt() + saltWaterP->getWater()));
		double abandonwater = asaltwater * (saltWaterP->getWater() /
												(saltWaterP->getSalt() + saltWaterP->getWater()));

		saltWaterP->addSalt(-abandonsalt);		//����������ǉ�
		saltWaterP->addWater(-abandonwater);	//����������ǉ�
	}

	SaltWater* getResult()const{ return saltWaterP; }	//���݂̉����擾
	~SaltWaterBuilder(){ delete saltWaterP; }
};
//--------------------------------------------------------------------

//�쐬�ߒ�------------------------------------------------------------
//////////////////////////////////////////////////////////////////
//Builder�I�u�W�F�N�g�́i�쐬�ߒ��j�N���X��`
class Director {
	Builder* builderP;				//���ۂɑ��삷�鐶��Builder�I�u�W�F�N�g���Ǘ�����|�C���^
public:
	Director(Builder* dbuilderP):builderP(dbuilderP){}

	//����Builder�I�u�W�F�N�g�̍쐬�ߒ��������Ȃ�ׂ����\�b�h
	void constract()
	{
		builderP->addSolvent(100);		//���ǉ�
		builderP->addSolute(40);		//���ǉ�
		builderP->abandonSolution(70);	//������70���p��
		builderP->addSolvent(100);		//���ǉ�
		builderP->addSolute(15);		//���ǉ�
	}
};
//--------------------------------------------------------------------

///////////////////////////////////////////////////////////////////
int main()
{
	//����Builder�I�u�W�F�N�g����
	Builder* builderP = new SaltWaterBuilder;

	//����Builder�I�u�W�F�N�g�̍쐬�ߒ��I�u�W�F�N�g����
	Director* directP = new Director(builderP);

	directP->constract();							//���������

	SaltWater* saltWaterP = (SaltWater*)builderP->getResult();		//������������擾

	cout << "�쐬���������̉���" << saltWaterP->getSalt() << "g"
		 << " ����" << saltWaterP->getWater() << "g" << endl;

	delete builderP;
	delete directP;

	return 0;
}
