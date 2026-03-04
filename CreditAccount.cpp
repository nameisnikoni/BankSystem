class CreditAccount : public Account {
private:
    double creditLimit; // максимальный отрицательный баланс
    double percent; // процент на использованные средства
    int woPercentPeriod; // льготный период (дней)

public:
    CreditAccount(double creditLimit, double percent, int woPercentPeriod):
    creditLimit(creditLimit), percent(percent), woPercentPeriod(woPercentPeriod) {};

    // Геттеры/сеттеры
    double getCreditLimit() const {
        return creditLimit;
    }
    double getPercent() const {
        return percent;
    }
    int getWoPercentPeriod() const {
        return woPercentPeriod;
    }
    double getAvailableCredit() const {
        return creditLimit + std::min(0.0, balance);
    } // creditLimit - min(0, balance)
    double getDebt() const {
        return std::min(0.0, balance);
    } // если баланс отрицательный

    void setCreditLimit(double newLimit) {
        creditLimit = newLimit;
    }
    void setPercent(double newPercent) {
        percent = newPercent;
    }

    // Расчет процентов (обычно daily на отрицательный баланс)
    double calculateInterest() const override;

    // Override с проверкой кредитного лимита
    bool withdraw(double amount, const std::string& description = "") override {
        if (amount > getAvailableCredit()) {
            return false;
        }
        balance = balance - amount;
        return true;
    }

    // Override
    std::string getAccountType() const override {
        return "Credit";
    }

    // Проверки
    bool isInGracePeriod() const {
        return woPercentPeriod > 0;
    } // проверка льготного периода
    double calculatePenalty() const; // штрафы при просрочке
};