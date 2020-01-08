//Iterator（shared-extend:array+vector）
//名簿のデータ構造（配列、vector）が変わっても、同じ走査ができるようにする
//名簿（配列、vector）どちらでも共通に走査できるように、
//共通走査用に拡張した拡張名簿と拡張名簿を走査する処理に分ける
//拡張名簿データはAggregate、走査はIteratorをそえぞれ継承して定義する
//そして、走査Iteratorを継承した派生Iteratorに、拡張名簿データAggregateを継承した
//派生Aggreagteを集約させる
//これにより、どのようなデータ構造であっても、派生Iteratorが派生Aggregateを走査する
//ことができる

//拡張名簿ExMeiboを定義しない場合、名簿Meibo、NewMeiboを別々に管理しなければならなくなる
//例えば、担任能力interfaceクラス定義（抽象クラス）が次のように定義される
//class Teacher {
//protected:
//	Meibo* meiboP;			//生成名簿オブジェクト管理用ポインタ
//	NewMeibo* newMeiboP;	//生成新名簿オブジェクト管理用ポインタ
//};

//新名簿NewMeiboクラス（vector対応）を使う場合、Studentオブジェクトはsharedポインタで管理することができるが、
//名簿Meiboクラス（配列対応）を使う場合、normalなポインタで管理しなければならない
//【理由】Studentオブジェクトをsharedポインタで管理すると、sharedポインタを要素とする配列をcreateObject()
//テンプレート関数で生成するが、配列生成時の第2パラメータに　default_delete<shared_ptr<student[]>()　を
//指定しなければならなくなる
//すると、sharedポインタに対しては、明示的なdeleteは行ってはいけないので、実行時エラーの原因になるからである

//プログラムでは、コマンドプロセッサを使って、使っているデータ構造が配列あるいはvectorかどうかで、
//対応を切り替えられるようにしてある
//#define MEIBO		//（配列）Meibo対応
//#undef MEIBO		//（vector）NewMeibo対応
//
//#define MEIBO
//#else
//#endif
//
//iterator03(shared-extend).cpp
//結果
//赤井亮太
//赤羽里美
//岡田美央
//西森俊介
//中ノ森玲菜

#include <iostream>
#include <string>
#include <vector>		//新名簿がvector利用のため
#include <memory>
using namespace std::tr1;
using namespace std;

#define MEIBO			//（配列）Meibo対応
//#undef MEIBO			//（vector）NewMeibo対応
 

//オブジェクト生成テンプレート関数-----------------------------------------
/////////////////////////////////////////////////////////////////
template<class X>
shared_ptr<X> createObject()
{
	return (shared_ptr<X>)(new X);
}
//--------------------------------------------------------------
//拡張名簿ExMeibo配列生成用
template<class X>
shared_ptr<X> createObject(int n)
{
	return (shared_ptr<X>)(new X(n));
}
//---------------------------------------------------------------
//生徒Student生成用（引数固定：氏名、性別）
template<class X>
shared_ptr<X> createObject(string n, int m)
{
	return (shared_ptr<X>)(new X(n, m));
}
//--------------------------------------------------------------------

//データ（生徒、名簿配列、新名簿vector）+++++++++++++++++++++++++++++++++++
/////////////////////////////////////////////////////////////////
//生徒クラス定義
class Student {
	string name;		//氏名
	int sex;		//男の子:1 女の子:2
public:
	Student(string sname = "", int ssex = 0):name(sname), sex(ssex){}
	string getName()const{ return name; }
	int getSex()const{ return sex; }
};
//---------------------------------------------------------------

//名簿データ構造---------------------------------------------------
//１）配列（Meiboクラス）
//２）vector（NewMeiboクラス）
/////////////////////////////////////////////////////////////////
//１）名簿（配列）クラス定義
class Meibo {
	int last;			//登録生徒数
protected:
	Student** studentsP;		//名簿（配列）管理用ポインタ
public:
	Meibo():last(0){}

	//名簿（配列）生成
	Meibo(int mlast):last(0), studentsP(new Student*[mlast]){} 

	//名簿（配列）に生徒を登録
	void add(Student* sstudentP)
	{
		studentsP[last] = sstudentP;	//生徒（のアドレス）を格納
		last++;
	}
 

	Student* getStudentAt(int index)const{ return studentsP[index]; }

	//生徒（のアドレス）を取得
	int getLastNum()const{ return last; }	//登録生徒数取得
	
	~Meibo()
	{
		//登録生徒の解放	
		for(int i = 0; i < last; i++){ delete studentsP[i]; } 

		//名簿（配列）の解放
		delete [] studentsP; 
	}
};
//---------------------------------------------------------------
//２）新名簿（vector）クラス定義
class NewMeibo {
protected:
	vector<shared_ptr<Student>> sh_vstudent;		//名簿vector
public:
	//名簿vectorに生徒（のアドレス）を格納
	void add(shared_ptr<Student> sh_student)
{ sh_vstudent.push_back(sh_student); } 

	//生徒（のアドレス）を取得
	shared_ptr<Student> getStudentAt(int index)const
{ return sh_vstudent[index]; } 

	//vectorサイズ取得
	int getLastNum()const{ return sh_vstudent.size(); }

	~NewMeibo(){}
};
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//名簿のデータ構造（Meibo：配列、NewMeibo：vector）が異なっていても
//共通に操作できるように、同名の拡張クラス(ExMeibo）を定義する
/////////////////////////////////////////////////////////////////

class Iterator;

