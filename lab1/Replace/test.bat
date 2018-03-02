rem %1 - значение первого аргумента командной строки bat-файла (какой он есть)
rem %~1 - значение первого аргумента командной строки bat-файла с удалением обрамляющих кавычек (если они были)

rem Переменная PROGRAM будет хранить первый аргумент командной строки заключённый в кавычки
set PROGRAM="%~1"

rem При запуске без параметров ожидается ненулевой код возврата
%PROGRAM% > nul
if NOT ERRORLEVEL 1 goto err

rem При запуске с правильными параметрами ожидается нулевой код возврата
%PROGRAM% fox.txt %TEMP%\fox.txt dog cat
if ERRORLEVEL 1 goto err
fc.exe %TEMP%\fox.txt fox.txt >nul
if ERRORLEVEL 1 goto err

rem При запуске с правильными параметрами ожидается нулевой код возврата
%PROGRAM% fox-dog-with-cat.txt %TEMP%\fox-dog-with-cat.txt fox cat
if ERRORLEVEL 1 goto err
fc.exe %TEMP%\fox-dog-with-cat.txt fox-dog-with-cat.txt
if ERRORLEVEL 1 goto err

echo OK
exit 0

:err
echo Program testing failed
exit 1