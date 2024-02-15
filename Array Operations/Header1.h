int mergeArr(int arr[], int start, int half, int end)
{
	int count = 0;

	int s1 = half - start + 1;
	int s2 = end - half;

	int* arr1 = new int[s1];
	int* arr2 = new int[s2];

	for (int i = 0; i < s1; i++)
	{
		arr1[i] = arr[start + i];
	}

	for (int i = 0; i < s2; i++)
	{
		arr2[i] = arr[half + 1 + i];
	}

	int p1 = 0;
	int p2 = 0;
	int index = start;

	while (p1 < s1 && p2 < s2)
	{
		if (arr1[p1] < arr2[p2])
		{
			arr[index] = arr1[p1];
			p1++;
			index++;
		}

		else
		{
			arr[index] = arr2[p2];
			p2++;
			index++;

			count += (s1 - p1);
		}
	}


	while (p1 < s1)
	{
		arr[index] = arr1[p1];
		index++;
		p1++;

	}

	while (p2 < s2)
	{
		arr[index] = arr2[p2];
		p2++;
		index++;

	}

	return count;
}



int merge(int arr[], int start, int end)
{
	int count = 0;

	if (start < end)
	{
		int half = (start + end) / 2;

		count += merge(arr, start, half);
		count += merge(arr, half + 1, end);

		count += mergeArr(arr, start, half, end);
	}

	return count;
	
}

int mergeSort(int arr[], int size)
{
	int x = merge(arr, 0, size - 1);

	return x;
}