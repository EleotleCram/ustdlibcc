
// http://www.nongnu.org/avr-libc/user-manual/malloc.html
long __heap_end = 0x80ffff;

extern "C" void __cxa_pure_virtual(void);

void __cxa_pure_virtual(void) {};

#include <cstdio>
#include <functional>

int main() {
	int i = -1;
	std::function<int(int) > f = [=](int j){return i + j;};
	printf("Answer: %d\n", f(1));

	int i2 = -1;
	std::function<void(int) > f2 = [&](int j) {i2 += j;};
	f2(1);
	printf("Answer: %d\n", i2);

	int i3 = -1;
	std::function<int() > f3 = [&]() {return i3 * i3;};
	printf("Answer: %d\n", f3());

	std::function<int() > f4;
	f4 = f3;

	int i5 = -1;
	std::function<void() > f5 = [&]() {i5 = i3 + i3;};
	f5();
	printf("Answer: %d\n", i5);
}
