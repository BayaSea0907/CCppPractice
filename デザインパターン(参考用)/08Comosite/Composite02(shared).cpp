//Composite�ishared�j
//�f�B���N�g���ƃt�@�C���̏W�܂�̂悤�ɁA�\���̒��ɍċA��������ꍇ�Ɏg��
//Directory1�ɂ́A�t�@�C���ifile1��file2�j��Directory2�i�t�@�C��file3�����j������
//Directory3�ɂ́A�t�@�C��file4������
//�t�@�C���ɂ̓t�@�C���͂Ȃ�
//�폜remove���\�b�h�ōċA�\����H���Ă��邱�Ƃ��킩��

//�����ł́A���ꂼ��̃t�@�C���ƃI�u�W�F�N�g��main�֐��Ő������A
//�폜remove���\�b�h�ł́A�u�폜���b�Z�[�W�v�݂̂�\�����Amain�֐��ŉ�����Ă���
//
//Composite02(shared).cpp
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
#include <memory>
using namespace std::tr1;
using namespace std;

//�I�u�W�F�N�g�����e���v���[�g�֐�-----------------------------------
///////////////////////////////////////////////////////////////////
template<class X>
shared_ptr<X> createObject()
{
	return (shared_ptr<X>)(new X);
}
//---------------------------------------------------------------
template<class X, class Y>
shared_ptr<X> createObject(Y n)
{
	return (shared_ptr<X>)(new X(n));
}
//--------------------------------------------------------------------

//////////////////////////////////////////////////////////////////
//Entry��`-------------------------------------------------------------
//////////////////////////////////////////////////////////////////
//�G���g��interface�N���X��`�i����interface�N���X�j
class IEntry {
public:
	virtual void addEntry(shared_ptr<IEntry> sh_entry) = 0;
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
	void addEntry(shared_ptr<IEntry> sh_entry)
	{
		cout << fileName << "�t�@�C����"
			 << sh_entry->getEntryName() << "�t�@�C����ǉ��ł��܂���" << endl;
	}

	void remove(){ cout << fileName + "���폜���܂���" << endl; }	//Entry�폜

	string getEntryName()const{ return fileName; }
	~File(){}
};
//-----------------------------------------------------------------

//////////////////////////////////////////////////////////////////
//�f�B���N�g���G���g���N���X��`
class Directory : public IEntry {
	string directoryName;			//�f���N�g����
	list<shared_ptr<IEntry>> lst_sh_Entries;		//�f�B���N�g���ɒǉ�����G���g�����i�[
public:
	Directory(string sdirectoryName):directoryName(sdirectoryName){}

	//�G���g���ǉ�
	void addEntry(shared_ptr<IEntry> sh_entry)
	{
		lst_sh_Entries.push_back(sh_entry);
	}

	//Entry�폜
	void remove()
	{
		list<shared_ptr<IEntry>>::iterator lst_itr = lst_sh_Entries.begin();

		//Entry���X�g����Entry���폜
		while(lst_itr != lst_sh_Entries.end())
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
	shared_ptr<IEntry> sh_file1(createObject<File>("file1"));
	shared_ptr<IEntry> sh_file2(createObject<File>("file2"));
	shared_ptr<IEntry> sh_file3(createObject<File>("file3"));
	shared_ptr<IEntry> sh_file4(createObject<File>("file4"));

	shared_ptr<IEntry> sh_dir1(createObject<Directory>("directory1"));
	shared_ptr<IEntry> sh_dir2(createObject<Directory>("directory2"));
	shared_ptr<IEntry> sh_dir3(createObject<Directory>("directory3"));

	//Directory��Entry��ǉ�
	sh_dir1->addEntry(sh_file1);
	sh_dir1->addEntry(sh_file2);
	sh_dir2->addEntry(sh_file3);
	sh_dir1->addEntry(sh_dir2);		//Directory1��Directory2��ǉ�
	sh_dir3->addEntry(sh_file4);

	sh_file1->addEntry(sh_file2);	//file��file��ǉ��ł��Ȃ�

	//directory����Entry���폜
	sh_dir1->remove();
	sh_dir3->remove();

	return 0;
}
