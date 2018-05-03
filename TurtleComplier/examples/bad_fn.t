// mismatch between the number
// of parameters in the definition of a function and the number of arguments in a call
turtle bad_fn_1

fun line(x, y)
{
	moveto(x, y)
}

{
	line(100);
}
