import cv2
import numpy

#Teams can add other helper functions
#which can be added here

def puzzle(D1,D2):
    
	#add your code here
	arr1=list(D1[0]);
	arr2=list(D2[0]);
	
	class A:
		i=int();
		val=int();
	class B:
		a=A();
		b=A();
	
	arr=list();
	
	for i in range(0,len(arr2)-1,2):
		a=A();
		a.i=arr2[i];
		a.val=arr2[i+1];
		arr.append(a)
	
	ans=list();
	for k in range(0,len(arr)):
		x=list();
		for i in range(0,len(arr1)):
			for j in range(i+1,len(arr1)):
				if(i!=j and arr[k].val==arr1[i]+arr1[j]):
					a1=A();
					a1.i=i;
					a1.val=arr1[i];
					b1=A();
					b1.i=j;
					b1.val=arr1[j];
					aa=B();
					aa.a=a1;
					aa.b=b1;
					x.append(aa);
		ans.append(x);	
			
	l1=ans[0];
	l2=ans[1];
	l3=ans[2];
	
	result=list();
	for i in l1:
		for j in l2:
			for k in l3:
				
				if(i.a.i!=j.a.i and i.a.i!=j.b.i and i.a.i!=k.a.i and i.a.i!=k.b.i and i.b.i!=j.a.i and i.b.i!=j.b.i and i.b.i!=k.a.i and i.b.i!=k.b.i and j.a.i!=k.a.i and j.a.i!=k.b.i and j.b.i!=k.a.i and j.b.i!=k.b.i):
					
					aaa=[i.a.val+i.b.val,i.a.val,i.b.val,j.a.val+j.b.val,j.a.val,j.b.val,k.a.val+k.b.val,k.a.val,k.b.val]
					result.append(aaa);

	i=result[0];
	for k in range(0,len(i),3):
		print i[k],"=",i[k+1],"+",i[k+2];
		 				
	return 0

if __name__ == "__main__":
    #code for checking output for single test input
    fo = open("test_inputs/Test_input0.txt", "r")
    D1=[map(int, fo.readline().split())]
    D2=[map(int, fo.readline().split())]
    puzzle (D1,D2)

    #code for checking output for all test inputs
    for file_number in range(0,3):
        file_name = "test_inputs/Test_input"+str(file_number)+".txt"
        fo = open(file_name, "r")
        D1=[map(int, fo.readline().split())]
        D2=[map(int, fo.readline().split())]
        puzzle (D1,D2)
