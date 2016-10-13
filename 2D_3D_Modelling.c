 s = serial('COM3','BaudRate',9600);
 set(s, 'InputBufferSize', 1); %number of bytes in inout buffer
 set(s, 'FlowControl', 'none');
 set(s, 'Parity', 'none');
 set(s, 'DataBits', 8);
 set(s, 'StopBit', 1);
 set(s, 'Timeout',100);
 fopen(s)
for i=1:1:10

 i = fscanf(s);
 j=str2num(i);
 disp(j);
 vid = videoinput('winvideo',1);
 set(vid,'TriggerRepeat',Inf);
 vid.FrameGrabInterval = 2;
 vid_src = getselectedsource(vid);
 set(vid_src,'Tag','2D to 3D modelling');
 start(vid)
 while(vid.FramesAcquired<=5) % Stop after 100 frames
    data = getdata(vid,2); 
    diff_im = data(:,:,:,1);

 end
 stop(vid)
 delete(vid)
 g=num2str(j)
 path=strcat(g,'.jpg')
      imwrite(diff_im,path);
end
 

 fclose(s)
 delete(s)
 clear s
 I=ycbcr2rgb(diff_im);
 b=rgb2gray(I)
 a=b;
 a=imresize(a, [240 320]);
 a=edge(a,'canny',0.4); % detecting laser edge
 a=bwareaopen(a,20);
 figure(35)
 [m,n]=size(a);
 k=1;
 x=[];
 y=[];
 for i=1:1:m
    for j=1:1:n
        
        if(a(i,j)==1)
            x(k)=i;
            y(k)=j;
            k=k+1;
        end
    end
    
 end

    x=uint16(x);
    y=uint16(y);

 xmin=min(x);
 ymin=min(y);
 xmax=max(x);
 ymax=max(y);
 dx=xmax-xmin;
 dy=ymax-ymin;
 a = imcrop(a,[ymin xmin dy dx]);
 [m,n]=size(a)
 k=1;
 for i=1:1:m
    for j=1:1:n
        if(a(i,j)==1)
            x(k)=i;
            y(k)=j;
            k=k+1;
        end
    end
 end

    x=uint16(x);
    y=uint16(y);
 d=x;
 x=y;
 y=d;
 x=double(x);
 y=double(y);
 z=-double(y);
 figure(1);
 l=length(x);
 maxx=max(x)
 minx=min(x)
 avgx=(maxx-minx)/2;
 for i=1:1:l
 x(i)=x(i)-avgx;
 end
 x1=x;
 y1=y;
 x=double(x);
 y=double(y);
 z=-double(y);
 for t=0:(pi/20):pi
  for i=1:1:l
  x(i)=x1(i)*cos(t);
  y(i)=x1(i)*sin(t);
  end
  hold all
  plot3(x,y,z);
 end
 m1=m;
 n1=n;
x11=0;
y11=0;
z11=0;

x11=double(x11);
y11=double(y11);
z11=double(z11);
 for i111=1:1:9
 j111=i111-1;
 g=num2str(j111);
 path=strcat(g,'.jpg');
 I=imread(path);
 I=ycbcr2rgb(I);
 b=rgb2gray(I);
 a=b;
 a=imresize(a, [240 320]);
 a=edge(a,'canny',0.4); % detecting laser edge
 a=bwareaopen(a,20);
 figure(35);
 [m,n]=size(a);
 k=1;
 x=[];
 y=[];
 for i=1:1:m
    for j=1:1:n
        if(a(i,j)==1)
            x(k)=i;
            y(k)=j;
            k=k+1;
        end
    end
 end
 x=uint16(x);
 y=uint16(y);

 xmin=min(x);
 ymin=min(y);
 xmax=max(x);
 ymax=max(y);
 dx=xmax-xmin;
 dy=ymax-ymin;
 a = imcrop(a,[ymin xmin dy dx]);
 a=imresize(a, [m1 n1]);
 [m,n]=size(a);
 k=1;
 for i=1:1:m
    for j=1:1:n
        if(a(i,j)==1)
            x(k)=i;
            y(k)=j;
            k=k+1;
        end
    end
 end
    x=uint16(x);
    y=uint16(y);
 d=x;
 x=y;
 y=d;
 x=double(x);
 y=double(y);
 z=-double(y);
 figure(1);
 l=length(x);
 maxx=max(x);
 minx=min(x);
 avgx=(maxx-minx)/2;
 for i=1:1:l
 x(i)=x(i)-avgx;
 end
 
 t=double((j111*pi)/10);
 for i=1:1:l
 z1(i)=-y(i);
 x1(i)=x(i)*cos(t);
 y1(i)=x(i)*sin(t);
 end
  figure(100)
 plot3(x1,y1,z1)
 hold all
 end

  