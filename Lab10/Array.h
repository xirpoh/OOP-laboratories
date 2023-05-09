#include <iostream>
#include <algorithm>
#include <exception>
 
class Compare
{
public:
    virtual ~Compare() {}
    virtual int CompareElements(void* e1, void* e2) = 0;
};
 
template<class T>
class Array;

template<class T>
class ArrayIterator
{
private:
    int Current; // current position in the array
    Array<T>* ArrayPtr; // pointer to the array being iterated over

public:
    // default constructor
    ArrayIterator() : Current(0), ArrayPtr(nullptr) {}

    // constructor that takes a pointer to the array and the current position
    ArrayIterator(Array<T>* arrayPtr, int current) : Current(current), ArrayPtr(arrayPtr) {}

    // prefix increment operator
    ArrayIterator& operator++() {
        ++Current;
        return *this;
    }

    // prefix decrement operator
    ArrayIterator& operator--() {
        --Current;
        return *this;
    }

    // equality operator
    bool operator==(const ArrayIterator<T>& other) const {
        return ArrayPtr == other.ArrayPtr && Current == other.Current;
    }

    // inequality operator
    bool operator!=(const ArrayIterator<T>& other) const {
        return !(*this == other);
    }

    // dereference operator
    T* operator*() {
        return ArrayPtr->operator[](Current);
    }

    // get the element at the current position
    T* GetElement() {
        return &ArrayPtr->operator[](Current);
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
    Array() : List(nullptr), Capacity(0), Size(0) {} // Lista nu e alocata, Capacity si Size = 0

    ~Array() // destructor
    {
        for (int i = 0; i < Capacity; i++)
            List[i] = nullptr;
    }

    Array(int capacity) : List { new T*[capacity] }, Capacity { capacity }, Size { 0 } {} // Lista e alocata cu 'capacity' elemente
                                                                                          
    Array(const Array<T> &otherArray) // constructor de copiere
    {
        for (int i = 0; i < Capacity; i++)
            List[i] = nullptr;
        for (int i = 0; i < Size; i++)
            List[i] = new T(*(otherArray.List[i]));
        Capacity = otherArray.Capacity;
        Size = otherArray.Size;
    }

    T& operator[] (int index) // arunca exceptie daca index este out of range
    {
        try {
            if (index < 0 || index >= Size)
                throw std::out_of_range("Index out of range");
        }
        catch (std::exception& e) {
            std::cout << "Exceptie: " << e.what() << '\n';
            exit(1);
        }

        return *List[index];
    }

    const Array<T>& operator+=(const T &newElem) // adauga un element de tipul T la sfarsitul listei si returneaza this
    {  
        if (Size == Capacity)
        {
            Capacity *= 2;
            T** newList = new T*[Capacity];
            for (int i = 0; i < Size; i++)
            {
                newList[i] = List[i];
            }
            for (int i = Size; i < Capacity; i++)
            {
                newList[i] = nullptr;
            }
            delete[] List;
            List = newList;
        }
        List[Size] = new T(newElem);
        Size++;
        return *this;
    }

    const Array<T>& Insert(int index, const T &newElem) // adauga un element pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
    {
        try {
            if (index < 0 || index > Size)
            {
                throw std::out_of_range("Index out of range");
            }
        }

        catch (std::exception& e) {
            std::cout << "Exceptie: " << e.what() << '\n';
            exit(1);
        }

        if (Size == Capacity)
        {
            Capacity *= 2;
            T** newList = new T*[Capacity];
            for (int i = 0; i < Size; i++)
            {
                newList[i] = List[i];
            }
            for (int i = Size; i < Capacity; i++)
            {
                newList[i] = nullptr;
            }
            delete[] List;
            List = newList;
        }
        // Shift elements to the right to make space for the new element
        for (int i = Size - 1; i >= index; i--) {
            List[i + 1] = List[i];
        }

        // Insert the new element at the specified index
        List[index] = new T(newElem);
        Size++;

        return *this;
    }

    const Array<T>& Insert(int index, const Array<T> otherArray) // adauga o lista pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
    {
        try {
            if (index < 0 || index > Size)
            {
                throw std::out_of_range("Index out of range");
            }
        }

        catch (std::exception& e) {
            std::cout << "Exceptie: " << e.what() << '\n';
            exit(1);
        }

        int otherSize = otherArray.Size;
        if (otherSize == 0) {
            return *this;
        }

        // Resize the list if necessary
        while (Size + otherSize > Capacity) {
            Capacity *= 2;
            T** newList = new T*[Capacity];
            for (int i = 0; i < Size; i++)
            {
                newList[i] = List[i];
            }
            for (int i = Size; i < Capacity; i++)
            {
                newList[i] = nullptr;
            }
            delete[] List;
            List = newList;
        }
        // Shift elements to the right to make space for the new elements
        for (int i = Size - 1; i >= index; i--) {
            List[i + otherSize] = List[i];
        }

        // Copy the elements from the other array into this array
        for (int i = 0; i < otherSize; i++) {
            List[index + i] = new T(otherArray.List[i]);
        }

        Size += otherSize;

        return *this;
    }

    const Array<T>& Delete(int index) // sterge un element de pe pozitia index, returneaza this. Daca index e invalid arunca o exceptie
    {
        try {
            if (index < 0 || index >= Size) {
                throw std::out_of_range("Index out of range.");
            }
        }

        catch (std::exception& e) {
            std::cout << "Exceptie: " << e.what() << '\n';
            exit(1);
        }

        delete List[index];

        for (int i = index; i < Size - 1; i++) {
            List[i] = List[i + 1];
        }

        Size--;
        List[Size] = nullptr;

        return *this;
    }

    bool operator=(const Array<T> &otherArray)
    {
        if (this == &otherArray) {
            return true;
        }

        for (int i = 0; i < Capacity; i++)
            List[i] = nullptr;

        Capacity = otherArray.Capacity;
        Size = otherArray.Size;

        List = new T*[Capacity];

        for (int i = 0; i < Size; i++) {
            List[i] = new T(*otherArray.List[i]);
        }

        return true;
    }

    void Sort() // sorteaza folosind comparatia intre elementele din T
    {
        std::sort(List, List + Size);
    }

    void Sort(int(*compare)(const T&, const T&)) // sorteaza folosind o functie de comparatie
    {
        std::sort(List, List + Size, compare);
    }

    void Sort(Compare *comparator) // sorteaza folosind un obiect de comparatie
    {
        if (Size <= 1) {
            return;
        }

        for (int i = 0; i < Size - 1; i++) {
            for (int j = i + 1; j < Size; j++) {
                if (comparator->CompareElements(List[i], List[j]) > 0) {
                    // Swap the elements at indices i and j
                    T* temp = List[i];
                    List[i] = List[j];
                    List[j] = temp;
                }
            }
        }
    }

    // functii de cautare - returneaza pozitia elementului sau -1 daca nu exista
    int BinarySearch(const T& elem) // cauta un element folosind binary search in Array
    {
        int left = 0;
        int right = Size - 1;

        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (*List[mid] == elem)
                return mid;
            else if (*List[mid] < elem)
                left = mid + 1;
            else
                right = mid - 1;
        }

        return -1; // element not found
    }

