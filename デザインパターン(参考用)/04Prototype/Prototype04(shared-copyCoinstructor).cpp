//Prototype�ishared�F�R�s�[�R���X�g���N�^��p�j
//���O�ɃN���X�̃C���X�^���X�i�I�u�W�F�N�g�j��p�ӂ��Ă����A
//���̃R�s�[�i�N���[���j����肾�����ƂŁA�ȍ~�̃C���X�^���X�������ȒP�ɂ���
//Clone���\�b�h���g�킸�ɁA�R�s�[�R���X�g���N�^���g���āAC++�炵��Clone������Ă���
//

//Prototype04(shared-copyConstructor).cpp
//����
//original name = MICKY
//clone name = MICKY

#include <iostream>
#include <string>
#include <memory>
using namespace std::tr1;
using namespace std;

//////////////////////////////////////////////////////////////////
//Clone interface�N���X��`�i����intrerface�N���X�j
class IClone {
public:
	virtual string getName()const = 0;
	virtual ~IClone(){}
};

//////////////////////////////////////////////////////////////////
//�N���[���}�E�X�N���X��`
//class Mouse {
class Mouse : public IClone {
	string name;
public:
	Mouse(string mname = ""):name(mname){}

	//���g�̃N���[�������R�s�[�R���X�g���N�^
	Mouse(const IClone& mob)
	{
		name = mob.getName();
	}
	
	string getName()const{ return name; }
	~Mouse(){}
};

//�I�u�W�F�N�g�����e���v���[�g�֐��ishared�|�C���^�̏ꍇ�����ɒ�`�j-----
///////////////////////////////////////////////////////////////////
template<class X>
shared_ptr<X> createObject(string n)
{
	return (shared_ptr<X>)(new X(n));
}
//shared�|�C���^�p--------------------------------------------------
template<class X>
shared_ptr<X> createObject(shared_ptr<IClone> n)
{
	return (shared_ptr<X>)(new X(*n));
}
//------------------------------------------------------------------------

///////////////////////////////////////////////////////////////////
int main()
{
/*
	Mouse original("MICKY");
	Mouse clone = original;		//clone�쐬

	cout << "original name = " << original.getName() << endl;
	cout << "clone name = " << clone.getName() << endl;
*/
/*
	Mouse* originalP = new Mouse("MICKY");
	Mouse* cloneP = new Mouse(*originalP);		//clone�쐬

	cout << "original name = " << originalP->getName() << endl;
	cout << "clone name = " << cloneP->getName() << endl;

	delete originalP;
	delete cloneP:
*/
/*
	IClone* original = new Mouse("MICKY");
	IClone* clone = new Mouse(*original);		//clone�쐬

	cout << "original name = " << original->getName() << endl;
	cout << "clone name = " << clone->getName() << endl;

	delete originalP;
	delete cloneP:
*/

	shared_ptr<IClone> original(createObject<Mouse>("MICKY"));
	shared_ptr<IClone> clone(createObject<Mouse>(original));		//clone�쐬

	cout << "original name = " << original->getName() << endl;
	cout << "clone name = " << clone->getName() << endl;

	return 0;
}
