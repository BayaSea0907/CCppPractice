//���O�Q�|�O�P		BayaSea
#include <iostream>
using namespace std;

//�}�`�N���X��`
class Fig {
	int high;		//�����icm�j
	int bottom;		//��Ӂicm�j
public:
	void setHigh(int sh){ high = sh; }					//�����ݒ�
	void setBottom(int sb){ bottom = sb; }    			//��Ӑݒ�
	double getArea(){ return (double)(bottom * high) / 2.0; }	//�ʐώ擾
};
//////////////////////////////////////////////////////////////
int main()
{
	Fig fig;		//�I�u�W�F�N�g�錾
	int high;		//�������͗p
	int bottom;		//��ӓ��͗p

	cout << "�����ƒ�ӂ̓���>> ";
	cin >> high >> bottom;

	fig.setHigh(high); 		//�����ݒ胁�\�b�h�Ăяo��
	fig.setBottom(bottom); 	//��Ӑݒ胁�\�b�h�Ăяo��

	cout << "�O�p�`�̖ʐ�=" << fig.getArea() << endl;

	system("pause");
	return 0;
}
