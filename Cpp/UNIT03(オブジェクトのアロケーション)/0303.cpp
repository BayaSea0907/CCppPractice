/*-----------------------------------------------------
|���03-03		BayaSea
-------------------------------------------------------*/
#include <iostream>
using namespace std;

//Hero�\���̒�`
struct Hero {
	int hp;				//HP
};
////////////////////////////////////////////////////////////
int main(){
	Hero* heroP(new Hero);		//�\���̕ϐ��̈�ւ̃|�C���^�錾

	//heroP = new Hero;			//�A���P�[�V����

	heroP->hp = 100;			//HP�ݒ�
	cout << "HP=" << heroP->hp << endl;	//HP�\��

	delete heroP;

	system("pause");
	return 0;
}