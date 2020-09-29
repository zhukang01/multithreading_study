#include <iostream>
#include <thread>
#include <time.h>
#include <mutex>

int increase(int* p, int times)
{
	for (int i = 0; i < times; ++i)
	{
		++*p;
	}
	return 0;
}

int main()
{
	time_t start = clock();//timer start

	int num = 0;

	std::thread thread1(increase, &num, 10000);
	std::thread thread2([&]() {
		for (int i = 0; i < 10000; ++i)
		{
			++num;
		}
	});

	thread1.join();
	thread2.join();

	std::cout << num << std::endl;





	time_t end = clock();//timer stop
	std::cout << "Time: " << (end - start) << " ms." << std::endl;
	system("pause");
	return 0;
}
