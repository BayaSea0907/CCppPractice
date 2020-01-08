//Iterator パターン（normal：名簿に配列使用）
//先生－生徒５人

//iterator00（normal-array）.cpp
//結果
//赤井亮太
//赤羽里美
//岡田美央
//西森俊介
//中ノ森玲菜

#include <iostream>
#include <string>
using namespace std;

///////////////////////////////////////////////////////////////////////
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
//名簿クラス定義
//生徒管理用の名簿の生成、名簿の走査、名簿の解放
class Meibo {
	int last;					//登録生徒数
protected:
	Student** studentsP;		//名簿（配列）管理用ポインタ
public:
	Meibo():last(0){}
	Meibo(int studentCount):last(0), studentsP(new Student*[studentCount]){}	//名簿（配列）生成

	//名簿に生徒を登録
	void add(Student *sstudentP)
	{
		studentsP[last] = sstudentP;		//生徒（のアドレス）を格納
		last++;
	}

	Student* getStudentAt(int index)const{ return studentsP[index]; }		//生徒（のアドレス）を取得
	int getLastNum()const{ return last; }									//登録生徒数取得
	
	~Meibo()
	{
		for(int n = 0; n < last; n++){ delete studentsP[n]; }				//生徒の解放
		delete [] studentsP;												//名簿（配列）の解放
	}
};

///////////////////////////////////////////////////////////////////////
//担任能力interfaceクラス定義（抽象クラス）
class Teacher {
protected:
	Meibo* meiboP;			//生成名簿オブジェクト管理用ポインタ
public:
	virtual void createMeibo() = 0;		//名簿に生徒を登録
	virtual void callStudents() = 0;	//名簿から生徒を取得
};

///////////////////////////////////////////////////////////////////////
//担任クラス定義
class MyTeacher : public Teacher {
public:
	//名簿に生徒を登録
	void createMeibo()
	{
		meiboP = new Meibo(5);					//名簿オブジェクト生成（生徒数５）
		meiboP->add(new Student("赤井亮太",1));
		meiboP->add(new Student("赤羽里美",2));
		meiboP->add(new Student("岡田美央",2));
		meiboP->add(new Student("西森俊介",1));
		meiboP->add(new Student("中ノ森玲菜",2));
	}

	//名簿から生徒を取得
	void callStudents()
	{
		int size = meiboP->getLastNum();		//名簿に登録した生徒数取得

		//生徒名表示
		for(int n = 0; n < size; n++)
		{
			cout << meiboP->getStudentAt(n)->getName() << endl;
		}
	}
	~MyTeacher(){ delete meiboP; }				//生成名簿オブジェクトの解放
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
