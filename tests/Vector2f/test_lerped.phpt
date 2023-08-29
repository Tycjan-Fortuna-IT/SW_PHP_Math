--TEST--
Check if Vector2f::lerped(Vector2f, Vector2f, float) method is working as it should.


--EXTENSIONS--
fastmath


--FILE--
<?php
var_dump(\SW\Math\Vector2f::lerped(new \SW\Math\Vector2f(1.75, 1.2899), new \SW\Math\Vector2f(0.0, 0.0), 0.5));
var_dump(\SW\Math\Vector2f::lerped(new \SW\Math\Vector2f(-2.5, 2.5), new \SW\Math\Vector2f(0.0, 0.0), 0.5));
var_dump(\SW\Math\Vector2f::lerped(new \SW\Math\Vector2f(3.564, -9.22), new \SW\Math\Vector2f(0.0, 0.0), 0.5));
var_dump(\SW\Math\Vector2f::lerped(new \SW\Math\Vector2f(-3.564, -9.22), new \SW\Math\Vector2f(0.0, 0.0), 0.5));
?>


--EXPECTF--
object(SW\Math\Vector2f)#%d (2) {
  ["x"]=>
  float(0.875)
  ["y"]=>
  float(0.64495)
}
object(SW\Math\Vector2f)#%d (2) {
  ["x"]=>
  float(-1.25)
  ["y"]=>
  float(1.25)
}
object(SW\Math\Vector2f)#%d (2) {
  ["x"]=>
  float(1.782)
  ["y"]=>
  float(-4.61)
}
object(SW\Math\Vector2f)#%d (2) {
  ["x"]=>
  float(-1.782)
  ["y"]=>
  float(-4.61)
}
