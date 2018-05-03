// draw a rectangle to the screen
turtle rectangle

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
	rect(200,200,50,50)
}
