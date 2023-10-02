#ifndef TERNARYARRAY_H
#define TERNARYARRAY_H

#include <iostream>
#include <string>
#include "Ternary/Ternary.h"



namespace Prog3{
    /**
    * @brief Класс, представляющий Троичный Массив.
    */
    class TernaryArray{
    private:
        size_t _size = 0; /**< Размер Троичного Массива. */
        size_t _countX = 0;  /**< Количество элементов со значением 'X'. */
        Prog2::TernarySignal *_arr = nullptr;  /**< Указатель на массив объектов Троичного Сигнала. */

    public:
        /**
         * @brief Конструктор по умолчанию.
         */
        explicit TernaryArray() = default;
        /**
         * @brief Конструктор, инициализирующий Троичный Массив заданным размером.
         * @param size Размер Троичного Массива.
         */
        explicit TernaryArray(size_t);

        /**
        * @brief Конструктор, инициализирующий Троичный Массив из строки.
        * @param str Строковое представление Троичного Массива.
        */
        explicit TernaryArray(const std::string&);
        /**
        * @brief Деструктор.
        */
        ~TernaryArray();
        /**
        * @brief Получить размер Троичного Массива.
        * @return Размер Троичного Массива.
        */
        [[nodiscard]] size_t getSize() const {return _size;}

        /**
         * @brief Конструктор копирования.
         * @param ob Объект Троичного Массива для копирования.
         */
        TernaryArray(const TernaryArray& ob);

        /**
       * @brief Оператор присваивания для копирования.
       * @param ob Объект Троичного Массива для присваивания.
       * @return Ссылка на присвоенный Троичный Массив.
       */
        TernaryArray& operator= (const TernaryArray&);

        /**
      * @brief Конструктор перемещения.
      * @param ob Объект Троичного Массива для перемещения.
      */
        TernaryArray(TernaryArray &&) noexcept;

        /**
       * @brief Оператор присваивания для перемещения.
       * @param ob Объект Троичного Массива для перемещения.
       * @return Ссылка на присвоенный Троичный Массив.
       */
        TernaryArray& operator= (TernaryArray &&ob) noexcept;

        /**
       * @brief Оператор индексации для константных объектов.
       * @param index Индекс для доступа.
       * @return Константная ссылка на объект Троичного Сигнала по указанному индексу.
       */
        const Prog2::TernarySignal& operator[](int) const;

        /**
       * @brief Оператор индексации для не константных объектов.
       * @param index Индекс для доступа.
       * @return Ссылка на объект Троичного Сигнала по указанному индексу.
       */
        Prog2::TernarySignal& operator[](int);

        /**
       * @brief Логический оператор ИЛИ для объединения Троичных Массивов.
       * @param ob Троичный Массив для операции ИЛИ.
       * @return Результат операции ИЛИ.
       */
        TernaryArray operator|(const TernaryArray &) const;

        /**
        * @brief Логический оператор И для объединения Троичных Массивов.
        * @param ob Троичный Массив для операции И.
        * @return Результат операции И.
        */
        TernaryArray operator&(const TernaryArray &) const;

        /**
       * @brief Логический оператор НЕ для инверсии Троичного Массива.
       * @return Результат операции НЕ.
       */
        TernaryArray operator~() const;

        /**
       * @brief Оператор сравнения для сравнения двух Троичных Массивов.
       * @param ob Троичный Массив для сравнения.
       * @return True, если Троичные Массивы равны, false в противном случае.
       */
        bool operator==(const TernaryArray &) const;

                /**
            * @brief Перегрузка оператора вывода для вывода Троичного Массива в поток.
            * @param os Поток вывода.
            * @param ob Троичный Массив для вывода.
            * @return Поток вывода.
            */

        friend std::ostream &operator<<(std::ostream &, const TernaryArray&);

        /**
        * @brief Перегрузка оператора ввода для ввода Троичного Массива из потока.
        * @param is Поток ввода.
        * @param ob Троичный Массив для ввода.
        * @return Поток ввода.
        */
        friend std::istream &operator>>(std::istream &, TernaryArray&);

        /**
         * @brief Проверить, содержит ли Троичный Массив элементы со значением 'X'.
        * @return True, если нет элементов со значением 'X', false в противном случае.
         */

        [[nodiscard]] bool checkUndefined() const{ return this->_countX == 0; }
        // std::ostream &print(std::ostream &) const;

    };



}

#endif //TERNARYARRAY_H