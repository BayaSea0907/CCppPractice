//--------------------------------------------------
//���03-04		BayaSea
//	Q.���ꂼ�ꃁ�����ɍ����̈於���q�ׂȂ����B
//
//	A.GNUM = �ÓI�̈�
//	  num  = �X�^�b�N�̈�
//    p    = �X�^�b�N�̈�
//    p�̒l(new int) = �q�[�v�̈�
//--------------------------------------------------
#include <iostream>
using namespace std;

int GNUM = 100;		//�O���ϐ�

int main()
{
	int num = 200;	//�����ϐ�
	int* p;			//�|�C���^�錾�i����������ϐ��j

	cout << "GNUM�A�h���X=" << hex << &GNUM << " �l=" << GNUM << endl;
	cout << "num�A�h���X=" << hex << &num << " �l=" << num << endl << endl;

	p = new int;	//�������A���P�[�V����
	*p = 300;		//�A���P�[�V�����̈�ɒl���i�[

	cout << "�A���P�[�V�����̈�A�h���X=" << hex <<	p << " �l=" <<	*p << endl;
	cout << "�|�C���^�A�h���X=" << hex << &p << " �l=" << p << endl;

	delete p;
	system("pause");
    return 0;
}

