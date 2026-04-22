class Pot {
public:
    Pot() : totalAmount(0) {}

    void addToPot(int amount) {
        totalAmount += amount;
    }

    int getTotalAmount() const {
        return totalAmount;
    }

    void zero()
    {
        totalAmount = 0; 
    }

    int playersInPot[6];  // Array to hold side pots for multiple all-ins
private:
	int totalAmount;  // Total amount in the pot
	
};
