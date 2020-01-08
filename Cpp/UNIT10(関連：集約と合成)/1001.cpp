/*---------------------------------------------------------
|���10-01	 BayaSea
-----------------------------------------------------------*/
#include <iostream>
#include <string>			//�����񑀍�p
using namespace std;

//�v���W�F�N�^�[�N���X��`
class Projector {
	string maker;			//���[�J�[
public:
	Projector(string pm = "") :maker(pm){}
	string getMaker(){ return maker; }
};
///////////////////////////////////////////////////////////
//�����N���X��`
class Room {
	Projector* projecP = NULL;
public:
	//�v���W�F�N�^�[�ݒu
	void setProjector(string sm)
	{
		//if�̔�r���Ȃ��ƁA�A���ŌĂяo�����ۂɃ��������[�N���N�����Ă��܂��B
		if (projecP == NULL) projecP = new Projector(sm);	
	}

	//�v���W�F�N�^�[���͂���
	void removeProjector()
	{
		if (projecP != NULL) delete projecP;
		projecP = NULL;
	}

	//�v���W�F�N�^�[�̃��[�J�[�擾
	string getProjectorMaker()
	{
		if (projecP != NULL)	return projecP->getMaker();
		else					return "�͂Ȃ�";
	}

	~Room()
	{
		if (projecP != NULL) delete projecP;
	}
};
///////////////////////////////////////////////////////////
int main()
{
	Room* roomP(new Room);

	roomP->setProjector("HITEC");
	cout << "�v���W�F�N�^�[=" << roomP->getProjectorMaker() << endl;

	roomP->removeProjector();

	delete roomP;
	return 0;
}

