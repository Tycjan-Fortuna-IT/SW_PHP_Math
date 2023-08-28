--TEST--
Check if normalize() method is working as it should.


--EXTENSIONS--
fastmath


--FILE--
<?php
$v1 = new \SW\Math\Vector2f(1.75, 1.2899);
$v2 = new \SW\Math\Vector2f(-2.5, 2.5);
$v3 = new \SW\Math\Vector2f(3.564, -9.22);
$v4 = new \SW\Math\Vector2f(-3.564, -9.22);

$v1->normalize();
$v2->normalize();
$v3->normalize();
$v4->normalize();

var_dump($v1);
var_dump($v2);
var_dump($v3);
var_dump($v4);
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
