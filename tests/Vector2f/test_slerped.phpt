--TEST--
Check if Vector2f::slerped(Vector2f, Vector2f, float) method is working as it should.


--EXTENSIONS--
fastmath


--FILE--
<?php
var_dump(\SW\Math\Vector2f::slerped(new \SW\Math\Vector2f(1.75, 1.2899), new \SW\Math\Vector2f(0.0, 0.0), 0.5));
var_dump(\SW\Math\Vector2f::slerped(new \SW\Math\Vector2f(-2.5, 2.5), new \SW\Math\Vector2f(0.0, 0.0), 0.5));
var_dump(\SW\Math\Vector2f::slerped(new \SW\Math\Vector2f(3.564, -9.22), new \SW\Math\Vector2f(0.0, 0.0), 0.5));
var_dump(\SW\Math\Vector2f::slerped(new \SW\Math\Vector2f(-3.564, -9.22), new \SW\Math\Vector2f(0.0, 0.0), 0.5));
?>


--EXPECTF--
object(SW\Math\Vector2f)#%d (2) {
  ["x"]=>
  float(1.237%d)
  ["y"]=>
  float(0.912%d)
}
object(SW\Math\Vector2f)#%d (2) {
  ["x"]=>
  float(-1.767%d)
  ["y"]=>
  float(1.767%d)
}
object(SW\Math\Vector2f)#%d (2) {
  ["x"]=>
  float(2.520%d)
  ["y"]=>
  float(-6.519%d)
}
object(SW\Math\Vector2f)#%d (2) {
  ["x"]=>
  float(-2.520%d)
  ["y"]=>
  float(-6.519%d)
}
