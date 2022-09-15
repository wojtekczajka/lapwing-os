# lapwing_os
## simple operating system
### to build os:
```sh
make all
```
### to run os using bochs:
```sh
# if you have rebuild os:
 gnome-disk-image-mounter --writable os.img # to mount os fat16 img
 cp bin/* $(findmnt -ro TARGET | grep OS)   # to copy all binaries to os.img
 umount $(findmnt -ro TARGET | grep OS)     # to unmount os fat16 img
#
bochs                                       # to run os using bochs
```
### features:
- [x] long mode
- [x] time handler
- [x] memory menager (paging mechanism)
- [x] process menager
- [x] multi-tasking and task switching
- [x] keyboard driver (PS/2)
- [x] simple fat16 module
- [x] printf, scanf functions
- [x] handling interrupts and exceptions
- [x] simple cli

### user commands:
```sh
LS       # list all files, use to check filesystem support
TOTALMEM # return all available memory (MB)
PINGPONG # use to check process calls like sleep, wait, switching between processes.
```
### lapwing_os in action:
https://user-images.githubusercontent.com/78093105/190382584-5fdbd028-177a-4216-9b27-3c9b6317327c.mp4

### requirements (my setup):
* Bochs x86 Emulator 2.6.11
* gcc 9.4.0
* nasm version 2.14.02
