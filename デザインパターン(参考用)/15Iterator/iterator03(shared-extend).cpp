//Iterator�ishared-extend:array+vector�j
//����̃f�[�^�\���i�z��Avector�j���ς���Ă��A�����������ł���悤�ɂ���
//����i�z��Avector�j�ǂ���ł����ʂɑ����ł���悤�ɁA
//���ʑ����p�Ɋg�������g������Ɗg������𑖍����鏈���ɕ�����
//�g������f�[�^��Aggregate�A������Iterator����������p�����Ē�`����
//�����āA����Iterator���p�������h��Iterator�ɁA�g������f�[�^Aggregate���p������
//�h��Aggreagte���W�񂳂���
//����ɂ��A�ǂ̂悤�ȃf�[�^�\���ł����Ă��A�h��Iterator���h��Aggregate�𑖍�����
//���Ƃ��ł���

//�g������ExMeibo���`���Ȃ��ꍇ�A����Meibo�ANewMeibo��ʁX�ɊǗ����Ȃ���΂Ȃ�Ȃ��Ȃ�
//�Ⴆ�΁A�S�C�\��interface�N���X��`�i���ۃN���X�j�����̂悤�ɒ�`�����
//class Teacher {
//protected:
//	Meibo* meiboP;			//��������I�u�W�F�N�g�Ǘ��p�|�C���^
//	NewMeibo* newMeiboP;	//�����V����I�u�W�F�N�g�Ǘ��p�|�C���^
//};

//�V����NewMeibo�N���X�ivector�Ή��j���g���ꍇ�AStudent�I�u�W�F�N�g��shared�|�C���^�ŊǗ����邱�Ƃ��ł��邪�A
//����Meibo�N���X�i�z��Ή��j���g���ꍇ�Anormal�ȃ|�C���^�ŊǗ����Ȃ���΂Ȃ�Ȃ�
//�y���R�zStudent�I�u�W�F�N�g��shared�|�C���^�ŊǗ�����ƁAshared�|�C���^��v�f�Ƃ���z���createObject()
//�e���v���[�g�֐��Ő������邪�A�z�񐶐����̑�2�p�����[�^�Ɂ@default_delete<shared_ptr<student[]>()�@��
//�w�肵�Ȃ���΂Ȃ�Ȃ��Ȃ�
//����ƁAshared�|�C���^�ɑ΂��ẮA�����I��delete�͍s���Ă͂����Ȃ��̂ŁA���s���G���[�̌����ɂȂ邩��ł���

//�v���O�����ł́A�R�}���h�v���Z�b�T���g���āA�g���Ă���f�[�^�\�����z�񂠂邢��vector���ǂ����ŁA
//�Ή���؂�ւ�����悤�ɂ��Ă���
//#define MEIBO		//�i�z��jMeibo�Ή�
//#undef MEIBO		//�ivector�jNewMeibo�Ή�
//
//#define MEIBO
//#else
//#endif
//
//iterator03(shared-extend).cpp
//����
//�Ԉ䗺��
//�ԉH����
//���c����
//���X�r��
//���m�X���

#include <iostream>
#include <string>
#include <vector>		//�V���낪vector���p�̂���
#include <memory>
using namespace std::tr1;
using namespace std;

#define MEIBO			//�i�z��jMeibo�Ή�
//#undef MEIBO			//�ivector�jNewMeibo�Ή�
 

//�I�u�W�F�N�g�����e���v���[�g�֐�-----------------------------------------
/////////////////////////////////////////////////////////////////
template<class X>
shared_ptr<X> createObject()
{
	return (shared_ptr<X>)(new X);
}
//--------------------------------------------------------------
//�g������ExMeibo�z�񐶐��p
template<class X>
shared_ptr<X> createObject(int n)
{
	return (shared_ptr<X>)(new X(n));
}
//---------------------------------------------------------------
//���kStudent�����p�i�����Œ�F�����A���ʁj
template<class X>
shared_ptr<X> createObject(string n, int m)
{
	return (shared_ptr<X>)(new X(n, m));
}
//--------------------------------------------------------------------

