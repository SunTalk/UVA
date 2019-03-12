@echo off

cls

g++ arrange.cpp -o arrange.exe
if %ERRORLEVEL% EQU 0 (
	arrange.exe
)

git add .
git commit -m "%1 complete"
git push origin master

echo.
echo push complete
