@echo off

cls
git add .
git commit -m "%1"
git push origin master

echo.
echo push complete
