int firstUniqChar(string s)
{
    Queue<char> object;

    int i = 0;

    while (s[i] != '\0')
    {
        object.enqueue(s[i]);
        i++;
    }

    Node<char>* temp = object.front;

    int index = 0;

    while (temp != NULL)
    {
        char c = temp->data;

        Node<char>* temp2 = object.front;

        bool found = false;

        while (temp2 != NULL)
        {
            if (temp2 != temp && c == temp2->data)
            {
                found = true;
                break;
            }

            temp2 = temp2->next;
        }

        if (!found)
        {
            return index;
        }

        index++;
        temp = temp->next;
    }

    return -1; 
}
