--TEST--
Check if Vector2f::negated(Vector2f) method is working as it should.


--EXTENSIONS--
fastmath


--FILE--
<?php
var_dump(\SW\Math\Vector2f::negated(new \SW\Math\Vector2f(1.75, 1.2899)));
var_dump(\SW\Math\Vector2f::negated(new \SW\Math\Vector2f(-2.5, 2.5)));
var_dump(\SW\Math\Vector2f::negated(new \SW\Math\Vector2f(3.564, -9.22)));
var_dump(\SW\Math\Vector2f::negated(new \SW\Math\Vector2f(-3.564, -9.22)));
?>


--EXPECTF--
object(SW\Math\Vector2f)#%d (2) {
  ["x"]=>
  float(-1.75)
  ["y"]=>
  float(-1.2899)
}
object(SW\Math\Vector2f)#%d (2) {
  ["x"]=>
  float(2.5)
  ["y"]=>
  float(-2.5)
}
object(SW\Math\Vector2f)#%d (2) {
  ["x"]=>
  float(-3.564)
  ["y"]=>
  float(9.22)
}
object(SW\Math\Vector2f)#%d (2) {
  ["x"]=>
  float(3.564)
  ["y"]=>
  float(9.22)
}
