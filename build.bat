@echo off
echo CHECKING DEPENDENCEIES.
rm --version >nul 2>nul
if not %ERRORLEVEL% == 0 (
    echo FAIL rm WAS NOT FOUND.
    goto ERR
)
echo 1 > tmp
rm tmp
if not %ERRORLEVEL% == 0 (
    echo FAIL rm WAS NOT WORK AS EXPECTED.
    goto ERR
)
if exist tmp (
    echo FAIL rm WAS NOT WORK AS EXPECTED.
    goto ERR
)
echo OK rm IS WORKING AS EXPECTED.
python --version >nul 2>nul
if not %ERRORLEVEL% == 0 (
    echo FAIL Python WAS NOT FOUND.
    goto ERR
)
python .\build\preprocessor.py --help >nul 2>nul
if not %ERRORLEVEL% == 0 (
    echo FAIL Python WAS NOT WORKING AS EXPECTED.
)
echo OK Python IS WORKING AS EXPECTED.
xelatex --version >nul 2>nul
if not %ERRORLEVEL% == 0 (
    echo FAIL XeLaTeX WAS NOT FOUND.
    goto ERR
)
xelatex ./build/tex-test >nul 2>nul
if not %ERRORLEVEL% == 0 (
    echo FAIL XeLaTeX WAS NOT WORKING AS EXPECTED.
    goto ERR
)
rm tex-test.* >nul 2>nul
echo OK XeLaTeX IS WORKING AS EXPECTED.
echo COMPILING, THAT WILL TAKE A FEW MINIUTES.
cd build
xelatex -shell-escape kactl >nul 2>nul
echo %ERRORLEVEL%
copy kactl.pdf .. >nul 2>nul
echo BUILD COMPLETED.
goto EX
:ERR
echo ONE OR MORE ERROR(S) OCCERED. NO PDF WAS GENERATED.
pause
goto EX
:EX
