class ParkingSystem {
public:
    int slots[3];
    //Time O(1), Space O(1)
    ParkingSystem(int big, int medium, int small) {
        slots[0] = big;
        slots[1] = medium;
        slots[2] = small;
    }
    
    //Time O(1), Space O(1)
    bool addCar(int carType) {
        if(slots[carType-1] == 0){
            return false;
        }
        --slots[carType-1];
        return true;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
