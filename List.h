#include<iostream>
#include<type_traits>
#include<string>
template <typename T>
class Data
{
public:
	T value;
	Data() {
		if (std::is_arithmetic<T>::value)
		{
			this->value = static_cast<T>(rand());
		}
		else {
			char randomChar = 'a' + (rand() % 26);
			this->value = static_cast<T>(randomChar);
		}
	};
	Data(T _value) {
		this->value = _value;
	};
	bool operator==(const Data<T>& other) const {
		return value == other.value;
	}
};

template <typename T1>
class Node
{
public:
	Node<T1>* prev;
	Node<T1>* next;
	Data<T1>* data;

	Node() {
		next = nullptr;
		prev = nullptr;
		data = new Data<T1>();
	};
};


using namespace std;

template <typename T>
class List
{
public:
	Node<T>* head;
	Node<T>* tail;
	int all;
	void addBegin(T data) {
		Node<T>* newNode = new Node<T>();
		newNode->data->value = data;
		newNode->next = head;

		if (all == 0) {
			tail = newNode;
		}
		else {
			head->prev = newNode;
		}
		head = newNode;
		newNode = nullptr;
		all++;
	};

	void addEnd() {
		Node<T>* newNode = new Node<T>();
		newNode->prev = head;

		if (all == 0) {
			tail = newNode;
		}
		else {
			tail->next = newNode;
		}
		tail = newNode;
		newNode = nullptr;
		all++;
	};

	void showAll() {
		Node<T>* myHead = head;
		while (myHead != nullptr) {
			std::cout << myHead->data->value << endl;
			myHead = myHead->next;
		}
		cout << all << endl;
		cout << "-------------------\n";
	};

	void deleteBegin() {
		if (all == 0) {
			cout << "Lista jest pusta.\n";
		}
		else {
			Node<T>* myHead = head->next;
			all--;
			delete head;
			head = myHead;
			if (head)
				head->prev = nullptr;
		}
	};

	void deleteEnd() {
		if (all == 0) {
			cout << "Lista jest pusta.\n";
		}
		else {
			Node<T>* myTail = tail->prev;
			delete tail;
			tail = myTail;
			tail->next = nullptr;
			all--;
		}
	};

	T findNodeNr(int i) {
		if (all == 0) {
			cout << "Lista jest pusta\n";
			return 0;
		}
		Node<T>* myHead = head;
		for (int j = 0; j < all; j++) {
			if (j == i)
			{
				return myHead->data->value;
			}
			myHead = myHead->next;
		}
		cout << "Element jest poza zakresem.\n";
		return false;
	};

	void newValueNr(int i, T newData) {
		if (all == 0) {
			cout << "Lista jest pusta\n";
			exit;
		}
		Node<T>* myHead = head;
		for (int j = 0; j < all; j++) {
			if (j == i)
			{
				myHead->data->value = newData;
			}
			myHead = myHead->next;
		}
		cout << "Element jest poza zakresem.\n";
		exit;
	};

	Node<T>* findNodeWithData(T _value) {
		if (all == 0) {
			cout << "Lista jest pusta\n";
			return 0;
		}
		Node<T>* myHead = head;
		for (int j = 0; j < all; j++) {

			if (_value == myHead->data->value)
			{
				return myHead;
			}
			myHead = myHead->next;
		}
		cout << "Element o podanej wartoœci nie istnieje.\n";
		return NULL;

	};
	
	bool deleteNodeWithData(T _value) {
		Node<T>* myNode = findNodeWithData(_value);
		if (myNode) {
			if (!myNode->prev) {
				deleteBegin();
				return true;
			}
			else if (!myNode->next) {
				deleteEnd();
				return true;
			}
			else {
				myNode->next->prev = myNode->prev;
				myNode->prev->next = myNode->next;
				delete myNode;
				all--;
				return true;
			}
		}
		else {
			return false;
		}
	};
	
	void deleteList() {
		while (all) {
			deleteBegin();
		}
	};
	List() {
		this->head = nullptr;
		this->tail = nullptr;
		this->all = 0;
	}
};

//template <typename T>
//class Data
//{
//public:
//	T value;
//	Data() {
//		if (std::is_arithmetic<T>::value)
//		{
//			this->value = static_cast<T>(rand());
//		}
//		else {
//			char randomChar = 'a' + (rand() % 26);
//			this->value = static_cast<T>(randomChar);
//		}
//	};
//	bool operator==(const Data<T>& other) const {
//		return value == other.value;
//	}
//};
//
//template <typename T1>
//class Node
//{
//public:
//	Node<T1>* prev;
//	Node<T1>* next;
//	Data<T1>* data;
//
//	Node() {
//		next = nullptr;
//		prev = nullptr;
//		data = new Data<T1>();
//	};
//};
//
