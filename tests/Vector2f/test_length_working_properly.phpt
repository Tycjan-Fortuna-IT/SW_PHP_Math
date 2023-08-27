--TEST--
Check if length() method is working as it should.


--EXTENSIONS--
fastmath


--FILE--
<?php
$v1 = new \SW\Math\Vector2f(1, 1);
$v2 = new \SW\Math\Vector2f(2, 2);
$v3 = new \SW\Math\Vector2f(3.564, -9.22);

$e = 0.0000000000000001;

$check = function (float $actual, float $expected, string $vector) {
    if ($actual - $expected > 0.0000000000000001) {
        echo "Length of $vector is incorrect." . PHP_EOL;
    }
};

$check($v1->length(), 1.4142135623730951, 'Vector2f(1, 1)');
$check($v2->length(), 2.8284271247461903, 'Vector2f(2, 2)');
$check($v3->length(), 9.9999999999999982, 'Vector2f(3.564, -9.22)');
?>


--EXPECT--
