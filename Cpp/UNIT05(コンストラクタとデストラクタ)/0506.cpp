/*----------------------------------------------------------
|���05-06   BayaSea
------------------------------------------------------------*/
#include <string>
#include <iostream>
#define DATELENGTH 3
using namespace std;

//����N���X��`
class Meibo {
	string* nameP[DATELENGTH];		//���O�i�[�p�|�C���^�z��
public:
	//�R���X�g���N�^
	Meibo() {
		nameP[0] = new string("MIZU");
		nameP[1] = new string("GORO");
		nameP[2] = new string("TOWA");
	}

	//�f�X�g���N�^
	~Meibo(){
		for (int i = 0; i < DATELENGTH; i++) {
			delete nameP[i];
		}
	}

	//����\��
	void show() {
		for (int i = 0; i < DATELENGTH; i++) {
			cout << *nameP[i] << endl;				// **(nameP + i)
		}
	}
};
///////////////////////////////////////////////////////////////
int main()
{
	Meibo* meiboP(new Meibo);

	//�\��
	meiboP->show();	

	delete meiboP;

	system("pause");
	return 0;
}
