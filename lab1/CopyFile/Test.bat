rem %1 - значение первого аргумента командной строки bat-файла (какой он есть)
rem %~1 - значение первого аргумента командной строки bat-файла с удалением обрамляющих кавычек (если они были)

rem Переменная PROGRAM будет хранить первый аргумент командной строки заключённый в кавычки
set PROGRAM="%~1"

rem При запуске без параметров ожидается ненулевой код возврата
rem %PROGRAM% > nul
rem if NOT ERRORLEVEL 1

%PROGRAM% test-data/copying-text.txt %TEMP%/copied-text.txt
if ERRORLEVEL 1 goto err

fc.exe %TEMP%\copied-text.txt test-data/copying-text.txt
if ERRORLEVEL 1 goto err

echo Program testing succeeded
exit 0

:err
echo Program testing failed
exit 1