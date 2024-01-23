void DiagonalTraverse()
{
  int r;
	int c;

	//cout << "TASK-3: " << endl << endl;

	cout << "Enter the rows of the Array:" << endl;
	cin >> r;

	cout << "Enter the cols of the Array:" << endl;
	cin >> c;

	int** arr1 = new int*[r];
	
	for (int i = 0; i < r; i++)
	{
		arr1[i] = new int[c];
	}

	cout << "Input the Array: " << endl;

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> arr1[i][j];
		}
	}

	cout << "The matrix: " << endl;

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cout << arr1[i][j] << " ";
		}

		cout << endl;
	}

	////
	int size = r * c;

	int* tr = new int [size];

	bool up = 1;                        //will control direction

	int row=0, col = 0;

	int index = 0;

	while (row < r && col < c)
	{
		if (up == 1)
		{
			while (row > 0 && col < c - 1)
			{
				tr[index++] = arr1[row][col];
				row--;
				col++;
			}

			tr[index++] = arr1[row][col];

			if (col == c - 1)
			{
				row++;
			}

			else
			{
				col++;
			}
		
		}

		else
		{
			while (row < r-1 && col > 0)
			{
				tr[index++] = arr1[row][col];
				row++;
				col--;
			}

			tr[index++] = arr1[row][col];

			if (row == r - 1)
			{
				col++;
			}

			else
			{
				row++;
			}
		}


		up = !up;
	}

	cout << endl << "Matrix after diagonal traverse: " << endl;

	for (int i = 0;i < size; i++)
	{
		cout << tr[i] << " ";
	}

	cout << endl;

  for (int i = 0; i < r; i++)
	{
		delete[] arr1[i];
	}

	delete[] arr1;
	
	delete[] tr;




}
