/*-----------------------------------------------------------
|���09-02	 BayaSea
-------------------------------------------------------------*/

#include <iostream>
#include <string>			//�����񑀍�p�N���X
using namespace std;

//��s�@�N���X��`�i��{�N���X�j
class AirPlane {
	string engine = "�v���y��";	//����
public:
	string getEngine() { return engine; }
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
	PassengerPlane* passPlaneP(new PassengerPlane);

	cout << "���q�@�G���W��=" << passPlaneP->getEngine()
		 << " ��q��=" << passPlaneP->getPassenger() << endl;

	delete passPlaneP;
	return 0;
}
