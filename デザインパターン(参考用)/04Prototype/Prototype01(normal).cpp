//Prototype�inormal�j
//���O�ɃN���X�̃C���X�^���X�i�I�u�W�F�N�g�j��p�ӂ��Ă����A
//���̃R�s�[�i�N���[���j����肾�����ƂŁA�ȍ~�̃C���X�^���X�������ȒP�ɂ���
//
//Prototype01(normal).cpp
//����
//real name = MICKY
//clone name = MICKY

#include <iostream>
#include <string>
using namespace std;

//////////////////////////////////////////////////////////////////
//Clone interface�N���X��`�i����intrerface�N���X�j
class IClone {
public:
	virtual IClone* Clone() = 0;
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
	IClone* Clone()
	{
		IClone* cloneP = new Mouse();
		
		cloneP->setName(name);
		return cloneP;
	}

	void setName(string sname){ name = sname; }
	string getName()const{ return name; }

	~Mouse(){}
};

///////////////////////////////////////////////////////////////////
int main()
{
	IClone* realP(new Mouse("MICKY"));

	IClone* cloneP = realP->Clone();

	cout << "real name = " << realP->getName() << endl;
	cout << "clone name = " << cloneP->getName() << endl;

	delete realP;
	delete cloneP;

	return 0;
}
