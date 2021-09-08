

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





	hor=	[[1, 0, 1, 1, 1],
		 [0, 1, 1, 1, 1],
		 [1, 0, 1, 1, 1],
		 [1, 1, 1, 1, 1],
		 [0, 1, 1, 1, 0],
		 [1, 1, 1, 1, 1]];

	ver=	[[1, 1, 1, 1, 0, 1],
		 [1, 1, 0, 1, 1, 1],
		 [1, 1, 0, 1, 1, 1],
		 [1, 1, 0, 1, 1, 1],
 		 [1, 0, 1, 1, 1, 1]];
	

	Gr[1][0].dis=0;
	start=Gr[1][0];

	dijkstra(Gr,start,hor,ver);
	p(Gr);
