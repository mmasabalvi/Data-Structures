template<typename T>
class Container
{
private:
	T* values;
	int capacity;
	int counter;

public:
	Container(int capacity)
	{
		counter = 0;
		this->capacity = capacity;
		values = new T[capacity];
	}

	bool isFull()
	{
		if (counter >= capacity-1)
		{
			return true;
		}

		else
		{
			return false;
		}
	}

	void insert(T value)
	{
		if (isFull()==false)
		{
			values[counter] = value;
			counter++;
		}
	}

	bool search(T value)
	{
		for (int i = 0; i < counter; i++)
		{
			if (value == values[i])
			{
				return true;
			}
		}

		return false;
		
	}

	void remove(T value)
	{
		if (search(value) == true)
		{
			for (int i = 0; i < counter; i++)
			{
				if (values[i] == value)
				{
					for (int j = i; j < counter - 1; j++)
					{
						values[j] = values[j + 1];
					}

					--counter;
					break;

				}
			}

		}	
	}

};
