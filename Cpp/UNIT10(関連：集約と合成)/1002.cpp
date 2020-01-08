/*--------------------------------------------------------
|���10-02	BayaSea
----------------------------------------------------------*/
#include <iostream>
#include <string>
using namespace std;

//�f�È�N���X��`
class Medical {
	string name;     //�f�È㖼
public:
	void setName(string sn = ""){ name = sn; }	//�f�È㖼�ݒ�
	string getName(){ return name; }			//�f�È㖼�擾
};
///////////////////////////////////////////////////////////
//�X�܃N���X��`
class Shop {
	Medical* mediP = NULL;
public:
	//�R���X�g���N�^
	Shop() : mediP(new Medical){}

	//�f�È㖼�ݒ�
	void setMedicalName(string mn) { mediP->setName(mn); }

	//�f�È㖼�擾
	string getMedicalName() { return mediP->getName(); }

	//�f�X�g���N�^
	~Shop()
	{
		if (mediP != NULL) delete mediP;
	}
};
///////////////////////////////////////////////////////////
int main()
{
	Shop* shopP(new Shop);

	shopP->setMedicalName("�؂̂���@");
	cout << "�f�È�=" << shopP->getMedicalName() << endl;

	delete shopP;

	system("pause");
	return 0;
}
