// test a while loop
turtle while

var i = 0

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
	while(i < 10) 
	{
		rect(100, 100, i * (10 + i * 2), i * (10 + i * 2))
		i = i + 1		
	}
}
