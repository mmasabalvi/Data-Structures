void ArrayRotate()
{
  int size;

	cout << "TASK-1: " << endl << endl;

	cout << "Enter the size of the Array:" << endl;
	cin >> size;

	int* arr1 = new int[size];

	cout << "Input the Array: " << endl;

	for (int i = 0; i < size; i++)
	{
		cin >> arr1[i];
	}

	int k;
	cout << "Input k: " << endl;
	cin >> k;


	for (int i = 0; i < k; i++)
	{
		int x = arr1[size - 1];

		for (int j = size - 1; j > 0; j--)
		{
			arr1[j] = arr1[j - 1];
		}

		arr1[0] = x;
	}

	cout << "Array after shifting: " << endl;

	for (int i = 0; i < size; i++)
	{
		cout << arr1[i] << " ";
	}

	cout << endl << endl;

  delete[] arr1;

}
