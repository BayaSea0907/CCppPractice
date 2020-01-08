//Composite�inormal�j
//�f�B���N�g���ƃt�@�C���̏W�܂�̂悤�ɁA�\���̒��ɍċA��������ꍇ�Ɏg��
//�f�B���N�g���̒��ɂ́A�t�@�C���̑��ɁA�X�Ƀf�B���N�g��������悤�ȍ\�����ċA���Ă���
//�u�e��ƒ��g�𓯈ꎋ����v�Ƃ������t�ŕ\������邱�Ƃ�����
//���̏ꍇ�A�f�B���N�g�����e��ŁA���̒��ɂ���t�@�C����f�B���N�g�������g�ƂȂ�
//
//���ꎋ�ł��邱�Ƃ��ړI�ł��邽�߁A��{�I�Ƀ_�E���L���X�g�̂悤�Ȃ��Ƃ͔�������
//�_�E���L���X�g�������̂Ȃ�A������IEntry�N���X�ɋ@�\���l�ߍ��ޕK�v�͖����Ȃ�
//�i�_�E���L���X�g�̏ꍇ�̗�j
//addEntry()�́ADirectory�N���X�̕��Ɉړ�����
//�����AIEntry::addEntry()����߂āADirectory::addEntry()�������`����ƁA
//static_cast<Directory*>(dir1)->addEntry(dir2);
//�̂悤�Ɏg�����ƂɂȂ�܂��B
//���̕��@�͎g�������ʓ|�ɂȂ�܂����AIEntry ����剻���Ȃ��čςނ��A
//Directory �� File �̈���ł����@�\���Ȃ��֐��̎����ɔY�܂��ɍς�

//Composite00(normal).cpp
//����
//test.txt�t�@�C����test.bin�t�@�C����ǉ����邱�Ƃ͂ł��Ȃ�
//Root
//Sub
//test.txt
//test.bin

#include <iostream>
#include <string>
#include <list>
using namespace std;

//////////////////////////////////////////////////////////////////
//�t�@�C���G���g��interface�N���X��`�i����interface�N���X�j
class IEntry {
public:
	virtual void addEntry(IEntry* entry) = 0;
	virtual string getName()const = 0;
};

//////////////////////////////////////////////////////////////////
//�f�B���N�g���N���X��`
class Directory : public IEntry {
	string directoryName;			//�f���N�g����
	list<IEntry*> lst_Entries;		//�f�B���N�g���ɒǉ������G���g�����i�[
public:
	Directory(string sname):directoryName(sname){}
	
	//�V�����t�@�C���G���g����ǉ�����
	void addEntry(IEntry* entry){ lst_Entries.push_back(entry); }
	
	string getName()const{ return directoryName; }		//�f�B���N�g�����擾

	~Directory(){}
};

//////////////////////////////////////////////////////////////////
//�t�@�C���N���X��`
class File : public IEntry{
	string fileName;			//�t�@�C����
public:
	File(string sname):fileName(sname){}

	//�V�����t�@�C���G���g����ǉ�����
	void addEntry(IEntry* entry)
	{
		cout << fileName << "�t�@�C����"
			 << entry->getName() << "�t�@�C����ǉ����邱�Ƃ͂ł��Ȃ�" << endl;
	}

	string getName()const{ return fileName; }		//�t�@�C�����擾

	~File(){}
};
//--------------------------------------------------------------------

///////////////////////////////////////////////////////////////////
int main()
{
	IEntry* directory1  = new Directory("Root");
	IEntry* directory2  = new Directory("Sub");
	IEntry* file1 = new File("test.txt");
	IEntry* file2 = new File("test.bin");
	
	//�f�B���N�g���\�������
	directory1->addEntry(directory2);
	directory1->addEntry(file1);
	directory2->addEntry(file2);
	
	file1->addEntry(file2);		//�G���[�i�t�@�C���Ƀt�@�C����ǉ��ł��Ȃ��j

	//�f�B���N�g�����ƃt�@�C������\����������
	cout << directory1->getName() << endl;
	cout << directory2->getName() << endl;
	cout << file1->getName() << endl;
	cout << file2->getName() << endl;

	delete file2;
	delete file1;
	delete directory2;
	delete directory1;

	return 0;
}
