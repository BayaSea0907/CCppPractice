//Iterator�inormal-extend:array+vector�j
//����̃f�[�^�\���i�z��Avector�j���ς���Ă��A�����������ł���悤�ɂ���
//����i�z��Avector�j�ǂ���ł����ʂɑ����ł���悤�ɁA
//���ʑ����p�Ɋg�������g������Ɗg������𑖍����鏈���ɕ�����
//�g������f�[�^��Aggregate�A������Iterator����������p�����Ē�`����
//�����āA����Iterator���p�������h��Iterator�ɁA�g������f�[�^Aggregate���p������
//�h��Aggreagte���W�񂳂���
//����ɂ��A�ǂ̂悤�ȃf�[�^�\���ł����Ă��A�h��Iterator���h��Aggregate�𑖍�����
//���Ƃ��ł���
//
//�g������ExMeibo���`���Ȃ��ꍇ�A����Meibo�ANewMeibo��ʁX�ɊǗ����Ȃ���΂Ȃ�Ȃ��Ȃ�
//�Ⴆ�΁A�S�C�\��interface�N���X��`�i���ۃN���X�j�����̂悤�ɒ�`�����
//class Teacher {
//protected:
//	Meibo* meiboP;			//��������I�u�W�F�N�g�Ǘ��p�|�C���^
//	NewMeibo* newMeiboP;	//�����V����I�u�W�F�N�g�Ǘ��p�|�C���^
//};

//�v���O�����ł́A�R�}���h�v���Z�b�T���g���āA�g���Ă���f�[�^�\�����z�񂠂邢��vector���ǂ����ŁA
//�Ή���؂�ւ�����悤�ɂ��Ă���
//#define MEIBO		//�i�z��jMeibo�Ή�
//#undef MEIBO		//�ivector�jNewMeibo�Ή�
//
//#define MEIBO
//#else
//#endif

//iterator02(normal-extend).cpp
//����
//�Ԉ䗺��
//�ԉH����
//���c����
//���X�r��
//���m�X���

#include <iostream>
#include <string>
#include <vector>			//�V���낪vector���p�̂���
using namespace std;

#define MEIBO		//�i�z��jMeibo�Ή�
#undef MEIBO		//�ivector�jNewMeibo�Ή�

//�f�[�^�i���k�A����z��A�V����vector�j++++++++++++++++++++++++++++++
///////////////////////////////////////////////////////////////////
//���k�N���X��`
class Student {
	string name;	//����
	int sex;		//�j�̎q:1 ���̎q:2
public:
	Student(string sname = "", int ssex = 0):name(sname), sex(ssex){}
	string getName()const{ return name; }
	int getSex()const{ return sex; }
};
//---------------------------------------------------------------

//����f�[�^�\��-------------------------------------------------
//�P�j�z��iMeibo�N���X�j
//�Q�jvector�iNewMeibo�N���X�j
/////////////////////////////////////////////////////////////////
//�P�j����i�z��j�N���X��`
class Meibo {
	int last;					//�o�^���k��
protected:
	Student** studentsP;		//����i�z��j�Ǘ��p�|�C���^
public:
	Meibo():last(0){}
	Meibo(int mlast):last(0), studentsP(new Student*[mlast]){}		//����i�z��j����

	//����i�z��j�ɐ��k��o�^
	void add(Student *sstudentP)
	{
		studentsP[last] = sstudentP;		//���k�i�̃A�h���X�j���i�[
		last++;
	}
	Student* getStudentAt(int index)const{ return studentsP[index]; }		//���k�i�̃A�h���X�j���擾
	int getLastNum()const{ return last; }									//�o�^���k���擾
	
	~Meibo()
	{
		for(int i = 0; i < last; i++){ delete studentsP[i]; }		//�o�^���k�̉��
		delete [] studentsP;										//����i�z��j�̉��
	}
};
//--------------------------------------------------------------
//�Q�j�V����ivector�j�N���X��`
class NewMeibo {
protected:
	vector<Student*> vstudent;		//����vector
public:
	void add(Student* studentP){ vstudent.push_back(studentP); }		//����vector�ɐ��k�i�̃A�h���X�j���i�[
	Student* getStudentAt(int index)const{ return vstudent[index]; }	//���k�i�̃A�h���X�j���擾

	int getLastNum()const{ return vstudent.size(); }			//vector�T�C�Y�擾

	~NewMeibo()
	{
		for(int i = 0; i < (int)vstudent.size(); i++){ delete vstudent[i]; }	//�o�^���k�̉��
	}
};
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//�i�V�j����̃f�[�^�\���iMeibo�F�z��ANewMeibo�Fvector�j���قȂ��Ă��Ă�
//���ʂɑ���ł���悤�ɁA�����̊g���N���X(ExMeibo�j���`����
//�������A�g�p���͂ǂ��炩������R�����g�ɂ���
///////////////////////////////////////////////////////////////

class Iterator;

