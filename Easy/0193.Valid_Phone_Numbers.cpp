#include <iostream>
using namespace std;

namespace Solution193
{
#pragma region Paste to execute 
	/*
	*/
#pragma endregion Paste to executes

	/// <summary>
	/// ���Ĺq�ܸ��X
	/// </summary>
	class Valid_Phone_Numbers
	{
#pragma region Model
	public:
		class Valid_Phone_Numbers_Model
		{
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///         ��� �G���D�حn�D��Bash�y�k
		///      Runtime : 91 ms					
		/// Memory Usage : 3.1 MB						
		/// </summary>
		/// <returns></returns>        
		void file()
		{
			/*����
			- o ��X�ǰt�쪺�奻�A���]�t��L���e
			- w �ǰt�����ŦX���C
			- e ���w�r�Ŧ갵���d���󤺮e���˦��C
			1. ���۫e�b�q"" ���e�O���h��F���ǰt�G�o�ӼҦ��Ω�ǰt�Φp"123 456-7890"���奻��A�䤤�e�T��O�Ʀr�A����O�@�ӪŮ�A�A����O�T�ӼƦr�M�@�ӳs�r�šA�̫�O�|�ӼƦr�C
			2. ���۫�b�q"" �O�t�ӥ��h��F���ǰt�G�o�ӼҦ��Ω�ǰt�Φp"123-456-7890"���奻��A�䤤�e�T��O�Ʀr�A����O�@�s�r�šA�A����O�T�ӼƦr�M�@�ӳs�r�šA�̫�O�|�ӼƦr�C
			�p�G����1. 2. �~�|��X�� file.txt ��
			*/

			/* Bash�y�k�p�U�G			
			grep -o -w -e "^([0-9][0-9][0-9]) [0-9][0-9][0-9]-[0-9][0-9][0-9][0-9]$" -o -w -e "^[0-9][0-9][0-9]-[0-9][0-9][0-9]-[0-9][0-9][0-9][0-9]$" file.txt
			grep -o -w -e "^([0-9][0-9][0-9]) [0-9][0-9][0-9]-[0-9][0-9][0-9][0-9]$" -o -w -e "^[0-9][0-9][0-9]-[0-9][0-9][0-9]-[0-9][0-9][0-9][0-9]$" file.txtz
			*/
		}
	public:
#pragma endregion Main
		/* �D��
		987-123-4567
        123 456 7890
        (123) 456-7890
		*/

		/* ��X �]���u���o��ӲŦX
		987-123-4567
        (123) 456-7890
		*/
	};
}