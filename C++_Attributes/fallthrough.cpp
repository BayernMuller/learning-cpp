/*

	[[fallthrough]] make compiler give warning when the code executes more than one cases at once in switch-case without [[fallthrough]]

*/


int main()
{
	switch (n)
	{
	case 1:
	case 2:
		g();
		[[fallthrough]];
		// no warning
	case 3:
		h();
		// compiler warns
	case 4:
		i();
		// ill-¡©formed
		[[fallthrough]];
	}
}
