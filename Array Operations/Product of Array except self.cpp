void Func()
{
  int size;

	//cout << "TASK-2: " << endl << endl;

	cout << "Enter the size of the Array:" << endl;
	cin >> size;

	int* arr2 = new int[size];

	cout << "Input the Array: " << endl;

	for (int i = 0; i < size; i++)
	{
		cin >> arr2[i];
	}

	int prod = 1;

	for (int i = 0; i < size; i++)
	{
		prod *= arr2[i];
	}

	for (int i = 0; i < size; i++)
	{
		arr2[i] = prod / arr2[i];
	}

	cout << "Array Result: " << endl;

	for (int i = 0; i < size; i++)
	{
		cout << arr2[i] << " ";
	}

	cout << endl << endl;

  delete[] arr2;
}
