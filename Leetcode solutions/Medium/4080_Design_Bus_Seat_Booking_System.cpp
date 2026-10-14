class BusBooking {
public:
    BusBooking(int n) {
        
    }
    
    void toggle(string seat) {
        char column=seat[0];
        int row=stoi(seat.substr(1));
        if(auto it=seats.find(seat);it!=seats.end()) {
            time-=it->second;
            seats.erase(it);
            seatCount--;
        } else {
            seatCount++;
            time++;
            if(column=='B'||column=='C')
                seats[seat]=1;
            else if(column=='A') {
                if(seats.count("B"+seat.substr(1)))
                    seats[seat]=3,time+=2;
                else
                    seats[seat]=1;
            } else {
                if(seats.count("C"+seat.substr(1)))
                    seats[seat]=3,time+=2;
                else
                    seats[seat]=1;
            }
        }
    }
    
    int getTotalTime() {
        return time;
    }
    
    int getMinTime() {
        return seatCount;
    }
    unordered_map<string,int> seats;
    int seatCount=0,time=0;
};

/**
 * Your BusBooking object will be instantiated and called as such:
 * BusBooking* obj = new BusBooking(n);
 * obj->toggle(seat);
 * int param_2 = obj->getTotalTime();
 * int param_3 = obj->getMinTime();
 */