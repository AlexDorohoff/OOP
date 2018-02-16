rem %1 - �������� ������� ��������� ��������� ������ bat-����� (����� �� ����)
rem %~1 - �������� ������� ��������� ��������� ������ bat-����� � ��������� ����������� ������� (���� ��� ����)

rem ���������� PROGRAM ����� ������� ������ �������� ��������� ������ ����������� � �������
set PROGRAM="%~1"

rem ��� ������� ��� ���������� ��������� ��������� ��� ��������
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