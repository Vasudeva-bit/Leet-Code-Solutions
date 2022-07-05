class ParkingSystem {
public:
    int bg, med, sm;
    ParkingSystem(int big, int medium, int small) {
        bg = big;
        med = medium;
        sm = small;
    }
    
    bool addCar(int carType) {
        if(carType == 1) {
            if(bg > 0) {
                bg--;
                return true;
            }
        }
        if(carType == 2) {
            if(med > 0) {
                med--;
                return true;
            }
        }
        if(carType == 3) {
            if(sm > 0) {
                sm--;
                return true;
            }
        }
        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */