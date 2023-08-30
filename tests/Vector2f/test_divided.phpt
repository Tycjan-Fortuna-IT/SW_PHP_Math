--TEST--
Check if Vector2f::divided(Vector2f, Vector2f) method is working as it should.


--EXTENSIONS--
fastmath


--FILE--
<?php
var_dump(\SW\Math\Vector2f::divided(new \SW\Math\Vector2f(1.75, 1.2899), new \SW\Math\Vector2f(-2.5, 2.5)));

?>

--EXPECTF--
object(SW\Math\Vector2f)#%d (2) {
  ["x"]=>
  float(-0.7)
  ["y"]=>
  float(0.515%d)
}
