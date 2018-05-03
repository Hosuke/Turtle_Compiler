// test the scope of variables
turtle local_global_var

var y = 100
var x = 100

fun line()
var y = 50
{
	down
	moveto(x, y)
	up
}

{
	up
	down
	moveto(x,y)
	up
	line()
}
