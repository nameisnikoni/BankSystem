class DebitAccount : public Account {
private:
    double percent; // процент на остаток (например, 0.05 = 5%)

public:
    DebitAccount(double percent): percent(percent) {};


    // Геттеры/сеттеры
    double getPercent() const {
        return percent;
    }
    void setPercent(double newPercent) {
        if (newPercent <= 0) {
            return;
        }
        percent = newPercent;
    }

    // Расчет процентов (обычно monthly)
    double calculateInterest() const override {
        return pow(1 + percent, 1.0/12.0) - 1;
    }

    // Override
    std::string getAccountType() const override {
        return "Debit";
    }

    // Специфические методы
    double calculateMonthlyProfit() const {
        return percent*Account::balance;
    } // сколько начислят процентов в месяц
};