#ifndef OOP2_TERNARNY_H
#define OOP2_TERNARNY_H
#include <iostream>


namespace Prog2{
    /**
   * @brief Перечисление для представления троичных сигналов.
   */
    enum class signal {
        _0 = '0',
        _1 = '1',
        X = 'X'
    };
    /**
     * @brief Класс, представляющий троичный сигнал.
     */

    class TernarySignal{
    private:
        signal state_; /**< Состояние троичного сигнала. */
    public:
        // getter
        /**
        * @brief Получить текущее состояние троичного сигнала.
        * @return Текущее состояние троичного сигнала.
        */
        [[nodiscard]] signal getSignal() const {return state_;};

        //setter
        /**
         * @brief Установить новое состояние троичного сигнала.
         * @param newSignal Новое состояние троичного сигнала.
         * @return Ссылка на объект троичного сигнала.
         */
        TernarySignal& setSignal(signal newSignal) {state_ = newSignal; return *this;};

        //init
        /**
      * @brief Конструктор по умолчанию, инициализирующий сигнал значением "X".
      */
        TernarySignal(): state_(signal::X) {}

        /**
       * @brief Конструктор, принимающий символьное представление сигнала.
       * @param _symbol Символ, представляющий сигнал.
       */
        explicit TernarySignal(char _symbol);

        /**
        * @brief Конструктор, принимающий целочисленное значение.
        * @param _value Значение сигнала.
        */
        explicit TernarySignal(int _value);

        /**
        * @brief Конструктор, принимающий значение из перечисления signal.
        * @param _signal Значение сигнала из перечисления.
        */
        TernarySignal(signal _signal) : state_(_signal) {};


        /**
         * @brief Логический оператор "ИЛИ" для троичных сигналов.
         * @param other Другой троичный сигнал.
         * @return Результат логической операции "ИЛИ".
         */
        TernarySignal operator||(const TernarySignal &other) const;

        /**
      * @brief Логический оператор "И" для троичных сигналов.
      * @param other Другой троичный сигнал.
      * @return Результат логической операции "И".
      */
        TernarySignal operator&&(const TernarySignal &other) const;

        /**
         * @brief Логический оператор "НЕ" для троичного сигнала.
         * @return Результат логической операции "НЕ".
         */
        TernarySignal operator!() const;

        /**
    * @brief Оператор сравнения для троичных сигналов.
    * @param other Другой троичный сигнал.
    * @return True, если троичные сигналы равны, false в противном случае.
    */
        bool operator==(const TernarySignal &other) const;

        /**
        * @brief Перегрузка оператора вывода для вывода троичного сигнала в поток.
        * @param os Поток вывода.
        * @param ob Троичный сигнал для вывода.
        * @return Поток вывода.
        */
        friend std::ostream &operator<<(std::ostream &, const TernarySignal &);
    };


}


#endif //OOP2_TERNARNY_H