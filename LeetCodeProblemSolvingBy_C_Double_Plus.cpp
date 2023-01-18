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