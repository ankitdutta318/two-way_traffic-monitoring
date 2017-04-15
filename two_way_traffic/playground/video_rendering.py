import numpy
import cv2

cascade_src = 'cars.xml'
video_src = 'video1.avi'

print("Starting app...")

len = 0
cap = cv2.VideoCapture(video_src)
car_cascade = cv2.CascadeClassifier(cascade_src)

while True:
    ret, img = cap.read()
    if (type(img) == type(None)):
        break
    
    gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
    
    cars = car_cascade.detectMultiScale(gray, minNeighbors=2)
    print(cars)

    for (x,y,w,h) in cars:
        cv2.rectangle(img,(x,y),(x+w,y+h),(0,255,0),2)
        len = len + 1
    
    cv2.imshow('video', img)
    
    if cv2.waitKey(33) == 27:
        break

cap.release()
cv2.destroyAllWindows()
print(len)
