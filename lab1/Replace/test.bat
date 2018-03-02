rem %1 - �������� ������� ��������� ��������� ������ bat-����� (����� �� ����)
rem %~1 - �������� ������� ��������� ��������� ������ bat-����� � ��������� ����������� ������� (���� ��� ����)

rem ���������� PROGRAM ����� ������� ������ �������� ��������� ������ ����������� � �������
set PROGRAM="%~1"

rem ��� ������� ��� ���������� ��������� ��������� ��� ��������
%PROGRAM% > nul
if NOT ERRORLEVEL 1 goto err

rem ������ �� ������������ ���������
%PROGRAM% "replace-lion.txt" "%TEMP%\replace-lion.txt" lion cat
if ERRORLEVEL 1 goto err
fc.exe "%TEMP%\replace-lion.txt" "replace-lion.txt"
if ERRORLEVEL 1 goto err

rem ������ ������������ ���������
rem %PROGRAM% fox.txt %TEMP%\fox.txt dog cat
rem if ERRORLEVEL 1 goto err
rem fc.exe  %TEMP%\fox.txt fox.txt
rem if ERRORLEVEL 1 goto err

rem ��� ������� � ����������� ����������� ��������� ������� ��� ��������
rem %PROGRAM% fox-dog-with-cat.txt %TEMP%\fox-dog-with-cat.txt fox cat
rem if ERRORLEVEL 1 goto err
rem fc.exe  %TEMP%\fox-dog-with-cat.txt fox-dog-with-cat.txt
rem if ERRORLEVEL 1 goto err

rem ����������� ������� �����
%PROGRAM% empty.txt %TEMP%\empty.txt fox cat
if ERRORLEVEL 1 goto err
fc.exe %TEMP%\empty.txt empty.txt
if ERRORLEVEL 1 goto err

%PROGRAM% fox-witout-param.txt %TEMP%\fox-witout-param.txt fox cat
if ERRORLEVEL 1 goto err
fc.exe  %TEMP%\fox-witout-param.txt fox-witout-param.txt
if ERRORLEVEL 1 goto err

echo OK
exit 0

:err
echo Program testing failed
exit 1