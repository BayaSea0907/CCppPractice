//���O�W�|�O�S	BayaSea
#include <iostream>
#include <string>
using namespace std;

//��ЃN���X��`
class Company {
    int* numP;
public:
    Company():numP(new int){}
	virtual ~Company() { delete numP; }		//virtual�w��q��ǉ����܂���
};
////////////////////////////////////////////////////////
//�X�܃N���X��`
class Shop : public Company {
    int* numP;
public:
    Shop():numP(new int){}
	~Shop() { delete numP; }
};
////////////////////////////////////////////////////////
int main()
{
    Company* companyP(new Shop);

    delete companyP;
    return 0;
}
