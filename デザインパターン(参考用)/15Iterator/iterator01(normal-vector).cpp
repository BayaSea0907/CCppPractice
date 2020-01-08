//Iterator(normal-vector�j
//�u����i�z��\���j���Â��Ȃ����̂ŁA �V�����`���̂��́ivector�\���j�ɕς���

//iterator01�inormal-vector�j.cpp
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

/////////////////////////////////////////////////////////////
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
//�V����N���X��`�i�����vector�ŊǗ��j
class NewMeibo {
protected:
	vector<Student*> vstudent;		//����vector
public:
	void add(Student* studentP){ vstudent.push_back(studentP); }		//����vector�ɐ��k�i�̃A�h���X�j���i�[
	Student* getStudentAd(int index)const{ return vstudent[index]; }	//���k�i�̃A�h���X�j���擾

	int getVecorSize()const{ return vstudent.size(); }				//vector�T�C�Y�擾
};

///////////////////////////////////////////////////////////////////////
//�S�C�\��interface�N���X��`�i���ۃN���X�j
class Teacher {
protected:
//	Meibo* meiboP;			//��������I�u�W�F�N�g�Ǘ��p�|�C���^
	NewMeibo* newMeiboP;	//�����V����I�u�W�F�N�g�Ǘ��p�|�C���^
public:
	virtual void createMeibo() = 0;		//����ɐ��k��o�^
	virtual void callStudents() = 0;	//���납�琶�k���擾
};

///////////////////////////////////////////////////////////////////////
//�S�C�N���X��`
class MyTeacher : public Teacher {
public:
	//����ɐ��k��o�^����
	void createMeibo()
	{
		newMeiboP = new NewMeibo;
		newMeiboP->add(new Student("�Ԉ䗺��",1));
		newMeiboP->add(new Student("�ԉH����",2));
		newMeiboP->add(new Student("���c����",2));
		newMeiboP->add(new Student("���X�r��",1));
		newMeiboP->add(new Student("���m�X���",2));
/*
		newMeiboP->add(new Student("����Y��",1));
		newMeiboP->add(new Student("���b��",2));
		newMeiboP->add(new Student("�������Y",1));
*/
	}

	//���납�琶�k���擾
	void callStudents()
	{
		int vsize = newMeiboP->getVecorSize();	//����o�^���k���擾

		for(int i = 0; i < vsize; i++)
		{
			cout << newMeiboP->getStudentAd(i)->getName() << endl;
		}
	}
	~MyTeacher(){ delete newMeiboP; }		//�����V����I�u�W�F�N�g�̉��
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
