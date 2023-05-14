#pragma once
#include <iostream>

class Compare

{

public:
	virtual int CompareElements(void* e1, void* e2) = 0;
};
class out_of_range : public std::exception
{
	virtual const char* what() const throw()
	{
		return "Indexul este inafara domeniului!";
	}

};
class size_out_of_range : public std::exception
{
	virtual const char* what() const throw()
	{
		return "Dimensiunea este mai mare decat capacitatea!";
	}

};

template<class T>

class ArrayIterator

{

private:
	T* array;
	int size;
	int Current; // mai adaugati si alte date si functii necesare pentru iterator

public:

	ArrayIterator()
	{
		size = 0;
		Current = 0;
	}
	ArrayIterator& operator ++ () {
		if (Current >= size) throw out_of_range();
		Current++;
	
	}
	ArrayIterator& operator -- () {
		if (Current <= 0) throw out_of_range();
		Current--;
	}
	bool operator= (ArrayIterator<T>& other) {
		return(this->array == other.array &&
			this->Current == other.Current &&
			this->size == other.size);
	}
	bool operator!=(ArrayIterator<T>&) {
		return (this->array != other.array ||
			this->Current != other.Current ||
			this->size != other.size);

	}
	T* GetElement() {
		return array[Current];
	}

};

template<class T>

class Array

{

private:

	T** List; // lista cu pointeri la obiecte de tipul T*
	int Capacity; // dimensiunea listei de pointeri
	int Size; // cate elemente sunt in lista

public:

	Array() {
		Capacity = 0;
		Size = 0;
	} // Lista nu e alocata, Capacity si Size = 0
	~Array() {
		for (int i = 0; i < size; i++)
			delete List[i];
		delete[] List;
	} // destructor
	Array(int capacity) {
		List = new T * [capacity];
		Capacity = capacity;
		Size = 0;
	} // Lista e alocata cu 'capacity' elemente
	Array(const Array<T>& otherArray) {
		List = new T * [otherArray.Capacity];
		List = otherArray.List;
		Capacity = otherArray.Capacity;
		Size = otherArray.Size;
	} // constructor de copiere
	T& operator[] (int index) {
		if (index < 0 || index >= size)
			throw out_of_range();
		return List[index];
	} // arunca exceptie daca index este out of range
	const Array<T>& operator+=(const T& newElem) {
		if (Size >= Capacity) throw size_out_of_range();
		List[Size] = new T(newElem);
		Size++;
		return this;

	} // adauga un element de tipul T la sfarsitul listei si returneaza this
	const Array<T>& Insert(int index, const T& newElem) {
		if (index < 0 || index > size)
			throw out_of_range();
		List[index] = newElem;
		if (index == size)
			size++;
		return this;
	} // adauga un element pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
	const Array<T>& Insert(int index, const Array<T> otherArray); // adauga o lista pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
	const Array<T>& Delete(int index); // sterge un element de pe pozitia index, returneaza this. Daca index e invalid arunca o exceptie
	bool operator=(const Array<T>& otherArray);
	void Sort(); // sorteaza folosind comparatia intre elementele din T
	void Sort(int(*compare)(const T&, const T&)); // sorteaza folosind o functie de comparatie
	void Sort(Compare* comparator); // sorteaza folosind un obiect de comparatie
	// functii de cautare - returneaza pozitia elementului sau -1 daca nu exista
	int BinarySearch(const T& elem); // cauta un element folosind binary search in Array
	int BinarySearch(const T& elem, int(*compare)(const T&, const T&));//  cauta un element folosind binary search si o functie de comparatie
	int BinarySearch(const T& elem, Compare* comparator);//  cauta un element folosind binary search si un comparator
	int Find(const T& elem); // cauta un element in Array
	int Find(const T& elem, int(*compare)(const T&, const T&));//  cauta un element folosind o functie de comparatie
	int Find(const T& elem, Compare* comparator);//  cauta un element folosind un comparator
	int GetSize();
	int GetCapacity();
	ArrayIterator<T> GetBeginIterator();
	ArrayIterator<T> GetEndIterator();

};
