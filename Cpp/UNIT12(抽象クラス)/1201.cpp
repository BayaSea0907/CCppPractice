/*------------------------------------------------------------
|���12-01	 BayaSea
--------------------------------------------------------------*/
#include <iostream>
#include <string>			//�����񑀍�p�N���X
using namespace std;

//��{�N���X��`
class Graduate{
protected:
	string subject;         //��
public:
	Graduate() :subject("CU"){}
	virtual string getName()	= 0;
	virtual string getSubject() = 0;
};
///////////////////////////////////////////////////////////////
//�h���N���X��`
class Student : public Graduate {
	string name;
public:
	Student() :name("ASAHN"){}
	string getName(){ return name; }
	string getSubject(){ return subject; }
};
///////////////////////////////////////////////////////////////
int main()
{
	Graduate* gradP(new Student);

	cout << "���Ɗw��=" << gradP->getSubject()
		 << " �w��="	<< gradP->getName() << endl;

	delete gradP;
	return 0;
}
