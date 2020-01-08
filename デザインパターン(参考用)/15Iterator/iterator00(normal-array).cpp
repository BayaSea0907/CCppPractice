//Iterator �p�^�[���inormal�F����ɔz��g�p�j
//�搶�|���k�T�l

//iterator00�inormal-array�j.cpp
//����
//�Ԉ䗺��
//�ԉH����
//���c����
//���X�r��
//���m�X���

#include <iostream>
#include <string>
using namespace std;

///////////////////////////////////////////////////////////////////////
//���k�N���X��`
class Student {
	string name;	//����
	int sex;		//�j�̎q:1 ���̎q:2
public:
	Student(string sname = "", int ssex = 0):name(sname), sex(ssex){}
	string getName()const{ return name; }
	int getSex()const{ return sex; }
};

///////////////////////////////////////////////////////////////////////
//����N���X��`
//���k�Ǘ��p�̖���̐����A����̑����A����̉��
class Meibo {
	int last;					//�o�^���k��
protected:
	Student** studentsP;		//����i�z��j�Ǘ��p�|�C���^
public:
	Meibo():last(0){}
	Meibo(int studentCount):last(0), studentsP(new Student*[studentCount]){}	//����i�z��j����

	//����ɐ��k��o�^
	void add(Student *sstudentP)
	{
		studentsP[last] = sstudentP;		//���k�i�̃A�h���X�j���i�[
		last++;
	}

	Student* getStudentAt(int index)const{ return studentsP[index]; }		//���k�i�̃A�h���X�j���擾
	int getLastNum()const{ return last; }									//�o�^���k���擾
	
	~Meibo()
	{
		for(int n = 0; n < last; n++){ delete studentsP[n]; }				//���k�̉��
		delete [] studentsP;												//����i�z��j�̉��
	}
};

///////////////////////////////////////////////////////////////////////
//�S�C�\��interface�N���X��`�i���ۃN���X�j
class Teacher {
protected:
	Meibo* meiboP;			//��������I�u�W�F�N�g�Ǘ��p�|�C���^
public:
	virtual void createMeibo() = 0;		//����ɐ��k��o�^
	virtual void callStudents() = 0;	//���납�琶�k���擾
};

///////////////////////////////////////////////////////////////////////
//�S�C�N���X��`
class MyTeacher : public Teacher {
public:
	//����ɐ��k��o�^
	void createMeibo()
	{
		meiboP = new Meibo(5);					//����I�u�W�F�N�g�����i���k���T�j
		meiboP->add(new Student("�Ԉ䗺��",1));
		meiboP->add(new Student("�ԉH����",2));
		meiboP->add(new Student("���c����",2));
		meiboP->add(new Student("���X�r��",1));
		meiboP->add(new Student("���m�X���",2));
	}

	//���납�琶�k���擾
	void callStudents()
	{
		int size = meiboP->getLastNum();		//����ɓo�^�������k���擾

		//���k���\��
		for(int n = 0; n < size; n++)
		{
			cout << meiboP->getStudentAt(n)->getName() << endl;
		}
	}
	~MyTeacher(){ delete meiboP; }				//��������I�u�W�F�N�g�̉��
};


///////////////////////////////////////////////////////////////////////
int main()
{
	Teacher* teacherP(new MyTeacher);	//�S�C�I�u�W�F�N�g����

	teacherP->createMeibo();			//����̍쐬
	teacherP->callStudents();			//���k�̎擾

	delete teacherP;					//�S�C�I�u�W�F�N�g�̉��

	return 0;
}
