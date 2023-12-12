wzl-cutl
========

## What Does This Library Do?

`wzl-cutl` attempts to provide a lightweight library of useful utility and platform-abstracted C functions for Windows and Linux.

## What Doesn't This Library Do?

There are a few things that `wzl-cutl` specifically avoids:

* Re-implementing functions which are available in the C standard, up to and including C11.
  * It does, however, implement some C annex or POSIX functions where these functions may be missing, or named differently, between Windows and Linux. Wherever possible, these functions are written to simply call into the system's implementation.
* Re-implementing functions that are already available in existing third party C libraries. For a list of libraries which provide useful functionality, see the [Useful Libraries](#useful-libraries) section.

## Useful Libraries

### Strings and String Manipulation

* [SPString](https://github.com/NJdevPro/SPString): Secure C string library for embedded systems
* [sds](https://github.com/antirez/sds): Dynamic string library for C
* [safestringlib](https://github.com/intel/safestringlib): Secure string library implementation by Intel
* [safeclib](https://github.com/rurban/safeclib): Safe libc extension implementation
* [nanoprintf](https://github.com/charlesnicholson/nanoprintf): Extremely lightweight `printf` implementation for embedded systems

### Filesystem and Paths

* [cwalk](https://github.com/likle/cwalk): path library for C/C++

### Threading

* [pthread-win32](https://github.com/GerHobbelt/pthread-win32): POSIX-compatible threading library for Windows

### Other
* [stb](https://github.com/nothings/stb): Collection of single-header libraries for various purposes (image loading etc.)
