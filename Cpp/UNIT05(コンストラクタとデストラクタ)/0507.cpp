/*--------------------------------------------------------------
| ���05-07	  BayaSea
----------------------------------------------------------------*/
#include <iostream>
using namespace std;

//���ԍ\����
struct Living {
	int room;		//������
};
/////////////////////////////////////////////////////////////////
//�ƃN���X
class House{
	Living* livingP;
public:
	//�R���X�g���N�^
	House() : livingP(new Living){}

	//�f�X�g���N�^
	~House() { delete livingP; }

	void setRoom(int sr = 0) { livingP->room = sr; }
	int getRoom() { return livingP->room; }
};
/////////////////////////////////////////////////////////////////
int main()
{
	House* houseP(new House);

	houseP->setRoom(10);
	cout << "����=" << houseP->getRoom() << endl;

	delete houseP;

	system("pause");
	return 0;
}
