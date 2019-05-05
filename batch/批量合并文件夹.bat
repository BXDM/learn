@echo off
set dd=ºÏ²¢
md "%dd%" 2>nul
for /d %%a in (*)do if not "%%a"=="%dd%" (
  echo %%a
  for /r %%b in ("%%a\*")do (
     echo  ... %%~nxb
     if exist "%dd%\%%~nxb" (
        set n=1&set "f=%%b"
        call :yky "%%~nb" "%%~xb"
     )else copy "%%b" "%dd%\">nul
  )
  rd/s/q "%%b"
)
pause
goto :eof
:yky
set/a n+=1
if exist "%dd%\%~1_%n%%~2" goto :yky
copy "%f%" "%dd%\%~1_%n%%~2">nul
goto :eof