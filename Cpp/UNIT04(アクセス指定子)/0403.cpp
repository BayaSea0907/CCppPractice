/*------------------------------------------------------------
|���04-03	 BayaSea
|
|�ݖ�.	Set�֐��ŁA->�̑���� .(�s���I�h)���g����setNum���\�b�h���Ăяo���Ȃ����B
|		->�̍����� . �̍����́A���ꂼ�ꉽ��\���Ă��܂����H
-------------------------------------------------------------*/
#include <iostream>
using namespace std;

//�X�܃N���X��`
class Shop {
	int num;		//��
public:
	void setNum(int sn){ num = sn; }	//���ݒ�
	int getNum(){ return num; }			//���擾
};
//////////////////////////////////////////////////////////////
//�O���֐� ����100��ݒ�
void Set(Shop* shopP){
	//shopP->setNum(100);			//�ݖ�@->�̍����́A�I�u�W�F�N�g�̃A�h���X
	 (*shopP).setNum(100);			//�ݖ�@�D�̍����́A�I�u�W�F�N�g�̗̈�
}
//////////////////////////////////////////////////////////////
int main()
{
	Shop* shopP(new Shop);

	Set(shopP);		//�O���֐��Ăяo��
	cout << "��=" << shopP->getNum() << endl;

	delete shopP;
	system("pause");
	return 0;
}
