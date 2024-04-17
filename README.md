You can download the binary under Releases on this page or you can compile it yourself like this:

1.) Download the CPP file or clone this repository.

2.) Download MiniGW here https://github.com/niXman/mingw-builds-binaries/releases

3.) Put the ``clipboard.cpp`` file in the ``bin`` folder inside of the MiniGW folder.

4.) Open command prompt in this directory and run:
``g++ -o clipboard-event-handler-win32.exe clipboard.cpp -static -luser32``

5.) Place the newly generated exe file in ``/node_modules/clipboard-event/platform`` and overwrite the old one.
