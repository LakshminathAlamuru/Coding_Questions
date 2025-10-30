#include<iostream>
using namespace std;


class Computer{
    public:
        void setCPU(string cpu)
        {
            cpu_ = cpu;
        }
        void setMemory(string memory)
        {
            memory_ = memory;
        }
        void display()
        {
            cout << "cpu : "<< cpu_ << "memory :"<< memory_ << endl;
        }
    private:
        std::string cpu_;
        std::string memory_;

};

//Builder class defined here
class ComputerBuilder{
    public:
        virtual void buildCPU(string cpu) = 0;
        virtual void buildMemory(string memory) = 0;
        virtual Computer getResult() = 0;
};


//concrete builder class
class DesktopComputerBuilder: public ComputerBuilder{
    public:
        DesktopComputerBuilder()
        {
            computer_ = Computer();
        }
        void buildCPU(string cpu) override {
            computer_.setCPU(cpu);
        }
        void buildMemory(string memory) override {
            computer_.setMemory(memory);
        }
        Computer getResult() override{
            cout << "Display the result:" << endl;
            return computer_;
        }
    private:
        Computer computer_;
};

int main()
{
    Computer *c = new Computer(); // create the computer product
    DesktopComputerBuilder *desk = new DesktopComputerBuilder();
    desk->buildCPU("intel");
    desk->buildMemory("Micron");
    c->display();
    return 0;
}