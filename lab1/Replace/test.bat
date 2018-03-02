rem %1 - �������� ������� ��������� ��������� ������ bat-����� (����� �� ����)
rem %~1 - �������� ������� ��������� ��������� ������ bat-����� � ��������� ����������� ������� (���� ��� ����)

rem ���������� PROGRAM ����� ������� ������ �������� ��������� ������ ����������� � �������
set PROGRAM="%~1"

rem ��� ������� ��� ���������� ��������� ��������� ��� ��������
%PROGRAM% > nul
if NOT ERRORLEVEL 1 goto err

rem ��� ������� � ����������� ����������� ��������� ������� ��� ��������
%PROGRAM% fox.txt %TEMP%\fox.txt dog cat
if ERRORLEVEL 1 goto err
fc.exe %TEMP%\fox.txt fox.txt >nul
if ERRORLEVEL 1 goto err

rem ��� ������� � ����������� ����������� ��������� ������� ��� ��������
%PROGRAM% fox-dog-with-cat.txt %TEMP%\fox-dog-with-cat.txt fox cat
if ERRORLEVEL 1 goto err
fc.exe %TEMP%\fox-dog-with-cat.txt fox-dog-with-cat.txt
if ERRORLEVEL 1 goto err

echo OK
exit 0

:err
echo Program testing failed
exit 1