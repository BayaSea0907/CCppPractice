/*------------------------------------------------------
|���08-06	 BayaSea
--------------------------------------------------------*/
#include <iostream>
#include <ctime>			//�V�X�e���^�C�}�p
#include <cstdlib>			//���������p

using namespace std;

//��ЃN���X��`�i��{�N���X�j
class Company {
public:
	virtual void show(){}		//���z���\�b�h
};
////////////////////////////////////////////////////////
//�X�܃N���X��`�i�h���N���X�j
class Shop : public Company {
public:
	void show(){ cout << "Shop" << endl; }
};
////////////////////////////////////////////////////////
//���Z�ƃN���X��`�i�h���N���X�j
class Finance : public Company {
public:
	void show(){ cout << "Finance" << endl; }
};
////////////////////////////////////////////////////////
int main()
{
	Shop* shopP   = NULL;			//�h���N���X�|�C���^�錾
	Finance* finP = NULL;		//�h���N���X�|�C���^�錾

	srand((unsigned)time(NULL));	//�����̎�ݒ�

	for (int i = 0; i < 5; i++)
	{
		//�����𔭐������ăI�u�W�F�N�g����
		if (rand() % 2) 
		{
			if (shopP != NULL) delete shopP;
			shopP = new Shop;
			shopP->show();
		}
		else
		{
			if (finP != NULL) delete finP;
			finP = new Finance;
			finP->show();
		}
	}

	if (shopP != NULL) delete shopP;
	if (finP  != NULL) delete finP;

	system("pause");
	return 0;
}
