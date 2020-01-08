//Composite（shared）
//ディレクトリとファイルの集まりのように、構造の中に再帰が見られる場合に使う
//Directory1には、ファイル（file1とfile2）とDirectory2（ファイルfile3をもつ）がある
//Directory3には、ファイルfile4がある
//ファイルにはファイルはない
//削除removeメソッドで再帰構造を辿っていることがわかる

//ここでは、それぞれのファイルとオブジェクトはmain関数で生成し、
//削除removeメソッドでは、「削除メッセージ」のみを表示し、main関数で解放している
//
//Composite02(shared).cpp
//結果
//file1ファイルにfile2ファイルを追加できません
//file1を削除しました
//file2を削除しました
//file3を削除しました
//directory2を削除しました
//directory1を削除しました
///file4を削除しました
//directory3を削除しました

#include <iostream>
#include <string>
#include <list>
#include <typeinfo>
#include <memory>
using namespace std::tr1;
using namespace std;

//オブジェクト生成テンプレート関数-----------------------------------
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
//Entry定義-------------------------------------------------------------
//////////////////////////////////////////////////////////////////
//エントリinterfaceクラス定義（抽象interfaceクラス）
class IEntry {
public:
	virtual void addEntry(shared_ptr<IEntry> sh_entry) = 0;
	virtual void remove() = 0;
	virtual string getEntryName()const = 0;
};

//////////////////////////////////////////////////////////////////
//ファイルエントリクラス定義
class File : public IEntry {
	string fileName;			//ファイル名
public:
	File(string sname):fileName(sname){}

	//エントリ追加
	void addEntry(shared_ptr<IEntry> sh_entry)
	{
		cout << fileName << "ファイルに"
			 << sh_entry->getEntryName() << "ファイルを追加できません" << endl;
	}

	void remove(){ cout << fileName + "を削除しました" << endl; }	//Entry削除

	string getEntryName()const{ return fileName; }
	~File(){}
};
//-----------------------------------------------------------------

//////////////////////////////////////////////////////////////////
//ディレクトリエントリクラス定義
class Directory : public IEntry {
	string directoryName;			//デレクトリ名
	list<shared_ptr<IEntry>> lst_sh_Entries;		//ディレクトリに追加するエントリを格納
public:
	Directory(string sdirectoryName):directoryName(sdirectoryName){}

	//エントリ追加
	void addEntry(shared_ptr<IEntry> sh_entry)
	{
		lst_sh_Entries.push_back(sh_entry);
	}

	//Entry削除
	void remove()
	{
		list<shared_ptr<IEntry>>::iterator lst_itr = lst_sh_Entries.begin();

		//EntryリストからEntryを削除
		while(lst_itr != lst_sh_Entries.end())
		{
			//Entryがファイルの場合
			if((string)typeid(**lst_itr).name() == "class File")
			{
				(*lst_itr)->remove();
			}
			//Entryがディレクトリの場合
			else if((string)typeid(**lst_itr).name() == "class Directory")
			{
				(**lst_itr).remove();
			}
			else
			{
				cout << "削除できません" << endl;
			}
			lst_itr++;
		}
		cout << directoryName + "を削除しました。" << endl;
	}
	string getEntryName()const{ return directoryName; }
	~Directory(){}
};
//--------------------------------------------------------------------

///////////////////////////////////////////////////////////////////
int main()
{
	//Entryオブジェクト生成
	shared_ptr<IEntry> sh_file1(createObject<File>("file1"));
	shared_ptr<IEntry> sh_file2(createObject<File>("file2"));
	shared_ptr<IEntry> sh_file3(createObject<File>("file3"));
	shared_ptr<IEntry> sh_file4(createObject<File>("file4"));

	shared_ptr<IEntry> sh_dir1(createObject<Directory>("directory1"));
	shared_ptr<IEntry> sh_dir2(createObject<Directory>("directory2"));
	shared_ptr<IEntry> sh_dir3(createObject<Directory>("directory3"));

	//DirectoryにEntryを追加
	sh_dir1->addEntry(sh_file1);
	sh_dir1->addEntry(sh_file2);
	sh_dir2->addEntry(sh_file3);
	sh_dir1->addEntry(sh_dir2);		//Directory1にDirectory2を追加
	sh_dir3->addEntry(sh_file4);

	sh_file1->addEntry(sh_file2);	//fileにfileを追加できない

	//directoryからEntryを削除
	sh_dir1->remove();
	sh_dir3->remove();

	return 0;
}
