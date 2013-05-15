truecrypt-vs2010
================

This is a copy of [TrueCrypt](http://www.truecrypt.org/ "TrueCrypt") 7.1a sources available from [TrueCrypt Source Download Page](http://www.truecrypt.org/downloads2 "TrueCrypt Source Download Page") configured to be compiled in Visual Studio 2010.

Please note that although the source code itself is not modified in any way, there were a number of solution's and projects' configuration adjustments made in order to allow for clean compile in VS2010. This and the fact I did no testing whatsoever, appeal for caution on the part of the user.

## Important ##

**Added projects**

The solution contains two additional projects - Api and ApiTest. These are not part of original TrueCrypt source and represent my attempt to create an API layer for TrueCrypt. Although the attempt had been initially successful, it became clear to me that the original TrueCrypt code structure is not suited very well for a neat extension the way I hoped it'd be, that is without modifying original code base. So I decided to move on with this project in separate [repository](https://github.com/nightnic/truecrypt-api "truecrypt-api"), leaving this one in its current state. If for a reason you find these projects unnecessary, please feel free to remove them from the solution. There are no dependencies to watch for.

**Unsigned drivers**

System drivers in Windows Vista and above are required to be signed by the developer which involves some additional maintenance effort as well as purchasing a certificate. Unless you're inclined to do that, the drivers compiled from this solution have very limited use.

## Dependencies ##
All dependencies and build notes defined in original Readme.txt file available [here](https://github.com/nightnic/truecrypt-vs2010/blob/master/Readme.txt "here").

## License ##
Original TrueCrypt license available in License.txt file [here](https://github.com/nightnic/truecrypt-vs2010/blob/master/License.txt "here").