#include <mutex>
#include <functional>

using namespace std;

class DiningPhilosophers {
private:
    std::mutex forks[5];

public:
    DiningPhilosophers() {

    }

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {

        int left_fork = philosopher;
        int right_fork = (philosopher + 1) % 5;


        if (philosopher % 2 == 0) {
            forks[left_fork].lock();
            forks[right_fork].lock();
            
            pickLeftFork();
            pickRightFork();
        } else {
            forks[right_fork].lock();
            forks[left_fork].lock();
            
            pickRightFork();
            pickLeftFork();
        }

        eat();

        putLeftFork();
        putRightFork();
        
        forks[left_fork].unlock();
        forks[right_fork].unlock();
    }
};