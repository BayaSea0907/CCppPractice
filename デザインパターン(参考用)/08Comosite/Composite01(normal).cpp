//Composite�inormal�j
//�f�B���N�g���ƃt�@�C���̏W�܂�̂悤�ɁA�\���̒��ɍċA��������ꍇ�Ɏg��
//Directory1�ɂ́A�t�@�C���ifile1��file2�j��Directory2�i�t�@�C��file3�����j������
//Directory3�ɂ́A�t�@�C��file4������
//�t�@�C���ɂ̓t�@�C���͂Ȃ�
//�폜remove���\�b�h�ōċA�\����H���Ă��邱�Ƃ��킩��

//�����ł́A���ꂼ��̃t�@�C���ƃI�u�W�F�N�g��main�֐��Ő������A
//�폜remove���\�b�h�ł́A�u�폜���b�Z�[�W�v�݂̂�\�����Amain�֐��ŉ�����Ă���
//
//Composite01(normal).cpp
//����
//file1�t�@�C����file2�t�@�C����ǉ��ł��܂���
//file1���폜���܂���
//file2���폜���܂���
//file3���폜���܂���
//directory2���폜���܂���
//directory1���폜���܂���
///file4���폜���܂���
//directory3���폜���܂���

#include <iostream>
#include <string>
#include <list>
#include <typeinfo>
using namespace std;

//Entry��`-------------------------------------------------------------
//////////////////////////////////////////////////////////////////
//�G���g��interface�N���X��`�i����interface�N���X�j
class IEntry {
public:
	virtual void addEntry(IEntry* entry) = 0;
	virtual void remove() = 0;
	virtual string getEntryName()const = 0;
};

//////////////////////////////////////////////////////////////////
//�t�@�C���G���g���N���X��`
class File : public IEntry {
	string fileName;			//�t�@�C����
public:
	File(string sname):fileName(sname){}

	//�G���g���ǉ�
	void addEntry(IEntry* entryP)
	{
		cout << fileName << "�t�@�C����"
			 << entryP->getEntryName() << "�t�@�C����ǉ��ł��܂���" << endl;
	}

	void remove(){ cout << fileName + "���폜���܂���" << endl; }	//Entry�폜

	string getEntryName()const{ return fileName; }
	~File(){}
};

//////////////////////////////////////////////////////////////////
//�f�B���N�g���G���g���N���X��`
class Directory : public IEntry {
	string directoryName;			//�f���N�g����
	list<IEntry*> lst_Entries;		//�f�B���N�g���ɒǉ�����G���g�����i�[
public:
	Directory(string sdirectoryName):directoryName(sdirectoryName){}

	//�G���g���ǉ�
	void addEntry(IEntry* entryP)
	{
		lst_Entries.push_back(entryP);
	}

	//Entry�폜
	void remove()
	{
		list<IEntry*>::iterator lst_itr = lst_Entries.begin();

		//Entry���X�g����Entry���폜
		while(lst_itr != lst_Entries.end())
		{
			//Entry���t�@�C���̏ꍇ
			if((string)typeid(**lst_itr).name() == "class File")
			{
				(*lst_itr)->remove();
			}
			//Entry���f�B���N�g���̏ꍇ
			else if((string)typeid(**lst_itr).name() == "class Directory")
			{
				(**lst_itr).remove();
			}
			else
			{
				cout << "�폜�ł��܂���" << endl;
			}
			lst_itr++;
		}
		cout << directoryName + "���폜���܂����B" << endl;
	}
	string getEntryName()const{ return directoryName; }
	~Directory(){}
};
//--------------------------------------------------------------------

///////////////////////////////////////////////////////////////////
int main()
{
	//Entry�I�u�W�F�N�g����
	IEntry* fileP1 = new File("file1");
	IEntry* fileP2 = new File("file2");
	IEntry* fileP3 = new File("file3");
	IEntry* fileP4 = new File("file4");

	IEntry* dirP1 = new Directory("directory1");
	IEntry* dirP2 = new Directory("directory2");
	IEntry* dirP3 = new Directory("directory3");

	//Directory��Entry��ǉ�
	dirP1->addEntry(fileP1);
	dirP1->addEntry(fileP2);
	dirP2->addEntry(fileP3);
	dirP1->addEntry(dirP2);		//Directory1��Directory2��ǉ�
	dirP3->addEntry(fileP4);

	fileP1->addEntry(fileP2);	//file��file��ǉ��ł��Ȃ�

	//directory����Entry���폜
	dirP1->remove();
	dirP3->remove();

	delete fileP1;
	delete fileP2;
	delete fileP3;
	delete fileP4;
	delete dirP1;
	delete dirP2;
	delete dirP3;

	return 0;
}
