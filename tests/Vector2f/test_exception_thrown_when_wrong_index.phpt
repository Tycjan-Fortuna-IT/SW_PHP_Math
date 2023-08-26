--TEST--
Check whether an exception is thrown when trying to access wrong offset.


--EXTENSIONS--
fastmath


--FILE--
<?php
$v = new \SW\Math\Vector2f();

try {
    $v[2] = 1;
} catch (\Throwable $e) {
    echo "Exception caught: " . $e->getMessage() . PHP_EOL;
}

try {
    $v[-1] = 1;
} catch (\Throwable $e) {
    echo "Exception caught: " . $e->getMessage() . PHP_EOL;
}

try {
    $v['c'] = 1;
} catch (\Throwable $e) {
    echo "Exception caught: " . $e->getMessage();
}
?>


--EXPECTF--
Exception caught: Vector2f offset must be a int '$vec[int]', 0 or 1!
Exception caught: Vector2f offset must be a int '$vec[int]', 0 or 1!
Exception caught: Vector2f offset must be a int '$vec[int]', 0 or 1!
