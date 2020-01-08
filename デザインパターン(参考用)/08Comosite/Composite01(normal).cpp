//Composite（normal）
//ディレクトリとファイルの集まりのように、構造の中に再帰が見られる場合に使う
//Directory1には、ファイル（file1とfile2）とDirectory2（ファイルfile3をもつ）がある
//Directory3には、ファイルfile4がある
//ファイルにはファイルはない
//削除removeメソッドで再帰構造を辿っていることがわかる

//ここでは、それぞれのファイルとオブジェクトはmain関数で生成し、
//削除removeメソッドでは、「削除メッセージ」のみを表示し、main関数で解放している
//
//Composite01(normal).cpp
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
using namespace std;

//Entry定義-------------------------------------------------------------
//////////////////////////////////////////////////////////////////
//エントリinterfaceクラス定義（抽象interfaceクラス）
class IEntry {
public:
	virtual void addEntry(IEntry* entry) = 0;
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
	void addEntry(IEntry* entryP)
	{
		cout << fileName << "ファイルに"
			 << entryP->getEntryName() << "ファイルを追加できません" << endl;
	}

	void remove(){ cout << fileName + "を削除しました" << endl; }	//Entry削除

	string getEntryName()const{ return fileName; }
	~File(){}
};

//////////////////////////////////////////////////////////////////
//ディレクトリエントリクラス定義
class Directory : public IEntry {
	string directoryName;			//デレクトリ名
	list<IEntry*> lst_Entries;		//ディレクトリに追加するエントリを格納
public:
	Directory(string sdirectoryName):directoryName(sdirectoryName){}

	//エントリ追加
	void addEntry(IEntry* entryP)
	{
		lst_Entries.push_back(entryP);
	}

	//Entry削除
	void remove()
	{
		list<IEntry*>::iterator lst_itr = lst_Entries.begin();

		//EntryリストからEntryを削除
		while(lst_itr != lst_Entries.end())
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
	IEntry* fileP1 = new File("file1");
	IEntry* fileP2 = new File("file2");
	IEntry* fileP3 = new File("file3");
	IEntry* fileP4 = new File("file4");

	IEntry* dirP1 = new Directory("directory1");
	IEntry* dirP2 = new Directory("directory2");
	IEntry* dirP3 = new Directory("directory3");

	//DirectoryにEntryを追加
	dirP1->addEntry(fileP1);
	dirP1->addEntry(fileP2);
	dirP2->addEntry(fileP3);
	dirP1->addEntry(dirP2);		//Directory1にDirectory2を追加
	dirP3->addEntry(fileP4);

	fileP1->addEntry(fileP2);	//fileにfileを追加できない

	//directoryからEntryを削除
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
