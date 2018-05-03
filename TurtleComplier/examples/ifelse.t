// test backpatching jump address in the conditional statements
turtle ifelse

var x = 1
var y = 2

fun rect(x , y, w, h)
{
  up
  moveto(x, y)
  down
  moveto(x+w, y)
  moveto(x+w, y+h)
  moveto(x, y+h)
  moveto(x, y)
  up
}

{
	if(x < y) 
	{
		rect(200,200,5,5)
	}
	else{
		rect(200,200,200,200)
	}
	
	if(y < x) 
	{
		rect(100,100,200,200)
	}
}
