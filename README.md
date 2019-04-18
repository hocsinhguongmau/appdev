# This project is to turn a Raspberry PI as an audio device. The device is able to do 2 functions: as a sound collector and as a test-tone generator.

## Table of Content

        # 1. Configuration Instructions
        # 2. Installation Instructions
        # 3. Operating Instructions
        # 4. File list (Manifest)
        # 5. Copyright / Copyleft
        # 6. Contact Information
        # 7. Credits
		
## 1. Configuration Instructions

The application is running in a Raspberry PI 3 model B.
This PI should come with a USB sound card, a network connection, a microphone.
Configure USB sound card as default audio device:

	```javascript
	- First use "lsusb" command to check if your USB sound card is mounted, it should show message below:
	Bus 001 Device 004: ID 0d8c:000c C-Media Electronics, Inc. Audio Adapter
	
	- Use "sudo nano /etc/asound.conf" command and put following content to the file:
	pcm.!default {
	  type plug
	  slave {
		pcm "hw:1,0"
	  }
	}
	ctl.!default {
		type hw
		card 1
	}
	```

	- Go to your home directory. Use "nano .asoundrc" command and put the same content to the file.
	
	- Run "alsamixer" to check whether the USB sound card is the default audio device.

## 2. Installation Instruction

Install libcurl library by following these steps:

	```javascript
	- First use command "ls /usr/include/curl" or "ls /usr/include/arm-linux-gnueabihf/curl" to identify that libcurl library is installed.
	
	- If the folder doesn’t exist. Run "sudo apt-get update” to update the application list.
	
	- Run "sudo apt-get install libcurl3” to install the libcurl3.
	
	- Run "sudo apt-get install libcurl4-openssl-dev” to install the development API of libcurl4.
	```

## 3. Operating Instructions
	
	```javascript
	- First using "make" command to generate .o file type
	
	- There are 2 features of this program:
	
		Run "./sound.out" to collect the sound.
		Run "./sound.out frequency", for example, "./sound.out 440", then you are able to select between 1 or 2 (mono or stereo) and choose the duration from 1 to 10.
	```
	
## 4. File list (Manifest)

	- Source code files: sound.c main.c screen.c comm.c
	- Header files: sound.h screen.h comm.h
	- Makefile
	- README

## 5. Copyright/Copyleft

	Copyright Nguyen Hoang Thang 2019
	
## 6. Contact Information

	- Author: Thang Nguyen
	- Email: thangnguyen24111990@gmail.com
	- Phone number: 0449158001
	
## 7. Credits

	- Instructions by Dr. Gao Chao
	- Equipment provided by Vaasa University of Applied Sciences.
