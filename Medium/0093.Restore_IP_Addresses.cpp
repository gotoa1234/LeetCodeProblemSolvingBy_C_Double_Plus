#include <iostream>
#include <unordered_map>
#include <string>
#include <cmath>
using namespace std;

namespace Solution91
{
#pragma region Paste to execute 
    /*
    #include <unordered_map>
    #include "Medium/0091.Restore_IP_Addresses.cpp"
    using namespace Solution91;

    int main()
    {
        Solution91::Restore_IP_Addresses useClass;
        Solution91::Restore_IP_Addresses::Restore_IP_Addresses_Model getTestModel = useClass.GetTestData001();
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
    /// «ì´_ IP ¦a§}
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
        ///         «ä¸ô ¡G
        ///      Runtime :
        /// Memory Usage :
        /// </summary>
        /// <returns></returns>
        vector<string> restoreIpAddresses(string s) {
         return {};
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