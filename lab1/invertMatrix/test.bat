
rem ���������� PROGRAM ����� ������� ������ �������� ��������� ������ ����������� � �������
set PROGRAM="%~1"

%PROGRAM% > nul
if NOT ERRORLEVEL 1 goto err
echo "Matrix.txt "
%PROGRAM% matrix.txt
if ERRORLEVEL 1 goto err
echo "empty.txt "
%PROGRAM% empty.txt
if NOT ERRORLEVEL 1 goto err

%PROGRAM% not-exist.txt
if NOT ERRORLEVEL 1 goto err

%PROGRAM% zeroDet.txt
if NOT ERRORLEVEL 1 goto err


echo Program testing succeeded
exit 0

:err
echo Program testing failed
exit 1