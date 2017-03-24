import sys
import numpy
import cv2
# import cv2.cv as cv

cascade_src = 'cars.xml'

print("Starting app.")

len = 0
rejectLevels = []
levelWeights = []

car_cascade = cv2.CascadeClassifier(cascade_src)

print("Reading image.")
img = cv2.imread('traffic1.jpg')
if (type(img) == type(None)):
    sys.exit("Error: Input not in image format")

print("Converting image to Gray scale")
gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
print("Filtering image to remove noises")
dst = cv2.fastNlMeansDenoising(gray,None,3,21,7)

cars = car_cascade.detectMultiScale(gray, 1.08, 3)

print("Proceeing...")
for (x,y,w,h) in cars:
    cv2.rectangle(img,(x,y),(x+w,y+h),(0,255,0),2)
    len = len + 1
    
print("We are done!")
print(len)
while cv2.waitKey(33) != 27:
    cv2.namedWindow('Output',cv2.WINDOW_NORMAL)
    cv2.resizeWindow('Output', 1000,700)
    cv2.imshow('Output', img)

cv2.destroyAllWindows()

