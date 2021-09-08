# -*- coding: cp1252 -*-
import numpy as np
import cv2

#####################################################################
## Experiment 1
#####################################################################

def divide_into_roi(img,direction,n):
    '''
    * Function Name: divide_into_roi
    * Input: img -- First test image (test_image1)
             direction -- 0=horizontal and 1=vertical
             n -- number of ROIs (1, 2, 3 or 4)
    * Output: roi –- a list containing the ROIs that the image has been split into
    * Example Call: divide_into_roi(img,0,2) >>> roi = [roi1, roi2]
    '''
    #add your code here
	roi=list();
	h,w,c=img.shape;
	x=0;
	y=0;
	k=0;
	if(direction==0):
		k=(w/n);
		y=k;
		for i in range(0,n):
			ii=img[:,x:y,:]
			roi.append(ii);
			x+=k;
			y+=k;
	else:
		k=(h/n);
		y=k;
		for i in range(0,n):
			ii=img[x:y,:,:];
			roi.append(ii);
			x+=k;
			y+=k;
	return	roi;


    return(roi)


#####################################################################
## Experiment 2
#####################################################################

def coins_contours(img):
    '''
    * Function Name: coins_contours
    * Input: img -- First test image (test_image1)
    * Output: a window named "Image" will pop up showing red contours around the coins
              contours –- a list containing the contours around the coins
    '''
    #add your code here
	out=img.copy();
	gray=cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)

	gray_blur = cv2.GaussianBlur(img, (15, 15), 0)
	lower=np.array([30,150,180])#bgr
	upper=np.array([150,250,255])
	
	
	shapeMask=cv2.inRange(img,lower,upper)
	img_cpy=shapeMask.copy();
	
		
	gray_blur = cv2.GaussianBlur(img_cpy, (15, 15), 0)
	thresh = cv2.adaptiveThreshold(gray_blur, 255, cv2.ADAPTIVE_THRESH_GAUSSIAN_C,cv2.THRESH_BINARY_INV, 11, 1)
	
	cont_img = thresh.copy()
	
	
	_,contours, hierarchy = cv2.findContours(cont_img, cv2.RETR_EXTERNAL,cv2.CHAIN_APPROX_NONE)
	
	
    	cv2.drawContours(img, contours, -1, (0,0,255), 3)
    	cv2.imshow('Image',img)
    	return(contours)


#####################################################################
## Experiment 3
#####################################################################

