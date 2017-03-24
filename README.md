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
