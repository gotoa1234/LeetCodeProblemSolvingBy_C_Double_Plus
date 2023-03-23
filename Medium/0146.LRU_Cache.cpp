#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

namespace Solution146
{
#pragma region Paste to execute 
    /*
    #include <unordered_map>
    #include "Medium/0146.LRU_Cache.cpp"
    using namespace Solution146;
    
    int main()
    {
        Solution146::LRUCache_Class::LRUCache lRUCache(2);
        lRUCache.put(1, 1); // cache is {1=1}
        lRUCache.put(2, 2); // cache is {1=1, 2=2}
        lRUCache.get(1);    // return 1
        lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
        lRUCache.get(2);    // returns -1 (not found)
        lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
        lRUCache.get(1);    // return -1 (not found)
        lRUCache.get(3);    // return 3
        lRUCache.get(4);    // return 4
        //Output
        //[null, null, null, 1, null, -1, null, -1, 3, 4]
    }
    */
#pragma endregion Paste to executes

    /// <summary>
    /// LRU(Least Recently Used Cache) 
    /// </summary>
    class LRUCache_Class
    {
#pragma region Main
    public:
        /// <summary>
        ///         思路 ：必須利用HashMap查詢才能達到O(1)的效能，
        ///                並且使用鏈表(list)使get時的值永遠重至於最前端。
        ///                set若大於快取大小時將list最後一個值與hashTable此Key移除
        ///      Runtime :   434 ms Beats 92.35 %
        /// Memory Usage : 165.1 MB Beats 77.84 %
        /// </summary>
        /// <returns></returns>  
        class LRUCache 
        {
            //1-1. 配置初始化變數
            int _sizeMax;
            list<pair<int, int>> _list;
            unordered_map<int, list<pair<int, int>>::iterator> _hashTable;
        public:
            //1-2. 快取大小
            LRUCache(int capacity) {
                _sizeMax = capacity;
            }

            //2-1. 取值功能
            int get(int key) 
            {
                //2-2. 快取不存在跳出
                if (_hashTable.count(key) == 0)
                    return -1;

                //2-3. 將當前_hashTable[key]的值貼到最前面，表示近期用過
                _list.splice(_list.begin(), _list, _hashTable[key]);
                //2-4. 將value返回，達到目標O(1)的查詢速度
                return _hashTable[key]->second;
            }

            //3-1. 設定快取值
            void put(int key, int value) 
            {
                //3-2. Key值重複的情況下，將舊的Key移除
                if (_hashTable.count(key))
                    _list.erase(_hashTable[key]);
                //3-3. 將新配置的快取紀錄
                _list.push_front(make_pair(key, value));
                _hashTable[key] = _list.begin();
                
                //3-4. 移除快取Key
                if (_hashTable.size() > _sizeMax) 
                {
                    int cacheKey = _list.rbegin()->first;
                    _list.pop_back();
                    _hashTable.erase(cacheKey);
                }
            }
        };
    };
#pragma endregion Main
}