def find_gold_coins(img):
    '''
    * Function Name: find_gold_coins
    * Input: img -- a test image
    * Output: mines_cont_gc -- a list used to store mines containing gold coins
    * Example Call: print find_gold_coins(img)
    
                    [[1,6],[2,7],[4],[5],[8,9,10,15,20]]
    '''
    #add your code here
	mp=dict();
	mp[(26,26)]=1;
	mp[(26,151)]=2;
	mp[(26,276)]=3;
	mp[(26,401)]=4;
	mp[(26,526)]=5;
	mp[(151,26)]=6;
	mp[(151,151)]=7;
	mp[(151,276)]=8;
	mp[(151,401)]=9;
	mp[(151,526)]=10;
	mp[(276,26)]=11;
	mp[(276,151)]=12;
	mp[(276,276)]=13;
	mp[(276,401)]=14;
	mp[(276,526)]=15;
	mp[(401,26)]=16;
	mp[(401,151)]=17;
	mp[(401,276)]=18;
	mp[(401,401)]=19;
	mp[(401,526)]=20;
	mp[(526,26)]=21;
	mp[(526,151)]=22;
	mp[(526,276)]=23;
	mp[(526,401)]=24;
	mp[(526,526)]=25;

	mp1=list();
	for x,y in mp.keys():
		mp1.append((x,y));

	roi=list();
	maping=dict();
	maping_roi=dict();
	coins=dict();
	area=dict();

	img0=img.copy();
	
	gray=cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
		
	egde=cv2.Canny(gray,650,650);
	_,contours, hierarchy = cv2.findContours(gray, cv2.RETR_TREE,cv2.CHAIN_APPROX_NONE)
	
	k=0;
	img1=img.copy();
	res=img.copy()
	for i in range(0,len(contours)):
		a=cv2.contourArea(contours[i]);
		
		if(a<1000):
			continue;
		x,y,width,height=cv2.boundingRect(contours[i])
		roi_t=img[0:650,0:650,:]
		mask = np.zeros(img.shape[:3], dtype="uint8") * 255
		mask=cv2.drawContours(mask,contours, i,(255,255,255), -1)

		mask_inv=cv2.bitwise_and(mask,img);#imp
		

		arr=list();
		for a,b in mp1:
			if(a>=x and a<=x+width and b>=y and b<=y+height):
				bl,gr,rd=img[b,a]
				if(bl==255 and gr==255 and rd==255):
					arr.append(mp[(b,a)])

		arr.sort();
		maping_roi[k]=contours[i];	
		maping[k]=arr;		
		roi.append(mask_inv)
		area[k]=a;
		k+=1;
		
	for i in range(0,len(roi)):
		gray_roi=cv2.cvtColor(roi[i],cv2.COLOR_BGR2GRAY)
		gray_blur = cv2.GaussianBlur(gray_roi, (15, 15), 0)
		
		thresh = cv2.adaptiveThreshold(gray_blur, 255, cv2.ADAPTIVE_THRESH_GAUSSIAN_C,cv2.THRESH_BINARY_INV, 11, 1)
		#for coins
		cont_img = thresh.copy()
		lower=np.array([30,150,180])#bgr
		upper=np.array([150,250,255])
	
	
		shapeMask=cv2.inRange(roi[i],lower,upper)
		_,contours_in_roi_gold, hierarchy = cv2.findContours(shapeMask.copy(), cv2.RETR_TREE,cv2.CHAIN_APPROX_NONE)
		
		coins[i]=False;	
		for ii in range(0,len(contours_in_roi_gold)):
			aa=cv2.contourArea(contours_in_roi_gold[ii])
		
			if(aa>1000 and aa<4000):
				if(aa>1000 and aa<2000):
					coins[i]+=1;
				if(aa>2000 and aa<3500):
					coins[i]+=2;
			else:
				continue;
		

	mines_cont_gc=list();
	for i in range(0,len(roi)):
		if(coins[i]>=1):
			if(len(maping[i])>0):
				mines_cont_gc.append(maping[i]);
			
	mines_cont_gc.sort();
	return mines_cont_gc;

