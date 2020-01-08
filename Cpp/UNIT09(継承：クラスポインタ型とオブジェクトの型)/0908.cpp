/*----------------------------------------------------------
|���09-08	 BayaSea
------------------------------------------------------------*/
#include <iostream>
#include <string>
using namespace std;

//BOSS�i�e�L�����j�N���X
class BOSS
{
    string bossName;	//�e�L������
    int defPower;		//�h��\��
public:
	BOSS(string bn = "") :bossName(bn) {};

	void setDefPower(int sd) { defPower = sd; }		//�h��\�͐ݒ�

	string getBossName() { return bossName; }		//�e�L�������擾
	int	   getDefPower() { return defPower; }		//�h��\�͎擾

	//�q�L�����p
	virtual void setWeapon(string) {};
	virtual string getFollName() { return ""; }
	virtual string getWeapon()	 { return ""; }
};
////////////////////////////////////////////////////////////
//Follower�i�q�L�����j�N���X
class Follower : public BOSS
{
    string follName;   //�q�L������
    string weapon;     //���햼
public:
	//�q�L�������A�e�L������������
	Follower(string fn = "", string bn = "") : follName(fn), BOSS(bn) {};

	void setWeapon(string sw) { weapon = sw; }		//���햼�ݒ�

	string getFollName() { return follName; }		//�q�L�������擾
	string getWeapon()	 { return weapon;	}		//���햼�擾
};
////////////////////////////////////////////////////////////
int main()
{
	BOSS* bossP(new Follower("�Ώ�", "���Y��"));

	bossP->setDefPower(100);
	bossP->setWeapon("���C�J");

	cout << "�q�L����="			<< bossP->getFollName() << endl;
	cout << "�q�L�����̐e�L����=" << bossP->getBossName() << endl;
    cout << "�q�L�����̖h��\��=" << bossP->getDefPower()	<< endl;
    cout << "�q�L�����̕���="		<< bossP->getWeapon()	<< endl;

	delete bossP;

	system("pause");
	return 0;
}
