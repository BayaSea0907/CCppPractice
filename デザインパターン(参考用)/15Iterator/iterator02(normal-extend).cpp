//Iterator（normal-extend:array+vector）
//名簿のデータ構造（配列、vector）が変わっても、同じ走査ができるようにする
//名簿（配列、vector）どちらでも共通に走査できるように、
//共通走査用に拡張した拡張名簿と拡張名簿を走査する処理に分ける
//拡張名簿データはAggregate、走査はIteratorをそえぞれ継承して定義する
//そして、走査Iteratorを継承した派生Iteratorに、拡張名簿データAggregateを継承した
//派生Aggreagteを集約させる
//これにより、どのようなデータ構造であっても、派生Iteratorが派生Aggregateを走査する
//ことができる
//
//拡張名簿ExMeiboを定義しない場合、名簿Meibo、NewMeiboを別々に管理しなければならなくなる
//例えば、担任能力interfaceクラス定義（抽象クラス）が次のように定義される
//class Teacher {
//protected:
//	Meibo* meiboP;			//生成名簿オブジェクト管理用ポインタ
//	NewMeibo* newMeiboP;	//生成新名簿オブジェクト管理用ポインタ
//};

//プログラムでは、コマンドプロセッサを使って、使っているデータ構造が配列あるいはvectorかどうかで、
//対応を切り替えられるようにしてある
//#define MEIBO		//（配列）Meibo対応
//#undef MEIBO		//（vector）NewMeibo対応
//
//#define MEIBO
//#else
//#endif

//iterator02(normal-extend).cpp
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

#define MEIBO		//（配列）Meibo対応
#undef MEIBO		//（vector）NewMeibo対応

//データ（生徒、名簿配列、新名簿vector）++++++++++++++++++++++++++++++
///////////////////////////////////////////////////////////////////
//生徒クラス定義
class Student {
	string name;	//氏名
	int sex;		//男の子:1 女の子:2
public:
	Student(string sname = "", int ssex = 0):name(sname), sex(ssex){}
	string getName()const{ return name; }
	int getSex()const{ return sex; }
};
//---------------------------------------------------------------

//名簿データ構造-------------------------------------------------
//１）配列（Meiboクラス）
//２）vector（NewMeiboクラス）
/////////////////////////////////////////////////////////////////
//１）名簿（配列）クラス定義
class Meibo {
	int last;					//登録生徒数
protected:
	Student** studentsP;		//名簿（配列）管理用ポインタ
public:
	Meibo():last(0){}
	Meibo(int mlast):last(0), studentsP(new Student*[mlast]){}		//名簿（配列）生成

	//名簿（配列）に生徒を登録
	void add(Student *sstudentP)
	{
		studentsP[last] = sstudentP;		//生徒（のアドレス）を格納
		last++;
	}
	Student* getStudentAt(int index)const{ return studentsP[index]; }		//生徒（のアドレス）を取得
	int getLastNum()const{ return last; }									//登録生徒数取得
	
	~Meibo()
	{
		for(int i = 0; i < last; i++){ delete studentsP[i]; }		//登録生徒の解放
		delete [] studentsP;										//名簿（配列）の解放
	}
};
//--------------------------------------------------------------
//２）新名簿（vector）クラス定義
class NewMeibo {
protected:
	vector<Student*> vstudent;		//名簿vector
public:
	void add(Student* studentP){ vstudent.push_back(studentP); }		//名簿vectorに生徒（のアドレス）を格納
	Student* getStudentAt(int index)const{ return vstudent[index]; }	//生徒（のアドレス）を取得

	int getLastNum()const{ return vstudent.size(); }			//vectorサイズ取得

	~NewMeibo()
	{
		for(int i = 0; i < (int)vstudent.size(); i++){ delete vstudent[i]; }	//登録生徒の解放
	}
};
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//（新）名簿のデータ構造（Meibo：配列、NewMeibo：vector）が異なっていても
//共通に操作できるように、同名の拡張クラス(ExMeibo）を定義する
//ただし、使用時はどちらか一方をコメントにする
///////////////////////////////////////////////////////////////

class Iterator;

//Aggregate--------------------------------------------------------
///////////////////////////////////////////////////////////////
//Agregate　interfaceクラス定義（抽象クラス）
class Aggregate {
public:
	virtual Iterator* iterator() = 0;
};
//-----------------------------------------------------------------
///////////////////////////////////////////////////////////////
#ifdef MEIBO
	//拡張名簿（配列）クラス定義
	class ExMeibo : public Meibo, public Aggregate {
	public:
		ExMeibo():Meibo(){}
		ExMeibo(int studentCnt);
		Iterator* iterator();
	};
