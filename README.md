# Cipher
A pet project of mine that implements the Vigenere cipher.

The Vigenere cipher is a simple alphabetic encryption method which employs a series of 
Caesar ciphers based on a keyword provided by the user. It was invented in the 16th 
century by Giovan Battista Bellaso and later misattributed to Blaise de Vigenère, from 
whom the cipher now lends the name. 

Please refer to [Wikipedia](https://en.wikipedia.org/wiki/Vigen%C3%A8re_cipher) for more 
background information and how the cipher works.

## Notes on the application

 - 	The table used for the cipher does not only contain the letters A to Z, but in fact 
	uses the first 128 characters of the ASCII alphabet. This way, also special 
	characters like spaces, colons, semi-colons, commas, etc. are supported. 
	
## Usage

The Cipher app works by reading a text file provided by the user and writing the 
encrypted contents back to the same file. That is, the file will be modified after 
execution. 

Usage of the app is as follows:

 - Encrypting a file: 
	```./Cipher encrypt <filename> <key>```
 - Decrypting a file: 
 	```./Cipher decrypt <filename> <key>```
 	
Where _filename_ represents a valid file name on disk and _key_ is a string of at 
least 1 character.

## Note on security

The Vigenere cipher is not a particularly safe method of encryption, therefore **the Cipher
application should not be used to encrypt sensitive data**. I merely implemented it for 
entertainment and educational purposes.
