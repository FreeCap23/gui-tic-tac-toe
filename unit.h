class Unit {
private:
    char state;
public:
    Unit() {
        state = ' ';
    }
    bool changeState(char newState) {
        if (state == ' ') {
            state = newState;
            return true;
        } else {
            return false;
        }
    }
    char getState() {
        return state;
    }
    void reset() {
        state = ' ';
    }
};
