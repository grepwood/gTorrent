#gTorrent
[![Build Status](https://travis-ci.org/gtorrent/gTorrent.svg?branch=master)](https://travis-ci.org/gtorrent/gTorrent)

PULL REQUESTS ARE ENCOURAGED

\>absolutely no code

\>yet another failed /g/ project

see the branches

what we have so far: http://a.pomf.se/lkowau.webm

#### About
A minimalistic lightweight bittorrent client written by the 4chan technology board.

#### Goals
1. Use native GUI toolkit on target platforms.
2. gTorrent should be themable with CSS, and XML/JSON for representing the application components.
3. RSS Automation
4. What the fuck should we write this in?
5. ...

## Compiling/Installing
#### GNU/Linux or Mac OS X
```
$ mkdir -p build/ && cd build/
$ cmake ..
$ make
```

##### Ubuntu notes
The version of libgtkmm in 14.04 is a bit out of date. To fix this do:

```
$ sudo add-apt-repository ppa:gnome3-team/gnome3-staging
$ sudo apt-get update
$ sudo apt-get dist-upgrade
```

##### ArchLinux
You have it easy. Install from the [AUR](https://aur.archlinux.org/packages/gtorrent/)

Then it'll build with no problems.

#### Windows
Requires CMake, MinGW, msys and all dependencies. Note that since gtorrent uses gtkmm/headerbar.h you must use at least  gtkmm-3.9.16. (Note: I have not verified that gtkmm-3.9.16 is enough) This has dependencies
`['giomm-2.4 >= 2.37.7 pangomm-1.4 >= 2.27.1 gtk+-3.0 >= 3.9.16 cairomm-1.0 >= 1.9.2 gdk-pixbuf-2.0 >= 2.22.1'`]
Note that since the prebuilt gtk package for Windows is currently at 3.6.4, you must compile gtk yourself. This is a clusterfuck and is poorly supported but possible with enough hacking, good luck.
Note: Libtorrent-rasterbar 1.0 fails to compile on Windows. It can be patched, but I recommend compiling the svn branch instead. Revision 10121 works for me with shared libraries compiled against shared boost with bjam. Since bjam does not generate files for pkg-config you should build with automake and install the one it creates to the appropriate directores. Additionally, the bjam script for building shared libraries is messed up and attempts to -lboost_system -lboost_chrono regardless of the libraries full name, so I recommend simply making a copy of the .dll and .dll.a with those names.

In a bash shell:
```
mkdir -p build/ && cd build/
cmake -G "MSYS Makefiles" ..
make
gTorrent.exe
```
