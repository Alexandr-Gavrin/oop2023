#include "TernaryArray/TernaryArray.h"
#include "Ternary/Ternary.h"
#include <iostream>


using namespace Prog2;


namespace Prog3{

    size_t checkNotNullChar(const std::string &str){
        size_t _counter = 0;
        for (char i: str){
            if (i != ' ') _counter++;
        }
        return _counter;
    }

    TernaryArray::TernaryArray(size_t _count):  _size{_count},
                                                _countX(_count),
                                                _arr(new TernarySignal[_count]){}



    TernaryArray::TernaryArray(const std::string& _string) : TernaryArray(checkNotNullChar(_string)) {
        size_t index = 0;
        for (char value: _string){
            if (value != ' '){
                _arr[index] = TernarySignal(value);
                index++;
            }
        }
    }


    TernaryArray::~TernaryArray() {
        delete[] _arr;
    }

    const Prog2::TernarySignal& TernaryArray::operator[](int _index) const {
        if (_index < 0 || _index >= _size)
            throw std::out_of_range("ошибка индексации");
        return _arr[_index];
    }


    Prog2::TernarySignal& TernaryArray::operator[](int _index){
        if (_index < 0 || _index >= _size)
            throw std::out_of_range("ошибка индексации");
        return _arr[_index];
    }

    TernaryArray TernaryArray::operator|(const TernaryArray &rhs) const {
        TernaryArray result((int)std::max(this->_size, rhs._size));
        for (int i = 0; i < result._size; i++){
            if (i >= rhs._size){
                result[i] = this->_arr[i];
            }
            else if (i >= this->_size){
                result[i] = rhs._arr[i];
            }
            else{
                result[i] = this->_arr[i] || rhs._arr[i];
            }
            if (result[i].getSignal() == signal::X){
                result._countX++;
            }
        }
        return result;
    }


    TernaryArray TernaryArray::operator&(const TernaryArray &rhs) const {
        TernaryArray result((int)std::max(this->_size, rhs._size));
        for (int i = 0; i < result._size; i++){
            if (i >= rhs._size){
                result[i] = this->_arr[i];
            }
            else if (i >= this->_size){
                result[i] = rhs._arr[i];
            }
            else{
                result[i] = this->_arr[i] && rhs._arr[i];
            }
            if (result[i].getSignal() == signal::X){
                result._countX++;
            }
        }
        return result;}

    TernaryArray TernaryArray::operator~() const {
        TernaryArray result((int)this->_size);
        for (size_t i = 0; i < this->_size; i++)
            result[(int)i] = !this->_arr[i];
        return result;}

    bool TernaryArray::operator==(const TernaryArray &rhs) const {
        if (this->_size != rhs._size || this->_countX != rhs._countX) return false;
        for (size_t i = 0; i < this->_size; i++){
            if (this->_arr[i].getSignal() != rhs._arr[i].getSignal()) return false;
        }
        return true;
    }


    std::ostream &operator<<(std::ostream & os, const TernaryArray &tr) {
        for (size_t i = 0; i < tr._size; i++){
            os << tr._arr[i];
        }
        return os;
    }


    std::istream &operator>>(std::istream & is, TernaryArray &tr) {
        std::string str;
        is >> str;
        tr = TernaryArray(str);
        return is;
    }

    TernaryArray::TernaryArray(const TernaryArray &ob): _size(ob._size), _countX(ob._countX), _arr(new TernarySignal[_size]) {
        std::copy(ob._arr, ob._arr + _size, _arr);
    }

    TernaryArray &TernaryArray::operator=(const TernaryArray &ob) {
        if (this != &ob){
                auto tmp = new TernarySignal[_size];
                std::copy(ob._arr, ob._arr + ob._size, tmp);
                delete[] _arr;
                _size = ob._size;
                _arr = tmp;

        }
        return *this;
    }

    TernaryArray::TernaryArray(TernaryArray &&ob) noexcept: _size(ob._size), _countX(ob._countX), _arr(ob._arr){
        ob._size = 0;
        ob._arr = nullptr;
        ob._countX = 0;

    }

    TernaryArray &TernaryArray::operator=(TernaryArray &&ob) noexcept {

        std::swap(ob._size, _size);
        std::swap(ob._countX, _countX);
        std::swap(ob._arr, _arr);

        return *this;
    }



}