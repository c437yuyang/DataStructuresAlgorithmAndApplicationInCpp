// functions to convert from type K to nonnegative integer
// derived from similar classes in SGI STL


#ifndef hash_
#define hash_

#include <iostream>
#include <string>

using namespace std;

template <class K> 
class hash_1;

template<>//对于string类型，需要转换
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

template<> //对于int和long，只是简单的转换为size_t类型
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
