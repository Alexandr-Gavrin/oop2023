#include "Ternary/Ternary.h"

namespace Prog2{
    TernarySignal::TernarySignal(char _symbol){
        if (_symbol != '0' && _symbol != '1' && _symbol != 'X'){
            state_ = signal::X;
        }
        else{
            state_ = (signal) _symbol;
        }
    }


    TernarySignal::TernarySignal(int _value){
        switch (_value) {
            case 1:
                state_ = signal::_1;
                break;
            case 0:
                state_ = signal::_0;
                break;
            default:
                state_ = signal::X;
                break;
        }
    }


    TernarySignal TernarySignal:: operator||(const TernarySignal &other) const{
        if (state_ == signal::_1 || other.state_ == signal::_1){
            return {signal::_1};
        }
        else if (state_ == signal::X || other.state_ == signal::X){
            return {signal::X};
        }
        else{
            return {signal::_0};
        }
    }


    TernarySignal TernarySignal::operator&&(const TernarySignal &other) const {
        if (state_ == signal::_0 || other.state_ == signal::_0){
            return {signal::_0};
        }
        else if (state_ == signal::X || other.state_ == signal::X){
            return {signal::X};
        }
        else{
            return {signal::_1};
        }
    }


    TernarySignal TernarySignal::operator!() const {
        if (state_ == signal::_1) return {signal::_0};
        if (state_ == signal::_0) return {signal::_1};
        return {signal::X};
    }




    std::ostream &operator<<(std::ostream &stream, const TernarySignal &signal) {
        stream << static_cast<char>(signal.getSignal());
        return stream;
    }

    bool TernarySignal::operator==(const TernarySignal &other) const {
        return this->state_ == other.state_;
    }

}


