/*----------------------------------------------------------
|���10-03	 BayaSea
------------------------------------------------------------*/
#include <iostream>
#include <string>			//�����񑀍�p
using namespace std;

//�X���N���X��`�i�����I�u�W�F�N�g�̃N���X�j
class Manager {
	string name;			//�X����
public:
	//�imn�F�X�����j
	Manager(string mn = "") :name(mn){}
	string getName(){ return name; }		//�X�����擾
	~Manager(){ cout << "�����I�u�W�F�N�g����" << endl; }
};
///////////////////////////////////////////////////////////
//�X�܃N���X��`
class Shop {
	Manager* manaP;		//�X���I�u�W�F�N�g���Q�Ƃ���|�C���^
public:
    //�������̂Ȃ��R���X�g���N�^
	Shop() : manaP(NULL) {}

	//���������X���I�u�W�F�N�g�̓X�����擾
	string getManagerName()
	{ 
		if (manaP != NULL)	return manaP->getName();
		else				return "�X���͍s���s���ł��B";
	}

    //�ǉ��i�X���̔C���@�����œX���I�u�W�F�N�g�����߂Đ�������j
	void  appoManager(string mn)
	{
		if(manaP == NULL) manaP = new Manager(mn);
	}


    //�ǉ��i�X���̉�C�@�X���I�u�W�F�N�g���������j
	void removeManager()
	{
		if(manaP != NULL)	delete manaP;
		manaP = NULL;
	}

    //�f�X�g���N�^
    ~Shop()
    {
        //���������X���I�u�W�F�N�g�̉��
		if (manaP != NULL)	delete manaP;

        cout << "�I�u�W�F�N�g�����ł��܂���" << endl;
    }
};
///////////////////////////////////////////////////////////
int main()
{
	Shop* shopP(new Shop);

	shopP->appoManager("ANRI");

	cout << "�X��=" << shopP->getManagerName() << endl;

	delete shopP;
	return 0;
}

