/*--------------------------------------------------------
|–â‘è10-02	BayaSea
----------------------------------------------------------*/
#include <iostream>
#include <string>
using namespace std;

//f—ÃˆãƒNƒ‰ƒX’è‹`
class Medical {
	string name;     //f—Ãˆã–¼
public:
	void setName(string sn = ""){ name = sn; }	//f—Ãˆã–¼Ý’è
	string getName(){ return name; }			//f—Ãˆã–¼Žæ“¾
};
///////////////////////////////////////////////////////////
//“X•ÜƒNƒ‰ƒX’è‹`
class Shop {
	Medical* mediP = NULL;
public:
	//ƒRƒ“ƒXƒgƒ‰ƒNƒ^
	Shop() : mediP(new Medical){}

	//f—Ãˆã–¼Ý’è
	void setMedicalName(string mn) { mediP->setName(mn); }

	//f—Ãˆã–¼Žæ“¾
	string getMedicalName() { return mediP->getName(); }

	//ƒfƒXƒgƒ‰ƒNƒ^
	~Shop()
	{
		if (mediP != NULL) delete mediP;
	}
};
///////////////////////////////////////////////////////////
int main()
{
	Shop* shopP(new Shop);

	shopP->setMedicalName("‰Ø‚Ì‚ ‚é‰@");
	cout << "f—Ãˆã=" << shopP->getMedicalName() << endl;

	delete shopP;

	system("pause");
	return 0;
}
