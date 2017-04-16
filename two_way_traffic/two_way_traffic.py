# import libraries
import sys
import numpy
import cv2
import serial
import time

cascade_src = 'dataset\cars.xml'
# Create Serial port object called arduinoSerialData
ser = serial.Serial('COM3', 9600, timeout = 1)

print("Starting app.")

no_of_cars = 0
rejectLevels = []
levelWeights = []
img_template = "C:\\Users\\anonymous\\Documents\\GitHub\\two-way_traffic-monitoring\\two_way_traffic\\img\\"
img_src = ["traffic1.jpg", "traffic2.jpg", "traffic3.jpg", "traffic4.jpg"]


car_cascade = cv2.CascadeClassifier(cascade_src)

for i in img_src:
    new_img = img_template + i
    no_of_cars = 0
    img = cv2.imread(new_img)
    if (type(img) == type(None)):
        sys.exit("Error: Input not in image format")

    gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
    #print("Filtering image to remove noises")
    #dst = cv2.fastNlMeansDenoising(gray,None,3,21,7)

    cars = car_cascade.detectMultiScale(gray, 1.05, 3)

    print("Proceeing...")
    for (x,y,w,h) in cars:
        cv2.rectangle(img,(x,y),(x+w,y+h),(0,255,0),2)
        no_of_cars = no_of_cars + 1
    
    print(no_of_cars)
    time_delay = int(2 + (0.5*no_of_cars))
    
    ser.write('%d' %time_delay)
    time.sleep(time_delay)
    while cv2.waitKey(33) != 27:
        cv2.namedWindow('Output',cv2.WINDOW_NORMAL)
        cv2.resizeWindow('Output', 1000,700)
        cv2.imshow('Output', img)

    cv2.destroyAllWindows()


