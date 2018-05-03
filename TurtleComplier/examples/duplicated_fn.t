// a function declared twice in the same scope
turtle duplicated_fn
var x = 10
var y = 100

fun jump(x, y) 
{
	moveto(x , y)
}

fun jump(x, y) 
{
	moveto(x, y)
}

{
	jump(x, y)
}