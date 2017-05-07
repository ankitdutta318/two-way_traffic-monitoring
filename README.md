# two-way_traffic-monitoring
A real time traffic monitoring system using OpenCV in Python in integration with Arduino.

# Vehicle Detection with Haar Cascades

Last version: **1.0.0** 

Hello everyone,
An easy way to perform vehicle detection is by using Haar Cascades. Currently, I don't have a detailed tutorial about it, but you can get some extra information in the OpenCV homepage, see [Cascade Classifier](http://docs.opencv.org/2.4/doc/tutorials/objdetect/cascade_classifier/cascade_classifier.html) page. See also [Cascade Classifier Training](http://docs.opencv.org/2.4/doc/user_guide/ug_traincascade.html) for training your own cascade classifier.

<p align="center">
<a href="https://www.youtube.com/watch?v=c4LobbqeKZc" target="_blank">
<img src="https://github.com/geekankit318/two-way_traffic-monitoring/blob/master/two_way_traffic/dataset/Capture.PNG" border="0" />
</a>
</p>

The haar-cascade **cars.xml** was trained using 526 images of cars from the rear (360 x 240 pixels, no scale).
The images were extracted from the Car dataset proposed by Brad Philip and Paul Updike taken of the freeways of southern California.

## Algorithm: 
1.	Import the data base for car features. And set the directory for your image to be processed.  
2.	Read the image to be processed and convert it into grayscale from RGB. 
3.	Feed the grayscale image in the car cascade function to test for the cars in the image. 
4.	For the count use the x, y, w and h component. And store the count in a variable. 
5.	Since it’s a linear model the time delay is calculated using the count of cars by m*(count) + c0 expression. 
6.	Finally the time delay value is sent to Arduino board via serial port. 
 
## Theory: 
In this code we have calculated the number of cars in the image using haar cascade using the car_cascade.detectMultiScale function which is the pre trained neural net for recognising the cars. Then we have calculated the time delay according to the density measure using a linear model of y=m*x+c form, this calculated delay is transmitted to Arduino board via serial communication (pyserial library for python). 

## Approach 
*	Image processing is used for counting cars on lanes by using haar cascade. 
*	We prepared a linear model for shifting the lights between the lanes. 
*	At starting a pic will be taken by the camera and the cars will be counted for that after counting the delay will be calculated and after that time another pic will be taken of the other lane and again same process will be done. 
*	The equation for shifting of lights is 
Y=y0+mX 
For our case y0=2 
M=0.5 
X=number of cars on lane 
Y=time of shifting 
*	After the number of cars have been counted (processed with python) data is sent to arduino via serial port. 
*	We have encountered a disadvantage of serial communication that only single byte is transmitted at a time on the serial buffer. Therefore, we have stored a byte at each time encountered the total number of cars in an image. 
*	Now arduino comes into role which has been used for just shifting the lights between the lanes. 
 

## Pyserial: 
This module encapsulates the access for the serial port. It provides backends for Python running on Windows, OSX, Linux, BSD (possibly any POSIX compliant system) and IronPython. The module named “serial” automatically selects the appropriate backend. 
Features: 
*	Same class based interface on all supported platforms. 
*	Access to the port settings through Python properties. 
*	Support for different byte sizes, stop bits, parity and flow control with RTS/CTS and/or Xon/Xoff. 
*	Working with or without receive timeout. 
*	File like API with “read” and “write” (“readline” etc. also supported). 
*	The files in this package are 100% pure Python. 
*	The port is set up for binary transmission. No NULL byte stripping, CR-LF translation etc. (which are many times enabled for POSIX.) This makes this module universally useful. 
*	Compatible with io library 
*	RFC 2217 client (experimental), server provided in the examples. 


### Requirement: 
*	Python 2.7 or newer, including Python 3.4 and newer 


## Serial communication for Arduino: 
Serial is used for communication between the Arduino board and a computer or other devices. All Arduino boards have at least one serial port (also known as a UART or USART): Serial. It communicates on digital pins 0 (RX) and 1 (TX) as well as with the computer via USB. Thus, if you use these functions, you cannot also use pins 0 and 1 for digital input or output. You can use the Arduino environment's built-in serial monitor to communicate with an Arduino board 
#### Begin() : 
Sets the data rate in bits per second (baud) for serial data transmission. For communicating with the computer, use one of these rates: 300, 600, 1200, 2400, 4800, 9600, 14400, 19200, 28800, 38400, 57600, or 115200. You can, however, specify other rates - for example, to communicate over pins 0 and 1 with a component that requires a particular baud rate. 
#### Available() : 
Get the number of bytes (characters) available for reading from the serial port. This is data that's already arrived and stored in the serial receive buffer (which holds 64 bytes). available() inherits from the Stream utility class. 
#### Read() : 
Reads incoming serial data. read() inherits from the Stream utility class. parseInt(): 
#### parseInt():
returns the first valid (long) integer number from the serial buffer. 
Characters that are not integers (or the minus sign) are skipped. 
In particular: 
*	Initial characters that are not digits or a minus sign, are skipped; 
*	Parsing stops when no characters have been read for a configurable time-out value, or a non-digit is read; 
*	If no valid digits were read when the time-out (see Serial.setTimeout()) occurs, 0 is returned; 
Serial.parseInt() inherits from the Stream utility class. 
 


For more information, please see:

* Train Your Own OpenCV Haar Classifier
 * http://coding-robin.de/2013/07/22/train-your-own-opencv-haar-classifier.html
 * https://github.com/mrnugget/opencv-haar-classifier-training

* Related paper:
 * Oliveira, M.; Santos, V. Automatic Detection of Cars in Real Roads using Haar-like Features ([PDF](https://sites.google.com/site/andrewssobral/Automatic_Detection_of_Cars_in_Real_Roads_using_Haar-like_Features.pdf))

* Some additional resources:
 * http://lars.mec.ua.pt/public/Media/ResearchDevelopmentProjects/HaarFeatures_RoadFilms/HaarFeaturesTests/CarsRear/
 * http://lars.mec.ua.pt/public/Media/ResearchDevelopmentProjects/HaarFeatures_RoadFilms/HaarFeaturesTests/

For Windows users
-----------------
* Check if your OpenCV is installed at: C:\OpenCV2.4.10
* Install Python 2.x. Set Path varialble.
* Install numpy, matplot and other required packages in the same directory.
* Next, click on **vehicle_detection.bat** and enjoy!

For Linux users
-----------------
* For Linux and Mac users, a Makefile is provided to compile the source code.
* * Requirements: OpenCV 2.4.x (it only works with this version).
* * Python 2.x, numpy, matplot, etc and other important libraries.
* * Check out the latest project source code and compile it:
```
~/git clone https://github.com/geekankit318/two-way_traffic-monitoring.git
~/cd two_way_traffic



Release Notes:
* Version 1.0.0:
First version.
