import cv2
import numpy as np
def fun(img):
	x1=25;
	y1=0;
	cv2.imshow("image",img);
	cv2.waitKey(0);
	height,width,c=img.shape
	mat1=list(list());
	mat2=list(list());
	for i in range(0,6):
		t=list();
		for j in range(0,5):
			t.append(j);
		mat1.append(t);
	for i in range(0,5):
		t=list();
		for j in range(0,6):
			t.append(j);
		mat2.append(t);
	
	for _1 in range(0,6):
		y1=y1+12;
		x1=25;
		for _2 in range(0,5):
			x1=x1+50;
			r,g,b=img[y1,x1];
			if(r==0 and b==0 and g==0):
				mat1[_1][_2]=1;
			else:
				mat1[_1][_2]=0;
			
			
			x1=x1+50+25;
		y1=y1+13+100;
	x1=0;
	y1=25;
	for _1 in range(0,5):
		y1=y1+50;
		x1=0;
		for _2 in range(0,6):
			x1=x1+12;
			r,g,b=img[y1,x1];
			if(r==0 and b==0 and g==0):
				mat2[_1][_2]=1;
			else:
				mat2[_1][_2]=0;
			
			
			x1=x1+13+100;
		y1=y1+50+25;
	print("horizontal")
	for i in range(0,6):
			print(mat1[i]);
	
	print ("vertical");
	for i in range(0,5):
			print(mat2[i]);
	

img=cv2.imread("./Test_Images/test_image1.jpg");
fun(img);
