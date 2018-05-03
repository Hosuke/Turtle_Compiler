// call a undefined function in the main program
turtle unresolved_fn

var x = 0
var y = 500

fun add(x) 
{
	x = x + 1
	return x
}

{
	up
	down
	undeclared_fn()
	up
}
