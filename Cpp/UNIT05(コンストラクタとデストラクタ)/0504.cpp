/*---------------------------------------------------------------------
|���05-04	  BayaSea
| �v���p�e�Bsales�̒l���A���̌��ʂ̂悤�ɕ\������f�X�g���N�^���q�ׂȂ����B
-----------------------------------------------------------------------*/
#include <iostream>
using namespace std;

//�X�܃N���X
class Shop {
	int sales = 300;	//���㍂�i���~�j
public:
	~Shop() { cout << "���㍂=" << sales << endl; }
};
///////////////////////////////////////////////////////////////
int main()
{
	Shop* shopP(new Shop);

	delete shopP;

	system("pause");
	return 0;
}


