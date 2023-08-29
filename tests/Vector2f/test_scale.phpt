--TEST--
Check if scale() method is working as it should.


--EXTENSIONS--
fastmath


--FILE--
<?php
$v1 = new \SW\Math\Vector2f(1.75, 1.2899);
$v2 = new \SW\Math\Vector2f(-2.5, 2.5);
$v3 = new \SW\Math\Vector2f(3.564, -9.22);
$v4 = new \SW\Math\Vector2f(-3.564, -9.22);

$v1->scale(2.5);
$v2->scale(-2.5);
$v3->scale(2.5);
$v4->scale(-2.5);

var_dump($v1);
var_dump($v2);
var_dump($v3);
var_dump($v4);
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
