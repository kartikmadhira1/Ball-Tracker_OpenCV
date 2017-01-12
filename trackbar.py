import cv2
import numpy as np
def empty(z):
    pass
cv2.namedWindow('frame')
cv2.createTrackbar('Hmin','frame',0,255,empty)
cv2.createTrackbar('Hmax','frame',0,255,empty)
cv2.createTrackbar('Smin','frame',0,255,empty)
cv2.createTrackbar('Smax','frame',0,255,empty)
cv2.createTrackbar('Vmin','frame',0,255,empty)
cv2.createTrackbar('Vmax','frame',0,255,empty)
cam = cv2.VideoCapture(0)
if cam.isOpened():
    cam.set(cv2.cv.CV_CAP_PROP_FRAME_HEIGHT,120)
    cam.set(cv2.cv.CV_CAP_PROP_FRAME_WIDTH,160)
while (True):
    ret,frame = cam.read()
    
    Hmin=cv2.getTrackbarPos('Hmin','frame')
    Hmax=cv2.getTrackbarPos('Hmax','frame')
    Smin=cv2.getTrackbarPos('Smin','frame')
    Smax=cv2.getTrackbarPos('Smax','frame')
    Vmin=cv2.getTrackbarPos('Vmin','frame')
    Vmax=cv2.getTrackbarPos('Vmax','frame')
    
    hsv=cv2.cvtColor(frame,cv2.COLOR_BGR2HSV)
    image_mask=cv2.inRange(hsv,np.array([Hmin,Smin,Vmin]),np.array([Hmax,Smax,Vmax]))    
    res=cv2.bitwise_and(frame,frame,mask=image_mask)
    cv2.imshow('frame',res)
    cv2.imshow('frame1',frame)
    if cv2.waitKey(1)==27:
        break
    
cv2.destroyAllWindow()
cam.release()
