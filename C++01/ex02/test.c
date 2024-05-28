#include <stdio.h>

//void	addone(int &i) // have in C++ dont have in C
// {
// 	i = i + 1;
// 	printf("%d\n", i);
// }

void	addone(int i) // does not effect the i at main, here it is his own
{
	i = i + 1;
	printf("%d\n", i);
}

void	addrefone(int *i) // no return as it directly modify i at main
{
	*i = *i + 1;
	printf("%d\n", *i);
}

int main()
{
	int i = 0;

	i = i + 1;
	printf("%d\n", i);
	addone(i); // onlt take in the value
	printf("%d\n", i);
	addrefone(&i); // takes the adress of object
}