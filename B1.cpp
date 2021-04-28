#include<iostream>
#define N 100

using namespace std;

double divider(int*, int); 
int chooseIndex(int*, int, double);
int countMethod(int*, int, int);
void swap(int*, int);

int main()
{
	int Arr[N], n, index = -1; //remains -1 if there is no 1 in the array
	double div;

	cout << "n = ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "Arr[" << i << "]" << endl;
		cin >> Arr[i];
	}
	div = divider(Arr, n);   //Calculate the torque pivoted at centre assuming weight of each 1 is 1 and 0 is 0. 
	index = chooseIndex(Arr, n, div);    //calculate the index of nearest 1 near the divider
	cout <<"count : "<< countMethod(Arr, n, index) << endl; //counts the number of methods used to group them.
	for (int i = 0; i < n; i++)
	{
		cout << Arr[i] << '\t';
	}

	return 0;
}

double divider(int* Arr, int n)
{
	double count = 0;

	for (int i = 0; i < n; i++)
	{
		if (Arr[i] == 1)
		{
			count = count + i + 1 - (double)(n + 1) / 2;
		}
	}

	return (double)(n + 1) / 2 + count;
}

int chooseIndex(int* Arr, int n, double div)
{
	int index = -1, temp = 0;
	for (int i = 0; i < n; i++)
	{
		if (Arr[i] == 1)
		{
			if (index == -1)
			{
				temp = abs(i + 1 - div);
				index = i + 1;
			}
			else
			{
				if (abs(i + 1 - div) < temp)
				{
					temp = abs(i + 1 - div);
					index = i + 1;
				}
			}
		}
	}
	return index;
}

int countMethod(int* Arr,int n,int index)
{
	int num = 0, change = 1;
	while (change > 0)
	{
		change = 0;
		for (int i = 0; i < n; i++)
		{
			if (Arr[i] == 1)
			{
				if (i + 1 - index < 0 && Arr[i + 1] == 0)
				{
					swap(Arr, i);
					change = 1;
					num++;
				}
				else if (i + 1 - index > 0 && Arr[i - 1] == 0)
				{
					swap(Arr, i - 1);
					change = 1;
					num++;
				}
			}
		}
	}
	return num;
}

void swap(int* Arr,int i)
{
	int temp = Arr[i];
	Arr[i] = Arr[i + 1];
	Arr[i + 1] = temp;
}