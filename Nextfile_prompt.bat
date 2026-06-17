@echo off
REM Interactive prompt to append a product to NextFile.dat (avoid spaces)
set /p name=Product name (no spaces): 
set /p comp=Company (no spaces): 
set /p price=Price: 
set /p id=ID: 
set /p qty=Quantity: 

echo %name% %comp% %price% %id% %qty% >> NextFile.dat
echo Added: %name% %comp% %price% %id% %qty%