//Aggregate---------------------------------------------------------
/////////////////////////////////////////////////////////////////
//Agregate　interfaceクラス定義（抽象クラス）
class Aggregate {
public:
	virtual shared_ptr<Iterator> iterator() = 0;
};
//---------------------------------------------------------------
 

/////////////////////////////////////////////////////////////////
#ifdef MEIBO
	//拡張名簿（配列）クラス定義
	class ExMeibo : public Meibo, public Aggregate {
	public:
		ExMeibo():Meibo(){}
		ExMeibo(int studentCnt);
		shared_ptr<Iterator> iterator();
	};
#else
	//拡張名簿（vector）クラス定義
	class ExMeibo : public NewMeibo, public Aggregate {
	public:
		shared_ptr<Iterator> iterator();
	};
#endif
//------------------------------------------------------------------

//iterator----------------------------------------------------------
/////////////////////////////////////////////////////////////////
//拡張名簿ExMeiboクラスと対になる走査iteratorクラス
//拡張名簿オブジェクトが管理する名簿（配列、vector）を走査する
//走査クラスに、拡張名簿オブジェクトを登録
/////////////////////////////////////////////////////////////////
//Iterator　interfaceクラス定義（抽象クラス）
class Iterator {
public:
	virtual bool hasNext() = 0;			//名簿に次の生徒がいるかどうか

#ifdef MEIBO
	virtual Student* next() = 0;		//名簿の次の生徒（のアドレス）を返す
#else
	virtual shared_ptr<Student> next() = 0;	//名簿の次の生徒（のアドレス）を返す
#endif

};
//---------------------------------------------------------------
/////////////////////////////////////////////////////////////////
//拡張名簿走査用クラス定義
class ExMeiboIterator : public Iterator {
	ExMeibo* exMeiboP;		//拡張名簿管理用ポインタ
	int index;			//拡張名簿索引用
public:
	ExMeiboIterator(ExMeibo* exmeiboP):exMeiboP(exmeiboP), index(0){}

	//名簿に次の生徒がいるかどうか
	bool hasNext()
	{
		if(exMeiboP->getLastNum() > index)    return true;
		else					    return false;
	}
 

#ifdef MEIBO
	//名簿の次の生徒を返す
	Student* next()
	{
		Student* studentP = exMeiboP->getStudentAt(index);
		index++;
		return studentP;
	}
#else
	//名簿の次の生徒を返す
	shared_ptr<Student> next()
	{
		shared_ptr<Student> studentP = exMeiboP->getStudentAt(index);
		index++;
		return studentP;
	}
#endif

};

//拡張名簿クラスメソッド定義-----------------------------------------
//【ここに定義しないとコンパイルエラーがおきる】
//---------------------------------------------------------------
#ifdef MEIBO
	ExMeibo::ExMeibo(int studentCnt):Meibo(studentCnt){}
	shared_ptr<Iterator> ExMeibo::iterator()
{ return (shared_ptr<Iterator>)(new ExMeiboIterator(this)); }
#else
	shared_ptr<Iterator> ExMeibo::iterator()
{ return (shared_ptr<Iterator>)(new ExMeiboIterator(this)); }
#endif
//---------------------------------------------------------------
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//拡張名簿ExMeiboクラスと走査ExMeiboIteratorクラスを使って、名簿を走査する
/////////////////////////////////////////////////////////////////
//担任能力interfaceクラス定義（抽象クラス）
class Teacher {
public:
	virtual void createMeibo() = 0;		//名簿に生徒を登録
	virtual void callStudents() = 0;		//名簿から生徒を取得
};
//---------------------------------------------------------------
//担任クラス定義
class MyTeacher : public Teacher {
	shared_ptr<ExMeibo> sh_exMeibo;		//拡張名簿管理用
	shared_ptr<Iterator> sh_iterator;		//拡張名簿走査
public:
	//名簿に生徒を登録
	void createMeibo()
	{

#ifdef MEIBO
		sh_exMeibo = createObject<ExMeibo>(5);	//拡張名簿生成（配列）
 

		//生成生徒オブジェクトはsh_exMeibo消滅時に、Meiboクラスのデストラクタで
//解放される
		sh_exMeibo->add(new Student("赤井亮太", 1));
		sh_exMeibo->add(new Student("赤羽里美", 2));
		sh_exMeibo->add(new Student("岡田美央", 2));
		sh_exMeibo->add(new Student("西森俊介", 1));
		sh_exMeibo->add(new Student("中ノ森玲菜", 2));
#else
		sh_exMeibo = createObject<ExMeibo>();	//拡張名簿生成（vector）

		sh_exMeibo->add(createObject<Student>("赤井亮太", 1));
		sh_exMeibo->add(createObject<Student>("赤羽里美", 2));
		sh_exMeibo->add(createObject<Student>("岡田美央", 2));
		sh_exMeibo->add(createObject<Student>("西森俊介", 1));
		sh_exMeibo->add(createObject<Student>("中ノ森玲菜", 2));
#endif

	}

	//名簿から生徒を取得
	void callStudents()
	{
		//拡張名簿走査オブジェクトを管理する
		sh_iterator = sh_exMeibo->iterator();

		while(sh_iterator->hasNext())
		{
			cout << ((sh_iterator->next())->getName()) << endl;
		}
	}

	~MyTeacher(){}
};

/////////////////////////////////////////////////////////////////
int main()
{
	//担任オブジェクト生成
	shared_ptr<Teacher> sh_teacher(createObject<MyTeacher>()); 

	sh_teacher->createMeibo();		//名簿の作成
	sh_teacher->callStudents();		//生徒の取得

	return 0;
}



