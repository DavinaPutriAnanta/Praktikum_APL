#include  <iostream>
using namespace std; 


int main (){
	int a[7] = {1,2,3,4,5,6,7};
	int (*aPtr)[7] = &a;
	cout << *aPtr << endl;
	return 0;
	
}


