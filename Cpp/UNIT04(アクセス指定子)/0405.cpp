/*-----------------------------------------------------------
| ���04-05	 BayaSea
-------------------------------------------------------------*/
#include <iostream>
using namespace std;

class CU{
	int total;		//�����i�l�j
	int male;		//�j���i�l�j
	int female;		//�����i�l�j
public:
	//�j���l���ݒ�
	void setMale  (int sm) { male = sm; }
	void setFamele(int sf) { female = sf; }

	//�l���擾
	int getMale()	{ return male; }
	int getFemale() { return female; }
	int getCalcTotal() { return total = male + female; }	//����

	//�\���䗦�擾
	double getCalcMaleRatio()	{ return ((double)male   / (double)total) * 100.0; }	//�j��
	double getCalcFemaleRatio()	{ return ((double)female / (double)total) * 100.0; }	//����
};
////////////////////////////////////////////////////////////
int main()
{
	CU* cuP(new CU);

	cuP->setMale(23);
	cuP->setFamele(5);

	cout << "�N���X�l��=" << cuP->getCalcTotal() << endl;
	cout << "�j��="	<< cuP->getMale()   << " �\����%=" << cuP->getCalcMaleRatio()   << endl;
	cout << "����=" << cuP->getFemale() << " �\����%=" << cuP->getCalcFemaleRatio() << endl;

	delete cuP;
	system("pause");
	return 0;
}
