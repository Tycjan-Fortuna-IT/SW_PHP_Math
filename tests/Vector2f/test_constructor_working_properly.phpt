--TEST--
Check if Vector2f class constructor is working as it should.
--EXTENSIONS--
fastmath
--FILE--
<?php
$vector = new \SW\Math\Vector2f(1.34, -9.23);

var_dump($vector);
?>
--EXPECT--
object(SW\Math\Vector2f)#1 (2) {
  ["x"]=>
  float(1.34)
  ["y"]=>
  float(-9.23)
}
