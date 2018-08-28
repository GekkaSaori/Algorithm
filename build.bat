@echo off
echo CHECKING DEPENDENCEIES.
rm --version
if not %ERRORLEVEL% == 0 (
    echo rm WAS NOT FOUND.
    goto ERR
)
python --version >nul 2>nul
if not %ERRORLEVEL% == 0 (
    echo Python WAS NOT FOUND.
    goto ERR
)
xelatex --version >nul 2>nul
if not %ERRORLEVEL% == 0 (
    echo XeLaTeX WAS NOT FOUND.
    goto ERR
)
echo COMPILING, THAT WILL TAKE A FEW MINIUTES.
cd build
xelatex -shell-escape kactl
copy kactl.pdf ..
echo BUILD COMPLETED.
goto EX
:ERR
echo ONE OR MORE ERROR(S) OCCERED. NO PDF WAS GENERATED.
pause
goto EX
:EX
exit
