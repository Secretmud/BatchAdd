# BatchAdd

Adding new users in batches using C

## File layout 

Use the following layout when you create the file to add in batches, if you want
to use another layout then rewrite the user_parse

|USERNAME|UUID|GROUP|USER COMMENT |HOME DIR   |SHELL    |PASSWORD |
|:------:|:--:|:---:|:-----------:|:---------:|:-------:|:-------:|
| user   |xxxx|group|user info    |/home/user |/bin/bash|pass     |

## Usage

To use the program you need to either install mkpasswd(on debian and the likes
it's found in the whois package). If you don't want to install mkpasswd you can
use openssl. There is still some work to be done with that parth though. Tested
on Ubuntu 16.04 w/ 4.4.0-171-generic. 

## Improvements 

Going to look into openssl/sha.h and see if I can get that working better than
using 



### shasums

Adding the program precompiled. These are the checksums

|Hash|Output|
|:---:|:---|
|SHA1|c37f41499fd4a417997f05624681c5e6581745ff|
|SHA256|d6128734a9e2ef5935c12e29b48bd4baf631863ff04561b961f614bad0cf48c9|
|SHA512|02a1850894429c80513df5cfd48f1b6f6ed0c3c3d423e67b54644ffae1325b91dcaf94d4a5c9c8261b5aba28975f793f1cffdba409bedcbd1373e8a819f1150a|

