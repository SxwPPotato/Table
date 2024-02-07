#include <iostream>

template<class T>
class Table {
    size_t count_rows_;
    size_t count_colums_;
    T** arr;
public:
    Table(T count_rows, T count_colums): count_rows_(count_rows), count_colums_(count_colums){
        arr = new T* [count_rows];
        for (int i = 0; i < count_rows; i++)
        {
            arr[i] = new T[count_colums];
        }

        //arr = new T[count_rows_ * count_colums_];
    }

    Table(const Table &other) { // конструктор копирования
        
        for (int i = 0; i < count_rows_; i++)
        {
            delete[] arr[i];
        }
        delete[] arr;
        
        this->count_rows_ = other.count_rows_;
        this->count_colums_ = other.count_colums_;

        this->arr = new T * [other.count_rows_];
        for (int i = 0; i < other.count_rows_; i++)
        {
            this->arr[i] = new T[other.count_colums_];
        }

        for (int j = 0; j < other.count_rows_; j++)
        {
            for (int i = 0; i < other.count_colums_; i++)
            {
                this->arr[j][i] = other.arr[j][i];
            }
        }
    }

    ~Table() { // деструктор

        for (int i = 0; i < count_rows_; i++)
        {
            delete[] arr[i]; 
        }
        delete[] arr;
    }

    Table& operator=(const Table& other) //оператор присваивания
    {
        for (int i = 0; i < count_rows_; i++)
        {
            delete[] arr[i];
        }
        delete[] arr;

        this->count_rows_ = other.count_rows_;
        this->count_colums_ = other.count_colums_;

        this->arr = new T * [other.count_rows_];
        for (int i = 0; i < other.count_rows_; i++)
        {
            this->arr[i] = new T[other.count_colums_];
        }

        for (int j = 0; j < other.count_rows_; j++)
        {
            for (int i = 0; i < other.count_colums_; i++)
            {
                this->arr[j][i] = other.arr[j][i];
            }
        }

        return *this;
    }

    size_t size() {
       return count_rows_ * count_colums_;
    }

    T* operator[] (int index) { // для присваивания 

        return *arr + index * count_colums_;
    }
    const T* operator[] (int index) const { // для доступа

        return *arr + index * count_colums_;
    }
    

};

int main()
{
    auto mass = Table<int>(3,5);
    mass[0][0] = 5;
    mass[0][1] = 3;
    std::cout << mass[0][0] << "\n";
    std::cout << mass[0][1] << "\n";
    std:: cout << "Size() = " << mass.size();

}