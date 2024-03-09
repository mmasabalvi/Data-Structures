#include<iostream>
using namespace std;
#include<string>
template<class T>
class List
{
public:
	T* values;
	int capacity = 3;
	int counter = 0;

	List(int capacity)
	{
		this->capacity = capacity;
		values = new T[capacity];
	}

	bool insert(T item)
	{
		if (!isFull())
		{
			values[counter] = item;
			counter++;
			return true;
		}

		else
		{
			return false;
		}
		
	}

	bool insertAt(T item, int index)
	{
		if (!isFull())
		{
			for (int i = capacity - 1; i > index; i--)
			{
				values[i] = values[i - 1];
			}

			values[index] = item;
			counter++;

			return true;
		}

		return false;
	}

	bool insertAfter(T itemTobeInserted, T item)
	{
		int index = search(item);

		if (index != -1)
		{
			int indexTobeInserted = index + 1;

			if (indexTobeInserted < capacity)
			{
				insertAt(itemTobeInserted, indexTobeInserted);
				return true;
			}
		}

		return false;
		
	}

	bool insertBefore(T itemTobeInserted, T item)
	{
		int index = search(item);
		cout << index << endl;

		if (index != -1)
		{
			int indexTobeInserted = index;

			cout << indexTobeInserted << endl;

			if (indexTobeInserted >= 0)
			{
				insertAt(itemTobeInserted, indexTobeInserted);
				return true;
			}
		}

		return false;
	
	}


	bool isEmpty()
	{
		if (counter == 0)
		{
			return true;
		}

		else
		{
			return false;
		}
	}

	bool isFull()
	{
		if (counter == capacity)
		{
			return true;
		}

		else
		{
			return false;
		}
	}

	bool remove(T item)
	{
		int index = search(item);

		if (index != -1)
		{	
			for (int j = index; j < capacity - 1; j++)
			{
				values[j] = values[j + 1];
			}

			counter--;	

			return true;
		}

		return false;
	}

	bool removeBefore(T item)
	{
		int index = search(item);

		if (index != -1)
		{
			int indexTobeDeleted = index - 1;

			if (indexTobeDeleted > 0)
			{
				T item = values[indexTobeDeleted];
				remove(item);
				return true;
			}
		}

		return false;
	}


	bool removeAfter(T item)
	{
		int index = search(item);
		

		if (index != -1)
		{
			int indexTobeDeleted = index + 1;

			if (indexTobeDeleted < capacity-1)
			{
				T item = values[indexTobeDeleted];
				//cout << "333" << endl;
				remove(item);
				return true;
			}
		}

		return false;
	}

	int search(T item)
	{
		int index = -1;

		for (int i = 0; i < capacity; i++)
		{
			if (values[i] == item)
			{
				index = i;
			}
		}

		return index;
	}

	void print()
	{
		for (int i = 0; i < counter; i++)
		{
			cout << values[i] << " ";
		}

		cout << endl;
	}

	bool operator==(List& L)
	{
		bool check = true;

		if (this->capacity == L.capacity)
		{
			for (int i = 0; i < this->capacity; i++)
			{
				if (values[i] != L.values[i])
				{
					check = false;
				}
			}
			return check;

		}

		else
		{
			return false;
		}
	}

	void reverse()
	{
		T* temp = new T[capacity];

		for (int i = capacity - 1, j = 0; i >= 0; i--, j++)
		{
			temp[j] = values[i];
		}


		for (int i = 0; i < capacity; i++)
		{
			values[i] = temp[i];
		}
	}
};


class Song
{
public:
	string title;
	string artist;
	int duration;
	int counter = 0;

	Song()
	{
		title = "";
		artist = "";
		duration = 0;
	}

	Song(int d)
	{
		duration = d;
	}

	Song(string t, string a, int d)
	{
		title = t;
		artist = a;
		d = duration;
	}


	int getsongcount()
	{
		return counter;
	}

};

class Playlist
{
public:
	string name;
	List<Song> songs;
	

	Playlist(string p) : name(p), songs(100) {}


	void addSong(const Song& song)
	{
		songs.insert(song);
	}

	void removeSong(const string& title)
	{
		int index = -1;

		for (int i = 0; i < songs.counter; i++)
		{
			if (songs.values[i].title == title) {
				index = i;
				break;  
			}
		}

		if (index != -1) 
		{
			for (int i = index; i < songs.counter-1; i++)
			{
				songs.values[i] = songs.values[i + 1];
			}

			songs.counter--;
		}
	}

	void DisplaySongs()
	{
		for (int i = 0; i < songs.capacity; i++)
		{
			//cout << songs.values[i] 
		}
	}

	int getsongcount()
	{
		return songs.counter;
	}

};
