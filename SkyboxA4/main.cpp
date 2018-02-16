#include "SwapHandler.h"

int main()
{
	SwapHandler sh;
	sh.run();
	system("pause");
	return 0;
}


/*
	1. int number = 10;
	this variable is stored on the functions stack frame; the integer takes up 4 bytes of contiguous memory to store the number it holds. Each of the 4 bytes represents a number
	between 0-255, which together are used to represent the integer as a whole. Each of the 4 bytes also has it's own memory address.

	2. passing a variable in by reference means you do not make a local copy of the variable; anything that happens to this variable in the function is a permanent change to the actual
	variable itself (where ever it may be stored in memory); this is analogous to dereferencing a pointer - you are changing the actual value at the memory address.

	passing a variable by value means that a local copy of the variable is made; any changes made are made to the copy, and the copy is destroyed once the function returns as the variable
	will be out of scope - the original value will have no changes made to it.

	5. Call Stack explanation (to the best of my understanding);
	function "A" calls function "B"; function B stack frame is created:
	- parameters for function B is pushed onto the stack
	- the local variables of function B are pushed onto the stack
	- the return address of function A is pushed onto the stack
	- space for return value is pushed onto the stack

	when B is finished it's operations, function B's stack frame is dismantled:
	- local variables are popped off the stack
	- parameters are popped off the stack
	- return address is popped off the stack
	- return value popped off the stack

	and control is given back to function A (which has the return value)

	I didn't include assembly level instructions such as incrementing and decrementing stack frame and base pointers, and the movement of data in registers, or
	an explanation on how the stack grows (directionally), as I'm not sure if that's what is needed for this question; it also seems to be architecture dependant.
	If we have time, it would be nice to have a more in depth discussion about this topic to solidify my understanding on the order things are
	pushed and popped off the stack, and who (which function) is responsible for each push and pop of a stack frame.

*/