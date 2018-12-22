@echo off
set /p name=Ãû³Æ£º
set /p address=ÍøÖ·£º

echo Ãû³Æ£º%name%
echo Ãû³Æ£º%name%>>%name%.txt
echo ÍøÖ·£º%address%
echo ÍøÖ·£º%address%>>%name%.txt
pause
start %name%.txt
