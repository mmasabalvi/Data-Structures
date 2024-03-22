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

/*Test Cases: 

////--------------------------------------------------------//
////               Container                                //
////--------------------------------------------------------//
//
///  *********************Test Cases*********************/
//

/*TEST(ContainerTest, InsertInt) {
    Container<int> intContainer(5);
    intContainer.insert(10);
    intContainer.insert(20);

    EXPECT_TRUE(intContainer.search(10));
    EXPECT_TRUE(intContainer.search(20));
    EXPECT_FALSE(intContainer.search(30));
}

TEST(ContainerTest, InsertFloat) {
    Container<float> floatContainer(5);
    floatContainer.insert(3.14f);
    floatContainer.insert(2.718f);

    EXPECT_TRUE(floatContainer.search(3.14f));
    EXPECT_TRUE(floatContainer.search(2.718f));
    EXPECT_FALSE(floatContainer.search(1.0f));
}

TEST(ContainerTest, InsertString) {
    Container<std::string> stringContainer(5);
    stringContainer.insert("Hello");
    stringContainer.insert("World");

    EXPECT_TRUE(stringContainer.search("Hello"));
    EXPECT_TRUE(stringContainer.search("World"));
    EXPECT_FALSE(stringContainer.search("Goodbye"));
}

TEST(ContainerTest, RemoveInt) {
    Container<int> intContainer(5);
    intContainer.insert(10);
    intContainer.insert(20);
    intContainer.remove(10);

    EXPECT_FALSE(intContainer.search(10));
    EXPECT_TRUE(intContainer.search(20));
}

TEST(ContainerTest, RemoveFloat) {
    Container<float> floatContainer(5);
    floatContainer.insert(3.14f);
    floatContainer.insert(2.718f);
    floatContainer.remove(2.718f);

    EXPECT_TRUE(floatContainer.search(3.14f));
    EXPECT_FALSE(floatContainer.search(2.718f));
}

TEST(ContainerTest, RemoveString) {
    Container<std::string> stringContainer(5);
    stringContainer.insert("Hello");
    stringContainer.insert("World");
    stringContainer.remove("Hello");

    EXPECT_FALSE(stringContainer.search("Hello"));
    EXPECT_TRUE(stringContainer.search("World"));
}*/