//�f�[�^�i���k�A����z��A�V����vector�j+++++++++++++++++++++++++++++++++++
/////////////////////////////////////////////////////////////////
//���k�N���X��`
class Student {
	string name;		//����
	int sex;		//�j�̎q:1 ���̎q:2
public:
	Student(string sname = "", int ssex = 0):name(sname), sex(ssex){}
	string getName()const{ return name; }
	int getSex()const{ return sex; }
};
//---------------------------------------------------------------

//����f�[�^�\��---------------------------------------------------
//�P�j�z��iMeibo�N���X�j
//�Q�jvector�iNewMeibo�N���X�j
/////////////////////////////////////////////////////////////////
//�P�j����i�z��j�N���X��`
class Meibo {
	int last;			//�o�^���k��
protected:
	Student** studentsP;		//����i�z��j�Ǘ��p�|�C���^
public:
	Meibo():last(0){}

	//����i�z��j����
	Meibo(int mlast):last(0), studentsP(new Student*[mlast]){} 

	//����i�z��j�ɐ��k��o�^
	void add(Student* sstudentP)
	{
		studentsP[last] = sstudentP;	//���k�i�̃A�h���X�j���i�[
		last++;
	}
 

	Student* getStudentAt(int index)const{ return studentsP[index]; }

	//���k�i�̃A�h���X�j���擾
	int getLastNum()const{ return last; }	//�o�^���k���擾
	
	~Meibo()
	{
		//�o�^���k�̉��	
		for(int i = 0; i < last; i++){ delete studentsP[i]; } 

		//����i�z��j�̉��
		delete [] studentsP; 
	}
};
//---------------------------------------------------------------
//�Q�j�V����ivector�j�N���X��`
class NewMeibo {
protected:
	vector<shared_ptr<Student>> sh_vstudent;		//����vector
public:
	//����vector�ɐ��k�i�̃A�h���X�j���i�[
	void add(shared_ptr<Student> sh_student)
{ sh_vstudent.push_back(sh_student); } 

	//���k�i�̃A�h���X�j���擾
	shared_ptr<Student> getStudentAt(int index)const
{ return sh_vstudent[index]; } 

	//vector�T�C�Y�擾
	int getLastNum()const{ return sh_vstudent.size(); }

	~NewMeibo(){}
};
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//����̃f�[�^�\���iMeibo�F�z��ANewMeibo�Fvector�j���قȂ��Ă��Ă�
//���ʂɑ���ł���悤�ɁA�����̊g���N���X(ExMeibo�j���`����
/////////////////////////////////////////////////////////////////

class Iterator;

//Aggregate---------------------------------------------------------
/////////////////////////////////////////////////////////////////
//Agregate�@interface�N���X��`�i���ۃN���X�j
class Aggregate {
public:
	virtual shared_ptr<Iterator> iterator() = 0;
};
//---------------------------------------------------------------
 

/////////////////////////////////////////////////////////////////
#ifdef MEIBO
	//�g������i�z��j�N���X��`
	class ExMeibo : public Meibo, public Aggregate {
	public:
		ExMeibo():Meibo(){}
		ExMeibo(int studentCnt);
		shared_ptr<Iterator> iterator();
	};
#else
	//�g������ivector�j�N���X��`
	class ExMeibo : public NewMeibo, public Aggregate {
	public:
		shared_ptr<Iterator> iterator();
	};
#endif
//------------------------------------------------------------------

