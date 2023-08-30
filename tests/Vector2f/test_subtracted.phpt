--TEST--
Check if Vector2f::subtracted(Vector2f, Vector2f) method is working as it should.


--EXTENSIONS--
fastmath


--FILE--
<?php
var_dump(\SW\Math\Vector2f::subtracted(new \SW\Math\Vector2f(1.75, 1.2899), new \SW\Math\Vector2f(-2.5, 2.5)));
var_dump(\SW\Math\Vector2f::subtracted(new \SW\Math\Vector2f(1.75, 1.2899), new \SW\Math\Vector2f(3.564, -9.22)));
var_dump(\SW\Math\Vector2f::subtracted(new \SW\Math\Vector2f(1.75, 1.2899), new \SW\Math\Vector2f(-3.564, -9.22)));

?>

--EXPECTF--
object(SW\Math\Vector2f)#3 (2) {
  ["x"]=>
  float(4.25)
  ["y"]=>
  float(-1.2101)
}
object(SW\Math\Vector2f)#1 (2) {
  ["x"]=>
  float(-1.814)
  ["y"]=>
  float(10.5099)
}
object(SW\Math\Vector2f)#3 (2) {
  ["x"]=>
  float(5.314)
  ["y"]=>
  float(10.5099)
}