//Aggregate--------------------------------------------------------
///////////////////////////////////////////////////////////////
//Agregate�@interface�N���X��`�i���ۃN���X�j
class Aggregate {
public:
	virtual Iterator* iterator() = 0;
};
//-----------------------------------------------------------------
///////////////////////////////////////////////////////////////
#ifdef MEIBO
	//�g������i�z��j�N���X��`
	class ExMeibo : public Meibo, public Aggregate {
	public:
		ExMeibo():Meibo(){}
		ExMeibo(int studentCnt);
		Iterator* iterator();
	};
//-------------------------------------------------------------
#else
	//�g������ivector�j�N���X��`
	class ExMeibo : public NewMeibo, public Aggregate {
	public:
		Iterator* iterator();
	};
#endif
//--------------------------------------------------------------

//iterator---------------------------------------------------------
///////////////////////////////////////////////////////////////////
//�g������ExMeibo�N���X�Ƒ΂ɂȂ鑖��iterator�N���X
//�g������I�u�W�F�N�g���Ǘ����閼��i�z��Avector�j�𑖍�����
//�����N���X�ɁA�g������I�u�W�F�N�g��o�^
///////////////////////////////////////////////////////////////////
//Iterator�@interface�N���X��`�i���ۃN���X�j
class Iterator {
public:
	virtual bool hasNext() = 0;			//����Ɏ��̐��k�����邩�ǂ���
	virtual Student* next() = 0;		//����̎��̐��k�i�̃A�h���X�j��Ԃ�
};
//-----------------------------------------------------------------
////////////////////////////////////////////////////////////////
//�g�����둖���p�N���X��`
class ExMeiboIterator : public Iterator {
	ExMeibo* exMeiboP;		//�g������Ǘ��p�|�C���^
	int index;				//�g����������p
public:
	ExMeiboIterator(ExMeibo* exmeiboP):exMeiboP(exmeiboP), index(0){}

	//����Ɏ��̐��k�����邩�ǂ���
	bool hasNext()
	{
		if(exMeiboP->getLastNum() > index)	return true;
		else								return false;
	}
	//����̎��̐��k��Ԃ�
	Student* next()
	{
		Student* studentP =  exMeiboP->getStudentAt(index);
		index++;
		return studentP;
	}
};

//�g������N���X���\�b�h��`---------------------------------------
//�����ɒ�`���Ȃ��ƃR���p�C���G���[��������
//-----------------------------------------------------------
#ifdef MEIBO
	ExMeibo::ExMeibo(int studentCnt):Meibo(studentCnt){}
	Iterator* ExMeibo::iterator(){ return new ExMeiboIterator(this); }
#else
	Iterator* ExMeibo::iterator(){ return new ExMeiboIterator(this); }
#endif
//------------------------------------------------------------------
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//�g������ExMeibo�N���X�Ƒ���ExMeiboIterator�N���X���g���āA����𑖍�����
///////////////////////////////////////////////////////////////////
//�S�C�\��interface�N���X��`�i���ۃN���X�j
class Teacher {

//�g������ExMeibo���`���Ȃ��ꍇ�A����Meibo�ANewMeibo��ʁX�ɊǗ����Ȃ���΂Ȃ�Ȃ��Ȃ�
//protected:
//	Meibo* meiboP;			//��������I�u�W�F�N�g�Ǘ��p�|�C���^
//	NewMeibo* newMeiboP;	//�����V����I�u�W�F�N�g�Ǘ��p�|�C���^

public:
	virtual void createMeibo() = 0;		//����ɐ��k��o�^
	virtual void callStudents() = 0;	//���납�琶�k���擾
};
//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|
//�S�C�N���X��`
class MyTeacher : public Teacher {
	ExMeibo* exMeiboP;		//�g������Ǘ��p�|�C���^
	Iterator* iteratorP;	//�g�����둖���|�C���^
public:
	//����ɐ��k��o�^
	void createMeibo()
	{

#ifdef MEIBO
		exMeiboP = new ExMeibo(5);	//�g�����됶���i�z��j
#else
		exMeiboP = new ExMeibo;		//�g�����됶���ivector�j
#endif

		//�������k�I�u�W�F�N�g��exMeiboP�������Meibo�ANewMeibo�N���X�̃f�X�g���N�^�ŉ�������
		exMeiboP->add(new Student("�Ԉ䗺��",1));
		exMeiboP->add(new Student("�ԉH����",2));
		exMeiboP->add(new Student("���c����",2));
		exMeiboP->add(new Student("���X�r��",1));
		exMeiboP->add(new Student("���m�X���",2));
	}

	//���납�琶�k���擾
	void callStudents()
	{
		//�g�����둖���I�u�W�F�N�g���Ǘ�����
		iteratorP = exMeiboP->iterator();

		while(iteratorP->hasNext())
		{
			cout << ((iteratorP->next())->getName()) << endl;
		}
	}

	~MyTeacher(){
		delete exMeiboP;		//��������I�u�W�F�N�g�̉��
		delete iteratorP;		//�������둖���I�u�W�F�N�g�̉��
	}
};

//////////////////////////////////////////////////////
int main()
{
	Teacher* teacherP(new MyTeacher);		//�S�C�I�u�W�F�N�g����

	teacherP->createMeibo();				//����̍쐬
	teacherP->callStudents();				//���k�̎擾

	delete teacherP;						//�S�C�I�u�W�F�N�g�̉��

	return 0;
}
