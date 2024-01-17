#include <iostream>
#include <thread>
#include <chrono>
#include <atomic>
#include <vector>

#define MAX_CLIENTS 5
std::atomic<int> countClients;

void client()
{
    while (countClients != MAX_CLIENTS)
    {
        countClients++;
        std::cout << "(Queue) Clients in queue: " << countClients << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));

    }
}

void oper()
{
    while (countClients != 0)
    {
        countClients--;
        std::cout << "(oper) Clients in queue: " << countClients << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }
}

int main()
{
    std::vector<std::thread> myThreads;
    std::thread t1(client);
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::thread t2(oper);
    t1.join();
    t2.join();
}