def find_bombs(img):
    '''
    * Function Name: find_bombs
    * Input: img -- a test image
    * Output: mines_cont_bombs -- a list used to store mines containing bombs
    * Example Call: print find_bombs(img)

                    [[1,6],[11,12,16,],[18],[25]]
    '''
    #add your code here
	mp=dict();
	mp[(26,26)]=1;
	mp[(26,151)]=2;
	mp[(26,276)]=3;
	mp[(26,401)]=4;
	mp[(26,526)]=5;
	mp[(151,26)]=6;
	mp[(151,151)]=7;
	mp[(151,276)]=8;
	mp[(151,401)]=9;
	mp[(151,526)]=10;
	mp[(276,26)]=11;
	mp[(276,151)]=12;
	mp[(276,276)]=13;
	mp[(276,401)]=14;
	mp[(276,526)]=15;
	mp[(401,26)]=16;
	mp[(401,151)]=17;
	mp[(401,276)]=18;
	mp[(401,401)]=19;
	mp[(401,526)]=20;
	mp[(526,26)]=21;
	mp[(526,151)]=22;
	mp[(526,276)]=23;
	mp[(526,401)]=24;
	mp[(526,526)]=25;

	mp1=list();
	for x,y in mp.keys():
		mp1.append((x,y));

	roi=list();
	maping=dict();
	maping_roi=dict();
	coins=dict();
	area=dict();
	bombs=dict();
	img0=img.copy();
	
	gray=cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
		
	egde=cv2.Canny(gray,650,650);
	_,contours, hierarchy = cv2.findContours(gray, cv2.RETR_TREE,cv2.CHAIN_APPROX_NONE)
	
	k=0;
	img1=img.copy();
	res=img.copy()
	for i in range(0,len(contours)):
		a=cv2.contourArea(contours[i]);
		
		if(a<1000):
			continue;
		x,y,width,height=cv2.boundingRect(contours[i])
		roi_t=img[0:650,0:650,:]
		mask = np.zeros(img.shape[:3], dtype="uint8") * 255
		mask=cv2.drawContours(mask,contours, i,(255,255,255), -1)

		mask_inv=cv2.bitwise_and(mask,img);#imp
		

		arr=list();
		for a,b in mp1:
			if(a>=x and a<=x+width and b>=y and b<=y+height):
				bl,gr,rd=img[b,a]
				if(bl==255 and gr==255 and rd==255):
					arr.append(mp[(b,a)])

		arr.sort();
		maping_roi[k]=contours[i];	
		maping[k]=arr;		
		roi.append(mask_inv)
		area[k]=a;
		k+=1;
		
	for i in range(0,len(roi)):
		gray_roi=cv2.cvtColor(roi[i],cv2.COLOR_BGR2GRAY)
		gray_blur = cv2.GaussianBlur(gray_roi, (15, 15), 0)
		
		thresh = cv2.adaptiveThreshold(gray_blur, 255, cv2.ADAPTIVE_THRESH_GAUSSIAN_C,cv2.THRESH_BINARY_INV, 11, 1)
		#for bombs
		lower=np.array([0,50,200]);
		upper=np.array([70,100,255]);
		
		shapeMask=cv2.inRange(roi[i],lower,upper)
		_,contours_in_roi_bomb, hierarchy = cv2.findContours(shapeMask.copy(), cv2.RETR_TREE,cv2.CHAIN_APPROX_NONE)
		bombs[i]=False;
		if(len(contours_in_roi_bomb)>0):
			bombs[i]=True;
		

	mines_cont_bombs=list();
	for i in range(0,len(roi)):
		if(bombs[i]==1):
			if(len(maping[i])>0):
				mines_cont_bombs.append(maping[i]);
			
	mines_cont_bombs.sort();
	return mines_cont_bombs;


