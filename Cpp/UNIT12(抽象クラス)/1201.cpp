/*------------------------------------------------------------
|問題12-01	 BayaSea
--------------------------------------------------------------*/
#include <iostream>
#include <string>			//文字列操作用クラス
using namespace std;

//基本クラス定義
class Graduate{
protected:
	string subject;         //科
public:
	Graduate() :subject("CU"){}
	virtual string getName()	= 0;
	virtual string getSubject() = 0;
};
///////////////////////////////////////////////////////////////
//派生クラス定義
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

	cout << "卒業学科=" << gradP->getSubject()
		 << " 学生="	<< gradP->getName() << endl;

	delete gradP;
	return 0;
}
