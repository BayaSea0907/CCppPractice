//**********************************************************
// �t�@�C����		:���1801.cpp
//**********************************************************
// �쐬��			:BayaSea
// �쐬��			:2016.11.10
//**********************************************************

#include <iostream>
#include <memory>
#include <string>			//�����񑀍�p�N���X
#include <vector>			//vector����p�p�N���X
using namespace std;

//�`�[���N���X��`
class Team {
	string name;
public:
	Team(string tn = "") :name(tn){}
	string getName()const{ return name; }
};
///////////////////////////////////////////////////////////////
//�I�u�W�F�N�g�𐶐�����e���v���[�g�O���֐�
template<class X>
shared_ptr<X> create(string n){ return (shared_ptr<X>)(new X(n)); }
////////////////////////////////////////////////////////////////
int main()
{
	vector<shared_ptr<Team>> sh_vTeam;
	
	sh_vTeam.push_back(create<Team>("TENJIN"));
	sh_vTeam.push_back(create<Team>("SAIKA"));

	for (size_t i = 0; i < sh_vTeam.size(); i++)
	{
		cout << sh_vTeam[i]->getName() << endl;
	}

	return 0;
}