def find_max_gold_coins(img):
    '''
    * Function Name: find_max_gold_coins
    * Input: img -- a test image
    * Output: mines_cont_max_gold_coins -- a list used to store mine/s containing
              maximum number of gold coins and "NO BOMBS"
    * Example Call: print find_max_gold_coins(img)

                    [[2 ,7],[4],[13]]
    '''
    #add your code here
	mp=dict();
	mp[(26,26)]=1;
	mp[(26,151)]=2;
	mp[(26,276)]=3;
	mp[(26,401)]=4;
	mp[(26,526)]=5;
	mp[(151,26)]=6;
	mp[(151,151)]=7;
	mp[(151,276)]=8;
	mp[(151,401)]=9;
	mp[(151,526)]=10;
	mp[(276,26)]=11;
	mp[(276,151)]=12;
	mp[(276,276)]=13;
	mp[(276,401)]=14;
	mp[(276,526)]=15;
	mp[(401,26)]=16;
	mp[(401,151)]=17;
	mp[(401,276)]=18;
	mp[(401,401)]=19;
	mp[(401,526)]=20;
	mp[(526,26)]=21;
	mp[(526,151)]=22;
	mp[(526,276)]=23;
	mp[(526,401)]=24;
	mp[(526,526)]=25;

	mp1=list();
	for x,y in mp.keys():
		mp1.append((x,y));

	roi=list();
	maping=dict();
	maping_roi=dict();
	coins=dict();
	area=dict();
	bombs=dict();
	nobombs=dict();

	img0=img.copy();
	
	gray=cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
		
	egde=cv2.Canny(gray,650,650);
	_,contours, hierarchy = cv2.findContours(gray, cv2.RETR_TREE,cv2.CHAIN_APPROX_NONE)
	
	k=0;
	img1=img.copy();
	res=img.copy()
	for i in range(0,len(contours)):
		a=cv2.contourArea(contours[i]);
		
		if(a<1000):
			continue;
		x,y,width,height=cv2.boundingRect(contours[i])
		roi_t=img[0:650,0:650,:]
		mask = np.zeros(img.shape[:3], dtype="uint8") * 255
		mask=cv2.drawContours(mask,contours, i,(255,255,255), -1)

		mask_inv=cv2.bitwise_and(mask,img);#imp
		

		arr=list();
		for a,b in mp1:
			if(a>=x and a<=x+width and b>=y and b<=y+height):
				bl,gr,rd=img[b,a]
				if(bl==255 and gr==255 and rd==255):
					arr.append(mp[(b,a)])

		arr.sort();
		maping_roi[k]=contours[i];	
		maping[k]=arr;		
		roi.append(mask_inv)
		area[k]=a;
		k+=1;
		
	for i in range(0,len(roi)):
		gray_roi=cv2.cvtColor(roi[i],cv2.COLOR_BGR2GRAY)
		gray_blur = cv2.GaussianBlur(gray_roi, (15, 15), 0)
		
		thresh = cv2.adaptiveThreshold(gray_blur, 255, cv2.ADAPTIVE_THRESH_GAUSSIAN_C,cv2.THRESH_BINARY_INV, 11, 1)

		#for coins
		cont_img = thresh.copy()
		lower=np.array([30,150,180])#bgr
		upper=np.array([150,250,255])
	
	
		shapeMask=cv2.inRange(roi[i],lower,upper)
		_,contours_in_roi_gold, hierarchy = cv2.findContours(shapeMask.copy(), cv2.RETR_TREE,cv2.CHAIN_APPROX_NONE)
		
		coins[i]=False;	
		for ii in range(0,len(contours_in_roi_gold)):
			aa=cv2.contourArea(contours_in_roi_gold[ii])
		
			if(aa>1000 and aa<4000):
				
				if(aa>1000 and aa<2000):
					coins[i]+=1;
					
				if(aa>2000 and aa<3500):
					coins[i]+=2;
					
			else:
				continue;
			

		#for bombs
		lower=np.array([0,50,200]);
		upper=np.array([70,100,255]);
		
		shapeMask=cv2.inRange(roi[i],lower,upper)
		_,contours_in_roi_bomb, hierarchy = cv2.findContours(shapeMask.copy(), cv2.RETR_TREE,cv2.CHAIN_APPROX_NONE)
		bombs[i]=False;
		if(len(contours_in_roi_bomb)>0):
			bombs[i]=True;
		


		coinsnobomb=0;
		
	for i in range(0,len(roi)):
		if(bombs[i]==0):
			if(coinsnobomb<coins[i]):
				coinsnobomb=coins[i];

	mines_cont_max_gold_coins=list();
	for i in range(0,len(roi)):
		if(bombs[i]==0 and coinsnobomb==coins[i]):
			if(len(maping[i])>0):
				mines_cont_max_gold_coins.append(maping[i]);
		
	mines_cont_max_gold_coins.sort();
	return mines_cont_max_gold_coins;

#####################################################################
## Main Function
#####################################################################
if __name__ == "__main__":
    
## Experiment 1
    img = cv2.imread('test_images/test_image1.jpg')
    print "Experiment 1 Output:"
    img_roi=divide_into_roi(img,1,2)
    cv2.imshow('img_roi[0]',img_roi[0])
    cv2.imshow('img_roi[1]',img_roi[1])
    print

## Experiment 2
    img = cv2.imread('test_images/test_image1.jpg')
    print "Experiment 2 Output:"
    contours = coins_contours(img)
    print len(contours)
    print
    
## Experiment 3
    img = cv2.imread('test_images/test_image1.jpg')
    print "Experiment 3 Output:"

    #checking output for single image
    mines_cont_gc = find_gold_coins(img)
    print "Mines containing gold coins"
    print mines_cont_gc
    print

    mines_cont_bombs = find_bombs(img)
    print "Mines containing bombs"
    print mines_cont_bombs
    print

    mines_cont_max_gold_coins = find_max_gold_coins(img)
    print "Mine/s containing maximum number of gold coins and NO BOMB"
    print mines_cont_max_gold_coins
    print
    
