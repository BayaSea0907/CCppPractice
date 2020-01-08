//Builder�ishared�j
//�u�쐬�ߒ��v�����肷��Director�ƌĂ΂����̂Ɓu�\���`���v�����肷��Builder�ƌĂ΂����̂�g�ݍ���āA
//�I�u�W�F�N�g�̐��������_��ɂ��A���̃I�u�W�F�N�g�́u�쐬�ߒ��v�����R���g���[�����邱�Ƃ��ł���悤�ɂ���
//
//Builder02(shared).cpp
//����
//�쐬���������̉���35g ����150g

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
	virtual shared_ptr<SaltWater> getResult()const = 0;
};

//////////////////////////////////////////////////////////////////
//����Builder�N���X��`
class SaltWaterBuilder : public Builder {
	shared_ptr<SaltWater> sh_saltWater;			//���������I�u�W�F�N�g
public:
	SaltWaterBuilder():sh_saltWater(createObject<SaltWater>()){}		//�����I�u�W�F�N�g����
	void addSolute(double asalt){ sh_saltWater->addSalt(asalt); }		//���ǉ�
	void addSolvent(double awater){ sh_saltWater->addWater(awater); }	//���ǉ�

	//�����p��
	void abandonSolution(double asaltwater)
	{
		double abandonsalt = asaltwater * (sh_saltWater->getSalt() /
												(sh_saltWater->getSalt() + sh_saltWater->getWater()));
		double abandonwater = asaltwater * (sh_saltWater->getWater() /
												(sh_saltWater->getSalt() + sh_saltWater->getWater()));

		sh_saltWater->addSalt(-abandonsalt);	//����������ǉ�
		sh_saltWater->addWater(-abandonwater);	//����������ǉ�
	}

	shared_ptr<SaltWater> getResult()const{ return sh_saltWater; }	//���݂̉����擾
};
//--------------------------------------------------------------------

//�쐬�ߒ�------------------------------------------------------------
//////////////////////////////////////////////////////////////////
//Builder�I�u�W�F�N�g�́i�쐬�ߒ��j�N���X��`
class Director {
	shared_ptr<Builder> sh_builder;		//���ۂɑ��삷�鐶��Builder�I�u�W�F�N�g���Ǘ�����
public:
	Director(shared_ptr<Builder> sh_dbuilder):sh_builder(sh_dbuilder){}

	//����Builder�I�u�W�F�N�g�̍쐬�ߒ��������Ȃ�ׂ����\�b�h
	void constract()
	{
		sh_builder->addSolvent(100);		//���ǉ�
		sh_builder->addSolute(40);			//���ǉ�
		sh_builder->abandonSolution(70);	//������70���p��
		sh_builder->addSolvent(100);		//���ǉ�
		sh_builder->addSolute(15);			//���ǉ�
	}
};
//--------------------------------------------------------------------

///////////////////////////////////////////////////////////////////
int main()
{
	//����Builder�I�u�W�F�N�g����
	shared_ptr<Builder> sh_builder(createObject<SaltWaterBuilder>());

	//����Builder�I�u�W�F�N�g�̍쐬�ߒ��I�u�W�F�N�g����
	shared_ptr<Director> sh_direct(createObject<Director>(sh_builder));

	sh_direct->constract();							//���������

	shared_ptr<SaltWater> sh_saltWater = sh_builder->getResult();		//������������擾

	cout << "�쐬���������̉���" << sh_saltWater->getSalt() << "g"
		 << " ����" << sh_saltWater->getWater() << "g" << endl;

	return 0;
}
