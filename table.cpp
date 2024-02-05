#include <iostream>

template<class T>
class Table {
    T count_rows_;
    T count_colums_;
    T* arr;
public:
    Table(T count_rows, T count_colums): count_rows_(count_rows), count_colums_(count_colums){
        arr = new T [count_rows * count_colums];
    }

    ~Table() {

        for (int i = 0; i < count_rows_; i++)
        {
            delete[] arr[i]; 
        }
        delete[] arr;
    }

    void const size() {
       std::cout << count_rows_ << 'x' << count_colums_;
    }

    T& operator()(T index_rows, T index_cols) {
        return arr[index_rows][index_cols];
    }

    /*const T& operator [](T index) const{
        
    }
    T& operator [](T index) {
       return arr[index][index];
    }*/
};

int main()
{
    auto mass = Table<int>(3,5);
    mass(0,0) = 3;
    std::cout << mass(0, 0);
    mass.size();

}