# easy-delete
A lightweight script to move unwanted raws automatically when the given jpeg is not present in a directory. Great for when you shoot both JPG + RAW and want to sift through unwanted photos, since you would only need to delete the jpegs first.

This program simply shifts files to a folder for you to review, and allows you to manually delete such raws conveniently by deleting the entire folder.

This program DOES NOT delete ANY file whatsoever. YOU are the one that has control over the delete operation, such that no file is accidentally deleted forever.

Instructions:
1) Download the latest release, or if you wish, you may clone the repo and recompile the file as is.

2) Place easy-delete.exe into the directory of your photos

3) On Windows 11, right click -> Run in Terminal to launch powershell, alternatively you may run cmd.exe and navigate to the current directory using command cd <dir>

4)In powershell, type ".\easy-delete.exe" to run the program that's in the current directory. In cmd.exe just type "easy-delete.exe" to run the program
