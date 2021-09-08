import cv2 
import numpy as np

''' Graph Structure '''
class Node:
	x=int();
	y=int();
	dis=int();
	path=list();
	visited=False;
'''
class Path:
	hor=int();
	ver=int();


path=list();
for i in range(0,6):
	pp=list();
	for j in range(0,6):
		P=Path();
		if(hor[i][j]==1):
			P.hor=1;
		if(ver[i][j]==1):
			P.ver=1;
		pp.append(P);
	path.append(pp);

'''

def p(G):	
	for i in range(0,6):
		for j in range(0,6):
			print "x=",G[i][j].x,"y=",G[i][j].y,"dis=",G[i][j].dis,"path=",G[i][j].path,"  ";
		print;


def dijkstra(G,start,hor,ver):
	print "x=",start.x;
	print "y=",start.y;
	print "dis=",start.dis;
	print start.path;
	G[start.x][start.y].visited=True;
	if((start.x!=0 and start.x-1<0) or (start.x!=5 and start.x+1>5) or (start.y!=0 and start.y-1<0) or (start.y!=5 and start.y+1>5)):
		return;
	






	if(start.y<5 ):
			print "x=",start.x;
			print "y=",start.y;
			if(hor[start.x][start.y]==1):
				print "horizontal";
				NN=G[start.x][start.y+1];
				dist=G[start.x][start.y].dis+1;
				pth=G[start.x][start.y].path;
				pth1=list(pth);
				if(dist<NN.dis):
					G[start.x][start.y+1].dis=dist;
					ll=[start.y+1,start.x];
					print "path------before:",pth
					pth.append(ll);
					G[start.x][start.y+1].path=pth;
					print "path-->",pth;
					G[start.x][start.y].path=pth1;
					print "path of old node:",pth1;
				if(G[start.x][start.y+1].visited==False):
					dijkstra(G,G[start.x][start.y+1],hor,ver);
				



	if(start.x<5):	
		print "x=",start.x;
		print "y=",start.y;
		if(ver[start.x][start.y]==1):
				print "vertical"
				NN=G[start.x+1][start.y];
				dist=start.dis+1;
				pth=start.path;
				pth1=list(pth);
				if(dist<NN.dis):
					G[start.x+1][start.y].dis=dist;
					ll=[start.y,start.x+1];
					print "path------before:",pth
					pth.append(ll);
					G[start.x+1][start.y].path=pth;
					print "path-->",pth;
					G[start.x][start.y].path=pth1;
					print "path of old node:",pth1;
				if(G[start.x+1][start.y].visited==False):
					dijkstra(G,G[start.x+1][start.y],hor,ver);
			

	if(start.x>0 and start.y<5):
		print "x=",start.x;
		print "y=",start.y;
		if(ver[start.x-1][start.y]==1):
			print "vertical neg"
			NN=G[start.x-1][start.y];
			dist=start.dis+1;
			pth=start.path;
			pth1=list(pth);
			if(dist<NN.dis):
				G[start.x-1][start.y].dis=dist;
				ll=[start.y,start.x-1];
				print "path------before:",pth
				pth.append(ll);
				G[start.x-1][start.y].path=pth;
				print "path-->",pth;
				G[start.x][start.y].path=pth1;
				print "path of old node:",pth1;
			if(G[start.x-1][start.y].visited==False):
				dijkstra(G,G[start.x-1][start.y],hor,ver);


	if(start.y>0 and start.x<5):
		print "x=",start.x;
		print "y=",start.y;
		if(ver[start.x][start.y-1]==1):
			print "horizontal neg"
			NN=G[start.x][start.y-1];
			dist=start.dis+1;
			pth=start.path;
			pth1=list(pth);
			if(dist<NN.dis):
				G[start.x][start.y-1].dis=dist;
				ll=[start.y-1,start.x];
				print "path------before:",pth
				pth.append(ll);
				G[start.x][start.y-1].path=pth;
				print "path-->",pth;
				G[start.x][start.y].path=pth1;
				print "path of old node:",pth1;
			if(G[start.x][start.y-1].visited==False):
				dijkstra(G,G[start.x][start.y-1],hor,ver);





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
	

	return mat1,mat2;


#####################################################################
## Main Function
#####################################################################
if __name__ == "__main__":
    


	Gr=list();
	for i in range(0,6):
		X=list();
	
		for j in range(0,6):
			a=Node();
			a.x=i;
			a.dis=999999;
			a.path=list();
			a.y=j;
			X.append(a);
		Gr.append(X);


	img=cv2.imread("./Test_Images/test_image1.jpg");
	hor,ver=fun(img);
	
		


	Gr[4][1].dis=0;
	start=Gr[4][1];

	dijkstra(Gr,start,hor,ver);
	p(Gr);
