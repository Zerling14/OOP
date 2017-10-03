#include <iostream>
#include <string>
using namespace std;

template <class T>
class List {
private:
	struct Unit {
		T value;
		Unit *next;
		Unit *prev;
	};
	Unit *GetN(int index)
	{
		if (index < 0 || index >= size) {
			cout << "index " << index << " not found" << endl;
			error = true;
			return NULL;
		}
		Unit *tmp = head;
		int i = 0;
		while (tmp && i < index) {
			tmp = tmp->next;
			i++;
		}
		return tmp;
	}
	Unit *head;
	Unit *tail;
	int size;
	bool error;
public:
	List()
	{
		error = false;
		head = NULL;
		tail = NULL;
		size = 0;
	}
	List(T obj)
	{
		Unit *tmp = new Unit{obj, NULL, NULL};
		error = false;
		head = tmp;
		tail = tmp;
		size = 1;
	}
	void Print()
	{
		Unit *tmp = head;
		while (tmp) {
			cout << tmp->value << " ";
			tmp = tmp->next;
		}
		cout << endl;
	}
	bool GetError()
	{
		return error;
	}
	int GetSize()
	{
		return size;
	}
	void PushFront(T obj)
	{
		Unit *tmp = new Unit{obj, head, NULL};
		if (head) {
			head->prev = tmp;
		}
		head = tmp;
		if (!tail) {
			tail = tmp;
		}
		size++;
	}

	T PopFront()
	{
		if (!head) {
			cout << "list is empty" << endl;
		}
		Unit *prev;
		T obj;
		prev = head;
		head = head->next;
		if (head) {
			head->prev = NULL;
		}
		if (prev == tail) {
			tail = NULL;
		}
		obj = prev->value;
		delete prev;

		size--;
		return obj;
	}

	void PushBack(T obj)
	{
		Unit *tmp = new Unit{obj, NULL, tail};
		if (tail) {
			tail->next = tmp;
		}
		tail = tmp;
		if (!head) {
			head = tmp;
		}
		size++;
	}
	T PopBack()
	{
		if (!tail) {
			cout << "list is empty" << endl;
		}
		Unit *next;
		T obj;
		next = tail;
		tail = tail->prev;
		if (tail) {
			tail->next = NULL;
		}
		if (next == head) {
			head = NULL;
		}
		obj = next->value;
		delete next;

		size--;
		return obj;
	}
	T Get(int index)
	{
		error = false;
		Unit *tmp = GetN(index);
		if (!tmp) {
			return 0;
		}
		return tmp->value;
	}
	void Add(T obj, int index = -1)
	{
		if (index == -1) {
			PushFront(obj);
		} else {
			Unit *tmp = GetN(index);
			if (!tmp) {
				return;
			}
			Unit *tmp_obj = new Unit{obj, tmp->next, tmp};
			if (tmp->next) {
				tmp->next->prev = tmp_obj;
			}
			tmp->next = tmp_obj;

			if (!tmp->prev) {
				head = tmp;
			}
			if (!tmp->next) {
				tail = tmp;
			}
			size++;
		}
	}
	void Move(int before, int after)
	{
		error = false;
		T tmp = Delete(before);
		Add(tmp, after);
	}
	T Delete(int index)
	{
		Unit *tmp = GetN(index);
		if (!tmp) {
			return 0;
		}
		if (tmp->prev) {
			tmp->prev->next = tmp->next;
		}
		if (tmp->next) {
			tmp->next->prev = tmp->prev;
		}
		if (!tmp->prev) {
			head = tmp->next;
		}
		if (!tmp->next) {
			tail = tmp->prev;
		}
		T value = tmp->value;
		delete tmp;

		size--;
		return value;
	}
};

int main()
{
	List<int> list;
	list.PushFront(1);
	list.PushFront(2);
	list.PushFront(3);
	list.PushFront(4);
	list.PushFront(5);
	list.PushFront(6);
	list.Move(0, 10);
	list.Print();
	system("pause");
}