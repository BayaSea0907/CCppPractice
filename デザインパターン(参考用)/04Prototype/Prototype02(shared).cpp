//Prototype�ishared�j
//���O�ɃN���X�̃C���X�^���X�i�I�u�W�F�N�g�j��p�ӂ��Ă����A
//���̃R�s�[�i�N���[���j����肾�����ƂŁA�ȍ~�̃C���X�^���X�������ȒP�ɂ���
//
//Prototype02(shared).cpp
//����
//real name = MICKY
//clone name = MICKY

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
//Clone interface�N���X��`�i����intrerface�N���X�j
class IClone {
public:
	virtual shared_ptr<IClone> Clone() = 0;
	virtual void setName(string) = 0;
	virtual string getName()const = 0;
	virtual ~IClone(){}
};

//////////////////////////////////////////////////////////////////
//�N���[���}�E�X�N���X��`
class Mouse : public IClone {
	string name;
public:
	Mouse(string mname = ""):name(mname){}
	
	//���g�̃N���[�������
	shared_ptr<IClone> Clone()
	{
		shared_ptr<IClone> clone(createObject<Mouse>());
		
		clone->setName(name);
		return (shared_ptr<IClone>)clone;
	}

	void setName(string sname){ name = sname; }
	string getName()const{ return name; }

	~Mouse(){}
};

///////////////////////////////////////////////////////////////////
int main()
{
	shared_ptr<IClone> real(createObject<Mouse>("MICKY"));
	shared_ptr<IClone> clone = real->Clone();

	cout << "real name = " << real->getName() << endl;
	cout << "clone name = " << clone->getName() << endl;

	return 0;
}
