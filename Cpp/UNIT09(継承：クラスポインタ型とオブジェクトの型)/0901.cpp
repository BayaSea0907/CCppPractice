/*-----------------------------------------------------------
|���09-01	 BayaSea
-------------------------------------------------------------*/

#include <iostream>
#include <string>			//�����񑀍�p�N���X
using namespace std;

//��s�@�N���X��`�i��{�N���X�j
class AirPlane {
	string engine = "�v���y��";	//����
public:
	string getEngine() { return engine; }
	virtual int getPassenger() { return 0; }
};
/////////////////////////////////////////////////////////////
//���q�@�N���X��`�i�h���N���X�j
class PassengerPlane : public AirPlane {
	int passenger = 180;		//��q��
public:
	int getPassenger() { return passenger; }
};
/////////////////////////////////////////////////////////////
int main()
{
	AirPlane* airP(new PassengerPlane);

	cout << "���q�@�G���W��=" << airP->getEngine()
		 << " ��q��=" << airP->getPassenger() << endl;

	delete airP;
	return 0;
}

