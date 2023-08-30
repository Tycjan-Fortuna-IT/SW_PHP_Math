--TEST--
Check if Vector2f::multiplied(Vector2f, Vector2f) method is working as it should.


--EXTENSIONS--
fastmath


--FILE--
<?php
var_dump(\SW\Math\Vector2f::multiplied(new \SW\Math\Vector2f(1.75, 1.2899), new \SW\Math\Vector2f(-2.5, 2.5)));
var_dump(\SW\Math\Vector2f::multiplied(new \SW\Math\Vector2f(1.75, 1.2899), new \SW\Math\Vector2f(3.564, -9.22)));
var_dump(\SW\Math\Vector2f::multiplied(new \SW\Math\Vector2f(1.75, 1.2899), new \SW\Math\Vector2f(-3.564, -9.22)));

?>

--EXPECTF--
object(SW\Math\Vector2f)#%d (2) {
  ["x"]=>
  float(-4.375)
  ["y"]=>
  float(3.224%d)
}
object(SW\Math\Vector2f)#%d (2) {
  ["x"]=>
  float(6.237)
  ["y"]=>
  float(-11.892%d)
}
object(SW\Math\Vector2f)#%d (2) {
  ["x"]=>
  float(-6.237)
  ["y"]=>
  float(-11.892%d)
}
