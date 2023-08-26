--TEST--
Check whether an exception is thrown when a value other than a number is stored.


--EXTENSIONS--
fastmath


--FILE--
<?php
$v = new \SW\Math\Vector2f();

try {
    $v[0] = 'asd';
} catch (\Throwable $e) {
    echo "Exception caught: " . $e->getMessage() . PHP_EOL;
}

try {
    $v[1] = 'asd';
} catch (\Throwable $e) {
    echo "Exception caught: " . $e->getMessage() . PHP_EOL;
}

try {
    $v->x= 'asd';
} catch (\Throwable $e) {
    echo "Exception caught: " . $e->getMessage() . PHP_EOL;
}

try {
    $v->y = 'asd';
} catch (\Throwable $e) {
    echo "Exception caught: " . $e->getMessage() . PHP_EOL;
}
?>


--EXPECTF--
Exception caught: Inside Vector2f only int and float values can be stored. '$vec[int] = float' or '$vec[int] = int']
Exception caught: Inside Vector2f only int and float values can be stored. '$vec[int] = float' or '$vec[int] = int']
Exception caught: Inside Vector2f only int and float values can be stored. '$vec[int] = float' or '$vec[int] = int']
Exception caught: Inside Vector2f only int and float values can be stored. '$vec[int] = float' or '$vec[int] = int']
