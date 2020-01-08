//Prototype�ideclare�F�R�s�[�R���X�g���N�^��p�j
//���O�ɃN���X�̃C���X�^���X�i�I�u�W�F�N�g�j��p�ӂ��Ă����A
//���̃R�s�[�i�N���[���j����肾�����ƂŁA�ȍ~�̃C���X�^���X�������ȒP�ɂ���
//Clone���\�b�h���g�킸�ɁA�R�s�[�R���X�g���N�^���g���āAC++�炵��Clone������Ă���
//

//Prototype03(declare-copyConstructor).cpp
//����
//original name = MICKY
//clone name = MICKY

#include <iostream>
#include <string>
using namespace std;

//�N���[���}�E�X�N���X��`
class Mouse {
	string name;
public:
	Mouse(string mname = ""):name(mname){}

	//���g�̃N���[�������R�s�[�R���X�g���N�^
	Mouse(const Mouse& mob)
	{
		name = mob.getName();
	}
	
	string getName()const{ return name; }
	~Mouse(){}
};

///////////////////////////////////////////////////////////////////
int main()
{
	Mouse original("MICKY");
	Mouse clone = original;		//clone�쐬

	cout << "original name = " << original.getName() << endl;
	cout << "clone name = " << clone.getName() << endl;

	return 0;
}