//-------------------------------------------------------------
#else
	//拡張名簿（vector）クラス定義
	class ExMeibo : public NewMeibo, public Aggregate {
	public:
		Iterator* iterator();
	};
#endif
//--------------------------------------------------------------

//iterator---------------------------------------------------------
///////////////////////////////////////////////////////////////////
//拡張名簿ExMeiboクラスと対になる走査iteratorクラス
//拡張名簿オブジェクトが管理する名簿（配列、vector）を走査する
//走査クラスに、拡張名簿オブジェクトを登録
///////////////////////////////////////////////////////////////////
//Iterator　interfaceクラス定義（抽象クラス）
class Iterator {
public:
	virtual bool hasNext() = 0;			//名簿に次の生徒がいるかどうか
	virtual Student* next() = 0;		//名簿の次の生徒（のアドレス）を返す
};
//-----------------------------------------------------------------
////////////////////////////////////////////////////////////////
//拡張名簿走査用クラス定義
class ExMeiboIterator : public Iterator {
	ExMeibo* exMeiboP;		//拡張名簿管理用ポインタ
	int index;				//拡張名簿索引用
public:
	ExMeiboIterator(ExMeibo* exmeiboP):exMeiboP(exmeiboP), index(0){}

	//名簿に次の生徒がいるかどうか
	bool hasNext()
	{
		if(exMeiboP->getLastNum() > index)	return true;
		else								return false;
	}
	//名簿の次の生徒を返す
	Student* next()
	{
		Student* studentP =  exMeiboP->getStudentAt(index);
		index++;
		return studentP;
	}
};

//拡張名簿クラスメソッド定義---------------------------------------
//ここに定義しないとコンパイルエラーがおきる
//-----------------------------------------------------------
#ifdef MEIBO
	ExMeibo::ExMeibo(int studentCnt):Meibo(studentCnt){}
	Iterator* ExMeibo::iterator(){ return new ExMeiboIterator(this); }
#else
	Iterator* ExMeibo::iterator(){ return new ExMeiboIterator(this); }
#endif
//------------------------------------------------------------------
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//拡張名簿ExMeiboクラスと走査ExMeiboIteratorクラスを使って、名簿を走査する
///////////////////////////////////////////////////////////////////
//担任能力interfaceクラス定義（抽象クラス）
class Teacher {

//拡張名簿ExMeiboを定義しない場合、名簿Meibo、NewMeiboを別々に管理しなければならなくなる
//protected:
//	Meibo* meiboP;			//生成名簿オブジェクト管理用ポインタ
//	NewMeibo* newMeiboP;	//生成新名簿オブジェクト管理用ポインタ

public:
	virtual void createMeibo() = 0;		//名簿に生徒を登録
	virtual void callStudents() = 0;	//名簿から生徒を取得
};
//－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－
//担任クラス定義
class MyTeacher : public Teacher {
	ExMeibo* exMeiboP;		//拡張名簿管理用ポインタ
	Iterator* iteratorP;	//拡張名簿走査ポインタ
public:
	//名簿に生徒を登録
	void createMeibo()
	{

#ifdef MEIBO
		exMeiboP = new ExMeibo(5);	//拡張名簿生成（配列）
#else
		exMeiboP = new ExMeibo;		//拡張名簿生成（vector）
#endif

		//生成生徒オブジェクトはexMeiboP解放時にMeibo、NewMeiboクラスのデストラクタで解放される
		exMeiboP->add(new Student("赤井亮太",1));
		exMeiboP->add(new Student("赤羽里美",2));
		exMeiboP->add(new Student("岡田美央",2));
		exMeiboP->add(new Student("西森俊介",1));
		exMeiboP->add(new Student("中ノ森玲菜",2));
	}

	//名簿から生徒を取得
	void callStudents()
	{
		//拡張名簿走査オブジェクトを管理する
		iteratorP = exMeiboP->iterator();

		while(iteratorP->hasNext())
		{
			cout << ((iteratorP->next())->getName()) << endl;
		}
	}

	~MyTeacher(){
		delete exMeiboP;		//生成名簿オブジェクトの解放
		delete iteratorP;		//生成名簿走査オブジェクトの解放
	}
};

//////////////////////////////////////////////////////
int main()
{
	Teacher* teacherP(new MyTeacher);		//担任オブジェクト生成

	teacherP->createMeibo();				//名簿の作成
	teacherP->callStudents();				//生徒の取得

	delete teacherP;						//担任オブジェクトの解放

	return 0;
}
