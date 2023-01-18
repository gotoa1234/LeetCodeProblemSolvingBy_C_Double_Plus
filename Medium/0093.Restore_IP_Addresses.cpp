#include <iostream>
#include <unordered_map>
#include <string>
#include <cmath>
using namespace std;

namespace Solution93
{
#pragma region Paste to execute 
    /*
    #include <unordered_map>
    #include "Medium/0093.Restore_IP_Addresses.cpp"
    using namespace Solution93;

    int main()
    {
        Solution93::Restore_IP_Addresses useClass;
        Solution93::Restore_IP_Addresses::Restore_IP_Addresses_Model getTestModel = useClass.GetTestData001();
        auto result1 = useClass.restoreIpAddresses(getTestModel.s);

        getTestModel = useClass.GetTestData002();
        auto result2 = useClass.restoreIpAddresses(getTestModel.s);

        getTestModel = useClass.GetTestData003();
        auto result3 = useClass.restoreIpAddresses(getTestModel.s);

        return 0;
    }
    */
#pragma endregion Paste to executes

    /// <summary>
    /// ��_ IP �a�}
    /// </summary>
    class Restore_IP_Addresses
    {
#pragma region Model
    public:
        class Restore_IP_Addresses_Model
        {
        public:
            string s;
        };
#pragma endregion Model

#pragma region Main
    public:
        /// <summary>
        ///         ��� �G�Q�λ��j�A�C���զ�1~3�Ӧr����IP�A�M���X�i��
        ///                �����X�k�����p�ɴ������X�A�קK�L�Ϊ��p��
        ///      Runtime :  0 ms Beats   100 %
        /// Memory Usage :6.6 MB Beats 41.75 %
        /// </summary>
        /// <returns></returns>
        vector<string> _result;
        vector<string> restoreIpAddresses(string s)
        {
            FindIpCompose(0, "", s);
            return _result;
        }

        void FindIpCompose(int ipTimes, string currentCompose, string s)
        {
            //1. �ư�IPv4 ���i��X�{�����p
            if (ipTimes == 0 && s.size() > 12 ||
                ipTimes == 1 && s.size() > 9 ||
                ipTimes == 2 && s.size() > 6 ||
                ipTimes == 3 && s.size() > 3)
                return;

            //3-1. �Yip��ĥ|�Ӧ�m EX: 1.2.3.4  ��.4���ɭ�times = 4
            if (ipTimes == 4)
            {
                //3-2. �Ys�w�g�κɡA��ܷ�e���զX����
                if (s.empty())
                    _result.push_back(currentCompose);
            }
            else
            {
                //2-1. �զ�1~3�Ӧr����IP EX:0~255
                for (int index = 1; index <= 3; index++)
                {
                    //2-2. �i��1 : �w�κɱj����X
                    if (s.size() < index)
                        break;
                    //2-3. �i��2 : �ন1��(0~255)��IP�A�����X�k�h���L
                    int val = atoi(s.substr(0, index).c_str());
                    if (val > 255 || index != to_string(val).size())
                        continue;
                    //2-4. ���ߡA�h���U�@�ӻ��j�i���ˬd
                    auto tempCompose = currentCompose + s.substr(0, index) + (ipTimes != 3 ? "." : "");
                    FindIpCompose(ipTimes + 1, tempCompose, s.substr(index));
                }
            }
        }

    public:
#pragma endregion Main

#pragma region TestData
    public:
        /// <summary>
        /// test 1
        /// </summary>        
        Restore_IP_Addresses_Model GetTestData001(void)
        {
            Restore_IP_Addresses_Model result;
            result.s = "25525511135";
            return result;//expect: ["255.255.11.135","255.255.111.35"]
        };

        /// <summary>
        /// test 2
        /// </summary>   
        Restore_IP_Addresses_Model GetTestData002(void)
        {
            Restore_IP_Addresses_Model result;
            result.s = "0000";
            return result;//expect: ["0.0.0.0"]
        };

        /// <summary>
        /// test 3
        /// </summary>   
        Restore_IP_Addresses_Model GetTestData003(void)
        {
            Restore_IP_Addresses_Model result;
            result.s = "101023";
            return result;//expect: ["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
        };
#pragma endregion TestData
    };
}