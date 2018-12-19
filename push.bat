@echo off

cls
git add .
git commit -m "%1 complete"
git push origin master

echo.
echo push complete
