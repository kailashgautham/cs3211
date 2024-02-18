/*
 * in shared ptr the reference count is thread safe, but the object IS NOT.
 */
 
#include<cstdio>
#include<memory>
#include<thread>
 int main()
{
    std::shared_ptr<atomic_int> ptr;

    auto reader = std::thread([](std::shared_ptr<int>& ptr) {
        for(int i = 0; i < 100; i++)
            printf("%d ", *ptr);
        printf("\n");
    }, ptr);

    auto writer = std::thread([](std::shared_ptr<int>& ptr) {
        for(int i = 0; i < 100; i++)
            *ptr = i;
    }, ptr);

    reader.join();
    writer.join();
}

//the issue here is that reader is trying to read ptr while writer is changing ptr at the same time
