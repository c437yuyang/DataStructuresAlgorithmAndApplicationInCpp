// output all permutations of n elements

#include <iostream>
#include <algorithm> // has copy
#include <iterator>
using namespace std;

template<class T>
void permutations(T list[], int k, int endIdx)
{// Generate all permutations of list[k:m].
 // Assume k <= m.

	//cout << "for list :";
	//copy(list, list + endIdx + 1, ostream_iterator<T>(cout, " "));
	//cout << endl;
	//cout << "from " << list[k] << " to " << list[endIdx] << endl;
	//cout << endl;
	int i;
	if (k == endIdx) {// list[k:m] has one permutation, output it
		copy(list, list + endIdx + 1,
			ostream_iterator<T>(cout, ""));
		cout << endl;
	}
	else  // list[k:m] has more than one permutation
		  // generate these recursively 
		for (i = k; i <= endIdx; i++)
		{
			swap(list[k], list[i]);
			permutations(list, k + 1, endIdx);
			swap(list[k], list[i]);
		}
}

int main()
{
	char a[] = { 'a', 'b', 'c', 'd' };

	cout << "The permutations of 1 are" << endl;
	permutations(a, 0, 0);

	cout << "The permutations of 123 are" << endl;
	permutations(a, 0, 2);

	cout << "The permutations of 1234 are" << endl;
	permutations(a, 0, 3);
	return 0;
}
