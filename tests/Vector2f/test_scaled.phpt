--TEST--
Check if Vector2f::scaled(Vector2f) method is working as it should.


--EXTENSIONS--
fastmath


--FILE--
<?php

var_dump(\SW\Math\Vector2f::scaled(new \SW\Math\Vector2f(1.75, 1.2899), 2.5));
var_dump(\SW\Math\Vector2f::scaled(new \SW\Math\Vector2f(-2.5, 2.5), -2.5));
var_dump(\SW\Math\Vector2f::scaled(new \SW\Math\Vector2f(3.564, -9.22), 2.5));
var_dump(\SW\Math\Vector2f::scaled(new \SW\Math\Vector2f(-3.564, -9.22), -2.5));
?>


--EXPECTF--
object(SW\Math\Vector2f)#%d (2) {
  ["x"]=>
  float(4.375)
  ["y"]=>
  float(3.22475%d)
}
object(SW\Math\Vector2f)#%d (2) {
  ["x"]=>
  float(6.25)
  ["y"]=>
  float(-6.25)
}
object(SW\Math\Vector2f)#%d (2) {
  ["x"]=>
  float(8.91)
  ["y"]=>
  float(-23.05)
}
object(SW\Math\Vector2f)#%d (2) {
  ["x"]=>
  float(8.91)
  ["y"]=>
  float(23.05)
}
