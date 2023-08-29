--TEST--
Check if Vector2f::normalized(Vector2f) method is working as it should.


--EXTENSIONS--
fastmath


--FILE--
<?php

var_dump(\SW\Math\Vector2f::normalized(new \SW\Math\Vector2f(1.75, 1.2899)));
var_dump(\SW\Math\Vector2f::normalized(new \SW\Math\Vector2f(-2.5, 2.5)));
var_dump(\SW\Math\Vector2f::normalized(new \SW\Math\Vector2f(3.564, -9.22)));
var_dump(\SW\Math\Vector2f::normalized(new \SW\Math\Vector2f(-3.564, -9.22)));
?>


--EXPECTF--
object(SW\Math\Vector2f)#%d (2) {
  ["x"]=>
  float(0.804%d)
  ["y"]=>
  float(0.593%d)
}
object(SW\Math\Vector2f)#%d (2) {
  ["x"]=>
  float(-0.707%d)
  ["y"]=>
  float(0.707%d)
}
object(SW\Math\Vector2f)#%d (2) {
  ["x"]=>
  float(0.360%d)
  ["y"]=>
  float(-0.932%d)
}
object(SW\Math\Vector2f)#%d (2) {
  ["x"]=>
  float(-0.360%d)
  ["y"]=>
  float(-0.932%d)
}
