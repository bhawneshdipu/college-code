# -*- coding: cp1252 -*-
import numpy as np
import cv2

#####################################################################
## Experiment 1
#####################################################################

def grid_to_arrays(img):
    	'''
    	* Function Name: grid_to_arrays
    	* Input: img  Any one of the test images 
    	* Output: arrays - a list containing the Horizontal Links array and the Vertical Links array
    	* Example Call: a, b = grid_to_arrays(img)
                    >>> a = horizontal_links, b = vertical_links
    	'''
	#add your code here

    	x1=25;
	y1=0;
	#cv2.imshow("image",img);
	#cv2.waitKey(0);
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
	#for filling matrix with 1 if their is an edge ,0 if not
	for _1 in range(0,6):
		y1=y1+12;
		x1=25;
		for _2 in range(0,5):
			x1=x1+50;#x in center of edge path
			r,g,b=img[y1,x1];
			if(r==0 and b==0 and g==0):#black pixel
				mat1[_1][_2]=1;#edge found
			else:
				mat1[_1][_2]=0;#edge not found
			
			
			x1=x1+50+25;#x to next edge position
		y1=y1+13+100;#set y to next row of edges
	x1=0;
	y1=25;
	for _1 in range(0,5):
		y1=y1+50;#y in center of edge path
		x1=0;
		for _2 in range(0,6):
			x1=x1+12;#set x to center of edge
			r,g,b=img[y1,x1];
			if(r==0 and b==0 and g==0):#black pixel
				mat2[_1][_2]=1;#edge found
			else:
				mat2[_1][_2]=0;#edge not found
			
			
			x1=x1+13+100;#incremnet x to next row
		y1=y1+50+25;#increment y to next edge
#	print("horizontal")
#	for i in range(0,6):
#			print(mat1[i]);
	
#	print ("vertical");
#	for i in range(0,5):
#			print(mat2[i]);
	

	return mat1,mat2;





    #return horizontal_links, vertical_links

#####################################################################
## Experiment 2
#####################################################################

def shortest_path(img):
    	'''
    	* Function Name: shortest_path
    	* Input: img  Any one of the test images
    	* Output: length  length of shortest path
              shortest_path  the shortest path as a list of coordinates of form (x,y)
    	* Example Call: l, sp = shortest_path(img)
                    >>> l = length, sp = shortest_path 
    	'''
    	#add your code here
	
    	#node class 
	class Node:
		x=int();
		y=int();
		dis=int();
		path=list();
		visited=False;


	way=list();#list to store each instance of end node each time it is updated
	def dijkstra(Graph,start,end,hor,ver,f):
		G=Graph;
