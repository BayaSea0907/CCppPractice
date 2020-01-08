//–â‘è‚O‚W|‚O‚S	BayaSea
#include <iostream>
#include <string>
using namespace std;

//‰ïĞƒNƒ‰ƒX’è‹`
class Company {
    int* numP;
public:
    Company():numP(new int){}
	virtual ~Company() { delete numP; }		//virtualw’èq‚ğ’Ç‰Á‚µ‚Ü‚µ‚½
};
////////////////////////////////////////////////////////
//“X•ÜƒNƒ‰ƒX’è‹`
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
