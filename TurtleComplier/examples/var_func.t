// test var declarations in function declarations
turtle var_func

fun move_to_upper_left()
var x = 0
var y = 500
{
	moveto(x, y)
}

fun move_to_center()
var x = 250
var y = 250
{
	moveto(x, y)
}

{
	up
	down
	move_to_upper_left()
	move_to_center()
	up
}
