#include <stdio.h>

void Sample1();
void Sample2();
void Sample3();
void Sample4();
void Sample5();

/*Instructions:
Navigate the functions and change what's necessary to fix the loop. 
After completing, Comment the Sample1 then uncomment Sample2

*/

int main() 
{
	Sample1();
	Sample2();
	Sample3();
	Sample4();
	Sample5();
}

void Sample1()
{
    printf("\nSample 1\n");
	for (int i = 0; i < 10; i++) 
	{
		printf("%d ", i);
	}
	
	//Output: 0 1 2 ... 9
}


void Sample2()
{
    printf("\nSample 2\n");
	int i = 5;

	for (; i < 10; i++) 
	{
		printf("%d ", i);
	};

	//Output: 5 6 7 ... 9
}


void Sample3() 
{
    printf("\nSample 3\n");
	for (int i = 0; i < 3; i++) 
	{
		for (int j = 0; j < 3; j++) 
		{
			printf("i=%d j=%d", i, j);
			if (i==2 && j==2) {
			    continue;
			}
			printf(", ");
		}
	}

	//Output: i=0 j=0, i=0 j=1, i=0 j=2 .... i=2 j=2
}


void Sample4() 
{
    printf("\nSample 4\n");
    int i=0;
	while (i < 10) 
	{
		printf("%d ", i);
		i++;
	}

	//Output: 0 1 2 ... 9
}


void Sample5() 
{
    printf("\nSample 5\n");
	int i = 0;
	while (i < 10)
	{
		printf("%d ", i);
		i++;
	}

	//Output: 0 1 2 ... 9
}

