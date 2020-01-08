//Iterator(normal-vector）
//「名簿（配列構造）が古くなったので、 新しい形式のもの（vector構造）に変える

//iterator01（normal-vector）.cpp
//結果
//赤井亮太
//赤羽里美
//岡田美央
//西森俊介
//中ノ森玲菜

#include <iostream>
#include <string>
#include <vector>			//新名簿がvector利用のため
using namespace std;

/////////////////////////////////////////////////////////////
//生徒クラス定義
class Student {
	string name;	//氏名
	int sex;		//男の子:1 女の子:2
public:
	Student(string sname = "", int ssex = 0):name(sname), sex(ssex){}
	string getName()const{ return name; }
	int getSex()const{ return sex; }
};

///////////////////////////////////////////////////////////////////////
//新名簿クラス定義（名簿をvectorで管理）
class NewMeibo {
protected:
	vector<Student*> vstudent;		//名簿vector
public:
	void add(Student* studentP){ vstudent.push_back(studentP); }		//名簿vectorに生徒（のアドレス）を格納
	Student* getStudentAd(int index)const{ return vstudent[index]; }	//生徒（のアドレス）を取得

	int getVecorSize()const{ return vstudent.size(); }				//vectorサイズ取得
};

///////////////////////////////////////////////////////////////////////
//担任能力interfaceクラス定義（抽象クラス）
class Teacher {
protected:
//	Meibo* meiboP;			//生成名簿オブジェクト管理用ポインタ
	NewMeibo* newMeiboP;	//生成新名簿オブジェクト管理用ポインタ
public:
	virtual void createMeibo() = 0;		//名簿に生徒を登録
	virtual void callStudents() = 0;	//名簿から生徒を取得
};

///////////////////////////////////////////////////////////////////////
//担任クラス定義
class MyTeacher : public Teacher {
public:
	//名簿に生徒を登録する
	void createMeibo()
	{
		newMeiboP = new NewMeibo;
		newMeiboP->add(new Student("赤井亮太",1));
		newMeiboP->add(new Student("赤羽里美",2));
		newMeiboP->add(new Student("岡田美央",2));
		newMeiboP->add(new Student("西森俊介",1));
		newMeiboP->add(new Student("中ノ森玲菜",2));
/*
		newMeiboP->add(new Student("中川雄介",1));
		newMeiboP->add(new Student("板東恵美",2));
		newMeiboP->add(new Student("水島太郎",1));
*/
	}

	//名簿から生徒を取得
	void callStudents()
	{
		int vsize = newMeiboP->getVecorSize();	//名簿登録生徒数取得

		for(int i = 0; i < vsize; i++)
		{
			cout << newMeiboP->getStudentAd(i)->getName() << endl;
		}
	}
	~MyTeacher(){ delete newMeiboP; }		//生成新名簿オブジェクトの解放
};

///////////////////////////////////////////////////////////////////////
int main()
{
	Teacher* teacherP(new MyTeacher);	//担任オブジェクト生成

	teacherP->createMeibo();			//名簿の作成
	teacherP->callStudents();			//生徒の取得

	delete teacherP;					//担任オブジェクトの解放

	return 0;
}
