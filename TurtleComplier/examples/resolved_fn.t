// call a function defined later 
turtle resolved_fn

fun line(x, y)
{
	moveto(add_100(x), add_100(y))
}

fun add_100(x)
{
	return x + 100
}

{
	line(100, 200);
}
