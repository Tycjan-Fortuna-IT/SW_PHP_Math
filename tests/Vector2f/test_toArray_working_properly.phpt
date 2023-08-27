--TEST--
Check if Vector2f class toArray() method is working as it should.


--EXTENSIONS--
fastmath


--FILE--
<?php
$v1 = new \SW\Math\Vector2f(1, 1);
$v2 = new \SW\Math\Vector2f(-1, 1.2);
$v3 = new \SW\Math\Vector2f(3.564, -9.22);

var_dump($v1->toArray());
var_dump($v2->toArray());
var_dump($v3->toArray());
?>


--EXPECT--
array(2) {
  [0]=>
  float(1)
  [1]=>
  float(1)
}
array(2) {
  [0]=>
  float(-1)
  [1]=>
  float(1.2)
}
array(2) {
  [0]=>
  float(3.564)
  [1]=>
  float(-9.22)
}
