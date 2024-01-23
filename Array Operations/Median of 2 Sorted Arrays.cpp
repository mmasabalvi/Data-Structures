int main()
{
  int size1;

	cout << "TASK-4: " << endl << endl;

	cout << "Enter the size of the 1st Array:" << endl;
	cin >> size1;

	float* nums1 = new float[size1];

	cout << "Input the Array: " << endl;

	for (int i = 0; i < size1; i++)
	{
		cin >> nums1[i];
	}

	//

	int size2;

	cout << "Enter the size of the 2nd Array:" << endl;
	cin >> size2;

	float* nums2 = new float[size2];

	cout << "Input the Array: " << endl;

	for (int i = 0; i < size2; i++)
	{
		cin >> nums2[i];
	}


	int size3 = size1 + size2;

	float* merged = new float[size3];

	for (int i = 0; i < size1; i++)
	{
		merged[i] = nums1[i];
	}

	for (int i = size1, j = 0; i < size3; i++, j++)
	{
		merged[i] = nums2[j];
	}

	for (int i = 0; i < size3; i++)
	{
		for (int j = 0; j < size3 - i - 1; j++)
		{
			if (merged[j] > merged[j + 1])
			{
				float temp = merged[j];
				merged[j] = merged[j + 1];
				merged[j + 1] = temp;
			}
		}
	}

	cout << "Array after merge and sort: " << endl;

	for (int i = 0; i < size3; i++)
	{
		cout << merged[i] << " ";
	}

	cout << endl << endl;

	float median;

	if (size3 % 2 == 0)
	{
		int x1 = (size3 / 2);
		int x2 = (size3 / 2) + 1;

		median = (merged[x1-1] + merged[x2-1]) / 2;
	}

	else
	{
		int x = (size3 / 2);

		median = merged[x];
	}

	cout << "The Median is: " << median << endl;

  delete[] nums1;
  delete[] nums2;
  delete[] merged;
}
