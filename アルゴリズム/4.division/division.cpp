/*---------------------------------------------------------------------------
|�ۑ�4 division
|   ���Z�A���Z������p���āA�����̏��Z���s���A���S���Y�����l����B�������A
|	���Ɨ]������߂�B2����(�폜���A����)�̓L�[���͂���B�܂��A���͕͂K��
|	�폜���������ł���Ƃ���B
|
|	2016/5/30	BayaSea
-----------------------------------------------------------------------------*/

#include <iostream>
using namespace std;

int main ()
{
	unsigned int dividend;				//�폜��
	unsigned int divisor;				//����
	unsigned int quotient = 0;			//��
	unsigned int surplus;				//��]

	cout << "�폜���E�����̓���(��:	20 3) >>";
	cin >> dividend >> divisor;

	surplus = dividend; 
	
	//���Z
	while(surplus >= divisor)
	{
		surplus -= divisor;
		quotient++;
	}

	cout << "�폜�� : " << dividend << endl;
	cout << "���� : "	 << divisor	   << endl << endl;
	cout << dividend << " / " << divisor << " = " << quotient << "�c" << surplus << endl;

	system ("pause");
	return 0;
}