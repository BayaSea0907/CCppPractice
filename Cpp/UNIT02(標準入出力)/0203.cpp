//���O�Q�|�O�R		BayaSea
#include <iostream>
using namespace std;

//�ٓ��N���X��`
class Bento {
	int kosu = 10;       //���i10�j
public:
	int getKosu(){ return kosu; }
	int calc(int un){ return kosu * un; }
};
///////////////////////////////////////////////////////////////////
int main()
{
	Bento bento; 		//�I�u�W�F�N�g�錾

	cout << "Enter�L�[�������ĉ�����" << endl;
	cin.ignore();

	cout << "kosu=" << bento.getKosu() << endl;

	cout << "Enter�L�[��2�񉟂��ĉ�����" << endl;
	cin.ignore(2);

	cout << "���v=" << bento.calc(500) << endl;

	system("pause");
	return 0;
}