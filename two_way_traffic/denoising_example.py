import numpy as np
import cv2
from matplotlib import pyplot as plt
img = cv2.imread('Screenshot.png')
dst = cv2.fastNlMeansDenoisingColored(img,None,10,10,7,21)
cv2.imshow(img)
cv2.imshow(dst)
