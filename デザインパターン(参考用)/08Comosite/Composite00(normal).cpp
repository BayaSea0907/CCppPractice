//Composite（normal）
//ディレクトリとファイルの集まりのように、構造の中に再帰が見られる場合に使う
//ディレクトリの中には、ファイルの他に、更にディレクトリがあるような構造が再帰している
//「容器と中身を同一視する」という言葉で表現されることもある
//この場合、ディレクトリが容器で、その中にあるファイルやディレクトリが中身となる
//
//同一視できることが目的であるため、基本的にダウンキャストのようなことは避けたい
//ダウンキャストを許すのなら、無理にIEntryクラスに機能を詰め込む必要は無くなる
//（ダウンキャストの場合の例）
//addEntry()は、Directoryクラスの方に移動する
//もし、IEntry::addEntry()をやめて、Directory::addEntry()だけを定義すると、
//static_cast<Directory*>(dir1)->addEntry(dir2);
//のように使うことになります。
//この方法は使う側が面倒になりますが、IEntry が肥大化しなくて済むし、
//Directory や File の一方でしか機能しない関数の実装に悩まずに済む

//Composite00(normal).cpp
//結果
//test.txtファイルにtest.binファイルを追加することはできない
//Root
//Sub
//test.txt
//test.bin

#include <iostream>
#include <string>
#include <list>
using namespace std;

//////////////////////////////////////////////////////////////////
//ファイルエントリinterfaceクラス定義（抽象interfaceクラス）
class IEntry {
public:
	virtual void addEntry(IEntry* entry) = 0;
	virtual string getName()const = 0;
};

//////////////////////////////////////////////////////////////////
//ディレクトリクラス定義
class Directory : public IEntry {
	string directoryName;			//デレクトリ名
	list<IEntry*> lst_Entries;		//ディレクトリに追加されるエントリを格納
public:
	Directory(string sname):directoryName(sname){}
	
	//新しいファイルエントリを追加する
	void addEntry(IEntry* entry){ lst_Entries.push_back(entry); }
	
	string getName()const{ return directoryName; }		//ディレクトリ名取得

	~Directory(){}
};

//////////////////////////////////////////////////////////////////
//ファイルクラス定義
class File : public IEntry{
	string fileName;			//ファイル名
public:
	File(string sname):fileName(sname){}

	//新しいファイルエントリを追加する
	void addEntry(IEntry* entry)
	{
		cout << fileName << "ファイルに"
			 << entry->getName() << "ファイルを追加することはできない" << endl;
	}

	string getName()const{ return fileName; }		//ファイル名取得

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
	
	//ディレクトリ構造を作る
	directory1->addEntry(directory2);
	directory1->addEntry(file1);
	directory2->addEntry(file2);
	
	file1->addEntry(file2);		//エラー（ファイルにファイルを追加できない）

	//ディレクトリ名とファイル名を表示しただけ
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
