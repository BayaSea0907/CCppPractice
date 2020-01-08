//**********************************************************
// �t�@�C����		:���1803.cpp
//**********************************************************
// �쐬��			:BayaSea
// �쐬��			:2016.11.10
//**********************************************************
// Q.���ʂ͂ǂ��Ȃ�܂����H
//
// A.Yoron��Trisima�̊ԂɁAAosima��2�}�����ꂽ�B
//   
//	���s����
//	 Yoron
//	 Aosima
//	 Aosima
//	 Trisima
//**********************************************************
#include <iostream>
#include <memory>
#include <string>			//�����񑀍�p�N���X
#include <vector>			//vector����p�p�N���X
using namespace std;

//���N���X��`
class Island {
	string name;			//����
public:
	Island(string in = "") :name(in){}
	string getName()const{ return name; }
};
///////////////////////////////////////////////////////////////
//�I�u�W�F�N�g�𐶐�����e���v���[�g�O���֐�
template<class X>
shared_ptr<X> create(string n){ return (shared_ptr<X>)(new X(n)); }
////////////////////////////////////////////////////////////////
int main()
{
	vector<shared_ptr<Island>> sh_vIsland;
	vector<shared_ptr<Island>>::iterator sh_vIslandItr;

	sh_vIsland.push_back(create<Island>("Yoron"));
	sh_vIsland.push_back(create<Island>("Torisima"));
	sh_vIslandItr = sh_vIsland.begin();
	sh_vIsland.insert(sh_vIslandItr + 1, 2, create<Island>("Aosima"));
	sh_vIslandItr = sh_vIsland.begin();

	for (size_t i = 0; i < sh_vIsland.size(); i++)
	{
		cout << sh_vIsland[i]->getName() << endl;
	}

	return 0;
}

