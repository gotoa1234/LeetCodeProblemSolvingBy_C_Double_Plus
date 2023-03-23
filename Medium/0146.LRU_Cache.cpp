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
        ///         ��� �G�����Q��HashMap�d�ߤ~��F��O(1)���į�A
        ///                �åB�ϥ����(list)��get�ɪ��ȥû����ܩ�̫e�ݡC
        ///                set�Y�j��֨��j�p�ɱNlist�̫�@�ӭȻPhashTable��Key����
        ///      Runtime :   434 ms Beats 92.35 %
        /// Memory Usage : 165.1 MB Beats 77.84 %
        /// </summary>
        /// <returns></returns>  
        class LRUCache 
        {
            //1-1. �t�m��l���ܼ�
            int _sizeMax;
            list<pair<int, int>> _list;
            unordered_map<int, list<pair<int, int>>::iterator> _hashTable;
        public:
            //1-2. �֨��j�p
            LRUCache(int capacity) {
                _sizeMax = capacity;
            }

            //2-1. ���ȥ\��
            int get(int key) 
            {
                //2-2. �֨����s�b���X
                if (_hashTable.count(key) == 0)
                    return -1;

                //2-3. �N��e_hashTable[key]���ȶK��̫e���A��ܪ���ιL
                _list.splice(_list.begin(), _list, _hashTable[key]);
                //2-4. �Nvalue��^�A�F��ؼ�O(1)���d�߳t��
                return _hashTable[key]->second;
            }

            //3-1. �]�w�֨���
            void put(int key, int value) 
            {
                //3-2. Key�ȭ��ƪ����p�U�A�N�ª�Key����
                if (_hashTable.count(key))
                    _list.erase(_hashTable[key]);
                //3-3. �N�s�t�m���֨�����
                _list.push_front(make_pair(key, value));
                _hashTable[key] = _list.begin();
                
                //3-4. �����֨�Key
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