    int BinarySearch(const T& elem, int(*compare)(const T&, const T&))//  cauta un element folosind binary search si o functie de comparatie
    {
        int left = 0;
        int right = Size - 1;

        while (left <= right)
        {
            int mid = (left + right) / 2;
            int comp = compare(*List[mid], elem);
            if (comp == 0)
                return mid;
            else if (comp < 0)
                left = mid + 1;
            else
                right = mid - 1;
        }

        return -1; // element not found
    }

    int BinarySearch(const T& elem, Compare *comparator)//  cauta un element folosind binary search si un comparator
    {
        int left = 0;
        int right = Size - 1;

        while (left <= right)
        {
            int mid = (left + right) / 2;
            int comp = comparator->CompareElements(List[mid], &elem);
            if (comp == 0)
                return mid;
            else if (comp < 0)
                left = mid + 1;
            else
                right = mid - 1;
        }

        return -1; // element not found
    }

    int Find(const T& elem) // cauta un element in Array
    {
        for (int i = 0; i < Size; i++)
        {
            if (*List[i] == elem)
                return i; // element found
        }

        return -1; // element not found
    }

    int Find(const T& elem, int(*compare)(const T&, const T&))//  cauta un element folosind o functie de comparatie
    {
        for (int i = 0; i < Size; i++)
        {
            if (compare(*List[i], elem) == 0)
                return i; // element found
        }

        return -1; // element not found
    }

    int Find(const T& elem, Compare *comparator)//  cauta un element folosind un comparator
    {
        for (int i = 0; i < Size; i++)
        {
            if (comparator->CompareElements(List[i], &elem) == 0)
                return i; // element found
        }

        return -1; // element not found
    }

    int GetSize() { return Size; }

    int GetCapacity() { return Capacity; }

    ArrayIterator<T> GetBeginIterator()
    {
        return ArrayIterator<T>(this, 0);
    }

    ArrayIterator<T> GetEndIterator()
    {
        return ArrayIterator<T>(this, Size);
    }
};
