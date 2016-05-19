: REM BAT-file name picino.bat
: REM %6 path to sourcefile name.ino ( C:\PK2proj\Work\name\name.ino )

: REM derive name of file from path to sourcefile

@echo off

set current=%~dp0
: REM echo %current%

Set pathname=%6
For %%a in ("%pathname%") do (
    set filename=%%~nxa
    set filepath=%%~dpa
)

set cfile=%filename:.ino=.c%
set ctarget=%filepath%%cfile%
set hexfile=%filename:.ino=.hex%
set hextarget=%filepath%%hexfile%
: REM echo %ctarget%

copy /y %6 %ctarget%

%current%Cc5x\Cc5x.exe %ctarget% -O%filepath% -a

%current%PK2Cmd\pk2cmd.exe -b%current%PK2Cmd\ -pPIC16f690 -f%hextarget% -a4.5 -m -r -t -jn
