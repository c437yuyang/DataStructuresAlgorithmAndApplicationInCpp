// functions to convert from type K to nonnegative integer
// derived from similar classes in SGI STL


#ifndef hash_
#define hash_

#include <iostream>
#include <string>

using namespace std;

template <class K> 
class hash_1;

template<>//����string���ͣ���Ҫת��
class hash_1<string>
{
   public:
      size_t operator()(const string theKey) const
      {// Convert theKey to a nonnegative integer.
         unsigned long hashValue = 0; 
         int length = (int) theKey.length();
         for (int i = 0; i < length; i++)
            hashValue = 5 * hashValue + theKey.at(i);
    
         return size_t(hashValue);
      }
};

template<> //����int��long��ֻ�Ǽ򵥵�ת��Ϊsize_t����
class hash_1<int>
{
   public:
      size_t operator()(const int theKey) const
      {return size_t(theKey);}
};

template<>
class hash_1<long>
{
   public:
      size_t operator()(const long theKey) const
      {return size_t(theKey);}
};

#endif