//iterator----------------------------------------------------------
/////////////////////////////////////////////////////////////////
//�g������ExMeibo�N���X�Ƒ΂ɂȂ鑖��iterator�N���X
//�g������I�u�W�F�N�g���Ǘ����閼��i�z��Avector�j�𑖍�����
//�����N���X�ɁA�g������I�u�W�F�N�g��o�^
/////////////////////////////////////////////////////////////////
//Iterator�@interface�N���X��`�i���ۃN���X�j
class Iterator {
public:
	virtual bool hasNext() = 0;			//����Ɏ��̐��k�����邩�ǂ���

#ifdef MEIBO
	virtual Student* next() = 0;		//����̎��̐��k�i�̃A�h���X�j��Ԃ�
#else
	virtual shared_ptr<Student> next() = 0;	//����̎��̐��k�i�̃A�h���X�j��Ԃ�
#endif

};
//---------------------------------------------------------------
/////////////////////////////////////////////////////////////////
//�g�����둖���p�N���X��`
class ExMeiboIterator : public Iterator {
	ExMeibo* exMeiboP;		//�g������Ǘ��p�|�C���^
	int index;			//�g����������p
public:
	ExMeiboIterator(ExMeibo* exmeiboP):exMeiboP(exmeiboP), index(0){}

	//����Ɏ��̐��k�����邩�ǂ���
	bool hasNext()
	{
		if(exMeiboP->getLastNum() > index)    return true;
		else					    return false;
	}
 

#ifdef MEIBO
	//����̎��̐��k��Ԃ�
	Student* next()
	{
		Student* studentP = exMeiboP->getStudentAt(index);
		index++;
		return studentP;
	}
#else
	//����̎��̐��k��Ԃ�
	shared_ptr<Student> next()
	{
		shared_ptr<Student> studentP = exMeiboP->getStudentAt(index);
		index++;
		return studentP;
	}
#endif

};

//�g������N���X���\�b�h��`-----------------------------------------
//�y�����ɒ�`���Ȃ��ƃR���p�C���G���[��������z
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

//�g������ExMeibo�N���X�Ƒ���ExMeiboIterator�N���X���g���āA����𑖍�����
/////////////////////////////////////////////////////////////////
//�S�C�\��interface�N���X��`�i���ۃN���X�j
class Teacher {
public:
	virtual void createMeibo() = 0;		//����ɐ��k��o�^
	virtual void callStudents() = 0;		//���납�琶�k���擾
};
//---------------------------------------------------------------
//�S�C�N���X��`
class MyTeacher : public Teacher {
	shared_ptr<ExMeibo> sh_exMeibo;		//�g������Ǘ��p
	shared_ptr<Iterator> sh_iterator;		//�g�����둖��
public:
	//����ɐ��k��o�^
	void createMeibo()
	{

#ifdef MEIBO
		sh_exMeibo = createObject<ExMeibo>(5);	//�g�����됶���i�z��j
 

		//�������k�I�u�W�F�N�g��sh_exMeibo���Ŏ��ɁAMeibo�N���X�̃f�X�g���N�^��
//��������
		sh_exMeibo->add(new Student("�Ԉ䗺��", 1));
		sh_exMeibo->add(new Student("�ԉH����", 2));
		sh_exMeibo->add(new Student("���c����", 2));
		sh_exMeibo->add(new Student("���X�r��", 1));
		sh_exMeibo->add(new Student("���m�X���", 2));
#else
		sh_exMeibo = createObject<ExMeibo>();	//�g�����됶���ivector�j

		sh_exMeibo->add(createObject<Student>("�Ԉ䗺��", 1));
		sh_exMeibo->add(createObject<Student>("�ԉH����", 2));
		sh_exMeibo->add(createObject<Student>("���c����", 2));
		sh_exMeibo->add(createObject<Student>("���X�r��", 1));
		sh_exMeibo->add(createObject<Student>("���m�X���", 2));
#endif

	}

	//���납�琶�k���擾
	void callStudents()
	{
		//�g�����둖���I�u�W�F�N�g���Ǘ�����
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
	//�S�C�I�u�W�F�N�g����
	shared_ptr<Teacher> sh_teacher(createObject<MyTeacher>()); 

	sh_teacher->createMeibo();		//����̍쐬
	sh_teacher->callStudents();		//���k�̎擾

	return 0;
}



