#include <mutex>

class TrafficLight {
public:
    TrafficLight() {
        road = 1;
    }

    void carArrived(
        int carId,                   // ID of the car
        int roadId,                  // ID of the road the car travels on. Can be 1 (road A) or 2 (road B)
        int direction,               // Direction of the car
        function<void()> turnGreen,  // Use turnGreen() to turn light to green on current road
        function<void()> crossCar    // Use crossCar() to make car cross the intersection
    ) {
        if(roadId == road)
        {
            std::lock_guard<std::mutex> lk(m);
            crossCar();
        }
        else
        {
            std::lock_guard<std::mutex> lk(m);
            road = roadId;
            turnGreen();
            crossCar();
        }
    }

private:
    std::mutex m;
    int road;
};
