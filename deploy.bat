@ECHO OFF
SET "sourceDir=C:\Users\tycja\Desktop\Libs\php-sdk\php-8.2.9\vs16\x64\php-src\ext\fastmath\x64\Release_TS"
SET "destDir=C:\php\ext"
SET "fileName=php_fastmath.dll"

IF NOT EXIST "%sourceDir%\%fileName%" (
    ECHO Source file does not exist.
    EXIT /b
)

IF NOT EXIST "%destDir%" (
    MKDIR "%destDir%"
)

COPY /y "%sourceDir%\%fileName%" "%destDir%\%fileName%"

IF %errorlevel% equ 0 (
    ECHO File copied successfully.
) ELSE (
    ECHO An error occurred during copying.
)
