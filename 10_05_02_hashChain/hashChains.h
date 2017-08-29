// hash table using sorted chains and division
// implements all dictionary methods

#ifndef hashChains_
#define hashChains_
#include <iostream>
#include "hash.h"  // mapping functions from K to nonnegative integer
#include "dictionary.h"
#include "sortedChain.h"

using namespace std;

template<class K, class E>
class hashChains : public dictionary<K, E>
{
public:
	hashChains(int theDivisor = 11)
	{
		divisor = theDivisor;
		dSize = 0;

		// allocate and initialize hash table array
		table = new sortedChain<K, E>[divisor];
	}

	~hashChains() { delete[] table; }

	bool empty() const { return dSize == 0; }
	int size() const { return dSize; }

	pair<const K, E>* find(const K& theKey) const
	{
		return table[hash_1(theKey) % divisor].find(theKey);
	}

	void insert(const pair<const K, E>& thePair)
	{
		int homeBucket = (int)hash_1(thePair.first) % divisor;
		int homeSize = table[homeBucket].size();
		table[homeBucket].insert(thePair); //因为这里insert可能并没有把size变大(原来已经有这个key了)，所以下面判断了size变大了再加这边的dsize
		if (table[homeBucket].size() > homeSize)
			dSize++;
	}

	void erase(const K& theKey)
	{
		table[hash_1(theKey) % divisor].erase(theKey);
		dSize--; //yxp 
	}

	void output(ostream& out) const
	{
		for (int i = 0; i < divisor; i++)
			if (table[i].size() == 0)
				cout << "NULL" << endl;
			else
				cout << table[i] << endl;
	}


protected:
	sortedChain<K, E>* table;  // hash table
	hash_1<K> hash_1;              // maps type K to nonnegative integer
	int dSize;                 // number of elements in list
	int divisor;               // hash function divisor
};


// overload <<
template <class K, class E>
ostream& operator<<(ostream& out, const hashChains<K, E>& x)
{
	x.output(out); return out;
}

#endif
