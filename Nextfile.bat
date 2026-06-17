@echo off
REM Append a product to NextFile.dat: name comp price id qty (no spaces in name/comp)
if "%~5"=="" (
  echo Usage: Nextfile.bat name comp price id qty
  echo Example: Nextfile.bat Keyboard Logitech 120 1001 10
  goto :eof
)

echo %1 %2 %3 %4 %5 >> NextFile.dat
echo Added product: %1 %2 %3 %4 %5
