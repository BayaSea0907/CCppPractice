//**********************************************************
// �t�@�C����		:���1802.cpp
//**********************************************************
// �쐬��			:BayaSea
// �쐬��			:2016.11.10
//**********************************************************
#include <iostream>
#include <memory>
#include <string>			//�����񑀍�p�N���X

#include <vector>			//vector����p�p�N���X
using namespace std;

//�����^���N���X��`
class Rental {
	int mem;		//�����
public:
	Rental(int rm = 0) :mem(rm){}
	int getMem()const{ return mem; }
};
///////////////////////////////////////////////////////////////
//�I�u�W�F�N�g�𐶐�����e���v���[�g�O���֐�
template<class X>
shared_ptr<X> create(int n){ return (shared_ptr<X>)(new X(n)); }
///////////////////////////////////////////////////////////////
//�@shared�|�C���^�������l�ɂ���vector�錾

/*
int main()
{
	vector<shared_ptr<Rental>> sh_vRent(3, create<Rental>(100));

	for (size_t i = 0; i < sh_vRent.size(); i++)
	{
		cout << "[" << i << "]=" << sh_vRent[i]->getMem() << endl;
		cout << "&" << sh_vRent[i] << endl;
	}

	return 0;
}
*/
///////////////////////////////////////////////////////////////
//�A�|�C���^�������l�ɂ���vector�錾
int main()
{
	vector<Rental*> vRentP(3, new Rental(100));

	for (size_t i = 0; i < vRentP.size(); i++)
	{
		cout << "[" << i << "]=" << vRentP[i]->getMem() << endl;
	}

	delete vRentP[0];	
	//----------------------------------------------------------
	// A.2�d�J���G���[���N���Ă���B
	//   �S�Ă̗v�f�ŗ̈�����L���Ă��邽�߁B
	//	 shared_ptr�͎Q�Ɖ񐔂��J�E���g���Ă�̂ŃG���[�͋N���Ȃ��B
	//----------------------------------------------------------

	return 0;
}
