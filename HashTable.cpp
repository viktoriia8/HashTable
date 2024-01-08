#include <iostream>
#include <string>
#include "DynamicArray.h"
#include "List.h"

using namespace std;

template < typename T >
struct hash_table_entry
{
	string key;
	T value;
};
template < typename T >
class hash_table : public DynamicArray < List < hash_table_entry < int >* >* >
{
	public:
	void put(string key, T value) {
		int hash = hash_function(key);
		hash_table_entry < T >* entry = new hash_table_entry < T >();
		entry->key = key;
		entry->value = value;
		if (this->size > this->maxSize * 0.75) {
			this->maxSize *= 2;
			rehash();
		}
		else {
			if (this->array[hash] == NULL) {
			List < hash_table_entry < T >* >* list = new List < hash_table_entry < T >* >();
			list->addBegin(entry);
			this->array[hash] = list;
			//this->size++;
			}else {
				this->array[hash]->addBegin(entry);
			}
			this->size++;
		}

	};
	void rehash(){
		List < hash_table_entry < T >* >** newArray = new List < hash_table_entry < T >* >*[this->maxSize];
		for (int i = 0; i < (this->size) * 0.75; i++) {
			if (this->array[i] != NULL) {
				string key = this->array[i]->head->data->value->key;
				int hash = hash_function(key);
				newArray[hash] = this->array[i];
			}
		}
		delete this->array;
		this->array = newArray;
	}
	string random_key(int length) {
		string key = "";
		for (int i = 0; i < length; i++) {
			char randomChar = 'a' + (rand() % 26);
			key += randomChar;
		}
		return key;
	};// klucze losowe length - znakowe 

	hash_table_entry <T>* get(string key) {};
	void print_stats() {};
	void clear() {};
	// funkcja haszujaca
	int hash_function(string key){
		int q = key.length();
		int N = maxSize;//aktualny maksymalny rozmiar tablicy dynamicznej
		//h(s) = (s0 * 31 ^ (q - 1) + s1 * 31 ^ (q - 2) + ... + sq - 1 * 31 ^ 0) % N // gdzie s0, s1, ..., sq - 1 to kolejne znaki klucza
		int hash = 0;
		for (int i = 0; i < q; i++) {
			hash += key[i] * pow(31, q - i - 1);
		}
		hash = abs(hash % N);	
		return hash;
	}
    
};
// funkcja haszujaca
string random_key(int length) {
	string key = "";
	for (int i = 0; i < length; i++) {
		char randomChar = 'a' + (rand() % 26);
		key += randomChar;
	}
	return key;
};
int main()
{
	const int MAX_ORDER = 7; // maksymalny rzad wielkosci dodawanych danych
	hash_table < int >* ht = new hash_table < int >(); // w tym przykladzie tablica mieszajaca par < string ,int > jako < klucz, wartosc >
		for (int o = 1; o <= MAX_ORDER; o++)
		{
			const int n = pow(10, o); // rozmiar danych 10^o
			// dodawanie do tablicy mieszajacej
			clock_t t1 = clock();
				for (int i = 0; i < n; i++)
					ht -> put(random_key(6), i); // klucze losowe 6 - znakowe , a jako wartosci indeks petli
			clock_t t2 = clock();
			 // wypis na ekran aktualnej postaci tablicy mieszajacej ( skrotowej ) oraz pomiarow czasowych
				// wyszukiwanie w tablicy mieszajacej
				const int m = pow(10, 4);
			int hits = 0;
			t1 = clock();
			for (int i = 0; i < m; i++)
			{
				hash_table_entry < int >* entry = ht -> get(random_key(6)); // wyszukiwanie wg losowego klucza
				if (entry != NULL)
					hits++;
			}
			t2 = clock();
			//...
			 // wypis na ekran pomiarow czasowych i liczby trafien
			// wypis statystyk ( dlugosci list kryjacych sie w tablicy mieszajacej )
				ht -> print_stats();
			ht -> clear(); // czyszczenie tablicy mieszajacej
		}
	delete ht;
	return 0;
}