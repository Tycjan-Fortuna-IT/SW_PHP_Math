@echo off
set "sourceDir=C:\Users\tycja\Desktop\Libs\php-sdk\php-8.2.9\vs16\x64\php-src\ext\fastmath\x64\Release_TS"
set "destDir=C:\php\ext"
set "fileName=php_fastmath.dll"

if not exist "%sourceDir%\%fileName%" (
    echo Source file does not exist.
    exit /b
)

if not exist "%destDir%" (
    mkdir "%destDir%"
)

copy /y "%sourceDir%\%fileName%" "%destDir%\%fileName%"

if %errorlevel% equ 0 (
    echo File copied successfully.
) else (
    echo An error occurred during copying.
)