#		print "frame=",f," x=",start.x, "y=",start.y,"dis=",start.dis,"visit=",start.visited;
#		print "y=",start.y;
#		print "dis=",start.dis;
#		print start.path;

		G[start.x][start.y].visited=True;#set node to visited
	
		if(start==end):
			#print "start=====end";
			way.append(start);#append to way list()

		if(start.x<0 or start.x>5 or start.y<0 or start.y>5):
			return;#out of index then return 
		
	





		if(start.y<5 ):
				if(hor[start.x][start.y]==1):
					
					NN=G[start.x][start.y+1];
					dist=G[start.x][start.y].dis+1;
					pth=G[start.x][start.y].path;
					pth1=list(pth);
					if(dist<NN.dis):#if distance is less then update
						G[start.x][start.y+1].dis=dist;
						ll=[start.y+1,start.x];#update cost
						pth.append(ll);#update path
						G[start.x][start.y+1].path=pth;
						G[start.x][start.y].path=pth1;
				#	print start.x,"  ",start.y,"dis=",start.dis,"horizontal ",start.x,"  ",start.y+1," ",G[start.x]	[start.y+1].dis;
					#if not visited within same frame then move
					if(G[start.x][start.y+1].visited==False and end.dis>=dist):#pruning as current node distance is greate then donot go
							dijkstra(G,G[start.x][start.y+1],end,hor,ver,f+1);
				


		#same for all 4 direction:
		if(start.x<5):	
			if(ver[start.x][start.y]==1):
					NN=G[start.x+1][start.y];
					dist=start.dis+1;
					pth=start.path;
					pth1=list(pth);
					if(dist<NN.dis):
						G[start.x+1][start.y].dis=dist;
						ll=[start.y,start.x+1];
						pth.append(ll);
						G[start.x+1][start.y].path=pth;
						G[start.x][start.y].path=pth1;
				#	print start.x,"  ",start.y," dis=",start.dis,"vertical ",start.x+1,"  ",start.y," ",G[start.x+1][start.y].dis;
					if(G[start.x+1][start.y].visited==False and end.dis>=dist):
						dijkstra(G,G[start.x+1][start.y],end,hor,ver,f+1);
			

		if(start.x>0):
			if(ver[start.x-1][start.y]==1):
				NN=G[start.x-1][start.y];
				dist=start.dis+1;
				pth=start.path;
				pth1=list(pth);
				if(dist<NN.dis):
					G[start.x-1][start.y].dis=dist;
					ll=[start.y,start.x-1];
					pth.append(ll);
					G[start.x-1][start.y].path=pth;
					G[start.x][start.y].path=pth1;
				#print start.x,"  ",start.y," dis=",start.dis,"vertical neg ",start.x-1,"  ",start.y," ",G[start.x-1]	[start.y].dis

				if(G[start.x-1][start.y].visited==False and end.dis>=dist):
					dijkstra(G,G[start.x-1][start.y],end,hor,ver,f+1);
	
	
		if(start.y>0):
			if(hor[start.x][start.y-1]==1):
				NN=G[start.x][start.y-1];
				dist=start.dis+1;
				pth=start.path;
				pth1=list(pth);
				if(dist<NN.dis):
					G[start.x][start.y-1].dis=dist;
					ll=[start.y-1,start.x];
					pth.append(ll);
					G[start.x][start.y-1].path=pth;
					G[start.x][start.y].path=pth1;
				#print start.x,"  ",start.y," dis= ",start.dis,"horizontal neg ",start.x,"  ",start.y-1," ",G[start.x]	[start.y-1].dis
				if(G[start.x][start.y-1].visited==False and end.dis>=dist):
					dijkstra(G,G[start.x][start.y-1],end,hor,ver,f+1);
	
		G[start.x][start.y].visited=False;	#set node as not visited so to have all recurssive calls



	def findpoints(img):
		x=0;
		y=0;
		#cv2.imshow("image",img);
		#cv2.waitKey(0);
		height,width,c=img.shape
		
		for _1 in range(0,6):
			x=x+12;
			y=0;
			for _2 in range(0,6):
				y=y+12;
				b,g,r=img[x,y];#b,g,r value
				
				if(g>250 and r<10 and b<10):#if green
					start=[_1,_2];
					#print "start";
				if(r>250 and g<10 and b<10):#if red
					#print "end";
					end=[_1,_2];
				y=y+113;
		
			x=x+113;
		return start,end;#return start and end node





	Gr=list();#graph is a matrix of nodes
	for i in range(0,6):
		X=list();	
		for j in range(0,6):
			a=Node();
			a.x=i;
			a.dis=999999;#set distance to infinity
			a.path=list();
			a.y=j;
			X.append(a);
		Gr.append(X);


	hor,ver=grid_to_arrays(img);#find horizontal and vertical links
	

	f,l=findpoints(img);#find start and end node
	
	Gr[f[0]][f[1]].dis=0;#set start node distance to zero
	start=Gr[f[0]][f[1]];
	end=Gr[l[0]][l[1]];
	Gr[f[0]][f[1]].path=[f[1],f[0]];
	
	dijkstra(Gr,start,end,hor,ver,0);
	dist=way[0].dis;#choose min distance path that has been saved .
	backtrace=way[0].path;
	for i in way:
		if(i.dis<dist):
			dist=i.dist;
			backtrace=i.path;

	return  dist,backtrace;		
	











    #return length, shortest_path


#####################################################################
## Main Function
#####################################################################
if __name__ == "__main__":
    
## Experiment 1
    img = cv2.imread('test_images/test_image5.jpg')
    print "Experiment 1 Output:"
    hl, vl = grid_to_arrays(img)
    print "Horizontal Links:\n", hl
    print "Vertical Links:\n", vl
    print

## Experiment 2
    img = cv2.imread('test_images/test_image5.jpg')
    print "Experiment 2 Output:"
    l, sp = shortest_path(img)
    print "Length = ", l
    print "Shortest Path:\n", sp
    print    
