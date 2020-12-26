/*

	[[noreturn]] functions don't return itself. so code flow does not go back to caller.

*/

[[noreturn]] void function()
{
	// do something
}

void g()
{
	function();
  
	std::cout << "No! That's impossible" << std::endl;
	// this never happen
}